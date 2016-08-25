isim force add Bus2IP_Clk 0 -time 0ns -value 1 -time 5ns -repeat 10ns
isim force add Bus2IP_Resetn 1 -time 0 ns -value 0 -time 12ns

isim force add slv_reg1 C1000000 -radix hex
isim force add slv_reg2 C5000000 -radix hex
isim force add slv_reg3 44 -radix hex
isim force add mst_go 1
isim force add Bus2IP_Data DEADBEEF -radix hex                    

isim force add Bus2IP_Mst_CmdAck 0
isim force add Bus2IP_Mst_Cmplt  0

run 30ns          

isim force add Bus2IP_Mst_CmdAck 1
isim force add Bus2IP_Mst_Cmplt  0

run 30ns