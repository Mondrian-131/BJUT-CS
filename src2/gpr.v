module gpr(clk,rst,reg1,reg2,GPRWr,write_data,write_reg,read_data1,read_data2,reg_in,data_out);
   
    input clk; // 时钟信号
    input rst; // 复位信号
    input GPRWr; // 寄存器写使能
    input [4:0] reg1; // A寄存器编号
    input [4:0] reg2; // B寄存器编号
    input [31:0] write_data; // 寄存器写入数据
    input [4:0] write_reg; // 目标寄存器编号
    input [4:0] reg_in; // jr寄存器编号
    output [31:0] data_out;// jr寄存器数据
    output [31:0] read_data1; // A操作数
    output [31:0] read_data2; // B操作数
    
    reg[31:0] regs[0:31];  // 寄存器堆
    integer i;

    assign read_data1 = regs[reg1]; //  A操作数数据
    assign read_data2 = regs[reg2]; // B操作数数据
    assign data_out = regs[reg_in]; // jr寄存器数据
    
    always@(posedge clk)
    begin
        if(rst) 
        begin
            for(i=0;i<32;i=i+1)
                regs[i]<=32'b0;
        end
        else if (GPRWr && write_reg!=0) 
            regs[write_reg] <= write_data;
    end


endmodule