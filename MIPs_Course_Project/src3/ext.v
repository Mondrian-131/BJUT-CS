module ext(din,Extop,dout);

    input [15:0] din; // 输入的16位立即数
    input [1:0] Extop; // 扩展类型选择器
    output reg [31:0] dout; // 扩展后数据

    always@(*)
    begin
        case(Extop)
            2'b00: dout = {16'b0,din}; // 零扩展
            2'b01: dout = {{16{din[15]}},din}; // 符号扩展
            2'b10: dout = {din,16'b0}; // lui高位扩展
            default:dout = 32'b0;
        endcase
    end

endmodule