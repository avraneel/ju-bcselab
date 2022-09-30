.model small
.stack 100h

.data

prompt  db 'Enter q to quit$'
newline db 10, 13, '$'

.code

loading_data:
    mov ax, @data
    mov ds, ax
    mov ax, 00h

prompt_user: 
    lea dx, prompt
    mov ah, 09h
    int 21h

    lea dx, newline
    mov ah, 09h
    int 21h

input: 
    mov ah, 01h ; data stored in al
    int 21h

compare:
    cmp     al, 71h ; ascii of q is 72h
    je      exit
    loop    input ; jump if zero flag is raised

;your code goes here

exit:
mov ah, 4ch
int 21h

end