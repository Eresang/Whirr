; GUID value storage
    GUID STRUCT
        Data1       DD  ?
        Data2       DW  ?
        Data3       DW  ?
        Data4a      DB  ?
        Data4b      DB  ?
        Data4c      DB  ?
        Data4d      DB  ?
        Data4e      DB  ?
        Data4f      DB  ?
        Data4g      DB  ?
        Data4h      DB  ?
    GUID ENDS

    IUD             EQU DQ

; --- Guid helper macros ---

    _DefineGuid MACRO name:REQ, l:REQ, w1:REQ, w2:REQ, b1:REQ, b2:REQ, b3:REQ, b4:REQ, b5:REQ, b6:REQ, b7:REQ, b8:REQ
        IFNDEF __&name&__
            __&name&__ EQU 1
            name GUID {l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8}
        ELSE
            ECHO Warning:_DefineGuid &name&: redefinition prevented
        ENDIF
    ENDM

    ; Ex. Usage:
    ; _CallCOM "instance", IUnknown, QueryInterface
    ; In which instance is a previously obtained [vTable]
    _CallCOM MACRO ifp:REQ, interface:REQ, method:REQ
        _ArgMove rcx, ifp

        call [rcx].interface.method
    ENDM