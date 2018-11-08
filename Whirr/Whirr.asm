include Macros.inc
include Heaps.inc
include Strings.inc

include Random.inc

.DATA
    WHIRR_HEAPHANDLE                            DQ ?

    _String WHIRR_TITLE, "Whirr"

; TEST
    HeapData                                    DQ ?

.CODE

    WhirrProc PROC
        call GetProcessHeap
        mov WHIRR_HEAPHANDLE, rax

        lea rcx, WHIRR_TITLE
        or rax, rax

        _HeapAlloc\
            HeapData,\
            WHIRR_HEAPHANDLE,\
            10000h

        ret
    WhirrProc ENDP

END