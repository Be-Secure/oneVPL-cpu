## Supported Parameters

The mfxVideoParam parameters are supported in the reference implementation.
Please note: no extended parameter buffers are supported in this release.

### Decode

Input:

| Parameter                 |  Accepted values                         |
|---------------------------|------------------------------------------|
| mfx.CodecID               | MFX_CODEC_HEVC, MFX_CODEC_AV1            |


Output:

| Parameter                 |  Accepted values                         |
|---------------------------|------------------------------------------|
| mfx.FrameInfo.FourCC      | MFX_FOURCC_IYUV, MFX_FOURCC_I010         |
| IOPattern                 | MFX_IOPATTERN_OUT_SYSTEM_MEMORY          |


### Encode

Input:

| Parameter                 |  Accepted values                         |
|---------------------------|------------------------------------------|
| IOPattern                 | MFX_IOPATTERN_IN_SYSTEM_MEMORY           |
| mfx.FrameInfo.FourCC      | MFX_FOURCC_IYUV, MFX_FOURCC_I010         |

Output:

| Parameter                     |  Accepted values                         |
|-------------------------------|------------------------------------------|
| mfx.CodecID                   | MFX_CODEC_HEVC, MFX_CODEC_AV1            |
| mfx.FrameInfo.Width           | [64 - 8192] HEVC, [64 - 4096] AV1        |
| mfx.FrameInfo.Height          | [64 - 4320] HEVC, [16 - 2304] AV1        |
| mfx.GopPicSize                | 0-65535                                  |
| mfx.GopRefDist                | 0-65535                                  |
| mfx.TargetKbps                | 1-65535                                  |
| mfx.FrameInfo.FrameRateExtN   | 1-65535                                  |
| mfx.FrameInfo.FrameRateExtD   | 1-65535                                  |
| mfx.FrameInfo.AspectRatioH    | 1-65535                                  |
| mfx.FrameInfo.AspectRatioW    | 1-65535                                  |
| mfx.NumSlice                  | 0-65535                                  |
| mfx.NumRefFrame               | 0-65535                                  |
| mfx.GopOptFlag                | MFX_GOP_CLOSED                           |
| mfx.FrameInfo.BitDepthChroma  | 8, 10                                    |
| mfx.RateControlMethod         | HEVC: CQP, VBR  AV1: CPU, VBR, CVBR=CBR  |
| mfx.QPP                       | [0-51] HEVC, [0-63] AV1                  |
| mfx.InitialDelayInKB          | 0-65535                                  |
| mfx.BufferSizeInKB            | 0-65535                                  |
| mfx.MaxKbps                   | 0-65535                                  |
| mfx.CodecProfile              | see below                                |
| mfx.CodecLevel                | see below                                |
| mfx.TargetUsage               | 1(best quality)  -7(best speed)          | 

### Profiles

| HEVC Profiles                 | AV1 Profiles                  |
|-------------------------------|-------------------------------|
| MFX_PROFILE_HEVC_MAIN         |        |
| MFX_PROFILE_HEVC_MAIN10       |        |


### Levels

| HEVC Levels                   |   AV1 Levels   |
|-------------------------------|----------------|
| MFX_LEVEL_HEVC_1              |                |
| MFX_LEVEL_HEVC_2              |                |
| MFX_LEVEL_HEVC_21             |                |
| MFX_LEVEL_HEVC_3              |                |
| MFX_LEVEL_HEVC_31             |                |
| MFX_LEVEL_HEVC_4              |                |
| MFX_LEVEL_HEVC_41             |                |
| MFX_LEVEL_HEVC_5              |                |
| MFX_LEVEL_HEVC_51             |                |
| MFX_LEVEL_HEVC_52             |                |
| MFX_LEVEL_HEVC_6              |                |
| MFX_LEVEL_HEVC_61             |                |
| MFX_LEVEL_HEVC_62             |                |
|                               |                | 
| MFX_TIER_HEVC_MAIN  = 0       |                |
| MFX_TIER_HEVC_HIGH  = 0x100   |                |

