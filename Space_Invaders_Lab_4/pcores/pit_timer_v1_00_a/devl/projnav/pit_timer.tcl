isim force add bus2ip_clk 0 -time 0 -value 1 -time 10ns -repeat 20ns
isim force add bus2ip_resetn 0 -time 0 -value 1 -time 25ns
isim force add pit_delay 000000FF -radix hex
isim force add pit_control 00000000 -radix hex -time 0 -value 00000007 -radix hex -time 35ns

run 500ns