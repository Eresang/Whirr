include Macros.inc

include Defines.inc
include Externals.inc

include COM.inc

include Heaps.inc
include Strings.inc

include Random.inc

.DATA
    ALIGN 8
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAPHANDLE                            DQ ?

    WHIRR_HWND                                  DQ ?

    _String\
        WHIRR_WINDOWCLASSNAME,\
        "WhirrWindowClass"

    _String\
        WHIRR_TITLE,\
        "Whirr"

    ALIGN 8
    WHIRR_WINDOWCLASS WNDCLASSEX\
    {   sizeof WNDCLASSEX,\
        CS_HREDRAW or CS_VREDRAW or CS_DBLCLK,\
        WhirrWindowProc,\
        0, 0, 0, 0, 0, 0, 0,\
        WHIRR_WINDOWCLASSNAME, 0}

.CODE

    WhirrWindowProc PROC
        _Enter 0
        cmp rdx, WM_CLOSE
        jne SkipClose
        xor rcx, rcx
        call PostQuitMessage
        _Leave
        SkipClose:
        call DefWindowProc
        _Leave
    WhirrWindowProc ENDP

; --- Main() ---

    WhirrProc PROC
    ; Initialize()
    ; {
        _Enter _ToBytes(8, 8), rax

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


        xor rcx, rcx
        mov rdx, rax

        lea r8, WHIRR_TITLE
        mov r9, WHIRR_MODULE

        mov rax, CW_USEDEFAULT
        mov [rsp + 20h], rax
        mov [rsp + 28h], rax
        mov [rsp + 30h], rax
        mov [rsp + 38h], rax
        mov [rsp + 40h], rcx
        mov [rsp + 48h], rcx
        mov [rsp + 50h], r9
        mov [rsp + 58h], rcx
        mov r9, WS_OVERLAPPEDWINDOW
        call CreateWindowEx
        mov WHIRR_HWND, rax

        mov rcx, rax
        mov rdx, SW_SHOWNORMAL
        call ShowWindow

        mov rcx, WHIRR_HWND
        call UpdateWindow


        MessageLoop:

            lea rcx, [rsp + 20h]
            xor rdx, rdx
            xor r8, r8
            xor r9, r9
            call GetMessage
            or rax, rax
            jz ExitMessageLoop

            lea rcx, [rsp + 20h]
            call TranslateMessage

            lea rcx, [rsp + 20h]
            call DispatchMessage

        jmp MessageLoop
        ExitMessageLoop:

    ; ---

    ; Finalize()
    ; {
        xor rcx, rcx
        call ExitProcess
        _Leave
    ; }
    WhirrProc ENDP

END