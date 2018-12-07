    CreateDXGIFactory                               PROTO STDCALL
    CreateDXGIFactory1                              PROTO STDCALL
    CreateDXGIFactory2                              PROTO STDCALL
    DXGIDeclareAdapterRemovalSupport                PROTO STDCALL

; --- Common/format structs and values ---

    LUID                                            EQU DQ

    DXGI_ERROR_ACCESS_DENIED                        EQU 0887A002Bh
    DXGI_ERROR_ACCESS_LOST                          EQU 0887A0026h
    DXGI_ERROR_ALREADY_EXISTS                       EQU 0887A0036h
    DXGI_ERROR_CANNOT_PROTECT_CONTENT               EQU 0887A002Ah
    DXGI_ERROR_DEVICE_HUNG                          EQU 0887A0006h
    DXGI_ERROR_DEVICE_REMOVED                       EQU 0887A0005h
    DXGI_ERROR_DEVICE_RESET                         EQU 0887A0007h
    DXGI_ERROR_DRIVER_INTERNAL_ERROR                EQU 0887A0020h
    DXGI_ERROR_FRAME_STATISTICS_DISJOINT            EQU 0887A000Bh
    DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE         EQU 0887A000Ch
    DXGI_ERROR_INVALID_CALL                         EQU 0887A0001h
    DXGI_ERROR_MORE_DATA                            EQU 0887A0003h
    DXGI_ERROR_NAME_ALREADY_EXISTS                  EQU 0887A002Ch
    DXGI_ERROR_NONEXCLUSIVE                         EQU 0887A0021h
    DXGI_ERROR_NOT_CURRENTLY_AVAILABLE              EQU 0887A0022h
    DXGI_ERROR_NOT_FOUND                            EQU 0887A0002h
    DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED           EQU 0887A0023h
    DXGI_ERROR_REMOTE_OUTOFMEMORY                   EQU 0887A0024h
    DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE             EQU 0887A0029h
    DXGI_ERROR_SDK_COMPONENT_MISSING                EQU 0887A002Dh
    DXGI_ERROR_SESSION_DISCONNECTED                 EQU 0887A0028h
    DXGI_ERROR_UNSUPPORTED                          EQU 0887A0004h
    DXGI_ERROR_WAIT_TIMEOUT                         EQU 0887A0027h
    DXGI_ERROR_WAS_STILL_DRAWING                    EQU 0887A000Ah
    S_OK                                            EQU 0

    DXGI_RATIONAL STRUCT
        _Numerator                                  DD ?
        _Denominator                                DD ?
    DXGI_RATIONAL ENDS

    DXGI_STANDARD_MULTISAMPLE_QUALITY_PATTERN       EQU 0ffffffffh
    DXGI_CENTER_MULTISAMPLE_QUALITY_PATTERN         EQU 0fffffffeh

    DXGI_SAMPLE_DESC STRUCT
        _Count                                      DD ?
        _Quality                                    DD ?
    DXGI_SAMPLE_DESC ENDS

    DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709             EQU 0
    DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709             EQU 1
    DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709           EQU 2
    DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020          EQU 3
    DXGI_COLOR_SPACE_RESERVED                           EQU 4
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601      EQU 5
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601         EQU 6
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601           EQU 7
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709         EQU 8
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709           EQU 9
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020        EQU 10
    DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020          EQU 11
    DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020          EQU 12
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020      EQU 13
    DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020        EQU 14
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020     EQU 15
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020   EQU 16
    DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020            EQU 17
    DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020    EQU 18
    DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020      EQU 19
    DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709           EQU 20
    DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020          EQU 21
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709         EQU 22
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020        EQU 23
    DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020     EQU 24
    DXGI_COLOR_SPACE_CUSTOM                             EQU 0FFFFFFFFh

    DXGI_FORMAT_UNKNOWN	                                EQU 0
    DXGI_FORMAT_R32G32B32A32_TYPELESS                   EQU 1
    DXGI_FORMAT_R32G32B32A32_FLOAT                      EQU 2
    DXGI_FORMAT_R32G32B32A32_UINT                       EQU 3
    DXGI_FORMAT_R32G32B32A32_SINT                       EQU 4
    DXGI_FORMAT_R32G32B32_TYPELESS                      EQU 5
    DXGI_FORMAT_R32G32B32_FLOAT                         EQU 6
    DXGI_FORMAT_R32G32B32_UINT                          EQU 7
    DXGI_FORMAT_R32G32B32_SINT                          EQU 8
    DXGI_FORMAT_R16G16B16A16_TYPELESS                   EQU 9
    DXGI_FORMAT_R16G16B16A16_FLOAT                      EQU 10
    DXGI_FORMAT_R16G16B16A16_UNORM                      EQU 11
    DXGI_FORMAT_R16G16B16A16_UINT                       EQU 12
    DXGI_FORMAT_R16G16B16A16_SNORM                      EQU 13
    DXGI_FORMAT_R16G16B16A16_SINT                       EQU 14
    DXGI_FORMAT_R32G32_TYPELESS                         EQU 15
    DXGI_FORMAT_R32G32_FLOAT                            EQU 16
    DXGI_FORMAT_R32G32_UINT                             EQU 17
    DXGI_FORMAT_R32G32_SINT                             EQU 18
    DXGI_FORMAT_R32G8X24_TYPELESS                       EQU 19
    DXGI_FORMAT_D32_FLOAT_S8X24_UINT                    EQU 20
    DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS                EQU 21
    DXGI_FORMAT_X32_TYPELESS_G8X24_UINT                 EQU 22
    DXGI_FORMAT_R10G10B10A2_TYPELESS                    EQU 23
    DXGI_FORMAT_R10G10B10A2_UNORM                       EQU 24
    DXGI_FORMAT_R10G10B10A2_UINT                        EQU 25
    DXGI_FORMAT_R11G11B10_FLOAT                         EQU 26
    DXGI_FORMAT_R8G8B8A8_TYPELESS                       EQU 27
    DXGI_FORMAT_R8G8B8A8_UNORM                          EQU 28
    DXGI_FORMAT_R8G8B8A8_UNORM_SRGB                     EQU 29
    DXGI_FORMAT_R8G8B8A8_UINT                           EQU 30
    DXGI_FORMAT_R8G8B8A8_SNORM                          EQU 31
    DXGI_FORMAT_R8G8B8A8_SINT                           EQU 32
    DXGI_FORMAT_R16G16_TYPELESS                         EQU 33
    DXGI_FORMAT_R16G16_FLOAT                            EQU 34
    DXGI_FORMAT_R16G16_UNORM                            EQU 35
    DXGI_FORMAT_R16G16_UINT                             EQU 36
    DXGI_FORMAT_R16G16_SNORM                            EQU 37
    DXGI_FORMAT_R16G16_SINT                             EQU 38
    DXGI_FORMAT_R32_TYPELESS                            EQU 39
    DXGI_FORMAT_D32_FLOAT                               EQU 40
    DXGI_FORMAT_R32_FLOAT                               EQU 41
    DXGI_FORMAT_R32_UINT                                EQU 42
    DXGI_FORMAT_R32_SINT                                EQU 43
    DXGI_FORMAT_R24G8_TYPELESS                          EQU 44
    DXGI_FORMAT_D24_UNORM_S8_UINT                       EQU 45
    DXGI_FORMAT_R24_UNORM_X8_TYPELESS                   EQU 46
    DXGI_FORMAT_X24_TYPELESS_G8_UINT                    EQU 47
    DXGI_FORMAT_R8G8_TYPELESS                           EQU 48
    DXGI_FORMAT_R8G8_UNORM                              EQU 49
    DXGI_FORMAT_R8G8_UINT                               EQU 50
    DXGI_FORMAT_R8G8_SNORM                              EQU 51
    DXGI_FORMAT_R8G8_SINT                               EQU 52
    DXGI_FORMAT_R16_TYPELESS                            EQU 53
    DXGI_FORMAT_R16_FLOAT                               EQU 54
    DXGI_FORMAT_D16_UNORM                               EQU 55
    DXGI_FORMAT_R16_UNORM                               EQU 56
    DXGI_FORMAT_R16_UINT                                EQU 57
    DXGI_FORMAT_R16_SNORM                               EQU 58
    DXGI_FORMAT_R16_SINT                                EQU 59
    DXGI_FORMAT_R8_TYPELESS                             EQU 60
    DXGI_FORMAT_R8_UNORM                                EQU 61
    DXGI_FORMAT_R8_UINT                                 EQU 62
    DXGI_FORMAT_R8_SNORM                                EQU 63
    DXGI_FORMAT_R8_SINT                                 EQU 64
    DXGI_FORMAT_A8_UNORM                                EQU 65
    DXGI_FORMAT_R1_UNORM                                EQU 66
    DXGI_FORMAT_R9G9B9E5_SHAREDEXP                      EQU 67
    DXGI_FORMAT_R8G8_B8G8_UNORM                         EQU 68
    DXGI_FORMAT_G8R8_G8B8_UNORM                         EQU 69
    DXGI_FORMAT_BC1_TYPELESS                            EQU 70
    DXGI_FORMAT_BC1_UNORM                               EQU 71
    DXGI_FORMAT_BC1_UNORM_SRGB                          EQU 72
    DXGI_FORMAT_BC2_TYPELESS                            EQU 73
    DXGI_FORMAT_BC2_UNORM                               EQU 74
    DXGI_FORMAT_BC2_UNORM_SRGB                          EQU 75
    DXGI_FORMAT_BC3_TYPELESS                            EQU 76
    DXGI_FORMAT_BC3_UNORM                               EQU 77
    DXGI_FORMAT_BC3_UNORM_SRGB                          EQU 78
    DXGI_FORMAT_BC4_TYPELESS                            EQU 79
    DXGI_FORMAT_BC4_UNORM                               EQU 80
    DXGI_FORMAT_BC4_SNORM                               EQU 81
    DXGI_FORMAT_BC5_TYPELESS                            EQU 82
    DXGI_FORMAT_BC5_UNORM                               EQU 83
    DXGI_FORMAT_BC5_SNORM                               EQU 84
    DXGI_FORMAT_B5G6R5_UNORM                            EQU 85
    DXGI_FORMAT_B5G5R5A1_UNORM                          EQU 86
    DXGI_FORMAT_B8G8R8A8_UNORM                          EQU 87
    DXGI_FORMAT_B8G8R8X8_UNORM                          EQU 88
    DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM              EQU 89
    DXGI_FORMAT_B8G8R8A8_TYPELESS                       EQU 90
    DXGI_FORMAT_B8G8R8A8_UNORM_SRGB                     EQU 91
    DXGI_FORMAT_B8G8R8X8_TYPELESS                       EQU 92
    DXGI_FORMAT_B8G8R8X8_UNORM_SRGB                     EQU 93
    DXGI_FORMAT_BC6H_TYPELESS                           EQU 94
    DXGI_FORMAT_BC6H_UF16                               EQU 95
    DXGI_FORMAT_BC6H_SF16                               EQU 96
    DXGI_FORMAT_BC7_TYPELESS                            EQU 97
    DXGI_FORMAT_BC7_UNORM                               EQU 98
    DXGI_FORMAT_BC7_UNORM_SRGB                          EQU 99
    DXGI_FORMAT_AYUV                                    EQU 100
    DXGI_FORMAT_Y410                                    EQU 101
    DXGI_FORMAT_Y416                                    EQU 102
    DXGI_FORMAT_NV12                                    EQU 103
    DXGI_FORMAT_P010                                    EQU 104
    DXGI_FORMAT_P016                                    EQU 105
    DXGI_FORMAT_420_OPAQUE                              EQU 106
    DXGI_FORMAT_YUY2                                    EQU 107
    DXGI_FORMAT_Y210                                    EQU 108
    DXGI_FORMAT_Y216                                    EQU 109
    DXGI_FORMAT_NV11                                    EQU 110
    DXGI_FORMAT_AI44                                    EQU 111
    DXGI_FORMAT_IA44                                    EQU 112
    DXGI_FORMAT_P8                                      EQU 113
    DXGI_FORMAT_A8P8                                    EQU 114
    DXGI_FORMAT_B4G4R4A4_UNORM                          EQU 115
    DXGI_FORMAT_P208                                    EQU 130
    DXGI_FORMAT_V208                                    EQU 131
    DXGI_FORMAT_V408                                    EQU 132
    DXGI_FORMAT_FORCE_UINT                              EQU 0ffffffffh

