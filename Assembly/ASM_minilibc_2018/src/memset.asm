section .text
global memset   ; void *memset(void *s, int c, size_t n)

memset:
	push rbp
	mov rbp, rsp
	xor rcx, rcx
	mov rax, rdi
loop:
	cmp rdx, rcx
	jz end
	mov [rax], sil
	inc rcx
	inc rax
	jmp loop

end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret