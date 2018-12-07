.DATA\

    ALIGN 8
    WHIRR_HWND                                  DQ ?

    _String\
        WHIRR_WNDCLASSNAME,\
        "WhirrWindowClass"

    ALIGN 8
    WHIRR_WNDCLASS WNDCLASSEX\
        {sizeof WNDCLASSEX,\
        CS_HREDRAW or CS_VREDRAW,\
        WhirrWindowProc,\
        0, 0, 0, 0, 0, 0, 0,\
        WHIRR_WNDCLASSNAME, 0}

    ALIGN 8
    WHIRR_FACTORY DQ 0
    WHIRR_ADAPTER DQ 0

.CODE

; --- Window message handling ---

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

; --- Create window class and a window belonging to it ---

    WhirrWindowCreate PROC
        _Enter 64
        mov rcx, WHIRR_MODULE
        lea rdx, WHIRR_WNDCLASSNAME

        mov WHIRR_WNDCLASS.hInstance, rcx
        mov WHIRR_WNDCLASS.lpszClassName, rdx

        ; Get appropiate icon dimensions
        mov rcx, SM_CXICON
        call GetSystemMetrics
        mov [rsp + 20h], rax
        mov rcx, SM_CYICON
        call GetSystemMetrics
        mov r9, rax

        ; Get icon
        mov rax, LR_SHARED
        mov rcx, WHIRR_MODULE
        mov rdx, 101
        mov r8, IMAGE_ICON
        mov [rsp + 28h], rax
        call LoadImage
        mov WHIRR_WNDCLASS.hIcon, rax       ; Ignore errors; just use default icon

        ; Get cursor
        mov rax, LR_SHARED
        xor r9, r9
        xor rcx, rcx
        mov rdx, IDC_ARROW
        mov r8, IMAGE_CURSOR
        mov [rsp + 20h], r9
        mov [rsp + 28h], rax
        call LoadImage
        mov WHIRR_WNDCLASS.hCursor, rax     ; Ignore errors; just use default cursor

        lea rcx, WHIRR_WNDCLASS
        call RegisterClassEx
        ; TODO -> ERRORCHECK (rax == null -> error)

        xor rcx, rcx                ; Extra styles
        mov rdx, rax                ; Class atom/name
        lea r8, WHIRR_TITLE         ; Window title
        mov r9, WHIRR_MODULE        ; Temporary use
        mov rax, CW_USEDEFAULT
        mov [rsp + 20h], rax        ; X position
        mov [rsp + 28h], rax        ; Y position
        mov [rsp + 30h], rax        ; Width
        mov [rsp + 38h], rax        ; Height
        mov [rsp + 40h], rcx        ; Parent window
        mov [rsp + 48h], rcx        ; Menu handle
        mov [rsp + 50h], r9         ; Module
        mov [rsp + 58h], rcx        ; WM_CREATE message lParam
        mov r9, WS_OVERLAPPEDWINDOW ; Window style
        call CreateWindowEx
        mov WHIRR_HWND, rax
        ; TODO -> ERRORCHECK (rax == null -> error)

        _Leave
    WhirrWindowCreate ENDP

; --- Window message loop ---

    WhirrMessageLoop PROC
        _Enter sizeof(MESSAGE)

        WhirrMessageLoop_Loop:
            lea rcx, [rsp + 20h]
            xor rdx, rdx
            xor r8, r8
            xor r9, r9
            call GetMessage
            or rax, rax
            jz WhirrMessageLoop_Break

            lea rcx, [rsp + 20h]
            call TranslateMessage

            lea rcx, [rsp + 20h]
            call DispatchMessage
        jmp WhirrMessageLoop_Loop
        WhirrMessageLoop_Break:

        _Leave
    WhirrMessageLoop ENDP

; --- Load pipeline ---

    WhirrLoadPipeline PROC
        _Enter 16 + sizeof DXGI_ADAPTER_DESC1 

        lea rcx, IDXGIFactory4
        lea rdx, WHIRR_FACTORY
        call CreateDXGIFactory1
        ; TODO -> ERRORCHECK (rax != null -> error)

        ; Find first adapter that supports D3D12
        xor rax, rax
        mov [rsp + 20h], rax
        mov [rsp + 28h], rax

        WhirrLoadPipeline_Loop:
            ; Get next adapter
            mov rdx, [rsp + 20h]
            lea r8, [rsp + 28h]
            _CallCom WHIRR_FACTORY, IDXGIFactory4, EnumAdapters1
            cmp eax, DXGI_ERROR_NOT_FOUND
            je WhirrLoadPipeline_Break1

            ; Check if adapter is software
            lea rdx, [rsp + 30h]
            _CallCom [rsp + 28h], IDXGIAdapter1, GetDesc1

            mov eax, DXGI_ADAPTER_FLAG_SOFTWARE
            and eax, [rsp + 30h].DXGI_ADAPTER_DESC1._Flags
            jnz WhirrLoadPipeline_Loop

            ; Check D3D12 support (feature level 11)
            mov rcx, [rsp + 28h]
            mov rdx, D3D_FEATURE_LEVEL_11_0
            lea r8, ID3D12Device
            xor r9, r9
            call D3D12CreateDevice
            or eax, eax                     ; eax < 0 == unable to create device
            jns WhirrLoadPipeline_Break2    ; No error? Break

            _CallCom [rsp + 28h], IDXGIAdapter1, Release
            inc QWORD PTR [rsp + 20h]
        jmp WhirrLoadPipeline_Loop
        WhirrLoadPipeline_Break2:
        _CallCom [rsp + 28h], IDXGIAdapter1, Release

        WhirrLoadPipeline_Break1:

        _CallCom WHIRR_FACTORY, IDXGIFactory4, Release

        _Leave
    WhirrLoadPipeline ENDP