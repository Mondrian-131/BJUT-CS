vlog src/my_module.v
vlog tb/my_module_tb.v

vsim -wlf wave/my_sim.wlf my_module_tb

add wave *
run 50ns
