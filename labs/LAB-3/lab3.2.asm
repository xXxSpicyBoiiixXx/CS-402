                .data 0x10010000

var1:           .word 0x1

var2:           .word 0x2

var3:           .word 0x2022

                .text
                .globl main

main:
                la $t0, var1
                lw $t1, 0($t0)
                
                la $t0, var2
                lw $t2, 0($t0)
                
                slt $t0, $t1, $t2
                beq $t0, $0, label
                bgtz $t0, else 

label:          
                la $t0, var3
                lw $t3, 0($t0)

                la $t0, var1
                sw $t3, 0($t0)
                
                la $t0, var2
                sw $t3, 0($t0)

                la $t0, var1
                lw $t4, 0($t0)
                la $t0, var2
                lw $t5, 0($t0)
                
                beq $0, $0, exit

else:
                xor $t1, $t1, $t2
                xor $t2, $t1, $t2
                xor $t1, $t1, $t2

                la $t0, var1
                sw $t1, 0($t0)

                la $t0, var2
                sw $t2,0($t0)
            
                beq $0, $0, exit

exit:
                jr $ra    

