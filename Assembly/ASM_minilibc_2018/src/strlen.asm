section .text
global strlen 		; size_t strlen(char const *s)

strlen:
	push rbp
	mov rbp, rsp
	xor rcx, rcx ; put rcx to 0

loop:
	cmp BYTE [rdi + rcx], 0
	je end
	inc rcx
	jmp loop

end:
	mov rax, rcx
	mov rsp, rbp
	pop rbp
	ret