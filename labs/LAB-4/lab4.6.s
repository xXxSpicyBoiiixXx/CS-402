	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_A                              ## -- Begin function A
	.p2align	4, 0x90
_A:                                     ## @A
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -8(%rbp)
	movl	%esi, -12(%rbp)
	cmpl	$0, -8(%rbp)
	jne	LBB0_2
## %bb.1:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	movl	%eax, -4(%rbp)
	jmp	LBB0_5
LBB0_2:
	cmpl	$0, -12(%rbp)
	jne	LBB0_4
## %bb.3:
	movl	-8(%rbp), %edi
	subl	$1, %edi
	movl	$1, %esi
	callq	_A
	movl	%eax, -4(%rbp)
	jmp	LBB0_5
LBB0_4:
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)                 ## 4-byte Spill
	movl	-8(%rbp), %edi
	movl	-12(%rbp), %esi
	subl	$1, %esi
	callq	_A
	movl	-16(%rbp), %edi                 ## 4-byte Reload
	movl	%eax, %esi
	callq	_A
	movl	%eax, -4(%rbp)
LBB0_5:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	leaq	-4(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %edi
	movl	-8(%rbp), %esi
	callq	_A
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Welcome! This program will give you answers to Ackermann's function, enjoy! \n"

L_.str.1:                               ## @.str.1
	.asciz	"Enter a non-negative integer: "

L_.str.2:                               ## @.str.2
	.asciz	"%d"

L_.str.3:                               ## @.str.3
	.asciz	"\n"

L_.str.4:                               ## @.str.4
	.asciz	"Enter another non-negative integer: "

L_.str.5:                               ## @.str.5
	.asciz	"Ackermann's function final answer: %d"

.subsections_via_symbols
