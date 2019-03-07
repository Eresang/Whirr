    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-byte aligned

    FXP_FRACTIONBITS_DEFAULT = 48

; --- FXP macros ---

    ; FXP
    ; Return input with added fraction bits
    _FXP MACRO input:REQ, fractBits
    LOCAL frt

        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            frt = fractBits
        ENDIF

        EXITM <input SHL frt>
    ENDM

    ; FXPAdd
    ; Calculate destination = augend + addend
    _FXPAdd MACRO destination:REQ, augend:REQ, addend:REQ
        add augend, augend
        _ArgMove destination, augend
    ENDM

    ; FXPSub
    ; Calculate destination = minuend - subtrahend
    _FXPSub MACRO destination:REQ, minuend:REQ, subtrahend:REQ
        sub minuend, subtrahend
        _ArgMove destination, minuend
    ENDM

    ; FXPMul
    ; Calculate destination = multiplicand * multiplier
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Beware of overflow - WILL NOT cause error
    _FXPMul MACRO destination:REQ, multiplicand:REQ, multiplier:REQ, fractBits
    LOCAL frt, whl

        ; Get shift values
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPMul fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPMul fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF
        whl = 64 - frt

        IFDIFI <multiplier>, <rax>
            _ArgMove rax, multiplicand
            imul multiplier
        ELSE
            imul multiplicand
        ENDIF

        ; Make result match fractBits format
        IFIDNI <destination>, <rdx>
            shld rdx, rax, whl
            ECHO Warning: _FXPMul: overflow lost due to destination register of rdx
        ELSE
            shrd rax, rdx, frt
            sar rdx, frt
            _ArgMove destination, rax
        ENDIF
    ENDM

    ; FXPDiv
    ; Calculate destination = dividend / divisor
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Beware of overflow - WILL cause error
    _FXPDiv MACRO destination:REQ, dividend:REQ, divisor:REQ, fractBits
    LOCAL frt, whl, ind

        ; Get shift values
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPDiv fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPDiv fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF
        whl = 64 - frt

        ; Ensure registers are not overwritten before division
        ind = _ArgIndexOf(divisor, rax, rdx)
        IF ind EQ -1            ; No overlapping register
            _ArgMove rax, dividend,\
                     rdx, dividend

            shl rax, frt
            sar rdx, whl
            idiv divisor
        ELSE                    ; Overlapping register
            IFIDNI <dividend>, <rcx>
                mov _ArgAtIndex(1 - ind, rax, rdx), rcx
                mov rcx, divisor
                mov _ArgAtIndex(ind, rax, rdx), _ArgAtIndex(1 - ind, rax, rdx)
            ELSE
                _ArgMove rax, dividend,\
                         rdx, dividend,\
                         rcx, divisor
            ENDIF

            shl rax, frt
            sar rdx, whl
            idiv rcx
        ENDIF

        _ArgMove destination, rax
    ENDM

    ; FXPSqrt
    ; Calculate destination = sqrt(input)
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Does NOT check for negative input
    _FXPSqrt MACRO destination:REQ, input:REQ, fractBits
    LOCAL frt, whl, bps

        ; Get shift values
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPSqrt fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPSqrt fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF
        whl = 64 - frt
        bps = whl / 2 + frt - 1     ; First relevant bit for specified fraction bits

        _ArgMove r12, input,\
                 r13, input

        mov cl, bps
        shr r12, whl
        shl r13, frt                ; r12-r13 = input

        xor rax, rax                ; Result tally
        mov rdx, 1 SHL bps          ; Relevant bit

        @FXPSqrt_Loop:
            mov r9, rax
            xor r8, r8
            add r9, r9
            adc r8, 0
            add r9, rdx
            adc r8, 0               ; r8-r9 = temporary value

            shld r8, r9, cl
            shl r9, cl

            cmp r12, r8             ; r12-r13 >= r8-r9 ?
            ja @FXPSqrt_Update
            jb @FXPSqrt_Skip

            cmp r13, r9
            jb @FXPSqrt_Skip
            @FXPSqrt_Update:        ; Update input and result
                sub r13, r9
                sbb r12, r8

                add rax, rdx
            @FXPSqrt_Skip:

            dec cl
            shr rdx, 1
        jnz @FXPSqrt_Loop

        _ArgMove destination, rax
    ENDM

    ; FXPSin
    ; Calculate destination = sin(input)
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Expects input to be in binary radians (i.e. pi = 1)
    ; Always calculates 4.60 fxp and shifts to desired fraction bits afterwards
    _FXPSin MACRO destination:REQ, input:REQ, fractBits
    LOCAL frt, whl, bps

        ; Get shift values
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPSin fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPSin fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF
        whl = 63 - frt              ; Shift required to match 60 bit fraction
        bps = 60 - frt

        _ArgMove rax, input

        lea r12, FXP_SINTABLE
        shl rax, whl                ; Move oddness bit to sign position, whl can never be zero
        cqo
        prefetchnta [r12]           ; Prefetch multiplier table
        mov r13, rdx                ; Input oddness becomes sign in r13

        shl rax, 1
        cqo
        xor rax, rdx
        sub rax, rdx                ; Mirror input around (-)0.5

        mov r9, rax
        mul r9
        xor r8, r8
        mov rcx, rdx                ; Input squared in rcx

        ALIGN 8
        @FXPSin_Loop:
            mov rax, [r12]
            mul r9
            jno @FXPSin_Break       ; Term has become too small to matter
            add r12, 8

            xor rdx, r13
            mov rax, r9
            shl r13, 1
            adc r8, rdx
            sar r13, 1

            mul rcx
            not r13
            mov r9, rdx
        jmp @FXPSin_Loop

        @FXPSin_Break:

        IF bps NE 0
            mov rax, r8
            cqo
            sar rax, bps
            adc rax, rdx            ; Rounding

            _ArgMove destination, rax
        ELSE
            _ArgMove destination, r8
        ENDIF
    ENDM

    ; FXPCos
    ; Calculate destination = cos(input)
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Expects input to be in binary radians (i.e. pi = 1)
    _FXPCos MACRO destination:REQ, input:REQ, fractBits
    LOCAL frt

        ; Get shift value
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPCos fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPCos fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF

        ; Prevent overwriting of input
        IFIDNI <input>, <rcx>
            mov rax, _FXP(1, frt - 1)
        ELSE
            mov rcx, _FXP(1, frt - 1)
        ENDIF

        add rax, rcx

        ; cos(input) = sin(input + 0.5)
        _FXPSin destination, rax, frt
    ENDM

    ; FXPTan
    ; Calculate destination = tan(input)
    ; Optional fractBits argument to specify fixed point position in input and output
    ; Expects input to be in binary radians (i.e. pi = 1)
    ; tan(input) = sin(input) / cos(input)
    ; - 1 Sin 1 Cos 1 Div
    ; tan(input) = (+/-) sin(input) / sqrt(1 - sin(input) * sin(input))
    ; - 1 Sin 1 Sqrt 1 Mul 1 Div
    ; - Requires fixing sign (along the lines of result *= Odd(input + 0.5) ? -1 : 1)
    _FXPTan MACRO destination:REQ, input:REQ, fractBits
    LOCAL frt, whl, bps

        ; Get shift values
        frt = FXP_FRACTIONBITS_DEFAULT
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPSin fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPSin fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
        ENDIF
        whl = 63 - frt              ; Shift required to match 60 bit fraction
        bps = 64 - frt

        ; Not using _FXPSin to reduce shifts

        _ArgMove rax, input

        mov rcx, _FXP(1, 62)
        shl rax, whl                ; Move oddness bit to sign position, whl can never be zero
        mov r14, rax
        lea r12, FXP_SINTABLE
        add rax, rcx
        cqo
        prefetchnta [r12]           ; Prefetch multiplier table
        mov r13, rdx                ; Input oddness becomes sign in r13

        shl rax, 1
        cqo
        xor rax, rdx
        sub rax, rdx                ; Mirror input around (-)0.5

        mov r9, rax
        mul r9
        xor r8, r8
        mov rcx, rdx                ; Input squared in rcx

        ALIGN 8
        @FXPTan_Cos_Loop:
            mov rax, [r12]
            mul r9
            jno @FXPTan_Cos_Break       ; Term has become too small to matter
            add r12, 8

            xor rdx, r13
            mov rax, r9
            shl r13, 1
            adc r8, rdx
            sar r13, 1

            mul rcx
            not r13
            mov r9, rdx
        jmp @FXPTan_Cos_Loop

        @FXPTan_Cos_Break:

        ; Calculate sin(input)
        mov rax, r14
        lea r12, FXP_SINTABLE
        cqo
        mov r13, rdx                ; Input oddness becomes sign in r13

        shl rax, 1
        cqo
        xor rax, rdx
        sub rax, rdx                ; Mirror input around (-)0.5

        mov r9, rax
        mul r9
        xor r14, r14
        mov rcx, rdx                ; Input squared in rcx

        ALIGN 8
        @FXPTan_Sin_Loop:
            mov rax, [r12]
            mul r9
            jno @FXPTan_Sin_Break       ; Term has become too small to matter
            add r12, 8

            xor rdx, r13
            mov rax, r9
            shl r13, 1
            adc r14, rdx
            sar r13, 1

            mul rcx
            not r13
            mov r9, rdx
        jmp @FXPTan_Sin_Loop

        @FXPTan_Sin_Break:

        ; Compare difference in magnitude between cos(input) and sin(input) to detect overflow
        ; 4.60 fxp to target fxp
        ; r8 = cos(input)
        ; r14 = sin(input)

        mov rax, 0517CC1B727220A94h     ; 1 / PI in 0.64 fxp
        mul r14

        shrd rax, rdx, bps
        sar rdx, bps
        idiv r8                         ; Potential for divide by zero, integer overflow

        _ArgMove destination, rax
    ENDM

