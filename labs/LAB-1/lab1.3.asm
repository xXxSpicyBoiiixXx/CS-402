### Lab-1
### Md Ali 
### CS402

         .data 0x10000000
msg1:    .asciiz "Please enter a floating point number: "

         .data 0x2000000
msg2:    .asciiz "You entered the floating number: "    

         .text
         .globl main

main:       addu $s0, $ra, $0   # save $31 and $16 
            li $v0, 4           # System call for print_str
            la $a0, msg1        # Address of string to print msg1 
            syscall

            li $v0, 6           # system call for read_float
            syscall             # the float is in v0
            
            # Just doing some computations
            add.s $f2, $f12, $f0 
            # add.s $f2, $f12, $f0 

            # printing message first 
            li $v0, 4
            la $a0, msg2
            syscall

            li $v0, 2
            add.s $f12, $f2, $f0
            syscall 
            
            addu $ra, $0, $s0
            jr $ra 
               

            
