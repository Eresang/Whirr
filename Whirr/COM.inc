; --- GUID helper macros ---

    _GetGuid MACRO destination:REQ, name:REQ
        IFNDEF <name>
            GUIDDATA SEGMENT
                ALIGN 8
                name DD name&_DATA0
                     DW name&_DATA1
                     DW name&_DATA2
                     DB name&_DATA3
                     DB name&_DATA4
                     DB name&_DATA5
                     DB name&_DATA6
                     DB name&_DATA7
                     DB name&_DATA8
                     DB name&_DATA9
                     DB name&_DATAA
            GUIDDATA ENDS
            .CODE
        ENDIF
        lea destination, name
    ENDM

    _DefineGuid MACRO name:REQ, l:REQ, w1:REQ, w2:REQ, b1:REQ, b2:REQ, b3:REQ, b4:REQ, b5:REQ, b6:REQ, b7:REQ, b8:REQ
        name&_DATA0 = l
        name&_DATA1 = w1
        name&_DATA2 = w2
        name&_DATA3 = b1
        name&_DATA4 = b2
        name&_DATA5 = b3
        name&_DATA6 = b4
        name&_DATA7 = b5
        name&_DATA8 = b6
        name&_DATA9 = b7
        name&_DATAA = b8
    ENDM

; --- COM return values ---

    E_ACCESSDENIED              EQU 080070005h
    E_FAIL                      EQU 080004005h
    E_INVALIDARG                EQU 080070057h
    E_OUTOFMEMORY               EQU 08007000Eh
    E_POINTER                   EQU 080004003h
    E_UNEXPECTED                EQU 08000FFFFh
    S_OK                        EQU 00h
    S_FALSE                     EQU 01h

; --- COM table builder ---

    ; Table building
    _ComTable MACRO name:REQ, macroName:REQ
        _&name&_ STRUCT
            macroName
        _&name&_ ENDS
    ENDM

; --- Com call ---

    ; Ex. Usage:
    ; _ComCall "instance", IUnknown, QueryInterface
    ; In which instance is a previously obtained [[vTable]]
    _ComCall MACRO ifp:REQ, interface:REQ, method:REQ
        _ArgMove rcx, ifp
        mov rax, [rcx]
        call QWORD PTR [rax]._&interface&_._&method&
    ENDM

; --- IUnknown ---

    _IUnknown MACRO
        _QueryInterface         DQ ?
        _AddRef                 DQ ?
        _Release                DQ ?
    ENDM

    _ComTable IUnkown, _IUnknown