                .data

int_1:          .asciiz "Enter a non-negative integer: "

int_2:          .asciiz "Enter another non-negative integer: "

answer:         .asciiz "Ackermann's function final answer: "

                .text
                .globl main

main:           li $v0, 4
                la $a0, int_1
                syscall

                li $v0, 5
                syscall
                
                move $t0, $v0
                li $v0, 4
                la $a0, int_2
                syscall

                li $v0, 5
                syscall
   
                move $t1, $v0
                jr $ra

ackermann:      beqz $t0, output_1
                beqz $t1, output_2
                addi $t1, $t1, -1
                jal ackermann

output_1:       addiu $t3, $t2, 1
                li $v0, 4
                la $a0, answer
                syscall
       
                li $v0, 1
                move $a0, $t2
                syscall

                jr $ra

output_2:       addi $t0, $t0, -1
                li $t1, 1
                jal ackermann
