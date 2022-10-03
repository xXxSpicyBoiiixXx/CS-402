	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_A                              ; -- Begin function A
	.p2align	2
_A:                                     ; @A
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	w0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #8]
	cbnz	w8, LBB0_2
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	stur	w8, [x29, #-4]
	b	LBB0_5
LBB0_2:
	ldr	w8, [sp, #4]
	cbnz	w8, LBB0_4
	b	LBB0_3
LBB0_3:
	ldr	w8, [sp, #8]
	mov	w1, #1
	subs	w0, w8, #1
	bl	_A
	stur	w0, [x29, #-4]
	b	LBB0_5
LBB0_4:
	ldr	w8, [sp, #8]
	subs	w8, w8, #1
	str	w8, [sp]                        ; 4-byte Folded Spill
	ldr	w0, [sp, #8]
	ldr	w8, [sp, #4]
	subs	w1, w8, #1
	bl	_A
	mov	x1, x0
	ldr	w0, [sp]                        ; 4-byte Folded Reload
	bl	_A
	stur	w0, [x29, #-4]
	b	LBB0_5
LBB0_5:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	x9, sp
	sub	x8, x29, #4
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	_scanf
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_printf
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	mov	x9, sp
	sub	x8, x29, #8
	str	x8, [x9]
	bl	_scanf
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	bl	_printf
	ldur	w0, [x29, #-4]
	ldur	w1, [x29, #-8]
	bl	_A
	stur	w0, [x29, #-12]
	ldur	w9, [x29, #-12]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Welcome! This program will give you answers to Ackermann's function, enjoy! \n"

l_.str.1:                               ; @.str.1
	.asciz	"Enter a non-negative integer: "

l_.str.2:                               ; @.str.2
	.asciz	"%d"

l_.str.3:                               ; @.str.3
	.asciz	"\n"

l_.str.4:                               ; @.str.4
	.asciz	"Enter another non-negative integer: "

l_.str.5:                               ; @.str.5
	.asciz	"Ackermann's function final answer: %d"

.subsections_via_symbols
