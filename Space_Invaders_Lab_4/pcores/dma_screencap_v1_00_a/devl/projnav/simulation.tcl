proc run_clock { {cycles 1} } {
	for {set i 0} {$i < $cycles} {incr i} {
		isim force add bus2ip_clk 0
		run 10ns
		isim force add bus2ip_clk 1
		run 10ns
	}
}

proc send_data { signal1 signal2 {count 16} } {
	for {set i 0} {$i < $count} {incr i} {
		isim force add $signal1 1
		
		run_clock
		
		isim force add $signal1 0
		
		run_clock
		
		isim force add $signal2 1
		
		run_clock

		isim force add $signal2 0
		
		run_clock
	}
}

proc assert_cycle { signal {cycles 1} } {
	isim force add $signal 1

	run_clock $cycles

	isim force add $signal 0
	
	run_clock $cycles
}

restart

# the script

# clear some inputs
isim force add mst_fifo_valid_write_xfer 0
isim force add mst_fifo_valid_read_xfer 0
isim force add Bus2IP_MstRd_d 0
isim force add Bus2IP_data 0

isim force add bus2ip_resetn 1

run_clock 1

isim force add bus2ip_resetn 0

run_clock 2

isim force add bus2ip_resetn 1

run_clock 10

# start the test'
# setup slave registers
isim force add slv_reg1 1024
isim force add slv_reg2 64
isim force add slv_reg3 [expr 20 * 4] ;# 20 words

isim force add mst_go 1

run_clock

# start a sequence of writes to the FIFO
isim force add Bus2IP_MstRd_d DEAFD00D -radix hex
isim force add mst_go 0

# do 16 reads
send_data mst_fifo_valid_write_xfer Bus2IP_Mst_Cmplt

run_clock 2

# do 16 writes
send_data mst_fifo_valid_read_xfer Bus2IP_Mst_Cmplt

run_clock 4

# do 16 reads
send_data mst_fifo_valid_write_xfer Bus2IP_Mst_Cmplt

run_clock 2

# do 16 writes
send_data mst_fifo_valid_read_xfer Bus2IP_Mst_Cmplt

run_clock 4

## # # # # # #
## Test small transfers
## # # # # # #
#
#isim force add slv_reg1 0
#isim force add slv_reg2 2048
#isim force add slv_reg3 [expr 4 * 4] ;# 20 words
#
#assert_cycle mst_go
#
## do 4 reads
#send_data mst_fifo_valid_write_xfer Bus2IP_Mst_Cmplt 4
#
## do 4 writes
#send_data mst_fifo_valid_read_xfer Bus2IP_Mst_Cmplt 4
#
#run_clock 4