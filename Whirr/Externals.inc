; --- Common ---

    GetCurrentProcess                           PROTO STDCALL
    GetModuleHandle                             EQU GetModuleHandleW
    GetModuleHandleW                            PROTO STDCALL
    CloseHandle                                 PROTO STDCALL
    ExitProcess                                 PROTO STDCALL
    MessageBox                                  EQU MessageBoxW
    MessageBoxW                                 PROTO STDCALL
    GetLastError                                PROTO STDCALL

; --- Heaps ---

    GetProcessHeap                              PROTO STDCALL

    HeapAlloc                                   PROTO STDCALL
    HeapCreate                                  PROTO STDCALL
    HeapDestroy                                 PROTO STDCALL
    HeapFree                                    PROTO STDCALL
    HeapReAlloc                                 PROTO STDCALL

    ; Heap_ flags
    HEAP_NO_SERIALIZE                           EQU 00000001h
    HEAP_GENERATE_EXCEPTIONS                    EQU 00000004h
    HEAP_ZERO_MEMORY                            EQU 00000008h

; --- Commandline functionality ---

    GetCommandLine                              EQU GetCommandLineW
    GetCommandLineW                             PROTO STDCALL
    CommandLineToArgvW                          PROTO STDCALL
    LocalFree                                   PROTO STDCALL

; --- Events ---

    CreateEvent                                 EQU CreateEventW
    CreateEventW                                PROTO STDCALL
    SetEvent                                    PROTO STDCALL
    ResetEvent                                  PROTO STDCALL

; --- Threads ---

    CreateThread                                PROTO STDCALL
    ResumeThread                                PROTO STDCALL
    GetCurrentThread                            PROTO STDCALL
    SetPriorityClass                            PROTO STDCALL
    SwitchToThread                              PROTO STDCALL

    ; Thread functions flags
    CREATE_SUSPENDED                            EQU 4
    ABOVE_NORMAL_PRIORITY_CLASS                 EQU 00008000h

; --- Gating ---

    WaitForSingleObject                         PROTO STDCALL
    WaitForMultipleObjects                      PROTO STDCALL
    SleepEx                                     PROTO STDCALL

; --- Cursor ---

    SetCursor                                   PROTO STDCALL
    ShowCursor                                  PROTO STDCALL
    SetCursorPos                                PROTO STDCALL
    GetCursorPos                                PROTO STDCALL
    UpdateWindow                                PROTO STDCALL
    ShowWindow                                  PROTO STDCALL

    SW_HIDE                                     EQU 0h
    SW_SHOWNORMAL                               EQU 001h

    SetCapture                                  PROTO STDCALL
    ReleaseCapture                              PROTO STDCALL
    ClipCursor                                  PROTO STDCALL

