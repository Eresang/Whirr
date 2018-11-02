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

    ; Wrappers only check if arguments match their target registers
    ; Invokers should ensure:
    ;  - Register values don't get overwritten
    ;  - Stack is 16-bit aligned

; --- Heap helper macros ---

    ; HeapReAlloc wrapper
    _HeapReAlloc MACRO destination:REQ, heaphandle:REQ, data:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\ 
                 rdx, HEAP_GENERATE_EXCEPTIONS OR HEAP_ZERO_MEMORY,\
                 r8, data,\
                 r9, bytes

        call HeapReAlloc

        _ArgMove destination, rax
    ENDM

    ; HeapFree wrapper
    _HeapFree MACRO heaphandle:REQ, data:REQ
        _ArgMove rcx, heaphandle,\
                 r8, data

        xor rdx, rdx

        call HeapFree
    ENDM

    ; HeapAlloc wrapper
    _HeapAlloc MACRO destination:REQ, heaphandle:REQ, bytes:REQ
        _ArgMove rcx, heaphandle,\
                 rdx, HEAP_GENERATE_EXCEPTIONS OR HEAP_ZERO_MEMORY,\
                 r8, bytes

        call HeapAlloc

        _ArgMove destination, rax
    ENDM

    ; HeapCreate wrapper
    _HeapCreate MACRO destination:REQ
        mov rcx, HEAP_GENERATE_EXCEPTIONS
        xor rdx, rdx
        xor r8, r8

        call HeapCreate

        _ArgMove destination, rax
    ENDM

    ; HeapDestroy wrapper
    _HeapDestroy MACRO heaphandle:REQ
        _ArgMove rcx, heaphandle

        call HeapDestroy
    ENDM