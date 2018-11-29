include Macros.inc

include Defines.inc
include Externals.inc

include Heaps.inc
include Strings.inc

include Random.inc

.DATA
    WHIRR_MODULE                                DQ ?
    WHIRR_HEAPHANDLE                            DQ ?

    _String\
        WHIRR_WINDOWCLASS,\
        "WhirrWindowClass"

    _String\
        WHIRR_TITLE,\
        "Whirr"

.CODE

    WhirrProc PROC
        xor rcx, rcx
        call GetModuleHandle
        mov WHIRR_MODULE, rax

        call GetProcessHeap
        mov WHIRR_HEAPHANDLE, rax

        mov rcx, 10000000000000

        @Loop:
            _Random rdx
            or edx, edx
            jz @Exit
        loop @Loop

        @Exit:
        xor rcx, rcx
        call ExitProcess
        ret
    WhirrProc ENDP

END