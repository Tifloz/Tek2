section .text
global strchr ; char *strchr(char const *s, int c)

strchr:
    push rbp
    mov rbp, rsp
    push rdi

loop:
    cmp BYTE [rdi], sil
    jz found
    cmp BYTE [rdi], 0
    jz fail
    inc rdi
    jmp loop

fail:
    mov rax, 0
    jmp end

found:
    mov rax, rdi

end:
    pop rdi
    mov rsp, rbp
    pop rbp
    ret