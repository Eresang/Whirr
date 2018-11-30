    CreateDXGIFactory               PROTO STDCALL
    CreateDXGIFactory1              PROTO STDCALL
    CreateDXGIFactory2              PROTO STDCALL

; --- DXGI Object ---

    _IDXGIObject MACRO
        _IUnknown
        SetPrivateData                              DQ ?
        SetPrivateDataInterface                     DQ ?
        GetPrivateData                              DQ ?
        GetParent                                   DQ ?
    ENDM

    _ComTable IDXGIObject, _IDXGIObject

; --- DXGI Adapter ---

    _IDXGIAdapter MACRO
        _IDXGIObject
        GetDesc                                     DQ ?
        EnumOutputs                                 DQ ?
        CheckInterfaceSupport                       DQ ?
    ENDM

    _ComTable IDXGIAdapter, _IDXGIAdapter

;

    _IDXGIAdapter1 MACRO
        _IDXGIAdapter
        GetDesc1                                    DQ ?
    ENDM

    _ComTable IDXGIAdapter1, _IDXGIAdapter1

;

    _IDXGIAdapter2 MACRO
        _IDXGIAdapter1
        GetDesc2                                    DQ ?
    ENDM

    _ComTable IDXGIAdapter2, _IDXGIAdapter2

;

    _IDXGIAdapter3 MACRO
        _IDXGIAdapter2
        RegisterHardwareContentProtectionTeardownStatusEvent        DQ ?
        UnregisterHardwareContentProtectionTeardownStatus           DQ ?
        QueryVideoMemoryInfo                                        DQ ?
        SetVideoMemoryReservation                                   DQ ?
        RegisterVideoMemoryBudgetChangeNotificationEvent            DQ ?
        UnregisterVideoMemoryBudgetChangeNotification               DQ ?
    ENDM

    _ComTable IDXGIAdapter3, _IDXGIAdapter3

; --- DXGI Device ---

    _IDXGIDevice MACRO
        _IDXGIObject
        GetAdapter                                  DQ ?
        CreateSurface                               DQ ?
        QueryResourceResidency                      DQ ?
        SetGPUThreadPriority                        DQ ?
        GetGPUThreadPriority                        DQ ?
    ENDM

    _ComTable IDXGIDevice, _IDXGIDevice

;

    _IDXGIDevice1 MACRO
        _IDXGIDevice
        SetMaximumFrameLatency                      DQ ?
        GetMaximumFrameLatency                      DQ ?
    ENDM

    _ComTable IDXGIDevice1, _IDXGIDevice1

;

    _IDXGIDevice2 MACRO
        _IDXGIDevice1
        OfferResources                              DQ ?
        ReclaimResources                            DQ ?
        EnqueueSetEvent                             DQ ?
    ENDM

    _ComTable IDXGIDevice2,_IDXGIDevice2

;

    _IDXGIDevice3 MACRO
        _IDXGIDevice2
        Trim                                        DQ ?
    ENDM

    _ComTable IDXGIDevice3, _IDXGIDevice3

;

    _IDXGIDevice4 MACRO
        _IDXGIDevice3
        OfferResources1                             DQ ?
        ReclaimResources1                           DQ ?
    ENDM

    _ComTable IDXGIDevice4, _IDXGIDevice4

; --- DXGI Factory ---

    _IDXGIFactory MACRO
        _IDXGIObject
        EnumAdapters                                DQ ?
        MakeWindowAssociation                       DQ ?
        GetWindowAssociation                        DQ ?
        CreateSwapChain                             DQ ?
        CreateSoftwareAdapter                       DQ ?
    ENDM

    _ComTable IDXGIFactory, _IDXGIFactory

;

    _IDXGIFactory1 MACRO
        _IDXGIFactory
        EnumAdapters1                               DQ ?
        IsCurrent                                   DQ ?
    ENDM

    _ComTable IDXGIFactory1, _IDXGIFactory1

;

    _IDXGIFactory2 MACRO
        _IDXGIFactory1
        IsWindowStereoEnabled                       DQ ?
        CreateSwapChainForHwnd                      DQ ?
        CreateSwapChainForCoreWindow                DQ ?
        GetSharedResourceAdapterLuid                DQ ?
        RegisterStereoStatusWindow                  DQ ?
        RegisterStereoStatusEvent                   DQ ?
        UnregisterStereoStatus                      DQ ?
        RegisterOcclusionStatusWindow               DQ ?
        RegisterOcclusionStatusEvent                DQ ?
        UnregisterOcclusionStatus                   DQ ?
        CreateSwapChainForComposition               DQ ?
    ENDM

    _ComTable IDXGIFactory2, _IDXGIFactory2

;

    _IDXGIFactory3 MACRO
        _IDXGIFactory2
        GetCreationFlags                            DQ ?
    ENDM

    _ComTable IDXGIFactory3, _IDXGIFactory3

;

    _IDXGIFactory4 MACRO
        _IDXGIFactory3
        EnumWarpAdapter                             DQ ?
        EnumAdapterByLuid                           DQ ?
    ENDM

    _ComTable IDXGIFactory4, _IDXGIFactory4

;

    _IDXGIFactory5 MACRO
        _IDXGIFactory4
        CheckFeatureSupport                         DQ ?
    ENDM

    _ComTable IDXGIFactory5, _IDXGIFactory5

; --- DXGI Keyed Mutex ---

    _IDXGIKeyedMutex MACRO
        _IDXGIObject
        AcquireSync                                 DQ ?
        ReleaseSync                                 DQ ?
    ENDM

    _ComTable IDXGIKeyedMutex, _IDXGIKeyedMutex

