; --- Global Interfaces ---

include GUID.inc
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
        call QWORD PTR [rax]._&interface&_.method
    ENDM

; --- IUnknown ---

    _IUnknown MACRO
        QueryInterface          DQ ?
        AddRef                  DQ ?
        Release                 DQ ?
    ENDM

    _ComTable IUnkown, _IUnknown

; --- Interface Specifications ---

include DXGI.inc