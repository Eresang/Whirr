    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-byte aligned

    TIME_FRACTIONBITS = 24
    TIME_MININTERVAL = _FXP(1, TIME_FRACTIONBITS - 10)  ; 2^-10 seconds (~0.001)
    TIME_MAXINTERVAL = _FXP(1, TIME_FRACTIONBITS)       ; 1 second

; --- Time macros ---

    ; Initiate time data fields
    ; Calculate conversion multiplier (1 / frequency)
    ; Using multiplier instead of divisor will result in less accurate results for higher frequencies
    _TimeInitiate MACRO
        lea rcx, TIME_MULTIPLIER_INT
        call QueryPerformanceFrequency                  ; Temporarily store frequency in multiplier

        mov rcx, TIME_MULTIPLIER_INT
        xor rax, rax
        mov TIME_INTERVALSINCESTART_FXP, rax
        mov edx, 1                                      ; mov to r32 destination clears upper bits of the full r64
        div rcx                                         ; No overflow if frequency > 1
        shr rcx, 1
        sub rcx, rdx
        adc rax, 1                                      ; Rounding
        mov TIME_MULTIPLIER_INT, rax

        lea rcx, TIME_COUNTERSTART_INT
        call QueryPerformanceCounter                    ; Retrieve start counter

        mov rax, TIME_COUNTERSTART_INT
        mov TIME_COUNTERNOW_INT, rax                    ; Set now counter to start counter
    ENDM

    ; Return last calculated interval value in destination
    _TimeInterval MACRO destination:REQ
        mov destination, TIME_INTERVAL_FXP
    ENDM

    ; Return last calculated interval since start value in destination
    _TimeIntervalSinceStart MACRO destination:REQ
        mov destination, TIME_INTERVALSINCESTART_FXP
    ENDM

    ; Calculates:
    ; a - Interval since last _TimeInitiate
    ; b - Interval since last _TimeCalculateInterval (or _TimeInitiate)
    ; Optionally returns a in destination
    _TimeCalculateInterval MACRO destination
        mov r9, TIME_COUNTERNOW_INT
        lea rcx, TIME_COUNTERNOW_INT
        call QueryPerformanceCounter

        mov rax, TIME_COUNTERNOW_INT                    ; Calculate interval since start
        sub rax, TIME_COUNTERSTART_INT
        mul TIME_MULTIPLIER_INT
        shld rdx, rax, TIME_FRACTIONBITS
        mov TIME_INTERVALSINCESTART_FXP, rdx            ; Let interval since start wrap around to zero without issue

        mov rax, TIME_COUNTERNOW_INT                    ; Calculate interval since last calculation
        sub rax, r9
        mul TIME_MULTIPLIER_INT
        mov rcx, TIME_MAXINTERVAL
        mov r8, TIME_MININTERVAL
        shrd rax, rdx, 64 - TIME_FRACTIONBITS
        shr rdx, 64 - TIME_FRACTIONBITS
        jnz @TimeInterval_Overflow                      ; If rdx <> 0 then also Interval > MaxInterval

        cmp rax, r8                                     ; Interval > MinInterval ?
        jae @TimeInterval_AboveMin

            xor rax, rax                                ; Minimum interval has not passed
            mov TIME_COUNTERNOW_INT, r9                 ; Restore counter
            mov TIME_INTERVAL_FXP, rax                  ; Set interval to zero
            jmp @TimeInterval_Return

        @TimeInterval_AboveMin:
        cmp rax, rcx                                    ; Interval < MaxInterval ?
        jbe @TimeInterval_BelowMax
        @TimeInterval_Overflow:

            mov rax, rcx                                ; Set interval to maximum interval

        @TimeInterval_BelowMax:

        mov TIME_INTERVAL_FXP, rax

        @TimeInterval_Return:

        IFNB <destination>
            _ArgMove destination, rax
        ENDIF
    ENDM

.DATA

    ALIGN 8
    TIME_MULTIPLIER_INT                         DQ ?
    TIME_COUNTERSTART_INT                       DQ ?
    TIME_COUNTERNOW_INT                         DQ ?
    TIME_INTERVAL_FXP                           DQ 0
    TIME_INTERVALSINCESTART_FXP                 DQ 0

.CODE