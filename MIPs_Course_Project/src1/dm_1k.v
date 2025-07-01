module dm_1k( addr, din, we, clk, dout ) ;
    input   [9:0]  addr ;  // 内存地址
    input   [31:0]  din ;   // 32位写入内存数据
    input    we ;    // 内存写使能
    input    clk ;   // 时钟信号
    output  [31:0]  dout ;  // 32位内存输出数据

    reg  [7:0]  dm[0:1023] ; // 1KB内存

    assign dout = {dm[addr+3],dm[addr+2],dm[addr+1],dm[addr]};

    always@(posedge clk)
    begin
        if(we) 
            begin
                dm[addr+3] <= din[31:24];
                dm[addr+2] <= din[23:16];
                dm[addr+1] <= din[15:8];
                dm[addr]   <= din[7:0];
            end
    end
endmodule