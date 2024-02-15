	.file	"loop_unroll.cpp"
	.text
	.globl	_Z11loop_unrollv
	.type	_Z11loop_unrollv, @function
_Z11loop_unrollv:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$20, %eax
.L2:
	subl	$1, %eax
	jne	.L2
	movl	$190, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z11loop_unrollv, .-_Z11loop_unrollv
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
