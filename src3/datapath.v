module datapath(clk,rst,pos_out,rs_out,rt_out,PCWr,
IRWr,GPRWr,Bsel,DMWr,MemByte,WDsel,GPRsel,Extop,
ALUOp,NPCOp,ALUsel,opcode,funct,zero,flow,PC,praddr,
prwd,prrd,EPC,Dout,DIn,SEL,intreq,eret);
    
    input clk,rst;

    input PCWr; // pc寄存器的写使能信号
    input IRWr; // 指令寄存器写使能
    input GPRWr; // 寄存器组目标寄存器写使能
    input Bsel; // 第二操作数选择器
    input DMWr; // 数据存储写使能
    input MemByte; // 是否为字节访问
    input [2:0] WDsel; //  寄存器组写入数据选择器 
    input [1:0] GPRsel; // 寄存器组目标寄存器选择器 
    input [1:0] Extop; // 数据扩展选择器 
    input [1:0] ALUOp; //计算类型选择器
    input [1:0] NPCOp; // 下一条指令顺序执行/跳转/分支/函数返回
    input [1:0] ALUsel; // 选择ALU输出

    output [5:0] opcode;
    output [5:0] funct;
    output flow,zero;
    output pos_out;

    output [4:0] rt_out;
    output [4:0] rs_out;

    output [31:2] PC; // 输出给cp0的指令地址
    output [31:0] DIn; // 输出给cp0数据

    output [31:0] praddr;
    output [31:0] prwd;
    input [31:0] prrd;

    output [4:0] SEL;
    input [31:2] EPC;

    input [31:0] Dout;

    input intreq;
    input eret;


    // 连线信号

    wire [31:0] pc,npc,pc_4; // pc寄存器输出线/npc端口输出线/pc+4输出线
    wire [31:0] instr; // 指令存储器输出线
    wire [31:0] instr_r; // 指令寄存器输出线
    wire [31:0] imm_ext; // 扩展器输出线
    wire [31:0] alu_out; // aluout输出线
    wire [31:0] alu_out_r; // aluout寄存器输出线
    wire [31:0] reg_a, reg_b; // a,b操作数结果输出线
    wire [31:0] reg_a_r,reg_b_r;// a,b操作数结果寄存器输出线
    wire [31:0] write_data; // 寄存器写入数据线
    wire [4:0] write_reg; // 写入寄存器编号线
    wire [31:0] dm_out; // 数据存储器输出
    wire [31:0] dm_out_r;// 数据寄存器输出
    wire [31:0] jr_data; // jr指令的数据
    wire zero_out;
    wire flow_out;
    wire pos_out;


    // 数据通路输出

    // 输出当前指令opcode和funct
    assign opcode = instr_r[31:26];
    assign funct = instr_r[5:0];

    // zero和flow
    assign zero = zero_out;
    assign flow = flow_out;

    assign rt_out = instr_r[20:16];
    assign rs_out = instr_r[25:21];

    assign prwd = reg_b_r; // rt

    assign SEL = instr_r[15:11];

    assign PC = pc[31:2]; // 

    assign praddr = alu_out_r; // alu_result 是 EXE 阶段输出，表示地址

    assign DIn = reg_b_r; // rt
    // 实例化

    // pc寄存器
    pc my_pc(
        .clk(clk),
        .rst(rst),
        .PCWr(PCWr),
        .din(npc),
        .dout(pc)
    );

    // 指令存储器
    im_1k my_im(
        .addr(pc[9:0]),
        .dout(instr)
    );

    // 指令寄存器
    ir my_ir(
        .clk(clk),
        .IRWr(IRWr),
        .pc_in(instr),
        .instr(instr_r)
    );

    //  寄存器写入数据选择组合逻辑
    assign write_data = (WDsel  == 3'b000)? alu_out_r:
                        (WDsel == 3'b001)? dm_out_r:
                        (WDsel == 3'b010)? pc_4 :(WDsel == 3'b011) ? prrd: Dout;
                        

    // 寄存器写入编号选择组合逻辑
    assign write_reg = (GPRsel==2'b00)?instr_r[20:16]:(GPRsel==2'b01)
    ?instr_r[15:11]:(GPRsel==2'b10)?5'b11110:5'b11111;


    // 寄存器堆
    gpr my_gpr(
        .clk(clk),
        .rst(rst),
        .GPRWr(GPRWr),
        .reg1(instr_r[25:21]),
        .reg2(instr_r[20:16]),
        .write_data(write_data),
        .write_reg(write_reg),
        .reg_in(instr_r[25:21]),// 应该是rs的编号
        .data_out(jr_data), 
        .read_data1(reg_a),
        .read_data2(reg_b)
    );

    // A,B寄存器

    opa my_opa(
        .clk(clk),
        .din(reg_a),
        .dout(reg_a_r)
    );

    opb my_opb(
        .clk(clk),
        .din(reg_b),
        .dout(reg_b_r)
    );

    // 扩展器
    ext my_ext(
        .din(instr_r[15:0]),
        .Extop(Extop),
        .dout(imm_ext)
    );

    // 运算器

    alu my_alu(
        .din1(reg_a_r),
        .din2((Bsel)?imm_ext:reg_b_r),
        .ALUOp(ALUOp),
        .ALUsel(ALUsel),
        .dout(alu_out),
        .flow(flow_out),
        .zero(zero_out),
        .pos(pos_out)
    );

    // alu结果寄存器

    aluout my_aluout(
        .clk(clk),
        .din(alu_out),
        .dout(alu_out_r)
    );

  

    // 数据存储器

    dm_1k my_dm(
        .addr(alu_out_r[9:0]),
        .din(reg_b_r),
        .rst(rst),
        .we(DMWr),
        .clk(clk),
        .MemByte(MemByte),
        .dout(dm_out)
    );
    
    // 数据寄存器
    
    dr my_dr(
        .clk(clk),
        .din(dm_out),
        .dout(dm_out_r)
    );


    // NPC

    npc my_npc(
        .addr(pc),
        .imm(instr_r[25:0]),
        .NPCOp(NPCOp),
        .reg_data(jr_data),
        .npc(npc),
        .pc_4(pc_4),
        .epc(EPC),
        .intreq(intreq),
        .eret(eret)
    );

endmodule 