; --- DXGI 1 structs and values ---

    DXGI_CPU_ACCESS_NONE                                EQU 0
    DXGI_CPU_ACCESS_DYNAMIC                             EQU 1
    DXGI_CPU_ACCESS_READ_WRITE                          EQU 2
    DXGI_CPU_ACCESS_SCRATCH                             EQU 3
    DXGI_CPU_ACCESS_FIELD                               EQU 15
    DXGI_USAGE_SHADER_INPUT                             EQU 000000010h
    DXGI_USAGE_RENDER_TARGET_OUTPUT                     EQU 000000020h
    DXGI_USAGE_BACK_BUFFER                              EQU 000000040h
    DXGI_USAGE_SHARED                                   EQU 000000080h
    DXGI_USAGE_READ_ONLY                                EQU 000000100h
    DXGI_USAGE_DISCARD_ON_PRESENT                       EQU 000000200h
    DXGI_USAGE_UNORDERED_ACCESS                         EQU 000000400h

    DXGI_USAGE                                          EQU DD

    DXGI_MODE_DESC STRUCT
        _Width                                      DD ?
        _Height                                     DD ?
        _RefreshRate                                DXGI_RATIONAL {}
        _Format                                     DD ?
        _ScanlineOrdering                           DD ?
        _Scaling                                    DD ?,?
    DXGI_MODE_DESC ENDS

    DXGI_FRAME_STATISTICS STRUCT
        _PresentCount                               DD ?
        _PresentRefreshCount                        DD ?
        _SyncRefreshCount                           DD ?,?
        _SyncQPCTime                                DQ ?
        _SyncGPUTime                                DQ ?
    DXGI_FRAME_STATISTICS ENDS

    DXGI_MAPPED_RECT STRUCT
        _Pitch                                      DD ?,?
        _pBits                                      DQ ?
    DXGI_MAPPED_RECT ENDS

    DXGI_ADAPTER_DESC STRUCT
        _Description                                DW 128 DUP (?)
        _VendorId                                   DD ?
        _DeviceId                                   DD ?
        _SubSysId                                   DD ?
        _Revision                                   DD ?
        _DedicatedVideoMemory                       DQ ?
        _DedicatedSystemMemory                      DQ ?
        _SharedSystemMemory                         DQ ?
        _AdapterLuid                                LUID ?
    DXGI_ADAPTER_DESC ENDS

    DXGI_OUTPUT_DESC STRUCT
        _DeviceName                                 DW 32 DUP (?)
        _DesktopCoordinates                         RECT {}
        _AttachedToDesktop                          DB ?,?,?,?
        _Rotation                                   DD ?
        _Monitor                                    DQ ?
    DXGI_OUTPUT_DESC ENDS

    DXGI_SHARED_RESOURCE STRUCT
        _Handle                                     DQ ?
    DXGI_SHARED_RESOURCE ENDS

    DXGI_RESOURCE_PRIORITY_MINIMUM                  EQU 028000000h
    DXGI_RESOURCE_PRIORITY_LOW                      EQU 050000000h
    DXGI_RESOURCE_PRIORITY_NORMAL                   EQU 078000000h
    DXGI_RESOURCE_PRIORITY_HIGH                     EQU 0a0000000h
    DXGI_RESOURCE_PRIORITY_MAXIMUM                  EQU 0c8000000h

    DXGI_RESIDENCY_FULLY_RESIDENT                   EQU 1
    DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY        EQU 2
    DXGI_RESIDENCY_EVICTED_TO_DISK                  EQU 3

    DXGI_SURFACE_DESC STRUCT
        _Width                                      DD ?
        _Height                                     DD ?
        _Format                                     DD ?
        _SampleDesc                                 DD ?
    DXGI_SURFACE_DESC ENDS

    DXGI_SWAP_EFFECT_DISCARD                        EQU 0
    DXGI_SWAP_EFFECT_SEQUENTIAL                     EQU 1
    DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL                EQU 3
    DXGI_SWAP_EFFECT_FLIP_DISCARD                   EQU 4

    DXGI_SWAP_CHAIN_FLAG_NONPREROTATED                          EQU 1
    DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH                      EQU 2
    DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE                         EQU 4
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT                     EQU 8
    DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER        EQU 16
    DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY                           EQU 32
    DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT          EQU 64
    DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER                       EQU 128
    DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO                       EQU 256
    DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO                              EQU 512
    DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED                           EQU 1024
    DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING                          EQU 2048
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS EQU 4096

    DXGI_SWAP_CHAIN_DESC STRUCT
        _BufferDesc                                 DXGI_MODE_DESC {}
        _SampleDesc                                 DXGI_SAMPLE_DESC {}
        _BufferUsage                                DD ?
        _BufferCount                                DD ?
        _OutputWindow                               DQ ?
        _Windowed                                   DB ?,?,?,?
        _SwapEffect                                 DD ?
        _Flags                                      DD ?,?
    DXGI_SWAP_CHAIN_DESC ENDS

    DXGI_ADAPTER_FLAG_NONE                          EQU 0
    DXGI_ADAPTER_FLAG_REMOTE                        EQU 1
    DXGI_ADAPTER_FLAG_SOFTWARE                      EQU 2
    DXGI_ADAPTER_FLAG_FORCE_DWORD                   EQU 0ffffffffh

    DXGI_ADAPTER_DESC1 STRUCT
        _Description                                DW 128 DUP (?)
        _VendorId                                   DD ?
        _DeviceId                                   DD ?
        _SubSysId                                   DD ?
        _Revision                                   DD ?
        _DedicatedVideoMemory                       DQ ?
        _DedicatedSystemMemory                      DQ ?
        _SharedSystemMemory                         DQ ?
        _AdapterLuid                                DQ ?
        _Flags                                      DD ?,?
    DXGI_ADAPTER_DESC1 ENDS

    DXGI_DISPLAY_COLOR_SPACE STRUCT
        _PrimaryCoordinates                          REAL4 16 DUP (?)
        _WhitePoints                                 REAL4 32 DUP (?)
    DXGI_DISPLAY_COLOR_SPACE ENDS

