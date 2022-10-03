A:      
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        sw      $16,28($sp)
        move    $fp,$sp
        sw      $4,40($fp)
        sw      $5,44($fp)
        lw      $2,40($fp)
        nop
        bne     $2,$0,$L2
        nop

        lw      $2,44($fp)
        nop
        addiu   $2,$2,1
        sw      $2,44($fp)
        lw      $2,44($fp)
        b       $L3
        nop

$L2:
        lw      $2,44($fp)
        nop
        bne     $2,$0,$L4
        nop

        lw      $2,40($fp)
        nop
        addiu   $2,$2,-1
        li      $5,1                        # 0x1
        move    $4,$2
        jal     A
        nop

        b       $L3
        nop

$L4:
        lw      $2,40($fp)
        nop
        addiu   $16,$2,-1
        lw      $2,44($fp)
        nop
        addiu   $2,$2,-1
        move    $5,$2
        lw      $4,40($fp)
        jal     A
        nop

        move    $5,$2
        move    $4,$16
        jal     A
        nop

$L3:
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        lw      $16,28($sp)
        addiu   $sp,$sp,40
        j       $31
        nop

$LC0:
        .ascii  "Welcome! This program will give you answers to Ackermann"
        .ascii  "'s function, enjoy! \000"
$LC1:
        .ascii  "Enter a non-negative integer: \000"
$LC2:
        .ascii  "%d\000"
$LC3:
        .ascii  "Enter another non-negative integer: \000"
$LC4:
        .ascii  "Ackermann's function final answer: %d\000"
main:
        addiu   $sp,$sp,-48
        sw      $31,44($sp)
        sw      $fp,40($sp)
        move    $fp,$sp
        lui     $2,%hi($LC0)
        addiu   $4,$2,%lo($LC0)
        jal     puts
        nop

        lui     $2,%hi($LC1)
        addiu   $4,$2,%lo($LC1)
        jal     printf
        nop

        addiu   $2,$fp,28
        move    $5,$2
        lui     $2,%hi($LC2)
        addiu   $4,$2,%lo($LC2)
        jal     __isoc99_scanf
        nop

        li      $4,10                 # 0xa
        jal     putchar
        nop

        lui     $2,%hi($LC3)
        addiu   $4,$2,%lo($LC3)
        jal     printf
        nop

        addiu   $2,$fp,32
        move    $5,$2
        lui     $2,%hi($LC2)
        addiu   $4,$2,%lo($LC2)
        jal     __isoc99_scanf
        nop

        li      $4,10                 # 0xa
        jal     putchar
        nop

        lw      $2,28($fp)
        lw      $3,32($fp)
        nop
        move    $5,$3
        move    $4,$2
        jal     A
        nop

        sw      $2,24($fp)
        lw      $5,24($fp)
        lui     $2,%hi($LC4)
        addiu   $4,$2,%lo($LC4)
        jal     printf
        nop

        move    $2,$0
        move    $sp,$fp
        lw      $31,44($sp)
        lw      $fp,40($sp)
        addiu   $sp,$sp,48
        j       $31
        nop
