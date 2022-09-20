            .data 0x10010000

var1:       .word 0x1

limit:      .word 0x100

            .text
            .globl main

main:       
            la $t1, limit
            lw $a1, 0($t1)
            j loop

loop:       ble $a1, $t0, exit
                la $a0, var1
                lw $t0, 0($a0)
                addi $t0, $t0, 1
                sw $t0, 0($a0)
                j loop

exit:   jr $ra
