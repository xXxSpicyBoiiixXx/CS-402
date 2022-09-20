                .data 0x10010000

my_array:       .space 10

intial_value:   .word 0x1

                .text
                .globl main

main:           
                li $s0, 10
                li$t0, 0
                li $t4, 0
                
                la $t1, my_array
                la $t2, initial_value
                lw $t3, 0($t2)

                j loop 

loop:   ble $s0, $t0, exit
                add $t5, $t1, $t4
                sw $t3, 0($t5)
                addi $t0, $t0, 1
                addi $t4 