; --- DXGI 2 structs and values ---

    DXGI_OUTDUPL_MOVE_RECT STRUCT
        _SourcePoint                                POINT {}
        _DestinationRect                            RECT {}
    DXGI_OUTDUPL_MOVE_RECT ENDS

    DXGI_OUTDUPL_DESC STRUCT
        _ModeDesc                                   DD ?
        _Rotation                                   DD ?
        _DesktopImageInSystemMemory                 DB ?,?,?,?,?,?,?,?
    DXGI_OUTDUPL_DESC ENDS

    DXGI_OUTDUPL_POINTER_POSITION STRUCT
        _Position                                   POINT {}
        _Visible                                    DB ?,?,?,?,?,?,?,?
    DXGI_OUTDUPL_POINTER_POSITION ENDS

    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME      EQU 1
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR           EQU 2
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR    EQU 4

    DXGI_OUTDUPL_POINTER_SHAPE_INFO STRUCT
        _Type                                       DD ?
        _Width                                      DD ?
        _Height                                     DD ?
        _Pitch                                      DD ?
        _HotSpot                                    POINT {}
    DXGI_OUTDUPL_POINTER_SHAPE_INFO ENDS

    DXGI_OUTDUPL_FRAME_INFO STRUCT
        _LastPresentTime                            DQ ?
        _LastMouseUpdateTime                        DQ ?
        _AccumulatedFrames                          DD ?
        _RectsCoalesced                             DB ?
        _ProtectedContentMaskedOut                  DB ?,?,?
        _PointerPosition                            DD ?
        _TotalMetadataBufferSize                    DD ?
        _PointerShapeBufferSize                     DD ?
    DXGI_OUTDUPL_FRAME_INFO ENDS

    DXGI_ALPHA_MODE_UNSPECIFIED                     EQU 0
    DXGI_ALPHA_MODE_PREMULTIPLIED                   EQU 1
    DXGI_ALPHA_MODE_STRAIGHT                        EQU 2
    DXGI_ALPHA_MODE_IGNORE                          EQU 3
    DXGI_ALPHA_MODE_FORCE_DWORD                     EQU 0ffffffffh

    DXGI_OFFER_RESOURCE_PRIORITY_LOW                EQU 1
    DXGI_OFFER_RESOURCE_PRIORITY_NORMAL             EQU DXGI_OFFER_RESOURCE_PRIORITY_LOW + 1
    DXGI_OFFER_RESOURCE_PRIORITY_HIGH               EQU DXGI_OFFER_RESOURCE_PRIORITY_NORMAL + 1

    DXGI_ENUM_MODES_STEREO                          EQU 4
    DXGI_ENUM_MODES_DISABLED_STEREO                 EQU 8
    DXGI_SHARED_RESOURCE_READ                       EQU 080000000h
    DXGI_SHARED_RESOURCE_WRITE                      EQU 1

    DXGI_MODE_DESC1 STRUCT
        _Width                                      DD ?
        _Height                                     DD ?
        _RefreshRate                                DXGI_RATIONAL {}
        _Format                                     DD ?
        _ScanlineOrdering                           DD ?
        _Scaling                                    DD ?
        _Stereo                                     DB ?,?,?,?,?,?,?,?
    DXGI_MODE_DESC1 ENDS

    DXGI_SCALING_STRETCH                            EQU 0
    DXGI_SCALING_NONE                               EQU 1
    DXGI_SCALING_ASPECT_RATIO_STRETCH               EQU 2

    DXGI_SWAP_CHAIN_DESC1 STRUCT
        _Width                                      DD ?
        _Height                                     DD ?
        _Format                                     DD ?
        _Stereo                                     DB ?,?,?,?
        _SampleDesc                                 DD ?
        _BufferUsage                                DD ?
        _BufferCount                                DD ?
        _Scaling                                    DD ?
        _SwapEffect                                 DD ?
        _AlphaMode                                  DD ?
        _Flags                                      DD ?,?
    DXGI_SWAP_CHAIN_DESC1 ENDS

    DXGI_SWAP_CHAIN_FULLSCREEN_DESC STRUCT
        _RefreshRate                                DXGI_RATIONAL {}
        _ScanlineOrdering                           DD ?
        _Scaling                                    DD ?
        _Windowed                                   DB ?,?,?,?,?,?,?,?
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC ENDS

    DXGI_PRESENT_PARAMETERS STRUCT
        _DirtyRectsCount                            DD ?,?
        _pDirtyRects                                DQ ?
        _pScrollRect                                DQ ?
        _pScrollOffset                              DQ ?
    DXGI_PRESENT_PARAMETERS ENDS

    DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY    EQU 0
    DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY     EQU 1
    DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY      EQU 2
    DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY         EQU 3
    DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY   EQU 4

    DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY     EQU 0
    DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY       EQU 1
    DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY   EQU 2
    DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY         EQU 3
    DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY    EQU 4

    DXGI_ADAPTER_DESC2 STRUCT
        _Description                                DW 128 DUP (?)
        _VendorId                                   DD ?
        _DeviceId                                   DD ?
        _SubSysId                                   DD ?
        _Revision                                   DD ?
        _DedicatedVideoMemory                       DQ ?
        _DedicatedSystemMemory                      DQ ?
        _SharedSystemMemory                         DQ ?
        _AdapterLuid                                DQ ?
        _Flags                                      DD ?
        _GraphicsPreemptionGranularity              DD ?
        _ComputePreemptionGranularity               DD ?
    DXGI_ADAPTER_DESC2 ENDS

