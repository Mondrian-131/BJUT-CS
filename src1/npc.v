module npc(addr,imm,pc_sel,npc_sel,zero,reg_data,npc,pc_4);
    
    input [31:0] addr; // pc传来的当前指令的地址
    input [25:0] imm ; // j/jal指令的26位立即数
    input [1:0] pc_sel; // 判断是顺序执行/跳转/函数返回(jr)
    input [31:0] reg_data; // jr指令指定的寄存器数据
    input zero; // 判断操作数相等(beq)
    input npc_sel; // 是否为分支指令
    output reg [31:0] npc; // 输出pc下一条指令地址
    output [31:0] pc_4; // 输出pc+4用于函数调用


    // pc_4 函数调用
    assign pc_4 = addr + 4;
    
    // 下一条指令地址
    always @(*)
    begin 
        if (zero & npc_sel)
            npc = addr + 4 + ({{14{imm[15]}}, imm[15:0], 2'b00});
        else 
        case(pc_sel)
            2'b00: npc = addr + 4;
            2'b01: npc = {addr[31:28],imm,2'b00};
            2'b10: npc = reg_data;
            default: npc = addr + 4;
        endcase
    end 

endmodule 