; --- Windows ---

    RegisterClassEx                             EQU RegisterClassExW
    RegisterClassExW                            PROTO STDCALL
    UnregisterClass                             EQU UnregisterClassW
    UnregisterClassW                            PROTO STDCALL

    ; Control styles
    CS_OWNDC                                    EQU 00020h
    CS_NOCLOSE                                  EQU 00200h
    CS_HREDRAW                                  EQU 00002h
    CS_VREDRAW                                  EQU 00001h
    CS_DBLCLK                                   EQU 00008h

    CreateWindow                                EQU CreateWindowW
    CreateWindowW                               PROTO STDCALL
    CreateWindowEx                              EQU CreateWindowExW
    CreateWindowExW                             PROTO STDCALL
    DestroyWindow                               PROTO STDCALL
    GetClientRect                               PROTO STDCALL
    GetWindowRect                               PROTO STDCALL

    ; Use default value
    CW_USEDEFAULT                               EQU 080000000h

    ; Window styles
    WS_BORDER                                   EQU 000800000h
    WS_CAPTION                                  EQU 000C00000h
    WS_DISABLED                                 EQU 008000000h
    WS_MINIMIZEBOX                              EQU 000020000h
    WS_MAXIMIZEBOX                              EQU 000010000h
    WS_OVERLAPPEDWINDOW                         EQU WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX
    WS_POPUP                                    EQU 080000000h
    WS_POPUPWINDOW                              EQU WS_POPUP OR WS_BORDER OR WS_SYSMENU
    WS_SYSMENU                                  EQU 000080000h
    WS_THICKFRAME                               EQU 000040000h
    WS_VISIBLE                                  EQU 010000000h

    ; Extended window styles
    WS_EX_LAYERED                               EQU 000080000h
    WS_EX_TOOLWINDOW                            EQU 000000080h

    ; Window messages
    WM_STATE                                    EQU 0000h
    WM_NULL                                     EQU 0000h
    WM_CREATE                                   EQU 0001h
    WM_DESTROY                                  EQU 0002h
    WM_MOVE                                     EQU 0003h
    WM_SIZE                                     EQU 0005h
    WM_ACTIVATE                                 EQU 0006h
    WM_SETFOCUS                                 EQU 0007h
    WM_KILLFOCUS                                EQU 0008h
    WM_ENABLE                                   EQU 000Ah
    WM_SETREDRAW                                EQU 000Bh
    WM_SETTEXT                                  EQU 000Ch
    WM_GETTEXT                                  EQU 000Dh
    WM_GETTEXTLENGTH                            EQU 000Eh
    WM_PAINT                                    EQU 000Fh
    WM_CLOSE                                    EQU 0010h
    WM_QUERYENDSESSION                          EQU 0011h
    WM_QUIT                                     EQU 0012h
    WM_QUERYOPEN                                EQU 0013h
    WM_ERASEBKGND                               EQU 0014h
    WM_SYSCOLORCHANGE                           EQU 0015h
    WM_ENDSESSION                               EQU 0016h
    WM_SYSTEMERROR                              EQU 0017h
    WM_SHOWWINDOW                               EQU 0018h
    WM_CTLCOLOR                                 EQU 0019h
    WM_WININICHANGE                             EQU 001Ah
    WM_DEVMODECHANGE                            EQU 001Bh
    WM_ACTIVATEAPP                              EQU 001Ch
    WM_FONTCHANGE                               EQU 001Dh
    WM_TIMECHANGE                               EQU 001Eh
    WM_CANCELMODE                               EQU 001Fh
    WM_SETCURSOR                                EQU 0020h
    WM_MOUSEACTIVATE                            EQU 0021h
    WM_CHILDACTIVATE                            EQU 0022h
    WM_QUEUESYNC                                EQU 0023h
    WM_GETMINMAXINFO                            EQU 0024h
    WM_PAINTICON                                EQU 0026h
    WM_ICONERASEBKGND                           EQU 0027h
    WM_NEXTDLGCTL                               EQU 0028h
    WM_SPOOLERSTATUS                            EQU 002Ah
    WM_DRAWITEM                                 EQU 002Bh
    WM_MEASUREITEM                              EQU 002Ch
    WM_DELETEITEM                               EQU 002Dh
    WM_VKEYTOITEM                               EQU 002Eh
    WM_CHARTOITEM                               EQU 002Fh
    WM_SETFONT                                  EQU 0030h
    WM_GETFONT                                  EQU 0031h
    WM_SETHOTKEY                                EQU 0032h
    WM_QUERYDRAGICON                            EQU 0037h
    WM_COMPAREITEM                              EQU 0039h
    WM_COMPACTING                               EQU 0041h
    WM_COMMNOTIFY                               EQU 0044h
    WM_WINDOWPOSCHANGING                        EQU 0046h
    WM_WINDOWPOSCHANGED                         EQU 0047h
    WM_POWER                                    EQU 0048h
    WM_COPYDATA                                 EQU 004Ah
    WM_CANCELJOURNAL                            EQU 004Bh
    WM_NOTIFY                                   EQU 004Eh
    WM_INPUTLANGCHANGEREQUEST                   EQU 0050h
    WM_INPUTLANGCHANGE                          EQU 0051h
    WM_TCARD                                    EQU 0052h
    WM_HELP                                     EQU 0053h
    WM_USERCHANGED                              EQU 0054h
    WM_NOTIFYFORMAT                             EQU 0055h
    WM_CONTEXTMENU                              EQU 007Bh
    WM_STYLECHANGING                            EQU 007Ch
    WM_STYLECHANGED                             EQU 007Dh
    WM_DISPLAYCHANGE                            EQU 007Eh
    WM_GETICON                                  EQU 007Fh
    WM_SETICON                                  EQU 0080h
    WM_NCCREATE                                 EQU 0081h
    WM_NCDESTROY                                EQU 0082h
    WM_NCCALCSIZE                               EQU 0083h
    WM_NCHITTEST                                EQU 0084h
    WM_NCPAINT                                  EQU 0085h
    WM_NCACTIVATE                               EQU 0086h
    WM_GETDLGCODE                               EQU 0087h
    WM_NCMOUSEMOVE                              EQU 00A0h
    WM_NCLBUTTONDOWN                            EQU 00A1h
    WM_NCLBUTTONUP                              EQU 00A2h
    WM_NCLBUTTONDBLCLK                          EQU 00A3h
    WM_NCRBUTTONDOWN                            EQU 00A4h
    WM_NCRBUTTONUP                              EQU 00A5h
    WM_NCRBUTTONDBLCLK                          EQU 00A6h
    WM_NCMBUTTONDOWN                            EQU 00A7h
    WM_NCMBUTTONUP                              EQU 00A8h
    WM_NCMBUTTONDBLCLK                          EQU 00A9h
    WM_KEYFIRST                                 EQU 0100h
    WM_KEYDOWN                                  EQU 0100h
    WM_KEYUP                                    EQU 0101h
    WM_CHAR                                     EQU 0102h
    WM_DEADCHAR                                 EQU 0103h
    WM_SYSKEYDOWN                               EQU 0104h
    WM_SYSKEYUP                                 EQU 0105h
    WM_SYSCHAR                                  EQU 0106h
    WM_SYSDEADCHAR                              EQU 0107h
    WM_KEYLAST                                  EQU 0108h
    WM_INITDIALOG                               EQU 0110h
    WM_COMMAND                                  EQU 0111h
    WM_SYSCOMMAND                               EQU 0112h
    WM_TIMER                                    EQU 0113h
    WM_HSCROLL                                  EQU 0114h
    WM_VSCROLL                                  EQU 0115h
    WM_INITMENU                                 EQU 0116h
    WM_INITMENUPOPUP                            EQU 0117h
    WM_MENUSELECT                               EQU 011Fh
    WM_MENUCHAR                                 EQU 0120h
    WM_ENTERIDLE                                EQU 0121h
    WM_MENURBUTTONUP                            EQU 0122h
    WM_MENUDRAG                                 EQU 0123h
    WM_MENUGETOBJECT                            EQU 0124h
    WM_UNINITMENUPOPUP                          EQU 0125h
    WM_MENUCOMMAND                              EQU 0126h
    WM_CTLCOLORMSGBOX                           EQU 0132h
    WM_CTLCOLOREDIT                             EQU 0133h
    WM_CTLCOLORLISTBOX                          EQU 0134h
    WM_CTLCOLORBTN                              EQU 0135h
    WM_CTLCOLORDLG                              EQU 0136h
    WM_CTLCOLORSCROLLBAR                        EQU 0137h
    WM_CTLCOLORSTATIC                           EQU 0138h
    WM_MOUSEFIRST                               EQU 0200h
    WM_MOUSEMOVE                                EQU 0200h
    WM_LBUTTONDOWN                              EQU 0201h
    WM_LBUTTONUP                                EQU 0202h
    WM_LBUTTONDBLCLK                            EQU 0203h
    WM_RBUTTONDOWN                              EQU 0204h
    WM_RBUTTONUP                                EQU 0205h
    WM_RBUTTONDBLCLK                            EQU 0206h
    WM_MBUTTONDOWN                              EQU 0207h
    WM_MBUTTONUP                                EQU 0208h
    WM_MBUTTONDBLCLK                            EQU 0209h
    WM_MOUSEWHEEL                               EQU 020Ah
    WM_MOUSELAST                                EQU 020Ah
    WM_PARENTNOTIFY                             EQU 0210h
    WM_ENTERMENULOOP                            EQU 0211h
    WM_EXITMENULOOP                             EQU 0212h
    WM_NEXTMENU                                 EQU 0213h
    WM_SIZING                                   EQU 0214h
    WM_CAPTURECHANGED                           EQU 0215h
    WM_MOVING                                   EQU 0216h
    WM_POWERBROADCAST                           EQU 0218h
    WM_DEVICECHANGE                             EQU 0219h
    WM_MDICREATE                                EQU 0220h
    WM_MDIDESTROY                               EQU 0221h
    WM_MDIACTIVATE                              EQU 0222h
    WM_MDIRESTORE                               EQU 0223h
    WM_MDINEXT                                  EQU 0224h
    WM_MDIMAXIMIZE                              EQU 0225h
    WM_MDITILE                                  EQU 0226h
    WM_MDICASCADE                               EQU 0227h
    WM_MDIICONARRANGE                           EQU 0228h
    WM_MDIGETACTIVE                             EQU 0229h
    WM_MDISETMENU                               EQU 0230h
    WM_ENTERSIZEMOVE                            EQU 0231h
    WM_EXITSIZEMOVE                             EQU 0232h
    WM_DROPFILES                                EQU 0233h
    WM_MDIREFRESHMENU                           EQU 0234h
    WM_IME_SETCONTEXT                           EQU 0281h
    WM_IME_NOTIFY                               EQU 0282h
    WM_IME_CONTROL                              EQU 0283h
    WM_IME_COMPOSITIONFULL                      EQU 0284h
    WM_IME_SELECT                               EQU 0285h
    WM_IME_CHAR                                 EQU 0286h
    WM_IME_KEYDOWN                              EQU 0290h
    WM_IME_KEYUP                                EQU 0291h
    WM_MOUSEHOVER                               EQU 02A1h
    WM_MOUSELEAVE                               EQU 02A3h
    WM_CUT                                      EQU 0300h
    WM_COPY                                     EQU 0301h
    WM_PASTE                                    EQU 0302h
    WM_CLEAR                                    EQU 0303h
    WM_UNDO                                     EQU 0304h
    WM_RENDERFORMAT                             EQU 0305h
    WM_RENDERALLFORMATS                         EQU 0306h
    WM_DESTROYCLIPBOARD                         EQU 0307h
    WM_DRAWCLIPBOARD                            EQU 0308h
    WM_PAINTCLIPBOARD                           EQU 0309h
    WM_VSCROLLCLIPBOARD                         EQU 030Ah
    WM_SIZECLIPBOARD                            EQU 030Bh
    WM_ASKCBFORMATNAME                          EQU 030Ch
    WM_CHANGECBCHAIN                            EQU 030Dh
    WM_HSCROLLCLIPBOARD                         EQU 030Eh
    WM_QUERYNEWPALETTE                          EQU 030Fh
    WM_PALETTEISCHANGING                        EQU 0310h
    WM_PALETTECHANGED                           EQU 0311h
    WM_HOTKEY                                   EQU 0312h
    WM_PRINT                                    EQU 0317h
    WM_PRINTCLIENT                              EQU 0318h
    WM_HANDHELDFIRST                            EQU 0358h
    WM_HANDHELDLAST                             EQU 035Fh
    WM_AFXFIRST                                 EQU 0360h
    WM_AFXLAST                                  EQU 037Fh
    WM_PENWINFIRST                              EQU 0380h
    WM_PENWINLAST                               EQU 038Fh
    WM_COALESCE_FIRST                           EQU 0390h
    WM_COALESCE_LAST                            EQU 039Fh
    WM_USER                                     EQU 0400h

    WHEEL_DELTA                                 EQU 120

    SetWindowPos                                PROTO STDCALL
    SetWindowText                               EQU SetWindowTextW
    SetWindowTextW                              PROTO STDCALL

    HWND_BOTTOM                                 EQU 1
    HWND_NOTOPMOST                              EQU -2
    HWND_TOP                                    EQU 0
    HWND_TOPMOST                                EQU -1

    SWP_NOSIZE                                  EQU 00001h
    SWP_NOMOVE                                  EQU 00002h
    SWP_NOZORDER                                EQU 00004h
    SWP_NOREDRAW                                EQU 00008h
    SWP_NOACTIVATE                              EQU 00010h
    SWP_DRAWFRAME                               EQU 00020h
    SWP_SHOWWINDOW                              EQU 00040h
    SWP_HIDEWINDOW                              EQU 00080h
    SWP_NOCOPYBITS                              EQU 00100h
    SWP_NOREPOSITION                            EQU 00200h
    SWP_DEFERERASE                              EQU 02000h
    SWP_ASYNCWINDOWPOS                          EQU 04000h

    DefWindowProc                               EQU DefWindowProcW
    DefWindowProcW                              PROTO STDCALL

    SetLayeredWindowAttributes                  PROTO STDCALL
    UpdateLayeredWindow                         PROTO STDCALL

    ULW_COLORKEY                                EQU 1
    ULW_ALPHA                                   EQU 2
    ULW_OPAQUE                                  EQU 4

    ClientToScreen                              PROTO STDCALL
    ScreenToClient                              PROTO STDCALL

