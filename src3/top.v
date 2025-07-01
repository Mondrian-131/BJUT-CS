module top (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] input_data,   // 输入设备数据（外部输入模拟） testbench
    output wire [31:0] output_data   // 输出设备数据给外部 testbench
);

    // 输入设备信号
    wire [31:0] indevice_data;       // 输入设备给桥

    // 输出设备信号
    wire        outdevice_en;        // 输出设备写使能
    wire [31:0] data_to_output;      // 从bridge到输出设备的数据

    // timer信号
    wire        timer_we;            // timer写使能
    wire [1:0]  addr_i;              // timer寄存器选择地址
    wire        timer_irq;           // timer 的中断请求

    // 桥
    wire [31:0] praddr;              // cpu给的设备地址
    wire [31:0] prwd;                // cpu给的要写入的数据
    wire [31:0] prrd;                // bridge给cpu的写入数据
    wire        bridge_wen;          // cpu给桥的写使能
    wire [7:2]  HWInt;               // 桥给cp0的中断信号
    wire [31:0] outdevice_data;       // 输出设备给桥的数据

    // CP0
    wire [31:0] Dout;                // cp0给cpu的数据，MFC0
    wire        Intreq_to_mip;       // 给控制器的中断信号
    wire [31:2] EPC_to_mip;          // EPC给cpu的中断恢复地址

    // Mips
    wire        EXLClr;              // 中断结束（ERET）后cpu传给cp0和timer
    wire        EXLSet;              // 中断产生时cpu传给cp0
    wire [4:0]  SEL;                 // 选择CP0内部的寄存器
    wire [31:2] PC;                  // mip给cp0用于保存中断下一条地址
    wire [31:0] DIn;                 // cpu给cp0的数据
    wire        Wen;                 // cpu给cp0的写使能，MTC0

    assign output_data = outdevice_data;

    // 实例化timer
    timer my_timer (
        .CLK_I(clk),
        .RST_I(rst),
        .ADD_I(addr_i),
        .WE_I(timer_we),
        .DAT_I(data_to_output),
        .IRQ(timer_irq),
        .exlclr(EXLClr)
    );

    // 实例化桥
    bridge my_bridge (
        .praddr        (praddr),
        .prwd          (prwd),
        .indevice_rd   (indevice_data),
        .wen           (bridge_wen),
        .irq           (timer_irq),
        .prrd          (prrd),
        .out_wd        (data_to_output),
        .timer_we      (timer_we),
        .outdevice_we  (outdevice_en),
        .hwint         (HWInt),
        .timer_addr    (addr_i),
        .outdevice_rd  (outdevice_data)    
    );

    // 实例化输出设备
    out_device my_out_device (
        .clk       (clk),
        .rst       (rst),
        .write_en  (outdevice_en),
        .data_in   (data_to_output),
        .data_out  (outdevice_data)
    );

    // 实例化输入设备
    in_device my_in_device (
        .data_out (indevice_data),
        .data_in  (input_data)
    );

    // Cp0实例化
    cp0 my__cp0 (
        .PC       (PC),           
        .DIn      (DIn),         
        .HWInt    (HWInt),         
        .Sel      (SEL),        
        .Wen      (Wen),           
        .EXLSet   (EXLSet),        
        .EXLClr   (EXLClr),        
        .clk      (clk),          
        .rst      (rst),         
        .IntReq   (Intreq_to_mip), 
        .epc      (EPC_to_mip),    
        .DOut     (Dout)          
    );

    // 这里你还需要实例化 MIPS CPU 核心模块，连接上面对应信号，比如：

    mips my_mips (
        .clk(clk),
        .rst(rst),
        .prrd(prrd),
        .prwd(prwd),
        .praddr(praddr),
        .EXLSet(EXLSet),
        .EXLClr(EXLClr),
        .SEL(SEL),
        .PC(PC),
        .DIn(DIn),
        .Wen(Wen),
        .Dout(Dout),
        .Intreq(Intreq_to_mip),
        .EPC(EPC_to_mip),
        .bridge_wen(bridge_wen)
    );

endmodule
