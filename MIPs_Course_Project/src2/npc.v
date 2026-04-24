module npc(addr,imm,NPCOp,reg_data,npc,pc_4);
    
    input [31:0] addr; // pc传来的下一条指令的地址
    input [25:0] imm ; // j/jal指令的26位立即数
    input [1:0] NPCOp; // 判断是顺序执行/跳转/分支/函数返回(jr)
    input [31:0] reg_data; // jr指令指定的寄存器数据
    output reg [31:0] npc; // 输出给pc下下一条指令地址
    output [31:0] pc_4; // 输出pc+4用于函数调用


    // pc_4 函数调用
    assign pc_4 = addr;
    
    // 下下一条指令地址
    always @(*)
    begin 
        case(NPCOp)
            2'b00: npc = addr + 4; // 顺序执行
            2'b01: npc = {addr[31:28],imm,2'b00};  // j/jal跳转
            2'b10: npc = addr + ({{14{imm[15]}}, imm[15:0], 2'b00}); //beq分支
            2'b11: npc = reg_data; // jr函数返回
            default: npc = addr + 4;
        endcase
    end

endmodule 