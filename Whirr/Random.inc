.DATA

    RANDOM_SEED                                 DQ 1234567899876543210
    RANDOM_ADD                                  EQU 9182736455463728197
    RANDOM_MULTIPLY                             EQU 13579086420135790861

.CODE

    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-bit aligned

; --- Random helper macros ---

    ; Randomize random seed by using system counter
    _Randomize MACRO seed
        IFB <seed>
            lea rcx, RANDOM_SEED
            call QueryPerformanceCounter
        ELSE
            mov RANDOM_SEED, seed
        ENDIF
    ENDM

    ; Return 64 quasi-random bits
    _Random MACRO destination:REQ, seed
        mov rax, RANDOM_MULTIPLY

        IFB <seed>
            mul RANDOM_SEED
        ELSE
            mul seed
        ENDIF

        add rax, rdx
        mov rdx, RANDOM_ADD
        adc rax, rdx

        IFB <seed>
            mov RANDOM_SEED, rax
        ELSE
            mov seed, rax
        ENDIF

        _ArgMove destination, rax
    ENDM

    ; Return a quasi-random 64 bit value between or equal to lower and upper limits
    _RandomRange MACRO destination:REQ, lower:REQ, upper:REQ, seed
        _ArgMove rcx, lower
        _ArgMove r8, upper
        _ArgMove rdx, upper
        
        mov rax, RANDOM_MULTIPLY
        sub r8, rcx

        IFB <seed>
            mul RANDOM_SEED
        ELSE
            mul seed
        ENDIF

        add rax, rdx
        mov rdx, RANDOM_ADD
        adc rax, rdx
        add r8, 1

        IFB <seed>
            mov RANDOM_SEED, rax
        ELSE
            mov seed, rax
        ENDIF

        mul r8
        mov rax, rdx
        add rax, rcx

        _ArgMove destination, rax
    ENDM

; --- Random procedures ---

    ; _Random as procedure
    ; RCX: seed pointer
    Random PROC
        ; Determine if custom seed is used
        or rcx, rcx
        jnz @Random_SeedSelected
            lea rcx, RANDOM_SEED
        @Random_SeedSelected:

        _Random rax, QWORD PTR [rcx]
        ret
    Random ENDP

    ; _RandomRange as procedure
    ; RCX: lower limit
    ; RDX: upper limit
    ; R8 : seed pointer
    RandomRange PROC
        ; Determine if custom seed is used
        or r8, r8
        jnz @RandomRange_SeedSelected
            lea r8, RANDOM_SEED
        @RandomRange_SeedSelected:

        ; _RandomRange uses r8
        mov r9, r8

        _RandomRange rax, rcx, QWORD PTR [r9]
        ret
    RandomRange ENDP