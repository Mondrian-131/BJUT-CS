module mips(clk, rst) ;
    
    input  clk ; 
    input  rst ;

    // 连线信号

    wire [5:0] opcode;
    wire [5:0] funct;
    wire [1:0] RegDst, MemtoReg, ALUctr, pc_sel, alu_sel, ExtOp;
    wire ALUSrc, RegWrite, MemWrite, nPC_sel, addi_sel;

    controller my_controller (
        .opcode(opcode),
        .funct(funct),
        .RegDst(RegDst),
        .ALUSrc(ALUSrc),
        .RegWrite(RegWrite),
        .MemtoReg(MemtoReg),
        .MemWrite(MemWrite),
        .nPC_sel(nPC_sel),
        .Ext_Op(ExtOp),
        .ALUctr(ALUctr),
        .pc_sel(pc_sel),
        .alu_sel(alu_sel),
        .addi_sel(addi_sel)
    );

    datapath my_datapath (
        .clk(clk),
        .rst(rst),
        .RegDst(RegDst),
        .ALUSrc(ALUSrc),
        .RegWr(RegWrite),
        .MemtoReg(MemtoReg),
        .MemWrite(MemWrite),
        .nPC_sel(nPC_sel),
        .Ext_Op(ExtOp),
        .ALUctr(ALUctr),
        .pc_sel(pc_sel),
        .alu_sel(alu_sel),
        .addi_sel(addi_sel),
        .opcode(opcode),   // 输出传到控制器
        .funct(funct)      // 输出传到控制器
    );

endmodule 