; --- DXGI 3 structs and values ---

    DXGI_MATRIX_3X2_F STRUCT
        __11                                        REAL4 ?
        __12                                        REAL4 ?
        __21                                        REAL4 ?
        __22                                        REAL4 ?
        __31                                        REAL4 ?
        __32                                        REAL4 ?
    DXGI_MATRIX_3X2_F ENDS

    DXGI_DECODE_SWAP_CHAIN_DESC STRUCT
        _Flags                                      DD ?,?
    DXGI_DECODE_SWAP_CHAIN_DESC ENDS

    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE            EQU 1
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709                    EQU 2
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC                    EQU 4

    DXGI_FRAME_PRESENTATION_MODE_COMPOSED                       EQU 0
    DXGI_FRAME_PRESENTATION_MODE_OVERLAY                        EQU 1
    DXGI_FRAME_PRESENTATION_MODE_NONE                           EQU 2
    DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE            EQU 3

    DXGI_FRAME_STATISTICS_MEDIA STRUCT
        _PresentCount                               DD ?
        _PresentRefreshCount                        DD ?
        _SyncRefreshCount                           DD ?,?
        _SyncQPCTime                                DQ ?
        _SyncGPUTime                                DQ ?
        _CompositionMode                            DD ?
        _ApprovedPresentDuration                    DD ?
    DXGI_FRAME_STATISTICS_MEDIA ENDS

    DXGI_OVERLAY_SUPPORT_FLAG_DIRECT                EQU 1
    DXGI_OVERLAY_SUPPORT_FLAG_SCALING               EQU 2

