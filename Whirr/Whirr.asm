include Macros.inc
include Heaps.inc

include Random.inc

.DATA
    WhirrHeapHandle                             DQ 0

; TEST
    HeapData                                    DQ ?

.CODE

    WhirrProc PROC
        call GetProcessHeap
        mov WhirrHeapHandle, rax

        mov rax, OPATTR(rcx)

        lea rcx, WhirrHeapHandle
        _Randomize rcx

        _HeapAlloc HeapData, WhirrHeapHandle, 10000h

        ret
    WhirrProc ENDP

END