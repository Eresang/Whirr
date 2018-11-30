include Macros.inc

include Defines.inc
include Externals.inc

include COM.inc

include Heaps.inc
include Strings.inc

include Random.inc

.DATA
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAPHANDLE                            DQ ?

    _String\
        WHIRR_WINDOWCLASSNAME,\
        "WhirrWindowClass"

    _String\
        WHIRR_TITLE,\
        "Whirr"

    ALIGN 8
    WHIRR_WINDOWCLASS WNDCLASSEX\
    {   sizeof WNDCLASSEX,\
        CS_HREDRAW or CS_VREDRAW,\
        WhirrWindowProc,\
        0, 0, 0, 0, 0, 0, 0, WHIRR_WINDOWCLASSNAME, 0}

.CODE

    WhirrWindowProc PROC
        call DefWindowProc
        ret
    WhirrWindowProc ENDP

    WhirrProc PROC
    ; Initialize()
    ; {
        _Enter rcx, rdx, r8, r9

        xor rcx, rcx
        call GetModuleHandle
        mov WHIRR_MODULE, rax

        call GetProcessHeap
        mov WHIRR_HEAPHANDLE, rax
    ; }

    ; ---


        mov rcx, WHIRR_MODULE
        lea rdx, WHIRR_WINDOWCLASSNAME

        mov WHIRR_WINDOWCLASS.hInstance, rcx
        mov WHIRR_WINDOWCLASS.lpszClassName, rdx

        lea rcx, WHIRR_WINDOWCLASS
        call RegisterClassEx
        or rax, rax


    ; ---

    ; Finalize()
    ; {
        xor rcx, rcx
        call ExitProcess

        _Leave
    ; }
    WhirrProc ENDP

END