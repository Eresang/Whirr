; --- PROC helper macros ---

    ; Prepare stack for arguments and push them
    _Enter MACRO arguments:VARARG
    LOCAL cnt, mxc, itr, ind
        cnt = _ArgCount(arguments)
        mxc = cnt

        ; Push an even and greater than 3 number of DQ
        IF cnt LT 4
            cnt = 4
        ENDIF
        IF (cnt MOD 2) EQ 1
            cnt = cnt + 1
        ENDIF

        ; Prepare stack pointer
        push rbp
        mov rbp, rsp
        sub rsp, cnt * 8

        ; Push actual values
        itr = 0
        REPT cnt
            ind TEXTEQU _ArgAtIndex(itr, arguments)
            IF itr LT mxc
                mov [rsp + itr * 8], ind
            ENDIF
            itr = itr + 1
        ENDM
    ENDM

    ; Restore stack pointer and return
    _Leave MACRO
        leave
        ret
    ENDM

; --- CALL helper macros ---

    _Call MACRO arguments:VARARG
    LOCAL cnt, itr
        cnt = _ArgCount(arguments)

        IF cnt LT 4
            cnt = 4
        ENDIF

        sub rsp, cnt * 8
        and sp, 0FFF0h

        itr = 0
        FOR item, <arguments>
            IF itr GT 4
                mov rax, item
                mov [rsp + itr * 8], rax
            ELSEIF lPointer EQ 0
                mov rcx, item
            ELSEIF lPointer EQ 1
                mov rdx, item
            ELSEIF lPointer EQ 2
                mov r8, item
            ELSEIF lPointer EQ 3
                mov r9, item
            ENDIF
            itr = itr + 1 
        ENDM
    ENDM

; --- VARARG helper macros ---

    ; Retrieves argument at index from list
    _ArgAtIndex MACRO index:REQ, arguments:VARARG
    LOCAL cnt, itr, cnd, txt
        cnt = _ArgCount(arguments)
        itr = 0
        cnd = 0

        FOR item, <arguments>
            IF itr EQ index
                cnd = 1
                EXITM <item>
            ENDIF
            itr = itr + 1
        ENDM

        IF cnd EQ 0
            EXITM <>
        ENDIF
    ENDM

    ; Retrieves index of match from list
    _ArgIndexOf MACRO match:REQ, arguments:VARARG
    LOCAL itr, cnd
        itr = 0
        cnd = 0

        FOR item, <arguments>
            IFIDNI <match>, <item>
                cnd = 1
                EXITM <itr>
            ENDIF
            itr = itr + 1
        ENDM

        IF cnd EQ 0
            EXITM <1>
        ENDIF
    ENDM

    ; Count number of arguments in a VARARG parameter
    _ArgCount MACRO arguments:VARARG
    LOCAL cnt
        cnt = 0
        FOR item, <arguments>
            cnt = cnt + 1
        ENDM
        EXITM <cnt>
    ENDM

    ; Swap arguments avoiding the use of xchg
    _ArgSwap MACRO a:REQ, b:REQ
        IFDIFI <a>, <b>
            xor a, b
            xor b, a
            xor a, b
        ENDIF
    ENDM

    ; Move odd index arguments to [their index-1] if they don't match
    _ArgMove MACRO arguments:VARARG
    LOCAL itr, previous
        itr = 0
        previous TEXTEQU <>

        FOR item, <arguments>
            ; Ignore every item in arguments at an even index
            IF itr EQ 1
                IFDIFI previous, <item>
                    mov previous, item
                ENDIF
            ENDIF

            previous TEXTEQU <item>
            itr = (itr + 1) MOD 2
        ENDM
    ENDM

.DATA

.CODE