for i in range(0, 16):  # 假设你只想 dump 前32个
    print(f"$dumpvars(0, my_mips.my_datapath.my_im.im[{i}]);")
