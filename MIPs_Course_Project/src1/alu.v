module alu(din1,din2,alu_sel,ALUctr,dout,zero,flow);
   
    input [31:0] din1; // A操作数
    input [31:0] din2; // B操作数
    input [1:0] ALUctr; // 计算类型选择
    input [1:0] alu_sel; // 输出结果选择：两操作数/addi/slt
    output reg [31:0] dout; // 输出结果
    output reg flow;
    output zero; // 结果是否为0信号

    reg [31:0] tmp ;// 保存addi/slt计算结果

    wire [4:0] shift_amt = din1[4:0];

    integer i;

    always@(*)
    begin 
        case(alu_sel)
            2'b00:  // 两操作数计算结果
            begin
                flow = 1'b0;
                case(ALUctr)
                    2'b00: dout = din1 + din2 ;
                    2'b01: dout = din1 + (~din2 + 1);
                    2'b10: dout = din1 | din2;
                    2'b11: // 移位
                    begin
                        flow = 1'b0;
                        dout = $signed(din2) >>> din1[4:0];
                    end
                endcase
            end
            2'b01: // addi
            begin
                tmp = din1 + din2;
                // 溢出
                if((~din1[31] & ~din2[31] & tmp[31]) | (din1[31] & din2[31] & ~tmp[31])) 
                    begin
                        dout = 32'h0001;
                        flow = 1'b1;
                    end
                else 
                begin
                    dout = tmp; 
                    flow = 1'b0;
                end
            end
            2'b10: // slt
            begin 
                tmp = din1 + (~din2 + 1);
                flow = 1'b0;
                if(tmp[31]==1'b1) dout = 32'h0001;
                else dout = 32'h0000;
            end
        endcase

    end

    assign zero =  (dout==0)? 1'b1:1'b0;
endmodule 