; --- DXGI 4 structs and values ---

    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT            EQU 1
    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT    EQU 2

    DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT               EQU 1

    DXGI_MEMORY_SEGMENT_GROUP_LOCAL                             EQU 0
    DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL                         EQU 1

    DXGI_QUERY_VIDEO_MEMORY_INFO STRUCT
        _Budget                                     DQ ?
        _CurrentUsage                               DQ ?
        _AvailableForReservation                    DQ ?
        _CurrentReservation                         DQ ?
    DXGI_QUERY_VIDEO_MEMORY_INFO ENDS

; --- DXGI 5 structs and values ---

    DXGI_OUTDUPL_COMPOSITED_UI_CAPTURE_ONLY                     EQU 1

    DXGI_HDR_METADATA_TYPE_NONE                     EQU 0
    DXGI_HDR_METADATA_TYPE_HDR10                    EQU 1
    DXGI_HDR_METADATA_TYPE_HDR10PLUS                EQU 2

    DXGI_HDR_METADATA_HDR10 STRUCT
        _RedPrimary                                 DW 2 DP (?)
        _GreenPrimary                               DW 2 DP (?)
        _BluePrimary                                DW 2 DP (?)
        _WhitePoint                                 DW 2 DP (?)
        _MaxMasteringLuminance                      DD ?
        _MinMasteringLuminance                      DD ?
        _MaxContentLightLevel                       DW ?
        _MaxFrameAverageLightLevel                  DW ?
                                                    DD ?
    DXGI_HDR_METADATA_HDR10 ENDS

    DXGI_HDR_METADATA_HDR10PLUS STRUCT
        _Data                                       DB 72 DUP (?)
    DXGI_HDR_METADATA_HDR10PLUS ENDS

    DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT         EQU 1

    DXGI_RECLAIM_RESOURCE_RESULT_OK                 EQU 0
    DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED          EQU 1
    DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED      EQU 2

    DXGI_FEATURE_PRESENT_ALLOW_TEARING              EQU 0