; --- Message loop ---

    GetMessage                                  EQU GetMessageW
    GetMessageW                                 PROTO STDCALL
    PeekMessage                                 EQU PeekMessageW
    PeekMessageW                                PROTO STDCALL
    TranslateMessage                            PROTO STDCALL
    DispatchMessage                             EQU DispatchMessageW
    DispatchMessageW                            PROTO STDCALL
    PostMessage                                 EQU PostMessageW
    PostMessageW                                PROTO STDCALL
    PostThreadMessage                           EQU PostThreadMessageW
    PostThreadMessageW                          PROTO STDCALL
    PostQuitMessage                             PROTO STDCALL

; --- Resources ---

    LoadImage                                   EQU LoadImageW
    LoadImageW                                  PROTO STDCALL

    ; Type
    IMAGE_BITMAP                                EQU 0
    IMAGE_ICON                                  EQU 1
    IMAGE_CURSOR                                EQU 2

    ; Load parameters
    LR_DEFAULTCOLOR                             EQU 0
    LR_CREATEDIBSECTION                         EQU 000002000h
    LR_DEFAULTSIZE                              EQU 000000040h
    LR_LOADFROMFILE                             EQU 000000010h
    LR_SHARED                                   EQU 000008000h

    LoadCursor                                  EQU LoadCursorW
    LoadCursorW                                 PROTO STDCALL

    IDC_ARROW                                   EQU 32512
    IDC_IBEAM                                   EQU 32513
    IDC_WAIT                                    EQU 32514
    IDC_CROSS                                   EQU 32515
    IDC_UPARROW                                 EQU 32516
    IDC_SIZE                                    EQU 32640
    IDC_ICON                                    EQU 32641
    IDC_SIZENWSE                                EQU 32642
    IDC_SIZENESW                                EQU 32643
    IDC_SIZEWE                                  EQU 32644
    IDC_SIZENS                                  EQU 32645
    IDC_NO                                      EQU 32648
    IDC_HAND                                    EQU 32649
    IDC_APPSTARTING                             EQU 32650
    IDC_HELP                                    EQU 32651

    LoadIcon                                    EQU LoadIconW
    LoadIconW                                   PROTO STDCALL

    IDI_APPLICATION                             EQU 32512
    IDI_HAND                                    EQU 32513
    IDI_QUESTION                                EQU 32514
    IDI_EXCLAMATION                             EQU 32515
    IDI_ASTERISK                                EQU 32516
    IDI_WINLOGO                                 EQU 32517

