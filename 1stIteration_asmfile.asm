%include "io64.inc"

section .data
matrix dq 0.0, 62.5, 10.1,60.0, 122.3, 5.5, 30.0, 160.7, 7.8
num_cars dq 3                
one_k dq 1000.0              
one_s dq 3600.0                            

section .bss
i resq 1                    
results resd 3 

section .text
global main

main:
    xor rax, rax
    mov qword [i], rax           

compute:
    mov rax, [i]
    cmp rax, [num_cars]
    jge exit              

    mov rbx, rax
    imul rbx, 3                  ; rbx = i * 3 (index for row)
    movq xmm0, qword [matrix + rbx * 8]    ; xmm0 = Vi (KM/H)
    movq xmm1, qword [matrix + rbx * 8 + 8]; xmm1 = Vf (KM/H)
    movq xmm2, qword [matrix + rbx * 8 + 16]; xmm2 = T (seconds)

    ; convert Vi and Vf from KM/H to M/S
    movq xmm3, qword [one_k]     ; xmm3 = 1000.0
    movq xmm4, qword [one_s]     ; xmm4 = 3600.0

    divsd xmm0, xmm4             ; Vi (KM/H) / 3600
    mulsd xmm0, xmm3             ; Vi (M/S)

    divsd xmm1, xmm4             ; Vf (KM/H) / 3600
    mulsd xmm1, xmm3             ; Vf (M/S)

    ; compute acceleration: (Vf - Vi) / T
    subsd xmm1, xmm0             ; Vf - Vi
    divsd xmm1, xmm2             ; (Vf - Vi) / T
    
    ;round up
    roundsd xmm1, xmm1, 0 

    ; convert result to integer
    cvttsd2si eax, xmm1          ; convert acceleration to int
    PRINT_DEC 4, eax
    NEWLINE
    mov dword [results + rax * 4], eax  ; store result in results array

    ; increment loop counter
    inc qword [i]
    jmp compute

exit:
   ret
