; --- GUID value storage ---
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

; --- GUID helper macros ---

    _DefineGuid MACRO name:REQ, l:REQ, w1:REQ, w2:REQ, b1:REQ, b2:REQ, b3:REQ, b4:REQ, b5:REQ, b6:REQ, b7:REQ, b8:REQ
        ALIGN 8
        name GUID {l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8}
    ENDM

; --- IID ---

include IID.inc

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
    ; _CallCom "instance", IUnknown, QueryInterface
    ; In which instance is a previously obtained [[vTable]]
    _CallCom MACRO ifp:REQ, interface:REQ, method:REQ
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