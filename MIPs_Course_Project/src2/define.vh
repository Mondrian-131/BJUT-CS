`define S0 4'd0
`define S1 4'd1
`define S2 4'd2
`define S3 4'd3
`define S4 4'd4
`define S5 4'd5
`define S6 4'd6
`define S7 4'd7
`define S8 4'd8

// Opcode 宏定义（instr[31:26])
`define OP_RTYPE   6'b000000  // R-type 通用
`define OP_ORI     6'b001101
`define OP_LW      6'b100011
`define OP_SW      6'b101011
`define OP_BEQ     6'b000100
`define OP_LUI     6'b001111
`define OP_J       6'b000010
`define OP_JAL     6'b000011
`define OP_ADDI    6'b001000
`define OP_ADDIU   6'b001001
`define OP_LB      6'b100000
`define OP_SB      6'b101000
`define OP_ERET    6'b010000
`define OP_MFC0    6'b010000
`define OP_MTC0    6'b010000

// funct 宏定义（R-type 指令专属 instr[5:0]）
`define FUNCT_ADDU 6'b100001
`define FUNCT_SUBU 6'b100011
`define FUNCT_SLT  6'b101010
`define FUNCT_JR   6'b001000
`define FUNCT_ERET 6'b011000