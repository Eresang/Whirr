include Defines.inc
include Macros.inc
include Externals.inc
include Strings.inc

include COM.inc

include RIID.inc
include DXGI.inc
include D3D.inc
include D3D12.inc

include Error.inc
include Heaps.inc

include FXP.inc
include Random.inc
include Time.inc
include Window.inc

.DATA
    ALIGN 8
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAP                                  DQ ?

    _String\
        WHIRR_TITLE,\
        "Whirr"

; Trigger plausible commit

.CODE

; --- START Main()
_EnterProc WhirrProc, 0

    ; Initialize()
    ; {
        xor rcx, rcx
        call GetModuleHandle
        ; _ErrorIfZero rax, ERROR_GETMODULEHANDLE
        mov WHIRR_MODULE, rax

        call GetProcessHeap
        ; _ErrorIfZero rax, ERROR_GETPROCESSHEAP
        mov WHIRR_HEAP, rax

        call WhirrWindowCreate

        _TimeInitiate

        IF RANDOMIZEATSTART EQ TRUE
            _Randomize
        ENDIF
    ; }

    ; ---

        mov rcx, WHIRR_HWND
        mov rdx, SW_SHOWNORMAL
        call ShowWindow
        mov rcx, WHIRR_HWND
        call UpdateWindow

        call WhirrLoadPipeline

        call WhirrMessageLoop

    ; ---

    ; Finalize()
    ; {
        xor rcx, rcx
        call ExitProcess
    ; }

_LeaveProc WhirrProc
; --- END Main()

END