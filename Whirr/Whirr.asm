include Defines.inc
include Macros.inc

include Externals.inc

include COM.inc

include DXGI.inc
include D3D.inc
include D3D12.inc

include FXP.inc
include Heaps.inc
include Strings.inc

include Random.inc
include Window.inc

.DATA
    ALIGN 8
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAP                                  DQ ?

    _String\
        WHIRR_TITLE,\
        "Whirr"

.CODE

; --- Main() ---

    WhirrProc PROC
        _Enter _ToBytes(8, 8)

    ; Initialize()
    ; {
        xor rcx, rcx
        call GetModuleHandle
        mov WHIRR_MODULE, rax

        call GetProcessHeap
        mov WHIRR_HEAP, rax
    ; }

    ; ---

        mov rax, _FXP(1, 58)
        _FXPTan rax, rax, 60

        mov rdx, 1 SHL 49 ; 2
        mov rcx, 1 SHL 50 ; 4
        _FXPDiv rax, rcx, rdx ; 4 / 2
        or rax, rax

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
    ; }

        _Leave
    WhirrProc ENDP

END