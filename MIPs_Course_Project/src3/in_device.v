module in_device (
    output [31:0]  data_out,    //  输入设备输出给桥的数据
    input  wire [31:0] data_in    // 外部输入（来自 testbench）
);
    assign data_out = data_in;

endmodule
