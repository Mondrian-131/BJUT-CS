module opa(clk,din,dout);
    input clk;
    input [31:0] din;
    output reg [31:0] dout;

    always@(posedge clk)
    begin
        dout<=din;
    end
endmodule