.DATA

    RANDOM_SEED                                 DQ 1234567899876543210
    RANDOM_ADD                                  EQU 9182736455463728197
    RANDOM_MULTIPLY                             EQU 13579086420135790861

.CODE

; --- Random helper macros ---

    ; Randomize random seed by using system counter
    _Randomize MACRO seed
        IFB <seed>
            lea rcx, RANDOM_SEED
            call QueryPerformanceCounter
        ELSE
            IFE OPATTR(seed) EQ 30
                mov rcx, QWORD PTR seed
                mov RANDOM_SEED, rcx
            ELSE
                mov RANDOM_SEED, seed
            ENDIF
        ENDIF
    ENDM

    ; Return 64 quasi-random bits
    _Random MACRO destination:REQ, seed
        mov rax, RANDOM_MULTIPLY

        IFB <seed>
            mul QWORD PTR RANDOM_SEED
        ELSE
            mul QWORD PTR seed
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

    ; _Random as procedure
    ; RCX: seed pointer
    Random PROC
        ; Determine if custom seed is used
        or rcx, rcx
        jnz @Random_SeedSelected
            mov rcx, RANDOM_SEED
        @Random_SeedSelected:

        _Random rax, rcx
        ret
    Random ENDP

    ; Return a quasi-random 64 bit value between or equal to lower and upper limits
    _RandomRange MACRO destination:REQ, lower:REQ, upper:REQ, seed
        IFIDNI <upper>, <rcx>
            ECHO Error: "_RandomRange: register rcx is not valid for passing upper limit"
        ENDIF

        IFNB <seed>
            IFE _ArgIndexOf(seed), rcx, rdx, r8 EQ -1
                ECHO Error: "_RandomRange: registers rcx, rdx and r8 are not valid for passing seed pointer"
            ENDIF
        ENDIF

        _ArgMove rcx, lower
        _ArgMove r8, upper
        _ArgMove rdx, upper
        
        mov rax, RANDOM_MULTIPLY
        sub r8, rcx

        IFB <seed>
            mul QWORD PTR RANDOM_SEED
        ELSE
            mul QWORD PTR seed
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

    ; _RandomRange as procedure
    ; RCX: lower limit
    ; RDX: upper limit
    ; R8 : seed pointer
    RandomRange PROC
        ; Determine if custom seed is used
        or r8, r8
        jnz @RandomRange_SeedSelected
            mov r8, RANDOM_SEED
        @RandomRange_SeedSelected:

        ; _RandomRange already uses r8
        mov r9, r8

        _RandomRange rax, rcx, r9
        ret
    RandomRange ENDP