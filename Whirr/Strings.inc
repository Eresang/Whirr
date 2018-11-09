    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register texts don't get overwritten
    ;  - Stack is 16-bit aligned

; --- String helper macros ---

    ; Construct a simple WideChar string started with a length field and terminated by a zero
    ; Allows creation of very long strings by entering a string in several partitions
    ; Some characters need to be repeated to be entered into the text data (e.g. !, ")
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

            cnt = cnt + __StringRealLength(item)
        ENDM

        ; Place length field
        ALIGN 8
        label DQ cnt

        ; Write actual text
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
    __StringRealLength MACRO text:REQ
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
    ; Will replace \n with CR + LF and pairs of double quotes with a single double quote
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
                ; Double quote
                tmp CATSTR tmp, <"""",>
                ctr = ctr + 1
            ELSE
                IFIDNI let, <\n>
                    ; Newline
                    tmp CATSTR tmp, <13,10,>
                    ctr = ctr + 1
                ELSE
                    ; Any other character
                    let SUBSTR <text>, ctr, 1
                    tmp CATSTR tmp, <">, let, <",>
                ENDIF
            ENDIF

            ; Limit line length
            chr SIZESTR tmp
            IF chr GE 60
                DW tmp
                tmp EQU <>
            ENDIF
        GOTO nxt
    ENDM

.DATA
    ALIGN 8
    STRINGS_NEWLINE                             DQ 2
                                                DQ 0A000Dh

    STRINGS_SPACE                               DQ 1
                                                DQ 20h

    _String STRINGS_NUMBERS, "0123456789ABCDEF"

.CODE