; --- DXGI 6 structs and values ---

    DXGI_ADAPTER_FLAG3_NONE                                     EQU 0
    DXGI_ADAPTER_FLAG3_REMOTE                                   EQU 1
    DXGI_ADAPTER_FLAG3_SOFTWARE                                 EQU 2
    DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE                           EQU 4
    DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES                 EQU 8
    DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES             EQU 010h
    DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE                  EQU 020h
    DXGI_ADAPTER_FLAG3_FORCE_DWORD                              EQU 0ffffffffh

    DXGI_ADAPTER_DESC3 STRUCT
        _Description                                DW 128 DUP (?)
        _VendorId                                   DD ?
        _DeviceId                                   DD ?
        _SubSysId                                   DD ?
        _Revision                                   DD ?
        _DedicatedVideoMemory                       DQ ?
        _DedicatedSystemMemory                      DQ ?
        _SharedSystemMemory                         DQ ?
        _AdapterLuid                                DQ ?
        _Flags                                      DD ?
        _GraphicsPreemptionGranularity              DD ?
        _ComputePreemptionGranularity               DD ?
    DXGI_ADAPTER_DESC3 ENDS

    DXGI_OUTPUT_DESC1 STRUCT
        _DeviceName                                 DW 32 DUP (?)
        _DesktopCoordinates                         RECT {}
        _AttachedToDesktop                          DB ?,?,?,?
        _Rotation                                   DD ?
        _dMonitor                                   DQ ?
        _BitsPerColor                               DD ?
        _ColorSpace                                 DD ?
        _RedPrimary                                 REAL4 2 DUP (?)
        _GreenPrimary                               REAL4 2 DUP (?)
        _BluePrimary                                REAL4 2 DUP (?)
        _WhitePoint                                 REAL4 2 DUP (?)
        _MinLuminance                               REAL4 ?
        _MaxLuminance                               REAL4 ?
        _MaxFullFrameLuminance                      REAL4 ?,?
    DXGI_OUTPUT_DESC1 ENDS

    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN           EQU 1
    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED             EQU 2
    DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED     EQU 4

    DXGI_GPU_PREFERENCE_UNSPECIFIED                 EQU 0
    DXGI_GPU_PREFERENCE_MINIMUM_POWER               EQU DXGI_GPU_PREFERENCE_UNSPECIFIED + 1
    DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE            EQU DXGI_GPU_PREFERENCE_MINIMUM_POWER + 1

; --- DXGI Object ---

    _IDXGIObject MACRO
        _IUnknown
        _SetPrivateData                             DQ ?
        _SetPrivateDataInterface                    DQ ?
        _GetPrivateData                             DQ ?
        _GetParent                                  DQ ?
    ENDM

    _ComTable IDXGIObject, _IDXGIObject

; --- DXGI Adapter ---

    _IDXGIAdapter MACRO
        _IDXGIObject
        _GetDesc                                    DQ ?
        _EnumOutputs                                DQ ?
        _CheckInterfaceSupport                      DQ ?
    ENDM

    _ComTable IDXGIAdapter, _IDXGIAdapter

; --- DXGI Adapter1 ---

    _IDXGIAdapter1 MACRO
        _IDXGIAdapter
        _GetDesc1                                   DQ ?
    ENDM

    _ComTable IDXGIAdapter1, _IDXGIAdapter1

; --- DXGI Adapter2 ---

    _IDXGIAdapter2 MACRO
        _IDXGIAdapter1
        _GetDesc2                                   DQ ?
    ENDM

    _ComTable IDXGIAdapter2, _IDXGIAdapter2

; --- DXGI Adapter3 ---

    _IDXGIAdapter3 MACRO
        _IDXGIAdapter2
        _RegisterHardwareContentProtectionTeardownStatusEvent       DQ ?
        _UnregisterHardwareContentProtectionTeardownStatus          DQ ?
        _QueryVideoMemoryInfo                                       DQ ?
        _SetVideoMemoryReservation                                  DQ ?
        _RegisterVideoMemoryBudgetChangeNotificationEvent           DQ ?
        _UnregisterVideoMemoryBudgetChangeNotification              DQ ?
    ENDM

    _ComTable IDXGIAdapter3, _IDXGIAdapter3

; --- DXGI Adapter4 ---

    _IDXGIAdapter4 MACRO
        _IDXGIAdapter3
        _GetDesc3                                   DQ ?
    ENDM

    _ComTable IDXGIAdapter4, _IDXGIAdapter4

