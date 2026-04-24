module datapath(clk,rst,RegDst,ALUSrc,RegWr,MemtoReg,MemWrite,nPC_sel,Ext_Op,ALUctr,pc_sel,alu_sel,addi_sel,opcode,funct);
    
    input clk,rst;

    input [1:0] RegDst;
    input ALUSrc;
    input RegWr;
    input [1:0] MemtoReg;
    input MemWrite;
    input nPC_sel;
    input [1:0] Ext_Op;
    input [1:0] ALUctr ;
    input [1:0] pc_sel;
    input [1:0] alu_sel;
    input addi_sel;

    output [5:0] opcode;
    output [5:0] funct;

    // 连线信号

    wire [31:0] pc,npc,pc_4;
    wire [31:0] instr;
    wire [31:0] imm_ext;
    wire [31:0] alu_out;
    wire [31:0] reg1_data, reg2_data;
    wire [31:0] write_data; // 寄存器写入数据
    wire [4:0] write_reg; // 写入寄存器编号
    wire [31:0] dm_out;
    wire [31:0] jr_data; // jr指令的数据
    wire zero;
    wire flow;


    // 数据通路输出

    assign opcode = instr[31:26];
    assign funct = instr[5:0];

    // 实例化

    // pc寄存器
    pc my_pc(
        .clk(clk),
        .rst(rst),
        .din(npc),
        .dout(pc)
    );

    // 指令寄存器
    im_1k my_im(
        .addr(pc[9:0]),
        .dout(instr)
    );

    //  寄存器写入数据选择组合逻辑
    assign write_data = (MemtoReg == 2'b00)? alu_out:
                        (MemtoReg == 2'b01)? dm_out:
                        (MemtoReg == 2'b10)? pc_4:32'b0;
    // 寄存器写入编号选择组合逻辑(注意还要考虑溢出)
assign write_reg = (instr[31:26] == 6'b001000) ? 
                      ((flow == 1'b1) ? 5'b11110 : instr[20:16]) :
                   (RegDst == 2'b00) ? instr[20:16] :
                   (RegDst == 2'b01) ? instr[15:11] :
                   (RegDst == 2'b10) ? 5'b11110 :
                                       5'b11111;


    // 寄存器堆
    gpr my_gpr(
        .clk(clk),
        .rst(rst),
        .GPRWr(RegWr),
        .reg1(instr[25:21]),
        .reg2(instr[20:16]),
        .write_data(write_data),
        .write_reg(write_reg),
        .reg_in(instr[25:21]),// 应该是rs的编号
        .data_out(jr_data), 
        .read_data1(reg1_data),
        .read_data2(reg2_data)
    );

    // 扩展器
    ext my_ext(
        .din(instr[15:0]),
        .extOp(Ext_Op),
        .dout(imm_ext)
    );

    // 运算器

    alu my_alu(
        .din1(reg1_data),
        .din2((ALUSrc)?imm_ext:reg2_data),
        .ALUctr(ALUctr),
        .alu_sel(alu_sel),
        .dout(alu_out),
        .flow(flow),
        .zero(zero)
    );


    // 数据存储器

    dm_1k my_dm(
        .addr(alu_out[9:0]),
        .din(reg2_data),
        .we(MemWrite),
        .clk(clk),
        .dout(dm_out)
    );


    // NPC

    npc my_npc(
        .addr(pc),
        .imm(instr[25:0]),
        .pc_sel(pc_sel),
        .reg_data(jr_data),
        .zero(zero),
        .npc_sel(nPC_sel),
        .npc(npc),
        .pc_4(pc_4)
    );

endmodule 