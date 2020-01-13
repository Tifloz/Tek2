section	.text
global rindex  ; char *rindex(const char *s, int c);

; strlen function
strlen:
	push rbp
	mov rbp, rsp
	xor rcx, rcx ; put rcx to 0

loop_2:
	cmp BYTE [rdi + rcx], 0
	je end_looper
	inc rcx
	jmp loop_2

end_looper:
	mov rax, rcx
	mov rsp, rbp
	pop rbp
	ret

rindex:
	push rbp
	mov	rbp, rsp	; |strlen:
    push rbp             	; enter
    mov rbp, rsp        	; |
    xor rdx, rdx        	; clear rdx
 loop:
    cmp byte [rdi + rdx], 0    ; if (*(str + rdx) == 0)
    je end_loop
    inc rdx
    jmp loop
 end_loop:
    mov rax, rdx
    mov rsp, rbp
    pop rbp
    ret
	xor	rcx, rcx
	xor	rdx, rdx
	push rdi
	call strlen
	mov	rdx, rax
	pop	rdi
	add	rdi, rdx
counter:
	cmp	byte [rdi + rcx], sil
	je	end
	dec	rcx
	jmp	counter
end:
	add	rdi, rcx
	mov	rax, rdi
	mov	rsp, rbp
	pop	rbp
	ret