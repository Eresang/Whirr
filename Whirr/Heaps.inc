    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-byte aligned

; --- Heap helper macros ---

    ; HeapReAlloc wrapper
    _HeapReAlloc MACRO destination:REQ, heaphandle:REQ, data:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\ 
                 rdx, HEAP_ZERO_MEMORY,\
                 r8, data,\
                 r9, bytes

        call HeapReAlloc
        _ErrorIfZero rax, ERROR_HEAPREALLOC

        _ArgMove destination, rax
    ENDM

    ; HeapFree wrapper
    _HeapFree MACRO heaphandle:REQ, data:REQ
        _ArgMove rcx, heaphandle,\
                 r8, data

        xor rdx, rdx

        call HeapFree
        _ErrorIfZero rax, ERROR_HEAPFREE
    ENDM

    ; HeapAlloc wrapper
    _HeapAlloc MACRO destination:REQ, heaphandle:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\
                 rdx, HEAP_ZERO_MEMORY,\
                 r8, bytes

        call HeapAlloc
        _ErrorIfZero rax, ERROR_HEAPALLOC

        _ArgMove destination, rax
    ENDM

    ; HeapCreate wrapper
    _HeapCreate MACRO destination:REQ
        xor rcx, rcx
        xor rdx, rdx
        xor r8, r8

        call HeapCreate
        _ErrorIfZero rax, ERROR_HEAPCREATE

        _ArgMove destination, rax
    ENDM

    ; HeapDestroy wrapper
    _HeapDestroy MACRO heaphandle:REQ
        _ArgMove rcx, heaphandle

        call HeapDestroy
        _ErrorIfZero rax, ERROR_HEAPDESTROY
    ENDM

; Error strings
    _ErrorString\
        ERROR_HEAPREALLOC,\
        "HeapReAlloc failed"
    _ErrorString\
        ERROR_HEAPFREE,\
        "HeapFree failed"
    _ErrorString\
        ERROR_HEAPALLOC,\
        "HeapAlloc failed"
    _ErrorString\
        ERROR_HEAPCREATE,\
        "HeapCreate failed"
    _ErrorString\
        ERROR_HEAPDESTROY,\
        "HeapDestroy failed"

.CODE