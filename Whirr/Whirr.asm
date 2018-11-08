include Macros.inc
include Heaps.inc
include Strings.inc

include Random.inc

.DATA
    WHIRR_HEAPHANDLE                            DQ 0

    _String WHIRR_TEXT,\
                  """A quoted string!!""\n",\
                  "Followed by an unquoted string\n"

; TEST
    HeapData                                    DQ ?

.CODE

    WhirrProc PROC
        call GetProcessHeap
        mov WHIRR_HEAPHANDLE, rax

        lea rcx, WHIRR_TEXT
        or rax, rax

        _HeapAlloc HeapData, WHIRR_HEAPHANDLE, 10000h

        ret
    WhirrProc ENDP

END