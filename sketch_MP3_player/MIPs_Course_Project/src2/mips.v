module mips (
    input  wire        clk,
    input  wire        rst
);

    // 内部连线
    wire [5:0] opcode;
    wire [5:0] funct;
    wire       zero, flow;

    wire       PCWr, IRWr, GPRWr, Bsel, DMWr, MemByte;
    wire       pos;
    wire [4:0] rt_out;
    wire [4:0] rs_out;
    wire [1:0]  GPRsel, Extop, ALUOp, NPCOp, ALUsel;
    wire [2:0]  WDsel;

    controller my_controller (
        .clk(clk),
        .rst(rst),
        .opcode(opcode),
        .funct(funct),
        .zero(zero),
        .flow(flow),
        .PCWr(PCWr),
        .IRWr(IRWr),
        .GPRWr(GPRWr),
        .Bsel(Bsel),
        .DMWr(DMWr),
        .MemByte(MemByte),
        .WDsel(WDsel),
        .GPRsel(GPRsel),
        .Extop(Extop),
        .ALUOp(ALUOp),
        .NPCOp(NPCOp),
        .pos(pos),
        .rt(rt_out),
        .rs(rs_out),
        .ALUsel(ALUsel)
    );

    datapath my_datapath (
        .clk(clk),
        .rst(rst),
        .rt_out(rt_out),
        .rs_out(rs_out),
        .pos_out(pos),
        .opcode(opcode),
        .funct(funct),
        .zero(zero),
        .flow(flow),
        .PCWr(PCWr),
        .IRWr(IRWr),
        .GPRWr(GPRWr),
        .Bsel(Bsel),
        .DMWr(DMWr),
        .MemByte(MemByte),
        .WDsel(WDsel),
        .GPRsel(GPRsel),
        .Extop(Extop),
        .ALUOp(ALUOp),
        .NPCOp(NPCOp),
        .ALUsel(ALUsel)
    );

endmodule