; --- Timing ---

    QueryPerformanceFrequency                   PROTO STDCALL
    QueryPerformanceCounter                     PROTO STDCALL
    GetTickCount64                              PROTO STDCALL

; --- System info ---

    GetSystemMetrics                            PROTO STDCALL

    SM_CXSCREEN                                 EQU 0
    SM_CYSCREEN                                 EQU 1
    SM_CXVSCROLL                                EQU 2
    SM_CYHSCROLL                                EQU 3
    SM_CYCAPTION                                EQU 4
    SM_CXBORDER                                 EQU 5
    SM_CYBORDER                                 EQU 6
    SM_CXDLGFRAME                               EQU 7
    SM_CYDLGFRAME                               EQU 8
    SM_CYVTHUMB                                 EQU 9
    SM_CXHTHUMB                                 EQU 10
    SM_CXICON                                   EQU 11
    SM_CYICON                                   EQU 12
    SM_CXCURSOR                                 EQU 13
    SM_CYCURSOR                                 EQU 14
    SM_CYMENU                                   EQU 15
    SM_CXFULLSCREEN                             EQU 16
    SM_CYFULLSCREEN                             EQU 17
    SM_CYKANJIWINDOW                            EQU 18
    SM_MOUSEPRESENT                             EQU 19
    SM_CYVSCROLL                                EQU 20
    SM_CXHSCROLL                                EQU 21
    SM_DEBUG                                    EQU 22
    SM_SWAPBUTTON                               EQU 23
    SM_RESERVED1                                EQU 24
    SM_RESERVED2                                EQU 25
    SM_RESERVED3                                EQU 26
    SM_RESERVED4                                EQU 27
    SM_CXMIN                                    EQU 28
    SM_CYMIN                                    EQU 29
    SM_CXSIZE                                   EQU 30
    SM_CYSIZE                                   EQU 31
    SM_CXFRAME                                  EQU 32
    SM_CYFRAME                                  EQU 33
    SM_CXMINTRACK                               EQU 34
    SM_CYMINTRACK                               EQU 35
    SM_CXDOUBLECLK                              EQU 36
    SM_CYDOUBLECLK                              EQU 37
    SM_CXICONSPACING                            EQU 38
    SM_CYICONSPACING                            EQU 39
    SM_MENUDROPALIGNMENT                        EQU 40
    SM_PENWINDOWS                               EQU 41
    SM_DBCSENABLED                              EQU 42
    SM_CMOUSEBUTTONS                            EQU 43
    SM_CXFIXEDFRAME                             EQU SM_CXDLGFRAME
    SM_CYFIXEDFRAME                             EQU SM_CYDLGFRAME
    SM_CXSIZEFRAME                              EQU SM_CXFRAME
    SM_CYSIZEFRAME                              EQU SM_CYFRAME
    SM_SECURE                                   EQU 44
    SM_CXEDGE                                   EQU 45
    SM_CYEDGE                                   EQU 46
    SM_CXMINSPACING                             EQU 47
    SM_CYMINSPACING                             EQU 48
    SM_CXSMICON                                 EQU 49
    SM_CYSMICON                                 EQU 50
    SM_CYSMCAPTION                              EQU 51
    SM_CXSMSIZE                                 EQU 52
    SM_CYSMSIZE                                 EQU 53
    SM_CXMENUSIZE                               EQU 54
    SM_CYMENUSIZE                               EQU 55
    SM_ARRANGE                                  EQU 56
    SM_CXMINIMIZED                              EQU 57
    SM_CYMINIMIZED                              EQU 58
    SM_CXMAXTRACK                               EQU 59
    SM_CYMAXTRACK                               EQU 60
    SM_CXMAXIMIZED                              EQU 61
    SM_CYMAXIMIZED                              EQU 62
    SM_NETWORK                                  EQU 63
    SM_CLEANBOOT                                EQU 67
    SM_CXDRAG                                   EQU 68
    SM_CYDRAG                                   EQU 69
    SM_SHOWSOUNDS                               EQU 70
    SM_CXMENUCHECK                              EQU 71
    SM_CYMENUCHECK                              EQU 72
    SM_SLOWMACHINE                              EQU 73
    SM_MIDEASTENABLED                           EQU 74
    SM_MOUSEWHEELPRESENT                        EQU 75
    SM_CMETRICS                                 EQU 76

    GetMonitorInfo                              EQU GetMonitorInfoW
    GetMonitorInfoW                             PROTO STDCALL
    MonitorFromWindow                           PROTO STDCALL

    MONITOR_DEFAULTTONEAREST                    EQU 2
    MONITOR_DEFAULTTONULL                       EQU 0
    MONITOR_DEFAULTTOPRIMARY                    EQU 1

    GetSystemInfo                               PROTO STDCALL

