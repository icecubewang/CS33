	.file	"cread_alt.c"
	.text
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB11:
	.cfi_startproc
	movl	$0, -4(%rsp)
	leaq	-4(%rsp), %rax
	testq	%rdi, %rdi
	cmove	%rax, %rdi
	movl	(%rdi), %eax
	ret
	.cfi_endproc
.LFE11:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
