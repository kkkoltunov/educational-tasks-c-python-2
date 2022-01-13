extern memcpy
extern intSize
extern plantSize

section .text
global PercentageOfVowelLetters
global MergeSort

strlen:
    ; Адрес сообщения уже загружен в rdi
    mov rcx, -1     ; ecx должен быть < 0
    xor al, al      ; конечный симврл = 0
    cld             ; направление обхода от начала к концу
    repne   scasb   ; while(msg[rdi]) != al) {rdi++, rcx--}
    neg rcx
    sub rcx, 2      ; ecx = length(msg)
    mov rax, rcx
    ret

PercentageOfVowelLetters:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32                     ; выделяем стекфрейм
        mov     [rbp - 8], rdi              ; в rdi лежит аргумент функции — сохраним его
        call    strlen                      ; не трогая аргумент, вызовем strlen от него
        mov     [rbp - 12], eax             ; сохраним результат strlen
        mov     dword [rbp - 16], 0         ; int vowels = 0 счётчик
        mov     dword [rbp - 20], 0         ; int i = 0 счётчик

.PercentageOfVowelLetters_loop_begin:
        mov     eax, [rbp - 20]                             ; перемещаем значение i в регистр eax
        cmp     eax, [rbp - 12]                             ; сравниваем с длиной строки
        jge     .PercentageOfVowelLetters_loop_out          ; если i больше или равно длины строки, то выходим
        mov     rax, [rbp - 8]                              ; достаем указатель на строку со стека
        movsx   eax, byte [rax]                             ; смотрим значение текущего символа
        cmp     eax, 'a'                                    ; сравнение на гласную
        je      .if_vowel                                   ; если это гласная, то прыгаем в иф
        cmp     eax, 'o'
        je      .if_vowel
        cmp     eax, 'i'
        je      .if_vowel
        cmp     eax, 'e'
        je      .if_vowel
        cmp     eax, 'u'
        je      .if_vowel
        cmp     eax, 'y'
        jne     .PercentageOfVowelLetters_loop_end       ; не гласная и можно иф перепрыгивать

.if_vowel:                                  ; блок иф при выполнении условия
        inc     dword [rbp - 16]            ; vowels++

.PercentageOfVowelLetters_loop_end:
        inc     qword [rbp - 8]                         ; temp++
        inc     dword [rbp - 20]                        ; i++
        jmp     .PercentageOfVowelLetters_loop_begin    ; переходим в заголовок цикла

.PercentageOfVowelLetters_loop_out:
        cvtsi2sd xmm0, [rbp - 16]           ; достаем vowels
        cvtsi2sd xmm1, [rbp - 12]           ; достаем strlen
        divsd   xmm0, xmm1                  ; делим wovels на strlen, в xmm0 по соглашению о вызовах возвращается double
        mov     rsp, rbp
        pop     rbp
        ret


MergeSort:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 80                     ; выделяем стекфрейм
        mov     [rbp - 8], rdi              ; сохраняем cont
        mov     [rbp - 12], esi             ; сохраняем len
        mov     dword [rbp - 16], 0         ; int i = 0

.MergeSort_loop_begin:
        mov     eax, [rbp - 12]             ; достаем len
        dec     eax                         ; вычитаем 1
        cmp     [rbp - 16], eax             ; если i >= len - 1, то выходим из цикла
        jge     .MergeSort_loop_out
        mov     [rbp - 20], eax             ; j = len - 1

.MergeSort_inner_loop_begin:               ; заголовок внутреннего цикла
        mov     eax, [rbp - 20]             ; достаем j
        cmp     eax, [rbp - 16]             ; сравниваем c i
        jle     .MergeSort_inner_loop_out  ; если j <= i, то выходим из внутреннего цикла

        mov     rax, [rbp - 8]
        mov     ecx, [plantSize]
        mov     edx, [rbp - 20]
        sub     edx, 1
        imul    ecx, edx
        movsxd  rcx, ecx
        add     rax, rcx
        mov     [rbp - 32], rax             ; посчитали void *first

        mov     rax, [rbp - 8]
        mov     ecx, [plantSize]
        imul    ecx, [rbp - 20]
        movsxd  rcx, ecx
        add     rax, rcx
        mov     [rbp - 40], rax             ; посчитали void *second


        mov     rdi, [rbp - 32]             ; достаем first
        movsxd  rax, dword [intSize]
        add     rdi, rax                    ; прибавляем к нему intSize
        call    PercentageOfVowelLetters    ; вызываем первый PercentageOfVowelLetters
        movsd   qword [rbp - 64], xmm0      ; сохраняем результат вычисления в aligned-адрес
        mov     rdi, qword [rbp - 40]       ; достаем secind
        movsxd  rax, dword [intSize]
        add     rdi, rax                    ; прибавляем к нему intSize
        call    PercentageOfVowelLetters    ; вызываем второй PercentageOfVowelLetters
        movsd   xmm1, qword [rbp - 64]      ; результат последнего вычисления в xmm0, восстанавливаем первый в xmm1
        ucomisd xmm0, xmm1                  ; сравниваем
        jbe     .MergeSortt_inner_loop_end  ; если первое >= второе, то уходим на следующий круг
        mov     eax, dword [plantSize]      ; достаем plantSize
        mov     rcx, rsp
        mov     [rbp - 48], rsp             ; сохраняем rsp
        mov     rcx, rax
        add     rcx, 15
        and     rcx, -16                    ; выделяем на стеке память под plantSize с учетом align
        sub     rsp, rcx                    ; двигаем верхушку стека
        mov     [rbp - 72], rsp             ; сохраняем указатель на temp
        mov     rdi, qword [rbp - 72]       ; делаем наши свапы
        mov     rsi, qword [rbp - 40]
        movsxd  rdx, dword [plantSize]
        call    memcpy
        mov     rdi, qword [rbp - 40]
        mov     rsi, qword [rbp - 32]
        movsxd  rdx, dword [plantSize]
        call    memcpy
		mov     rdi, qword [rbp - 32]
        mov     rsi, qword [rbp - 72]
        movsxd  rdx, dword [plantSize]
        call    memcpy
        mov     rsp, qword [rbp - 48]      ; возвращаем старую верхушку стека

.MergeSort_inner_loop_end:
        dec     dword [rbp - 20]           ; j--
        jmp     .MergeSort_inner_loop_begin

.MergeSort_inner_loop_out:
.MergeSort_loop_end:
        inc     dword [rbp - 16]           ; i++
        jmp     .MergeSort_loop_begin
.MergeSort_loop_out:
        mov     rsp, rbp
        pop     rbp
        ret