; --- Keys ---

    CharLowerBuff                               EQU CharLowerBuffW
    CharLowerBuffW                              PROTO STDCALL
    CharUpperBuff                               EQU CharUpperBuffW
    CharUpperBuffW                              PROTO STDCALL
    MapVirtualKey                               EQU MapVirtualKeyW
    MapVirtualKeyW                              PROTO STDCALL
    GetKeyNameText                              EQU GetKeyNameTextW
    GetKeyNameTextW                             PROTO STDCALL

    MAPVK_VK_TO_VSC                             EQU 0
    MAPVK_VSC_TO_VK_EX                          EQU 3
    MAPVK_VK_TO_VSC_EX                          EQU 4

; --- Structs ---

    POINT STRUCT
        x                                       DD 0
        y                                       DD 0
    POINT ENDS

    RECT STRUCT
        left                                    DD 0
        top                                     DD 0
        right                                   DD 0
        bottom                                  DD 0
    RECT ENDS

    WNDCLASSEX STRUCT
        cbSize                                  DD ?
        style                                   DD ?
        lpfnWndProc                             DQ ?
        cbClsExtra                              DD ?
        cbWndExtra                              DD ?
        hInstance                               DQ ?
        hIcon                                   DQ ?
        hCursor                                 DQ ?
        hbrBackground                           DQ ?
        lpszMenuName                            DQ ?
        lpszClassName                           DQ ?
        hIconSm                                 DQ ?
    WNDCLASSEX ENDS

    CREATESTRUCT STRUCT
        lpCreateParams                          DQ ?
        hInstance                               DQ ?
        hMenu                                   DQ ?
        hwndParent                              DQ ?
        csy                                     DD ?
        csx                                     DD ?
        y                                       DD ?
        x                                       DD ?
        style                                   DD ?
                                                DD ?
        lpszName                                DQ ?
        lpszClass                               DQ ?
        dwExStyle                               DD ?
                                                DD ?
    CREATESTRUCT ENDS

    MESSAGE STRUCT
        hwnd                                    DQ ?
        message                                 DD ?
                                                DD ?
        wParam                                  DQ ?
        lParam                                  DQ ?
        time                                    DD ?
        pt                                      POINT {}
                                                DD ?
    MESSAGE ENDS

    MONITORINFO STRUCT
        cbSize                                  DD ?
        rcMonitor                               RECT {}
        rcWork                                  RECT {}
        dwFlags                                 DD ?
    MONITORINFO ENDS

    SYSTEM_INFO STRUCT
        dwProcessorArchitecture                 DW ?
        dwReserved                              DW ?
        dwPageSize                              DD ?
        lpMinimumApplicationAddress             DQ ?
        lpMaximumApplicationAddress             DQ ?
        dwActiveProcessorMask                   DQ ?
        dwNumberOfProcessors                    DD ?
        dwProcessorType                         DD ?
        dwAllocationGranularity                 DD ?
        wProcessorLevel                         DW ?
        wProcessorRevision                      DW ?
    SYSTEM_INFO ENDS