; --- DXGI Output ---

    _IDXGIOutput MACRO
        _IDXGIObject
        GetDesc                                     DQ ?
        GetDisplayModeList                          DQ ?
        FindClosestMatchingMode                     DQ ?
        WaitForVBlank                               DQ ?
        TakeOwnership                               DQ ?
        ReleaseOwnership                            DQ ?
        GetGammaControlCapabilities                 DQ ?
        SetGammaControl                             DQ ?
        GetGammaControl                             DQ ?
        SetDisplaySurface                           DQ ?
        GetDisplaySurfaceData                       DQ ?
        GetFrameStatistics                          DQ ?
    ENDM

    _ComTable IDXGIOutput, _IDXGIOutput

;

    _IDXGIOutput1 MACRO
        _IDXGIOutput
        GetDisplayModeList1                         DQ ?
        FindClosestMatchingMode1                    DQ ?
        GetDisplaySurfaceData1                      DQ ?
        DuplicateOutput                             DQ ?
    ENDM

    _ComTable IDXGIOutput1, _IDXGIOutput1

;

    _IDXGIOutput2 MACRO
        _IDXGIOutput1
        SupportsOverlays                            DQ ?
    ENDM

    _ComTable IDXGIOutput2, _IDXGIOutput2

;

    _IDXGIOutput3 MACRO
        _IDXGIOutput2
        CheckOverlaySupport                         DQ ?
    ENDM

    _ComTable IDXGIOutput3, _IDXGIOutput3

;

    _IDXGIOutput4 MACRO
        _IDXGIOutput3
        CheckOverlayColorSpaceSupport               DQ ?
    ENDM

    _ComTable IDXGIOutput4, _IDXGIOutput4

;

    _IDXGIOutput5 MACRO
        _IDXGIOutput4
        DuplicateOutput1                            DQ ?
    ENDM

    _ComTable IDXGIOutput5, _IDXGIOutput5

; --- DXGI Resource ---

    _IDXGIResource MACRO
        _IDXGIObject
        GetSharedHandle                             DQ ?
        GetUsage                                    DQ ?
        SetEvictionPriority                         DQ ?
        GetEvictionPriority                         DQ ?
    ENDM

    _ComTable IDXGIResource, _IDXGIResource

;

    _IDXGIResource1 MACRO
        _IDXGIResource
        CreateSubresourceSurface                    DQ ?
        CreateSharedHandle                          DQ ?
    ENDM

    _ComTable IDXGIResource1, _IDXGIResource1

; --- DXGI Surface ---

    _IDXGISurface MACRO
        _IDXGIObject
        GetDesc                                     DQ ?
        Map                                         DQ ?
        Unmap                                       DQ ?
    ENDM

    _ComTable IDXGISurface, _IDXGISurface

;

    _IDXGISurface1 MACRO
        _IDXGISurface
        GetDC                                       DQ ?
        ReleaseDC                                   DQ ?
    ENDM

    _ComTable IDXGISurface1, _IDXGISurface1

;

    _IDXGISurface2 MACRO
        _IDXGISurface1
        GetResource                                 DQ ?
    ENDM

    _ComTable IDXGISurface2, _IDXGISurface2

; --- DXGI Swap Chain ---

    _IDXGISwapChain MACRO
        _IDXGIObject
        Present                                     DQ ?
        GetBuffer                                   DQ ?
        SetFullscreenState                          DQ ?
        GetFullscreenState                          DQ ?
        GetDesc                                     DQ ?
        ResizeBuffers                               DQ ?
        ResizeTarget                                DQ ?
        GetContainingOutput                         DQ ?
        GetFrameStatistics                          DQ ?
        GetLastPresentCount                         DQ ?
    ENDM

    _ComTable IDXGISwapChain, _IDXGISwapChain

;

    _IDXGISwapChain1 MACRO
        _IDXGISwapChain
        GetDesc1                                    DQ ?
        GetFullscreenDesc                           DQ ?
        GetHwnd                                     DQ ?
        GetCoreWindow                               DQ ?
        Present1                                    DQ ?
        IsTemporaryMonoSupported                    DQ ?
        GetRestrictToOutput                         DQ ?
        SetBackgroundColor                          DQ ?
        GetBackgroundColor                          DQ ?
        SetRotation                                 DQ ?
        GetRotation                                 DQ ?
    ENDM

    _ComTable IDXGISwapChain1, _IDXGISwapChain1

;

    _IDXGISwapChain2 MACRO
        _IDXGISwapChain1
        SetSourceSize                               DQ ?
        GetSourceSize                               DQ ?
        SetMaximumFrameLatency                      DQ ?
        GetMaximumFrameLatency                      DQ ?
        GetFrameLatencyWaitableObject               DQ ?
        SetMatrixTransform                          DQ ?
        GetMatrixTransform                          DQ ?
    ENDM

    _ComTable IDXGISwapChain2, _IDXGISwapChain2

;

    _IDXGISwapChain3 MACRO
        _IDXGISwapChain2
        GetCurrentBackBufferIndex                   DQ ?
        CheckColorSpaceSupport                      DQ ?
        SetColorSpace1                              DQ ?
        ResizeBuffers1                              DQ ?
    ENDM

    _ComTable IDXGISwapChain3, _IDXGISwapChain3

;

    _IDXGISwapChain4 MACRO
        _IDXGISwapChain3
        SetHDRMetaData                              DQ ?
    ENDM

    _ComTable IDXGISwapChain4, _IDXGISwapChain4