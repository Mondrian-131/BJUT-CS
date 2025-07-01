module pc(clk,rst,din,dout);

    input clk; // 时钟信号 
    input rst; // 复位信号
    input [31:0] din; // npc计算的下一条指令地址
    output reg [31:0] dout; // 输出当前指令地址

    always@(posedge clk)
        if (rst) dout <= 32'h0000_3000;// pc复位后的初值
        else
            dout <= din; 

endmodule