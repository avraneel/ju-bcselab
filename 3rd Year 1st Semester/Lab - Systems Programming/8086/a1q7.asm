.model small
.stack 500h

.data

prompt1 db "2nd number is less than 1st$"
prompt2 db "Numbers are equal$"
prompt3 db "1st number is less than 2nd$"
.code

loading_data:
    mov     ax, @data
    mov     ds, ax
    xor     ax, ax

comparing:
    mov ax, 07h
    mov bx, 06h
    cmp ax, bx
    je equal
    jl negative
    jg positive

negative:
    lea dx, prompt3
    mov ah, 09h
    int 21h
    jmp exit

equal:
    lea dx, prompt2
    mov ah, 09h
    int 21h
    jmp exit

positive:
    lea dx, prompt1
    mov ah, 09h
    int 21h
    jmp exit

exit:
    mov ah, 4ch
    int 21h

end