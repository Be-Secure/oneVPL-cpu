/*############################################################################
  # Copyright (C) 2020 Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#ifndef TEST_UNIT_API_UNIT_API_H_
#define TEST_UNIT_API_UNIT_API_H_

#include "vpl/mfxdispatcher.h"
#include "vpl/mfximplcaps.h"
#include "vpl/mfxvideo.h"

// globals controlling test configuration
extern bool g_bDispInclSW;
extern bool g_bDispInclGPU_VPL;
extern bool g_bDispInclGPU_MSDK;

#define SKIP_IF_DISP_SW_DISABLED()    \
    {                                 \
        if (g_bDispInclSW == false) { \
            GTEST_SKIP();             \
        }                             \
    }

#define SKIP_IF_DISP_GPU_DISABLED()                                        \
    {                                                                      \
        if (g_bDispInclGPU_VPL == false && g_bDispInclGPU_MSDK == false) { \
            GTEST_SKIP();                                                  \
        }                                                                  \
    }

#define SKIP_IF_DISP_GPU_VPL_DISABLED()    \
    {                                      \
        if (g_bDispInclGPU_VPL == false) { \
            GTEST_SKIP();                  \
        }                                  \
    }

#endif // TEST_UNIT_API_UNIT_API_H_