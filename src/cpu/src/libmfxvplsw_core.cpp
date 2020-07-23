/*############################################################################
  # Copyright (C) 2020 Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#include "./cpu_workstream.h"
#include "vpl/mfxvideo.h"

// stubs
mfxStatus MFXVideoCORE_SetFrameAllocator(mfxSession session,
                                         mfxFrameAllocator *allocator) {
    return MFX_ERR_UNSUPPORTED;
}
mfxStatus MFXVideoCORE_SetHandle(mfxSession session,
                                 mfxHandleType type,
                                 mfxHDL hdl) {
    return MFX_ERR_UNSUPPORTED;
}
mfxStatus MFXVideoCORE_GetHandle(mfxSession session,
                                 mfxHandleType type,
                                 mfxHDL *hdl) {
    return MFX_ERR_UNSUPPORTED;
}
mfxStatus MFXVideoCORE_QueryPlatform(mfxSession session,
                                     mfxPlatform *platform) {
    return MFX_ERR_UNSUPPORTED;
}

mfxStatus MFXVideoCORE_SyncOperation(mfxSession session,
                                     mfxSyncPoint syncp,
                                     mfxU32 wait) {
    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == syncp) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);
    return ws->Sync(syncp, wait);
}
