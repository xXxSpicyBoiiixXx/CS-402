         .data 0x10000000
msg1:    .asciiz "Please enter an integer number: "

         .text
         .globl main

# $31 ($ra) initially containt the return adddress from main,
# we will need to change this and save it.

main:    addu $s0, $ra, $0      # save $31 in $16 

labell:  li $v0, 4              # print_str 
         la $a0, msg1           # address of string to print
         syscall

         li $v0, 5              # read int 
         syscall                # place the int in $v0
        
         addu $t0, $v0, $0      # move the number in $t0
         sll $t0, $t0, 1        # Any number besides 2
    
         li $v0, 1              # print_int
         addu $a0, $t0, $0      # move number to print in $a0 
         syscall 

         addu $ra, $0, $s0      # return address back in $31
         jr $ra                 # return from main 
