section .text
global strstr 		; char *strchr(char const *haystack, char const *needle)

strstr:
    push rbp
    mov rbp, rsp
    jmp reset

start:
	cmp al, 0
	je failed
	inc rdi

reset:
	mov al, [rdi]
	mov al, [rsi]
	xor rcx, rcx

loop:
	mov al, [rdi + rcx]
	mov r8b, [rsi + rcx]
	cmp r8b, 0
	jz win
	cmp al, r8b
	jne start
	inc rcx
	jmp loop

win:
	mov rax, rdi
	jmp end

failed:
	xor rax, rax

end:
    mov rsp, rbp
	pop rbp
	ret
