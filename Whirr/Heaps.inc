    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-bit aligned

; --- Heap helper macros ---

    ; HeapReAlloc wrapper
    _HeapReAlloc MACRO destination:REQ, heaphandle:REQ, data:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\ 
                 rdx, HEAP_ZERO_MEMORY,\
                 r8, data,\
                 r9, bytes

        call HeapReAlloc
        ; TODO -> ERRORCHECK (rax == null -> error)

        _ArgMove destination, rax
    ENDM

    ; HeapFree wrapper
    _HeapFree MACRO heaphandle:REQ, data:REQ
        _ArgMove rcx, heaphandle,\
                 r8, data

        xor rdx, rdx

        call HeapFree
        ; TODO -> ERRORCHECK (rax == null -> error)
    ENDM

    ; HeapAlloc wrapper
    _HeapAlloc MACRO destination:REQ, heaphandle:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\
                 rdx, HEAP_ZERO_MEMORY,\
                 r8, bytes

        call HeapAlloc
        ; TODO -> ERRORCHECK (rax == null -> error)

        _ArgMove destination, rax
    ENDM

    ; HeapCreate wrapper
    _HeapCreate MACRO destination:REQ
        xor rcx, rcx
        xor rdx, rdx
        xor r8, r8

        call HeapCreate
        ; TODO -> ERRORCHECK (rax == null -> error)

        _ArgMove destination, rax
    ENDM

    ; HeapDestroy wrapper
    _HeapDestroy MACRO heaphandle:REQ
        _ArgMove rcx, heaphandle

        call HeapDestroy
        ; TODO -> ERRORCHECK (rax == null -> error)
    ENDM

.DATA

.CODE