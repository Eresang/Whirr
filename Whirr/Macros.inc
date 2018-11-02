; --- VARARG helper macros ---

    ; Retrieves argument from list
    _ArgAtIndex MACRO index:REQ, arguments:VARARG
    LOCAL cnt, itr
        cnt = _ArgCount(arguments)
        itr = 0

        FOR item, <arguments>
            IF itr EQ index
                EXITM <item>
            ENDIF

            itr = itr + 1
        ENDM

        EXITM <>
    ENDM

    ; Retrieves index from list
    _ArgIndexOf MACRO match:REQ, arguments:VARARG
    LOCAL itr
        itr = -1

        FOR item, <arguments>
            IFIDNI <match>, <item>
                EXITM <itr>
            ENDIF

            itr = itr + 1
        ENDM

        EXITM <itr>
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

    ; Move odd index arguments to [their index-1], if they don't match
    _ArgMove MACRO arguments:VARARG
    LOCAL itr, previous
        itr = 0
        previous TEXTEQU <>

        FOR item, <arguments>
            IF itr EQ 1
                IFDIFI previous, <item>
                    mov previous, item
                ENDIF
            ENDIF

            previous TEXTEQU <item>
            itr = (itr + 1) MOD 2
        ENDM
    ENDM