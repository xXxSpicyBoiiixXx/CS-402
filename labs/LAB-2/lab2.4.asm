            .data 0x10010000

var1:       .word 0x0

var2:       .word 0x1

            .extern ext1 4
            .extern ext2 4

            .text
            .globl main

main:       
            la $t0, ext2        # Loading address of ext2
            lw $t1, var1        # Loading data of var1
            sw $t1, 0($t0)      # Store data var1
            add $t0, $t0, $t1   # t0 <- t0 + t1
            sw $t0, ext2        # Store data ext2

            la $t0, ext1        # Loading address of ext1
            lw $t1, var2        # Loading data of var2
            sw $t1, 0($t0)      # Store data var2
            add $t0, $t0, $t1   # t0 <- t0 + t1
            sw $t0, ext1        # Store data ext1

            la $s0, var1        # Load address of var1
            la $s1, var2        # Load address of var2
            la $s2, ext1        # Load address of ext1
            la $s3, ext2        # Load address of ext2

            li $v0, 10          # System call to exit 
            syscall
