            .data 0x10010000

var1:      .word 0x3a

var2:      .word 0x7b

var3:      .word 0x9c

var4:      .word 0x1d

first:     .word m

last:      .word a


            .text
            .globl main

main:       
            la $t0, var1        # Loading address of var1 
            lw $t1, 0($t0)      # Loading data of var1 
            la $t2, var4        # Loading address of var4
            lw $t3, 0($t2)      # Loading data of var4

            xor $t1, $t1, $t3   # var1 = init of var4 
            xor $t3, $t1, $t3   # var4 = init of var1
            xor $t1, $t1, $t3
            
            sw $t1, 0($t0)      # store data var1
            sw $t3, 0($t2)      # store data var4
    
            la $t0, var2        # Loading address of var2
            lw $t1, 0($t0)      # Loading data of var2
            la $t2, var3        # Loading address of var3
            lw $t3, 0($t2)      # Loading data of var3 

            xor $t1, $t1, $t3   # var2 = init of var3
            xor $t3, $t1, $t3   # var3 = init of var2
            xor $t1, $t1, $t3 

            sw $t1, 0($t0)      # store data var2
            sw $t3, 0($t2)      # store data var3

            jr $ra
