// Taylor Simons & Joseph DeVictoria
// ECEN 427 - FALL 2014.

#include "xgpio.h"          // Provides access to PB GPIO driver.
#include <stdio.h>          // xil_printf and so forth.
#include "platform.h"       // Enables caching and other system stuff.
#include "mb_interface.h"   // provides the microblaze interrupt enables, etc.
#include "xintc_l.h"        // Provides handy macros for the interrupt controller.

XGpio gpLED;  // This is a handle for the LED GPIO block.
XGpio gpPB;   // This is a handle for the push-button GPIO block.

int fit_counter, debouncer, updateMode, scaling;
int time, sec, min, hour;
u32 currentButtonState;

//This function adjusts the time based on button presses.
void adjustTime(int cbs){
	//the following are masks for all of the button combinations we wish to use
	char left = cbs&(0x8);
	char mid = cbs&(0x1);
	char right = cbs&(0x2);
	char up = cbs&(0x10);
	char down = cbs&(0x4);
	char upDown = cbs&(0x14);
	//If no buttons are press then we turn off scaling mode and update mode
	if (cbs == 0){
		updateMode = 0;
		scaling = 0;
		return;
	}
	//for the right, middle and left buttons we preform logic acordingly
	if (left){
		updateMode = 1;
		if (up){
			if (time/3600 >= 23){		//If we go over 23 hours on the display...
				time -= 82800;			//... we loop back to 00 hours
			}
			else{
				time += 3600;			//increment the time by an hour
			}
		}
		if (down){
			if (time/3600 <= 0){		//If we go below 00 hours on the display...
				time += 82800;			//... we loop back to 23 hours
			}
			else{
				time -= 3600;			//decrement the time by an hour
			}
		}
		if (upDown == 0){				//Exit scaling mode
			scaling = 0;
		}
	}
	if (mid){
		updateMode = 1;
		if (up){
			if (((time - 3600*(time/3600))/60) >= 59){	//If we go over 59 minutes on the display...
				time -= 3540;			//... we loop back to 00 minutes
			}
			else{
				time += 60;				//increment the time by a minute
			}
		}
		if (down){
			if (((time - 3600*(time/3600))/60) <= 0){	//If we go below 00 minutes on the display...
				time += 3540;			//... we loop back to 59 minutes
			}
			else{
				time -= 60;				//decrement the time by a minute
			}
		}
		if (upDown == 0){				//Exit scaling mode
			scaling = 0;
		}
	}
	if (right){
		updateMode = 1;
		if (up){
			if ((time % 60) >= 59){		//If we go over 59 seconds on the display...
				time -= 59;				//... we loop back to 00 seconds
			}
			else{
				time++;					//increment the time by a second
			}
		}
		if (down){
			if ((time % 60) <= 0){		//If we go below 00 seconds on the display...
				time += 59;				//... we loop back to 59 seconds
			}
			else{
				time--;					//decrement the time by a second
			}
		}
		if (upDown == 0){
			scaling = 0;				//Exit scaling mode
		}
	}
}

void printTime(){
	hour = time / 3600;
	min = (time - (3600*hour)) / 60;
	sec = time % 60;
	xil_printf("%02d:%02d:%02d\r", hour, min, sec);
}

// This is invoked in response to a timer interrupt.
// It does 2 things: 1) debounce switches, and 2) advances the time.
void timer_interrupt_handler() {
	fit_counter++;
	if (scaling == 0){						//If the scaling feature is not set...
		if(debouncer <= 49){				//...keep counting up to .5 sec, waiting for scaling mode
			debouncer++;
		}
		if (debouncer == 2 ){
			adjustTime(currentButtonState);	//If we have debounced for .02 seconds register a botton press
			printTime();					//Print the time after a time change
		}
		if (debouncer == 50 ){				//Set scaling mode after .5 seconds
			scaling = 1;
		}
	}else if (scaling == 1){				//In scaling mode check the debounce
		if (debouncer != 50){
			debouncer++;
		} else {
			adjustTime(currentButtonState);	//If we hit a half second increment the timer
			printTime();
			debouncer = 0;
		}
	}
	if (fit_counter == 100){				//Update the timer by one second every second
		if (updateMode == 0){
			time++;							//Increment the timer
		}
		printTime();						//Print time after time update
		fit_counter = 0;					//reset the fit count
	}
}

// This is invoked each time there is a change in the button state (result of a push or a bounce).
void pb_interrupt_handler() {
  // Clear the GPIO interrupt.
  XGpio_InterruptGlobalDisable(&gpPB);                // Turn off all PB interrupts for now.
  // You need to do something here.
  currentButtonState = XGpio_DiscreteRead(&gpPB, 1);  // Get the current state of the buttons.
  debouncer = 0;
  XGpio_InterruptClear(&gpPB, 0xFFFFFFFF);            // Ack the PB interrupt.
  XGpio_InterruptGlobalEnable(&gpPB);                 // Re-enable PB interrupts.
}

// Main interrupt handler, queries the interrupt controller to see what peripheral
// fired the interrupt and then dispatches the corresponding interrupt handler.
// This routine acks the interrupt at the controller level but the peripheral
// interrupt must be ack'd by the dispatched interrupt handler.
void interrupt_handler_dispatcher(void* ptr) {
	int intc_status = XIntc_GetIntrStatus(XPAR_INTC_0_BASEADDR);
	// Check the FIT interrupt first.
	if (intc_status & XPAR_FIT_TIMER_0_INTERRUPT_MASK){
		XIntc_AckIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
		timer_interrupt_handler();
	}
	// Check the push buttons.
	if (intc_status & XPAR_PUSH_BUTTONS_5BITS_IP2INTC_IRPT_MASK){
		XIntc_AckIntr(XPAR_INTC_0_BASEADDR, XPAR_PUSH_BUTTONS_5BITS_IP2INTC_IRPT_MASK);
		pb_interrupt_handler();
	}
}

int main (void) {
    init_platform();
    // Initialize the GPIO peripherals.
    int success;
    // print("hello world\n\r");
    success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);
    // success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);

    // Set the push button peripheral to be inputs.
    XGpio_SetDataDirection(&gpPB, 1, 0x0000001F);
    // Enable the global GPIO interrupt for push buttons.
    XGpio_InterruptGlobalEnable(&gpPB);
    // Enable all interrupts in the push button peripheral.
    XGpio_InterruptEnable(&gpPB, 0xFFFFFFFF);

    microblaze_register_handler(interrupt_handler_dispatcher, NULL);
    XIntc_EnableIntr(XPAR_INTC_0_BASEADDR,
    		(XPAR_FIT_TIMER_0_INTERRUPT_MASK | XPAR_PUSH_BUTTONS_5BITS_IP2INTC_IRPT_MASK));
    XIntc_MasterEnable(XPAR_INTC_0_BASEADDR);
    microblaze_enable_interrupts();

    while(1);  // Program never ends.

    cleanup_platform();

    return 0;
}
