.data   0x10000000

        msg1:        .asciiz "Please enter a type of double: "
        
        zeroAsDouble: .double 0.0
.text

.globl main

main:       addu $s0, $ra, $0
            lwc1 $f4, zeroAsDouble
            
            # Display msg1 
            li $v0, 4          
            la $a0, msg1       
            syscall

            # Read user's inputted double
            li $v0, 7           
            syscall       
            
            # Display value 
            li $v0, 3 
            add.d $f12, $f0, $f4
            syscall 
            
            addu $ra, $0, $s0
            jr $ra
