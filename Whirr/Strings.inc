.DATA
    ALIGN 8
    STRINGS_NEWLINE                             DQ 2
                                                DQ 0A000Dh
    STRINGS_SPACE                               DQ 1
                                                DQ 20h

.CODE

    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register texts don't get overwritten
    ;  - Stack is 16-bit aligned

; --- String helper macros ---

    ; Construct a simple WideChar string started with a length field and terminated by a zero
    ; Allows creation of very long strings by entering a string in several partitions
    ; Some characters need to be repeated be entered into the text data (e.g. !, ")
    ; Ex. IN:
    ;           _String textName, "hello"
    ; Ex. OUT:
    ;           ALIGN 8
    ;           textName DQ 5
    ;           DW "h","e","l","l","o",
    ;           DW 0
    _String MACRO label:REQ, text:VARARG
    LOCAL cnt
        cnt = 0

        ; Count actual characters
        FOR item, <text>
            IF __StringValidate(item) EQ 0
                ECHO Error:_String &label&: invalid string format
            ENDIF

            cnt = cnt + __StringActualLength(item)
        ENDM

        ; Place length field and label
        ALIGN 8
        label DQ cnt

        FOR item, <text>
            __StringToWords item
        ENDM

        DW 0
    ENDM

    ; _String helper
    ; Checks for opening/closing double quotes
    __StringValidate MACRO text:REQ
    LOCAL lgt, let
        lgt SIZESTR <text>

        let SUBSTR <text>, 1, 1
        IFDIF let, <">
            EXITM <0>
        ENDIF
        let SUBSTR <text>, lgt, 1
        IFDIF let, <">
            EXITM <0>
        ENDIF

        EXITM <1>
    ENDM

    ; _String helper
    ; Count number of characters that string should contain after __StringToWords
    ; Presumes valid format and ignores opening/closing double quotes
    __StringActualLength MACRO text:REQ
    LOCAL lgt, ctr, flg
        lgt SIZESTR <text>

        ctr = 1
        flg = 0
        :cnx
            ctr = ctr + 1
            IF ctr GE lgt
                GOTO bcn
            ENDIF

            flg = flg + 1

            let SUBSTR <text>, ctr, 2
            IFIDN let, <"">
                ctr = ctr + 1
            ENDIF
        GOTO cnx
        :bcn

        EXITM <flg>
    ENDM

    ; _String helper
    ; Turn string into a field of DW data
    ; Presumes valid format and ignores opening/closing double quotes
    ; Will replace \n with CR + LF
    __StringToWords MACRO text:REQ
    LOCAL lgt, ctr, let, tmp, chr
        lgt SIZESTR <text>

        tmp EQU <>
        ctr = 1
        :nxt
            ctr = ctr + 1
            IF ctr GE lgt
                chr SIZESTR tmp
                IF chr GT 0
                    DW tmp
                ENDIF
                EXITM
            ENDIF

            let SUBSTR <text>, ctr, 2
            IFIDN let, <"">
                tmp CATSTR tmp, <"""",>
                ctr = ctr + 1
            ELSE
                IFIDNI let, <\n>
                    tmp CATSTR tmp, <13,10,>
                    ctr = ctr + 1
                ELSE
                    let SUBSTR <text>, ctr, 1
                    tmp CATSTR tmp, <">, let, <",>
                ENDIF
            ENDIF

            chr SIZESTR tmp
            IF chr GE 60
                DW tmp
                tmp EQU <>
            ENDIF
        GOTO nxt
    ENDM