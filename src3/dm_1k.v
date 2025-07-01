module dm_1k(addr, rst,din, we, clk, dout,MemByte) ;
    input   [9:0]  addr ;  // 10位内存地址
    input   [31:0]  din ;   // 32位写入内存数据
    input   rst;
    input    we ;    // 内存写使能
    input    clk ;   // 时钟信号
    input   MemByte; // 是否为字节访问
    output [31:0] dout ;  // 32位内存输出数据

    integer i;

    reg  [7:0]  dm[0:1023] ; // 1KB内存

    assign dout = (MemByte==1'b1)? {{24{dm[addr][7]}},dm[addr]}:{dm[addr+3],dm[addr+2],dm[addr+1],dm[addr]};

    always@(posedge clk)
    begin
        if(rst)
            begin
                for(i=0;i<1024;i=i+1) 
                    dm[i]<=8'b0;
            end
        else if(we) 
            begin
                if(MemByte==1'b1) dm[addr]<=din[7:0];
                else
                    begin
                        dm[addr+3] <= din[31:24];
                        dm[addr+2] <= din[23:16];
                        dm[addr+1] <= din[15:8];
                        dm[addr] <= din[7:0];
                    end
            end
    end
endmodule