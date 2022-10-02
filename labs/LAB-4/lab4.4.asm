            .data

int_1:      .asciiz "Input an integer"

int_2:      .asciiz "Input another integer"

ans:        .asciiz "The larger integer is: "

            .text
            .globl main



main:       add $sp, $sp, -8
            li $v0, 4
            la $a0, int_1
            syscall

            li $v0, 5
            syscall

            move $t0, $v0
            sw $t0, 8($sp)
            li $v0, 4
            la $a0, int_2
            syscall

            li $v0, 5
            syscall

            move $t1, $v0
            sw $t1, 4($sp)
            jal largest
            li $v0, 10
            syscall

largest:    lw $t0, 4($sp)
            add $sp, $sp, 4
            lw $t1, 4($sp)
            add $sp, $sp, 4
            bge $t1, $t0, print_ans
            move $t1, $t0
            bge $t2, $t1, print_ans
            move $t2, $t1
            jr $ra

print_ans:  li $v0, 4
            la $a0, ans
            syscall

            li $v0, 1
            move $a0, $t1
            syscall

