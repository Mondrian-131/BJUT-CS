module mips (
    input  wire        clk,
    input  wire        rst,

    input  wire [31:0] prrd,       // 来自桥的读数据
    output wire [31:0] prwd,       // 写数据给桥
    output wire [31:0] praddr,     // 地址给桥

    output wire        EXLSet,
    output wire        EXLClr,     
    output wire [31:2] PC,         
    output wire [31:0] DIn,
    output wire        Wen,
    output wire [4:0] SEL,
    input  wire [31:0] Dout,       // cp0读出数据
    input  wire        Intreq,     // cp0的中断请求
    input  wire [31:2] EPC,        // EPC寄存器值
    output wire bridge_wen
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
    wire eret;

    wire int_npc;


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
        .ALUsel(ALUsel),
        .EXLClr(EXLClr),
        .EXLSet(EXLSet),
        .Wen(Wen),
        .intreq(Intreq),
        .bridge_wen(bridge_wen),
        .eret(eret),
        .int_npc(int_npc)
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
        .ALUsel(ALUsel),
        .PC(PC),
        .DIn(DIn),
        .prrd(prrd), // prrd传给datapath
        .praddr(praddr), // praddr传给桥 
        .prwd(prwd), // 给桥的数据
        .EPC(EPC),
        .SEL(SEL),
        .intreq(int_npc),
        .eret(eret)
    );

endmodule
