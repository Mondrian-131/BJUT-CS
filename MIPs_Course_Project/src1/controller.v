module controller(opcode,funct,RegDst,ALUSrc,RegWrite,MemtoReg,MemWrite,nPC_sel,Ext_Op,ALUctr,pc_sel,alu_sel,addi_sel);
    input [5:0] opcode; // 操作码
    input [5:0] funct; // 功能码
    output reg [1:0] RegDst; // 目标写入寄存器
    output reg ALUSrc; // B操作数类型
    output reg [1:0] MemtoReg; // 写入寄存器数据选择
    output reg RegWrite;
    output reg MemWrite; // 数据存储（内存）写使能
    output reg nPC_sel;  //判断是否为分支指令
    output reg[1:0] Ext_Op;  //扩展数选择器
    output reg [1:0] ALUctr ; //计算类型
    output reg [1:0] pc_sel; // NPC顺序执行/跳转/函数返回
    output reg [1:0] alu_sel; // 选择ALU输出
    output reg addi_sel;

    always@(*)
    begin
        case(opcode)
            6'b000000:
                case(funct)
                    6'b100001:
                    begin
                        RegDst = 2'b01;
                        ALUSrc = 1'b0;
                        MemtoReg = 2'b00;
                        RegWrite = 1'b1;
                        MemWrite = 1'b0;
                        nPC_sel = 1'b0;
                        Ext_Op = 2'bxx;
                        ALUctr = 2'b00;
                        pc_sel = 2'b00;
                        alu_sel = 2'b00;
                        addi_sel = 1'b0;
                    end
                    6'b100011:
                    begin
                        RegDst = 2'b01;
                        ALUSrc = 1'b0;
                        MemtoReg = 2'b00;
                        RegWrite = 1'b1;
                        MemWrite = 1'b0;
                        nPC_sel = 1'b0;
                        Ext_Op = 2'bxx;
                        ALUctr = 2'b01;
                        pc_sel = 2'b00;
                        alu_sel = 2'b00;
                        addi_sel = 1'b0;
                    end
                    6'b101010:
                    begin
                        RegDst = 2'b01;
                        ALUSrc = 1'b0;
                        MemtoReg = 2'b00;
                        RegWrite = 1'b1;
                        MemWrite = 1'b0;
                        nPC_sel = 1'b0;
                        Ext_Op = 2'bxx;
                        ALUctr = 2'b01;
                        pc_sel = 2'b00;
                        alu_sel = 2'b10;
                        addi_sel = 1'b0;
                    end
                    6'b001000:
                    begin
                        RegDst = 2'bxx;
                        ALUSrc = 1'bx;
                        MemtoReg = 2'bxx;
                        RegWrite = 1'b0;
                        MemWrite = 1'b0;
                        nPC_sel = 1'b0;
                        Ext_Op = 2'bxx;
                        ALUctr = 2'bxx;
                        pc_sel = 2'b10;
                        alu_sel = 2'b00;
                        addi_sel = 1'b0;
                    end
                    6'b000111:
                    begin
                        RegDst = 2'b01;
                        ALUSrc = 1'b0;
                        MemtoReg = 2'b00;
                        RegWrite = 1'b1;
                        MemWrite = 1'b0;
                        nPC_sel = 1'b0;
                        Ext_Op = 2'bxx;
                        ALUctr = 2'b11;
                        pc_sel = 2'b00;
                        alu_sel = 2'b00;
                        addi_sel = 1'b0;
                    end
                endcase
            6'b001101:
            begin
                RegDst = 2'b00;
                ALUSrc = 1'b1;
                MemtoReg = 2'b00;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'b00;
                ALUctr = 2'b10;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b100011:
            begin
                RegDst = 2'b00;
                ALUSrc = 1'b1;
                MemtoReg = 2'b01;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'b01;
                ALUctr = 2'b00;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b101011:
            begin
                RegDst = 2'bxx;
                ALUSrc = 1'b1;
                MemtoReg = 2'bxx;
                RegWrite = 1'b0;
                MemWrite = 1'b1;
                nPC_sel = 1'b0;
                Ext_Op = 2'b01;
                ALUctr = 2'b00;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b000100:
            begin
                RegDst = 2'bxx;
                ALUSrc = 1'b0;
                MemtoReg = 2'bxx;
                RegWrite = 1'b0;
                MemWrite = 1'b0;
                nPC_sel = 1'b1;
                Ext_Op = 2'bxx;
                ALUctr = 2'b01;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end    
            6'b001111:
            begin
                RegDst = 2'b00;
                ALUSrc = 1'b1;
                MemtoReg = 2'b00;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'b10;
                ALUctr = 2'b10;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b000010:
            begin
                RegDst = 2'bxx;
                ALUSrc = 1'bx;
                MemtoReg = 2'bxx;
                RegWrite = 1'b0;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'bxx;
                ALUctr = 2'bxx;
                pc_sel = 2'b01;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b001000:
            begin
                RegDst = 2'bxx;
                ALUSrc = 1'b1;
                MemtoReg = 2'b00;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'b01;
                ALUctr = 2'b00;
                pc_sel = 2'b00;
                alu_sel = 2'b01;
                addi_sel = 1'b1;
            end
            6'b001001:
            begin
                RegDst = 2'b00;
                ALUSrc = 1'b1;
                MemtoReg = 2'b00;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'b01;
                ALUctr = 2'b00;
                pc_sel = 2'b00;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
            6'b000011:
            begin
                RegDst = 2'b11;
                ALUSrc = 1'bx;
                MemtoReg = 2'b10;
                RegWrite = 1'b1;
                MemWrite = 1'b0;
                nPC_sel = 1'b0;
                Ext_Op = 2'bxx;
                ALUctr = 2'bxx;
                pc_sel = 2'b01;
                alu_sel = 2'b00;
                addi_sel = 1'b0;
            end
        endcase
    end 
endmodule 