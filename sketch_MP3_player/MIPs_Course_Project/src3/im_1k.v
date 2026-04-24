module im_1k( addr, dout ) ;
    input   [9:0]  addr ;  // 32位地址的低10位
    output  [31:0]  dout ;  // 32位内存输出数据

   reg [7:0] im[0:8191];  // 8K

    initial 
    begin
        $readmemh("main.txt", im, 0,59);       // main 程序从索引0开始
        $readmemh("isr.txt", im, 64,107 ); // isr程序从索引64处开始
    end

    assign dout = {im[addr],im[addr+1],im[addr+2],im[addr+3]}; // 取指令存储器处的指令(大端序)

endmodule