; --- DXGI Device ---

    _IDXGIDevice MACRO
        _IDXGIObject
        _GetAdapter                                 DQ ?
        _CreateSurface                              DQ ?
        _QueryResourceResidency                     DQ ?
        _SetGPUThreadPriority                       DQ ?
        _GetGPUThreadPriority                       DQ ?
    ENDM

    _ComTable IDXGIDevice, _IDXGIDevice

; --- DXGI Device1 ---

    _IDXGIDevice1 MACRO
        _IDXGIDevice
        _SetMaximumFrameLatency                     DQ ?
        _GetMaximumFrameLatency                     DQ ?
    ENDM

    _ComTable IDXGIDevice1, _IDXGIDevice1

; --- DXGI Device2 ---

    _IDXGIDevice2 MACRO
        _IDXGIDevice1
        _OfferResources                             DQ ?
        _ReclaimResources                           DQ ?
        _EnqueueSetEvent                            DQ ?
    ENDM

    _ComTable IDXGIDevice2, _IDXGIDevice2

; --- DXGI Device3 ---

    _IDXGIDevice3 MACRO
        _IDXGIDevice2
        _Trim                                       DQ ?
    ENDM

    _ComTable IDXGIDevice3, _IDXGIDevice3

; --- DXGI Device4 ---

    _IDXGIDevice4 MACRO
        _IDXGIDevice3
        _OfferResources1                            DQ ?
        _ReclaimResources1                          DQ ?
    ENDM

    _ComTable IDXGIDevice4, _IDXGIDevice4

; --- DXGI Factory ---

    _IDXGIFactory MACRO
        _IDXGIObject
        _EnumAdapters                               DQ ?
        _MakeWindowAssociation                      DQ ?
        _GetWindowAssociation                       DQ ?
        _CreateSwapChain                            DQ ?
        _CreateSoftwareAdapter                      DQ ?
    ENDM

    _ComTable IDXGIFactory, _IDXGIFactory

; --- DXGI Factory1 ---

    _IDXGIFactory1 MACRO
        _IDXGIFactory
        _EnumAdapters1                              DQ ?
        _IsCurrent                                  DQ ?
    ENDM

    _ComTable IDXGIFactory1, _IDXGIFactory1

; --- DXGI Factory2 ---

    _IDXGIFactory2 MACRO
        _IDXGIFactory1
        _IsWindowStereoEnabled                      DQ ?
        _CreateSwapChainForHwnd                     DQ ?
        _CreateSwapChainForCoreWindow               DQ ?
        _GetSharedResourceAdapterLuid               DQ ?
        _RegisterStereoStatusWindow                 DQ ?
        _RegisterStereoStatusEvent                  DQ ?
        _UnregisterStereoStatus                     DQ ?
        _RegisterOcclusionStatusWindow              DQ ?
        _RegisterOcclusionStatusEvent               DQ ?
        _UnregisterOcclusionStatus                  DQ ?
        _CreateSwapChainForComposition              DQ ?
    ENDM

    _ComTable IDXGIFactory2, _IDXGIFactory2

; --- DXGI Factory3 ---

    _IDXGIFactory3 MACRO
        _IDXGIFactory2
        _GetCreationFlags                           DQ ?
    ENDM

    _ComTable IDXGIFactory3, _IDXGIFactory3

; --- DXGI Factory4 ---

    _IDXGIFactory4 MACRO
        _IDXGIFactory3
        _EnumWarpAdapter                            DQ ?
        _EnumAdapterByLuid                          DQ ?
    ENDM

    _ComTable IDXGIFactory4, _IDXGIFactory4

; --- DXGI Factory5 ---

    _IDXGIFactory5 MACRO
        _IDXGIFactory4
        _CheckFeatureSupport                        DQ ?
    ENDM

    _ComTable IDXGIFactory5, _IDXGIFactory5

; --- DXGI Factory6 ---

    _IDXGIFactory6 MACRO
        _IDXGIFactory5
        _EnumAdapterByGpuPreference                 DQ ?
    ENDM

    _ComTable IDXGIFactory6, _IDXGIFactory6

; --- DXGI Factory7 ---

    _IDXGIFactory7 MACRO
        _IDXGIFactory6
        _RegisterAdaptersChangedEvent               DQ ?
        _UnregisterAdaptersChangedEvent             DQ ?
    ENDM

    _ComTable IDXGIFactory7, _IDXGIFactory7

; --- DXGI Keyed Mutex ---

    _IDXGIKeyedMutex MACRO
        _IDXGIObject
        _AcquireSync                                DQ ?
        _ReleaseSync                                DQ ?
    ENDM

    _ComTable IDXGIKeyedMutex, _IDXGIKeyedMutex

; --- DXGI Output ---

    _IDXGIOutput MACRO
        _IDXGIObject
        _GetDesc                                    DQ ?
        _GetDisplayModeList                         DQ ?
        _FindClosestMatchingMode                    DQ ?
        _WaitForVBlank                              DQ ?
        _TakeOwnership                              DQ ?
        _ReleaseOwnership                           DQ ?
        _GetGammaControlCapabilities                DQ ?
        _SetGammaControl                            DQ ?
        _GetGammaControl                            DQ ?
        _SetDisplaySurface                          DQ ?
        _GetDisplaySurfaceData                      DQ ?
        _GetFrameStatistics                         DQ ?
    ENDM

    _ComTable IDXGIOutput, _IDXGIOutput

