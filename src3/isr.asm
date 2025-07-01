 interrupt_handler:
    lw    $10, 0($4)      
    beq   $10, $11, same     

    sw    $10, 0($5)         
    addu  $11, $10, $0       
    j     restart_timer

same:
    lw    $12, 0($5)         
    addiu $12, $12, 1
    sw    $12, 0($5)

restart_timer:
    sw    $13, 0($2)         
    sw    $13, 0($3)         
    eret                    

