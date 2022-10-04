                .data
#        .align  2
int_1:          .asciiz	"\nEnter a non-negative integer: "

int_2:          .asciiz	"\nEnter another non-negative integer: "

answer:         .asciiz	"\nAckermann's function final answer: "

                .text
       	        .globl main
       	
main:
	            move $s0, $0
                la $a0, int_1
                li $v0, 4
                syscall

                li $v0, 5
                syscall

                move $s1, $v0
                la $a0, int_2
                li $v0, 4
                syscall
 	
                li $v0, 5
                syscall 
                move $s2, $v0
                move $a0, $s1
                move $a1, $s2
	            jal ackermann
                move $s0, $v0 
  
                la $a0, answer
                li $v0, 4
                syscall
            
                li $v0, 1
                move $a0, $s0
                syscall 

                li $v0, 10
                syscall

ackermann:
                addi $sp, $sp, -24
                sw $ra, 20($sp)
                sw $s0, 16($sp) 
                sw $s1, 12($sp)
                sw $s2, 8($sp)
                sw $s3, 4($sp)
                sw $s4, 0($sp)

                move $s0, $a0
                move $s1, $a1
                move $s2, $0
                
                bne $s0, 0, check_1
                addi $s2, $s1, 1

check_1:
                ble $s0, 0, check_2
                bne $s1, 0, check_2
                addi $a0, $s0, -1
                addi $a1, $0, 1
                jal ackermann
                move $s2, $v0               

check_2:        
                ble $s0, 0, end
                ble $s1, 0, end
                move $a0, $s0
                addi $a1, $s1, -1
                jal ackermann
                move $s2, $v0

end:            
                move $v0, $s2                 
                lw $ra, 20($sp)
                lw $s0, 16($sp)
                lw $s1, 12($sp)
                lw $s2, 8($sp)
                lw $s3, 4($sp)               
                lw $s4, 0($sp)
                addi $sp, $sp, 24
                jr $ra