; --- DXGI Output1 ---

    _IDXGIOutput1 MACRO
        _IDXGIOutput
        _GetDisplayModeList1                        DQ ?
        _FindClosestMatchingMode1                   DQ ?
        _GetDisplaySurfaceData1                     DQ ?
        _DuplicateOutput                            DQ ?
    ENDM

    _ComTable IDXGIOutput1, _IDXGIOutput1

; --- DXGI Output2 ---

    _IDXGIOutput2 MACRO
        _IDXGIOutput1
        _SupportsOverlays                           DQ ?
    ENDM

    _ComTable IDXGIOutput2, _IDXGIOutput2

; --- DXGI Output3 ---

    _IDXGIOutput3 MACRO
        _IDXGIOutput2
        _CheckOverlaySupport                        DQ ?
    ENDM

    _ComTable IDXGIOutput3, _IDXGIOutput3

; --- DXGI Output4 ---

    _IDXGIOutput4 MACRO
        _IDXGIOutput3
        _CheckOverlayColorSpaceSupport              DQ ?
    ENDM

    _ComTable IDXGIOutput4, _IDXGIOutput4

; --- DXGI Output5 ---

    _IDXGIOutput5 MACRO
        _IDXGIOutput4
        _DuplicateOutput1                           DQ ?
    ENDM

    _ComTable IDXGIOutput5, _IDXGIOutput5

; --- DXGI Output6 ---

    _IDXGIOutput6 MACRO
        _IDXGIOutput5
        _GetDesc1                                   DQ ?
        _CheckHardwareCompositionSupport            DQ ?
    ENDM

    _ComTable IDXGIOutput6, _IDXGIOutput6

; --- DXGI Resource ---

    _IDXGIResource MACRO
        _IDXGIObject
        _GetSharedHandle                            DQ ?
        _GetUsage                                   DQ ?
        _SetEvictionPriority                        DQ ?
        _GetEvictionPriority                        DQ ?
    ENDM

    _ComTable IDXGIResource, _IDXGIResource

; --- DXGI Resource1 ---

    _IDXGIResource1 MACRO
        _IDXGIResource
        _CreateSubresourceSurface                   DQ ?
        _CreateSharedHandle                         DQ ?
    ENDM

    _ComTable IDXGIResource1, _IDXGIResource1

; --- DXGI Surface ---

    _IDXGISurface MACRO
        _IDXGIObject
        _GetDesc                                    DQ ?
        _Map                                        DQ ?
        _Unmap                                      DQ ?
    ENDM

    _ComTable IDXGISurface, _IDXGISurface

; --- DXGI Surface1 ---

    _IDXGISurface1 MACRO
        _IDXGISurface
        _GetDC                                      DQ ?
        _ReleaseDC                                  DQ ?
    ENDM

    _ComTable IDXGISurface1, _IDXGISurface1

; --- DXGI Surface2 ---

    _IDXGISurface2 MACRO
        _IDXGISurface1
        _GetResource                                DQ ?
    ENDM

    _ComTable IDXGISurface2, _IDXGISurface2

; --- DXGI SwapChain ---

    _IDXGISwapChain MACRO
        _IDXGIObject
        _Present                                    DQ ?
        _GetBuffer                                  DQ ?
        _SetFullscreenState                         DQ ?
        _GetFullscreenState                         DQ ?
        _GetDesc                                    DQ ?
        _ResizeBuffers                              DQ ?
        _ResizeTarget                               DQ ?
        _GetContainingOutput                        DQ ?
        _GetFrameStatistics                         DQ ?
        _GetLastPresentCount                        DQ ?
    ENDM

    _ComTable IDXGISwapChain, _IDXGISwapChain

; --- DXGI SwapChain1 ---

    _IDXGISwapChain1 MACRO
        _IDXGISwapChain
        _GetDesc1                                   DQ ?
        _GetFullscreenDesc                          DQ ?
        _GetHwnd                                    DQ ?
        _GetCoreWindow                              DQ ?
        _Present1                                   DQ ?
        _IsTemporaryMonoSupported                   DQ ?
        _GetRestrictToOutput                        DQ ?
        _SetBackgroundColor                         DQ ?
        _GetBackgroundColor                         DQ ?
        _SetRotation                                DQ ?
        _GetRotation                                DQ ?
    ENDM

    _ComTable IDXGISwapChain1, _IDXGISwapChain1

; --- DXGI SwapChain2 ---

    _IDXGISwapChain2 MACRO
        _IDXGISwapChain1
        _SetSourceSize                              DQ ?
        _GetSourceSize                              DQ ?
        _SetMaximumFrameLatency                     DQ ?
        _GetMaximumFrameLatency                     DQ ?
        _GetFrameLatencyWaitableObject              DQ ?
        _SetMatrixTransform                         DQ ?
        _GetMatrixTransform                         DQ ?
    ENDM

    _ComTable IDXGISwapChain2, _IDXGISwapChain2

; --- DXGI SwapChain3 ---

    _IDXGISwapChain3 MACRO
        _IDXGISwapChain2
        _GetCurrentBackBufferIndex                  DQ ?
        _CheckColorSpaceSupport                     DQ ?
        _SetColorSpace1                             DQ ?
        _ResizeBuffers1                             DQ ?
    ENDM

    _ComTable IDXGISwapChain3, _IDXGISwapChain3

; --- DXGI SwapChain4 ---

    _IDXGISwapChain4 MACRO
        _IDXGISwapChain3
        _SetHDRMetaData                             DQ ?
    ENDM

    _ComTable IDXGISwapChain4, _IDXGISwapChain4