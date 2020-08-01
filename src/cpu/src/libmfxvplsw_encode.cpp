/*############################################################################
  # Copyright (C) 2020 Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#include "./cpu_workstream.h"
#include "vpl/mfxvideo.h"

mfxStatus MFXVideoENCODE_Query(mfxSession session,
                               mfxVideoParam *in,
                               mfxVideoParam *out) {
    mfxStatus sts = MFX_ERR_NONE;

    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == out) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);
    sts               = ws->EncodeQuery(in, out);

    return sts;
}

mfxStatus MFXVideoENCODE_QueryIOSurf(mfxSession session,
                                     mfxVideoParam *par,
                                     mfxFrameAllocRequest *request) {
    mfxStatus sts = MFX_ERR_NONE;

    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == par || 0 == request) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);

    sts = ws->EncodeQueryIOSurf(par, request);

    return sts;
}

mfxStatus MFXVideoENCODE_Init(mfxSession session, mfxVideoParam *par) {
    mfxStatus sts = MFX_ERR_NONE;

    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == par) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);

    sts = ws->InitEncode(par);

    return sts;
}

mfxStatus MFXVideoENCODE_Close(mfxSession session) {
    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);

    if (ws->getEncInit() == false)
        return MFX_ERR_NOT_INITIALIZED;

    eVPLMemMgmtType memMgmtType = ws->getEncMemMgmtType();

    if (memMgmtType == VPL_MEM_MGMT_INTERNAL) {
        ws->FreeEncodeSurfacePool();
    }

    ws->FreeEncode();

    return MFX_ERR_NONE;
}

mfxStatus MFXVideoENCODE_EncodeFrameAsync(mfxSession session,
                                          mfxEncodeCtrl *ctrl,
                                          mfxFrameSurface1 *surface,
                                          mfxBitstream *bs,
                                          mfxSyncPoint *syncp) {
    mfxStatus sts = MFX_ERR_NONE;

    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == bs || 0 == syncp) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);

    if (ws->getEncInit() == false)
        return MFX_ERR_NOT_INITIALIZED;

    sts = ws->EncodeFrame(surface, bs);

    *syncp = (mfxSyncPoint)(0);
    if (sts == MFX_ERR_NONE)
        *syncp = (mfxSyncPoint)(0x56789abc);

    return sts;
}

// stubs
mfxStatus MFXVideoENCODE_Reset(mfxSession session, mfxVideoParam *par) {
    mfxStatus sts = MFX_ERR_NONE;

    if (0 == session) {
        return MFX_ERR_INVALID_HANDLE;
    }
    if (0 == par) {
        return MFX_ERR_NULL_PTR;
    }

    CpuWorkstream *ws = reinterpret_cast<CpuWorkstream *>(session);

    if (ws->getEncInit() == false)
        return MFX_ERR_NOT_INITIALIZED;

    ws->FreeEncode();

    sts = ws->InitEncode(par);

    return sts;
}

mfxStatus MFXVideoENCODE_GetVideoParam(mfxSession session, mfxVideoParam *par) {
    return MFX_ERR_NOT_IMPLEMENTED;
}

mfxStatus MFXVideoENCODE_GetEncodeStat(mfxSession session,
                                       mfxEncodeStat *stat) {
    return MFX_ERR_NOT_IMPLEMENTED;
}
