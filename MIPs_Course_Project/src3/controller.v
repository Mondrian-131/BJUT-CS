`include "define.vh"

module controller(clk,rst,opcode,funct,zero,pos,rs,rt,flow,
PCWr,IRWr,GPRWr,Bsel,DMWr,MemByte,WDsel,GPRsel,Extop,ALUOp,NPCOp,ALUsel,
intreq,int_npc,EXLSet,eret,EXLClr,Wen,bridge_wen);
    
    input clk; // 时钟
    input rst; // 复位信号
    input [5:0] opcode; // 操作码
    input [5:0] funct; // 功能码
    input zero; // 计算结果是否为0
    input flow; // 溢出信号
    input pos; // bgez
    input [4:0] rt; // rt字段
    input [4:0] rs; // rs字段 

    input intreq; // 中断请求

    output PCWr; // pc寄存器的写使能信号
    output IRWr; // 指令寄存器写使能
    output GPRWr; // 寄存器组目标寄存器写使能
    output Bsel; // 第二操作数选择器
    output DMWr; // 数据存储写使能
    output MemByte; // 是否为字节访问
    output [2:0] WDsel; //  寄存器组写入数据选择器 
    output [1:0] GPRsel; // 寄存器组目标寄存器选择器 
    output [1:0] Extop; // 数据扩展选择器 
    output [1:0] ALUOp; //计算类型选择器
    output [1:0] NPCOp; // 下一条指令顺序执行/跳转/分支/函数返回
    output [1:0] ALUsel; // 选择ALU输出

    output wire int_npc; // 给npc的中断跳转信号
    output wire EXLSet  ;// 给cp0的中断响应信号

    output wire eret; // 给npc的中断返回信号
    output wire EXLClr; // 给cp0的中断清零信号

    output wire Wen;
    output wire bridge_wen; // 给桥的写使能信号

    reg [3:0] fsm; // 状态机


    // 时序部分
    always@(posedge clk)
    begin
        if(rst)
        begin
            fsm <= `S0; // 回到取指状态
        end 
        else
        begin
            case(fsm)
                `S0:
                    begin
                        fsm <= `S1;
                    end
                `S1:
                    begin
                        if(opcode==`OP_BEQ || (opcode==6'b000001 && rt==5'b00001)) fsm<=`S6;
                        else if(opcode==`OP_J || (opcode==`OP_RTYPE && funct==`FUNCT_JR) || opcode==`OP_JAL 
                        || ((opcode == `OP_ERET) && (funct == `FUNCT_ERET) && (rs== 5'b10000))) fsm<=`S7;
                        else fsm<=`S2;
                    end
                `S2: 
                    begin
                        if(opcode==`OP_LW || opcode==`OP_LB || ((opcode == `OP_MFC0) && (rs == 5'b00000))) fsm<=`S3;
                        else if(opcode==`OP_SW || opcode==`OP_SB || ((opcode == `OP_MTC0) && (rs == 5'b00100))) fsm<=`S4;
                        else fsm<=`S5;
                    end
                `S3:
                    fsm<=`S5;
                `S4:
                    if(intreq==1'b1) fsm<=`S8;
                    else fsm<=`S0;
                `S5:
                    if(intreq==1'b1) fsm<=`S8;
                    else fsm<=`S0;
                `S6:
                    if(intreq==1'b1) fsm<=`S8;
                    else fsm<=`S0;
                `S7:
                    if(intreq==1'b1) fsm<=`S8;
                    else fsm<=`S0;
                `S8:fsm<=`S0;
            endcase
        end
    end


    // 组合部分
    
    assign PCWr = (fsm==`S0) | ((opcode==`OP_J || opcode==`OP_JAL || (opcode==`OP_RTYPE && funct==`FUNCT_JR) ||
    ((opcode == `OP_ERET) && (funct == `FUNCT_ERET) && (rs== 5'b10000))  ) && fsm==`S7)
    |(fsm==`S6 && opcode==`OP_BEQ && zero==1'b1) | ( (fsm==`S6) && (opcode==6'b000001) && (rt==5'b00001) && (pos==1'b1)) | (fsm==`S8);

    assign IRWr = (fsm==`S0);

    assign WDsel = (opcode==`OP_LW || opcode==`OP_LB) ? 3'b011 :
               (opcode==`OP_JAL) ? 3'b010 :
               ((opcode == `OP_MFC0) && (rs == 5'b00000)) ? 3'b100 :
               3'b000;

    assign GPRsel = (opcode==`OP_RTYPE && (funct==`FUNCT_ADDU || funct==`FUNCT_SUBU || funct==`FUNCT_SLT)) ? 2'b01 :
                (opcode == `OP_JAL) ? 2'b11 :
                ((opcode == `OP_ADDI) && (flow == 1'b1)) ? 2'b10 :
                2'b00;


    assign Extop = (opcode==`OP_LW || opcode==`OP_SW || opcode==`OP_ADDI || opcode==`OP_ADDIU || opcode==`OP_LB
    || opcode==`OP_SB)? 2'b01:(opcode==`OP_LUI)? 2'b10:2'b00;

    assign GPRWr = (fsm == `S5 && (
        (opcode == `OP_RTYPE && funct != `FUNCT_JR) ||  // R型中除了jr
        opcode == `OP_ADDI || opcode == `OP_ADDIU || 
        opcode == `OP_ORI  || opcode == `OP_LUI    ||
        opcode == `OP_LW   || opcode == `OP_LB ||((opcode == `OP_MFC0) && (rs == 5'b00000))
    )) || (fsm == `S7 && opcode == `OP_JAL) ;


    assign Bsel = (opcode==`OP_ORI || opcode==`OP_LW||opcode==`OP_SW||opcode==`OP_LUI||opcode==`OP_ADDI|| opcode==`OP_ADDIU
    || opcode==`OP_LB || opcode==`OP_SB)? 1'b1:1'b0;


    assign ALUOp = ((opcode==`OP_RTYPE && funct==`FUNCT_SUBU) || opcode==`OP_BEQ)? 2'b01:(opcode==`OP_LUI || opcode==`OP_ORI)?2'b10:2'b00;

    assign NPCOp = ((fsm == `S6 && opcode == `OP_BEQ) || ((fsm==`S6) && (opcode==6'b000001) && (rt==5'b00001) && (pos==1'b1))) ? 2'b10 :
                   (fsm == `S7 && opcode == `OP_J)   ? 2'b01 :
                   (fsm == `S7 && opcode == `OP_JAL) ? 2'b01 :
                   (fsm == `S7 && opcode == `OP_RTYPE && funct == `FUNCT_JR) ? 2'b11 :
                   2'b00;

    assign DMWr = (fsm == `S4 && (opcode == `OP_SW || opcode == `OP_SB));

    assign ALUsel = (opcode == `OP_ADDI)?2'b01:(opcode==`OP_RTYPE && funct==`FUNCT_SLT)?2'b10:2'b00;

    assign MemByte = (opcode == `OP_LB || opcode == `OP_SB);

    assign int_npc = (fsm==`S8);

    assign EXLSet = (fsm==`S8);

    assign eret = (((opcode == `OP_ERET) && (funct == `FUNCT_ERET) && (rs== 5'b10000)) && fsm==`S7);

    assign EXLClr =  (((opcode == `OP_ERET) && (funct == `FUNCT_ERET) && (rs== 5'b10000)) && fsm==`S7);
    
    assign Wen = ((opcode == `OP_MTC0) && (rs == 5'b00100)) && (fsm==`S4);

    assign bridge_wen = (fsm == `S4 && (opcode == `OP_SW || opcode == `OP_SB));

endmodule