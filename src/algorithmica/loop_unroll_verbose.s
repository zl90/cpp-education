	.file	"loop_unroll.cpp"
# GNU C++17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	_Z11loop_unrollv
	.type	_Z11loop_unrollv, @function
_Z11loop_unrollv:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# loop_unroll.cpp:5:   int result = 0;
	movl	$0, -8(%rbp)	#, result
# loop_unroll.cpp:6:   for (int i = 0; i < 20; i++) {
	movl	$0, -4(%rbp)	#, i
# loop_unroll.cpp:6:   for (int i = 0; i < 20; i++) {
	jmp	.L2	#
.L3:
# loop_unroll.cpp:7:     result += i;
	movl	-4(%rbp), %eax	# i, tmp84
	addl	%eax, -8(%rbp)	# tmp84, result
# loop_unroll.cpp:6:   for (int i = 0; i < 20; i++) {
	addl	$1, -4(%rbp)	#, i
.L2:
# loop_unroll.cpp:6:   for (int i = 0; i < 20; i++) {
	cmpl	$19, -4(%rbp)	#, i
	jle	.L3	#,
# loop_unroll.cpp:9:   return result;
	movl	-8(%rbp), %eax	# result, _5
# loop_unroll.cpp:10: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
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
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# loop_unroll.cpp:13:   loop_unroll();
	call	_Z11loop_unrollv	#
# loop_unroll.cpp:15:   return 0;
	movl	$0, %eax	#, _3
# loop_unroll.cpp:16: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
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
