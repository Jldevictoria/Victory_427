################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bitmap.c \
../src/platform.c \
../src/renderer.c \
../src/space_invaders_main.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/bitmap.o \
./src/platform.o \
./src/renderer.o \
./src/space_invaders_main.o 

C_DEPS += \
./src/bitmap.d \
./src/platform.d \
./src/renderer.d \
./src/space_invaders_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -I../../space_invaders_bsp/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.20.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


