module ir(clk,IRWr,pc_in,instr);
    input clk;
    input IRWr; // 指令寄存器写使能
    input [31:0] pc_in;// 指令存储器传来下一条指令
    output reg [31:0] instr; // 输出当前指令

    always@(posedge clk)
    begin
        if(IRWr) instr<=pc_in;
    end
endmodule