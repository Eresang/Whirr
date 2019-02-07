    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-byte aligned

; --- FXP macros ---

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
        frt = 48
        whl = 16
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPMul fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPMul fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
            whl = 64 - frt
        ENDIF

        IFDIFI <multiplier>, <rax>
            _ArgMove rax, multiplicand
            imul multiplier
        ELSE
            imul multiplicand
        ENDIF

        ; Make result match fractBits format
        IFIDNI <destination>, <rdx>
            shld rdx, rax, whl
            IFIDNI <destination>, <rdx>
                ECHO Warning: _FXPMul: overflow lost due to destination register of rdx
            ENDIF
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
    LOCAL frt, whl

        ; Get shift values
        frt = 48
        whl = 16
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPDiv fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPDiv fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
            whl = 64 - frt
        ENDIF

        ; TODO: ensure registers are not overwritten
        ; mov rax, dividend
        ; mov rdx, dividend

        ; Perform shift to make result match fractBits format
        shl rax, frt
        sar rdx, whl
        idiv divisor

        _ArgMove destination, rax
    ENDM

    ; FXPSqrt
    ; Calculate destination = sqrt(input)
    ; Optional fractBits argument to specify fixed point position in input and output
    _FXPSqrt MACRO destination:REQ, input:REQ, fractBits
    LOCAL frt, whl, bps

        ; Get shift values
        frt = 48
        whl = 16
        IFNB <fractBits>
            IF fractBits GT 60
                ECHO Error: _FXPSqrt fractBits: too high (max: 60)
            ENDIF
            IF fractBits LT 0
                ECHO Error: _FXPSqrt fractBits: too low (min: 0)
            ENDIF
            frt = fractBits
            whl = 64 - frt
        ENDIF
        bps = whl / 2 + frt - 1     ; First relevant bit for specific fraction bits

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

.DATA

.CODE

    ; _FXPSqrt as procedure
    ; RCX: input
    ; Optional fractBits parameter not available
    FXPSqrt PROC
        _FXPSqrt rax, rcx
        ret
    FXPSqrt ENDP