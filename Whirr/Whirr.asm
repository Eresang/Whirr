include Macros.inc

include Defines.inc
include Externals.inc

include COM.inc

include Heaps.inc
include Strings.inc
include Random.inc
include Window.inc

.DATA
    ALIGN 8
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAPHANDLE                            DQ ?

    _String\
        WHIRR_TITLE,\
        "Whirr"

.CODE

; --- Main() ---

    WhirrProc PROC
    ; Initialize()
    ; {
        _Enter _ToBytes(8, 8)

        xor rcx, rcx
        call GetModuleHandle
        mov WHIRR_MODULE, rax

        call GetProcessHeap
        mov WHIRR_HEAPHANDLE, rax
    ; }

    ; ---

        call WhirrWindowCreate

        call WhirrLoadPipeline

        mov rcx, WHIRR_HWND
        mov rdx, SW_SHOWNORMAL
        call ShowWindow

        mov rcx, WHIRR_HWND
        call UpdateWindow

        call WhirrMessageLoop

    ; ---

    ; Finalize()
    ; {
        xor rcx, rcx
        call ExitProcess
        _Leave
    ; }
    WhirrProc ENDP

END