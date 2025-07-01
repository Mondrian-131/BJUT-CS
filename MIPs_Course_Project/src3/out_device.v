module out_device (
    input   clk,
    input   rst,
    input   write_en,    // 来自 bridge 的写使能
    input   [31:0] data_in,     // CPU 要写入的值
    output reg [31:0]  data_out  // 外部可见输出值（testbench 显示用）
    
);
    reg [31:0] preData;

    always @(posedge clk) 
    begin
        if (rst)
            begin 
                preData<=32'b0;
                data_out <= 32'b0;
            end   
        else if (write_en)
            begin 
                if(data_in != preData)
                    begin  
                        preData <=data_out;
                        data_out <= data_in;
                    end
            end
    end

endmodule
