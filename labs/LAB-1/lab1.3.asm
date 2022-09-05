.data   0x10000000

        msg1:        .asciiz "Please enter a floating point number: "
        
        zeroAsFloat: .float 0.0
.text

.globl main

main:       addu $s0, $ra, $0
            lwc1 $f4, zeroAsFloat
            
            # Display msg1 
            li $v0, 4          
            la $a0, msg1       
            syscall

            # Read user's input float 
            li $v0, 6           
            syscall       
            
            # Display value 
            li $v0, 2 
            add.s $f12, $f0, $f4
            syscall 
            
            addu $ra, $0, $s0
            jr $ra
