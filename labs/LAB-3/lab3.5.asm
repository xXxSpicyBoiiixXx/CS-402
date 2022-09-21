                .data 0x10000000

msg1:           .asciiz "Please enter an integer: "
msg2:           .asciiz "I'm far away."
msg3:           .asciiz "I'm nearby."

                .text
                .globl main

main:           addu $s0, $ra, $0
                li $v0, 4
                la $a0, msg1
                syscall

                li $v0, 5
                syscall 
            
                move $t1, $v0
                li $v0, 4
                la $a0, msg1
                syscall 
      
                li $v0, 5
                syscall

                move $t2, $v0
                beq $t1, $t2, far
                bne $t1, $t2, nearby
                
                addu $ra, $s0, $0
                jr $ra

far:            li $v0, 4
                la $a0, msg2
                syscall

                j exit

nearby:         li $v0, 4
                la $a0, msg3
                syscall
            
                j exit

exit:           li $v0, 10
                syscall 
