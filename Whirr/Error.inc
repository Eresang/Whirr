    _Error MACRO message:REQ
        lea rdx, message
        call WhirrError
    ENDM

    _ErrorIfZero MACRO value:REQ, message:REQ
    LOCAL ecp
        or value, value
        jnz ecp
        _Error message
        ecp:
    ENDM

    _ErrorIfNotZero MACRO value:REQ, message:REQ
    LOCAL ecp
        or value, value
        jz ecp
        _Error message
        ecp:
    ENDM

    _ErrorIfNotX MACRO value:REQ, x:REQ, message:REQ
    LOCAL ecp
        cmp value, x
        je ecp
        _Error message
        ecp:
    ENDM

; Error caption
    _ErrorString\
        ERROR_CAPTION,\
        "Critical error"

.CODE

; --- Whirr error handler ---
; Display a fixed error message and then exit the process
_EnterProc WhirrError, 0

    xor rcx, rcx
    lea r8, ERROR_CAPTION
    xor r9, r9
    call MessageBox

    xor rcx, rcx
    call ExitProcess

_LeaveProc WhirrError
; ---