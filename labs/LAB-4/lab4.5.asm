            .data

input:      .asciiz "Input an integer: "

            .text
            .globl main

main:       jal int_input
            jal factorial 
            
            jr $ra

int_input:  li $v0, 4
            la $a0, input
            syscall

            li $v0, 5
            syscall

            move $t0, $v0
            slti $t1, $t0, 0
            bne $t1, $0, input

factorial:  subu $sp, $sp, 4
            sw $ra, 4($sp)
            beqz $t0, terminate
            subu $sp, $sp, 4
            sw $t0, 4($sp)
            sub $t0, $t0, 1
            jal factorial

            lw $t0, 4($sp)
            mul $v0, $v0, $t0
            lw $ra, 8($sp)
            add $sp, $sp, 8
            jr $ra

terminate:  li $v0, 1
            lw $ra, 4($sp)
            add $sp, $sp, 4
            jr $ra

