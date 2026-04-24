`timescale 1ns/1ps

module tb_mips;

    reg clk;
    reg rst;

    // 实例化顶层 MIPS 模块（必须命名子模块）
    mips my_mips (
        .clk(clk),
        .rst(rst)
    );

    // 时钟生成（10ns周期）
    initial clk = 0;
    always #5 clk = ~clk;

    // 初始化控制
    initial begin
        rst = 1;
        #20;
        rst = 0;

        #1000;  // 仿真时长

        $finish;
    end

    // 指定波形记录文件和模块
    initial begin
        $dumpfile("wave.vcd");

    // 记录前4个内存单元
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[0]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[1]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[2]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[3]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[4]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[5]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[6]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[7]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[8]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[9]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[10]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[11]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[12]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[13]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[14]);
    $dumpvars(0, my_mips.my_datapath.my_dm.dm[15]);

    // 记录32个寄存器的值

    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[0]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[1]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[2]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[3]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[4]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[5]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[6]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[7]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[8]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[9]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[10]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[11]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[12]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[13]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[14]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[15]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[16]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[17]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[18]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[19]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[20]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[21]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[22]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[23]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[24]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[25]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[26]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[27]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[28]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[29]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[30]);
    $dumpvars(0, my_mips.my_datapath.my_gpr.regs[31]);


    $dumpvars(0, my_mips.my_datapath.my_im.im[0]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[1]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[2]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[3]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[4]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[5]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[6]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[7]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[8]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[9]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[10]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[11]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[12]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[13]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[14]);
    $dumpvars(0, my_mips.my_datapath.my_im.im[15]);
    
    // 记录所有信号的值
    $dumpvars(0, tb_mips); 
    end

endmodule
