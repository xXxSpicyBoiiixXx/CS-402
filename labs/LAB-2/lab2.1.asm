            .data 0x10010000
var1:       .word 0x55

var2:       .word 0xaa

            .text
            .globl main

main:       addu $s0, $ra, $0

            li $t0, 1
            move $t1, $t0
            la $t2, var2
            lw $t3, var2
            sw $t2, var1

            addu $ra, $0, $s0
            jr $ra 