.DATA
    ALIGN 8
    ; Taylor series multipliers (WolframAlpha): Table[IntegerPart(pi^(2n+1)*2^60/(2n+1)!),{n,0,15}]
    FXP_SINTABLE                                DQ 3622009729038561421
                                                DQ 5957967193751243514
                                                DQ 2940138961849664420
                                                DQ 690904962802041567
                                                DQ 94707759188965403
                                                DQ 8497528335533855
                                                DQ 537610532427990
                                                DQ 25266682271063
                                                DQ 916809406409
                                                DQ 26457737287
                                                DQ 621731905
                                                DQ 12126972
                                                DQ 199480
                                                DQ 2804
                                                DQ 34
                                                DQ 0

.CODE

    ; _FXPSqrt as procedure
    ; RCX: input
    ; Optional fractBits parameter not available
    FXPSqrt PROC
        _FXPSqrt rax, rcx
        ret
    FXPSqrt ENDP

    ; _FXPSin as procedure
    ; RCX: input
    ; Optional fractBits parameter not available
    FXPSin PROC
        _FXPSin rax, rcx
        ret
    FXPSin ENDP

    ; _FXPCos as procedure
    ; RCX: input
    ; Optional fractBits parameter not available
    FXPCos PROC
        _FXPCos rax, rcx
        ret
    FXPCos ENDP