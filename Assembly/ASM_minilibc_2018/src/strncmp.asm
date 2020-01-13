section .text
global strncmp ; int strncmp(char const *s1, char const *s2, size_t n)

strncmp:
    push rbp
    mov rbp, rsp
    xor rcx, rcx ; put rcx to 0

loop:
    mov al, [rdi + rcx] ; move an accumulator register AL into rdi + rcx
	mov r8b, [rsi + rcx] ; move a one-byte integer r8b into rsi + rcx
    cmp al, 0
	je end
	cmp r8b, 0
	je end
	cmp al, r8b
	jne end
	inc rcx
	cmp rcx, rdx
	je end
	jmp loop

end:
	sub al, r8b
	movsx rax, al
	mov rsp, rbp
	pop rbp
	ret