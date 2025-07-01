module im_1k( addr, dout ) ;
    input   [9:0]  addr ;  // 32位地址的[]位
    output  [31:0]  dout ;  // 32位内存输出数据

    reg [7:0]  im[0:1023] ; // 1KB内存

    initial 
    begin
        $readmemh("p1-test.txt", im); // 从文件加载指令
    end

    assign dout = {im[addr],im[addr+1],im[addr+2],im[addr+3]}; // 取指令存储器处的指令

endmodule
