`timescale 1ns / 1ps

module top_test;

    reg clk;
    reg rst;
    reg [31:0] input_data;  // 输入设备模拟值

    wire [31:0] output_data; // 输出设备值

    // 实例化顶层模块
    top my_top (
        .clk(clk),
        .rst(rst),
        .input_data(input_data),
        .output_data(output_data)
    );

    // 时钟生成
    initial clk = 0;
    always #5 clk = ~clk; // 10ns

    // 复位和初始输入
    initial begin
        rst = 1;
        input_data = 32'h00000000;
        #10;
        rst = 0;
    end

    // 模拟输入设备行为
    initial begin
        #200;  
        input_data = 32'h12345678;

        #2000; 
        input_data = 32'h12345678; // 相同，触发加一

        #2000;
        input_data = 32'h11111111; // 不同，触发替换
    end

    // 添加波形输出
    initial begin
        $dumpfile("wave.vcd");     // 输出波形文件名
        $dumpvars(0, top_test);    // 从 top_test 开始递归记录变量

        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[0]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[1]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[2]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[3]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[4]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[5]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[6]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[7]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[8]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[9]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[10]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[11]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[12]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[13]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[14]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[15]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[16]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[17]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[18]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[19]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[20]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[21]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[22]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[23]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[24]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[25]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[26]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[27]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[28]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[29]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[30]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[31]);

        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[0]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[1]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[2]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[3]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[4]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[5]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[6]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[7]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[8]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[9]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[10]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[11]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[12]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[13]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[14]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_im.im[15]);

        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[0]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[1]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[2]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[3]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[4]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[5]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[6]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[7]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[8]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[9]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[10]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[11]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[12]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[13]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[14]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[15]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[16]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[17]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[18]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[19]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[20]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[21]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[22]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[23]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[24]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[25]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[26]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[27]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[28]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[29]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[30]);
        $dumpvars(0, my_top.my_mips.my_datapath.my_gpr.regs[31]);
    
    end

    // 限制仿真时间，防止无限运行
    initial begin
        #10000; // 1万时间单位后结束仿真
        $display("Simulation finished at time %t", $time);
        $finish;
    end

endmodule
