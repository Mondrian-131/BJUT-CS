module cp0 (
    input  wire [31:2] PC,       // 保存中断发生时的PC
    input  wire [31:0] DIn,      // 写入数据（MTC0）
    input  wire [7:2]  HWInt,    // 6个设备中断信号
    input  wire [4:0]  Sel,      // 寄存器选择信号
    input  wire        Wen,      // 写使能
    input  wire        EXLSet,   // 置位EXL
    input  wire        EXLClr,   // 清除EXL
    input  wire        clk,
    input  wire        rst,
   
    output wire        IntReq,   // 中断请求
    output wire [31:2] epc,      // EPC寄存器内容
    output wire [31:0] DOut      // 读取cp0寄存器数据（MFC0）
);

    parameter [4:0] SR    = 5'd12;
    parameter [4:0] CAUSE = 5'd13;
    parameter [4:0] EPC_R = 5'd14;
    parameter [4:0] PRID  = 5'd15;

    reg [31:0] reg_cp0 [31:0];
    integer i;

    wire [5:0] im;  // 中断允许位，对应SR寄存器的15:10
    wire exl;       // 全局中断使能，SR寄存器bit1
    wire ie;        // 中断允许，SR寄存器bit0

    assign im  = reg_cp0[SR][15:10];
    assign exl = reg_cp0[SR][1];
    assign ie  = reg_cp0[SR][0];

    assign epc  = reg_cp0[EPC_R];
    assign DOut = reg_cp0[Sel];

    // 中断请求信号
    assign IntReq = (| (HWInt & im)) & ie & (~exl);

    // 同步复位及寄存器初始化
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 32; i = i + 1)
                reg_cp0[i] <= 32'b0;
            reg_cp0[SR][15:10] <= 6'b000001;  // 允许第0号中断
            reg_cp0[SR][1]     <= 1'b0;        // EXL清0
            reg_cp0[SR][0]     <= 1'b1;        // IE使能
            reg_cp0[CAUSE][15:10] <= 6'b000001; // 只有一个设备中断
            reg_cp0[PRID]      <= 32'h2307_1003;
        end else begin
            if (Wen & (Sel != CAUSE)) begin
                reg_cp0[Sel] <= DIn;
            end
            if (EXLSet) begin
                reg_cp0[SR][1] <= 1'b1;     // 进入中断
                reg_cp0[EPC_R] <= PC;
            end
            if (EXLClr) begin
                reg_cp0[SR][1:0] <= 2'b01; // 退出中断，IE=1, EXL=0
            end
            // CAUSE 寄存器只更新 HWInt 位
            reg_cp0[CAUSE][15:10] <= HWInt;
        end
    end

endmodule
