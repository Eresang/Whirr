    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-bit aligned

; --- Random helper macros ---

    ; Randomize random seed by using system counter
    ; Expects custom seed to be in a register
    _Randomize MACRO seed
        IFB <seed>
            lea rcx, RANDOM_SEED
            call QueryPerformanceCounter
        ELSE
            mov RANDOM_SEED, seed
        ENDIF
    ENDM

    ; Return 64 quasi-random bits
    ; Expects custom seed to be a memory location or an otherwise unused register
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
    ; Expects custom seed to be a memory location or an otherwise unused register
    _RandomRange MACRO destination:REQ, lower:REQ, upper:REQ, seed
        _ArgMove rcx, lower, r8, upper, rdx, upper
        
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
        add rdx, rcx

        _ArgMove destination, rdx
    ENDM

.DATA

    ALIGN 8
    RANDOM_SEED                                 DQ 13043817825332783101
    RANDOM_ADD                                  EQU 9223372036854775783
    RANDOM_MULTIPLY                             EQU 18446744073709551557

.CODE

    ; _Random as procedure
    ; RCX: seed pointer
    ;      if NULL use RANDOM_SEED
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
    ;      if NULL use RANDOM_SEED
    RandomRange PROC
        ; Determine if custom seed is used
        or r8, r8
        jnz @RandomRange_SeedSelected
            lea r8, RANDOM_SEED
        @RandomRange_SeedSelected:

        ; _RandomRange uses r8
        mov r9, r8
        _RandomRange rax, rcx, rdx, QWORD PTR [r9]
        ret
    RandomRange ENDP