/*############################################################################
  # Copyright (C) 2017-2020 Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#ifndef __MFX_JPEG_H__
#define __MFX_JPEG_H__

#include "mfxdefs.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* CodecId */
enum {
    MFX_CODEC_JPEG    = MFX_MAKEFOURCC('J','P','E','G') /*!< JPEG codec */
};

/* CodecProfile, CodecLevel */
enum
{
    MFX_PROFILE_JPEG_BASELINE      = 1 /*!< Baseline JPEG Profile. */
};

/*! The Rotation enumerator itemizes the JPEG rotation options. */
enum
{
    MFX_ROTATION_0      = 0, /*!< No rotation. */
    MFX_ROTATION_90     = 1, /*!< 90 degree rotation */
    MFX_ROTATION_180    = 2, /*!< 180 degree rotation */
    MFX_ROTATION_270    = 3  /*!< 270 degree rotation */
};

enum {
    MFX_EXTBUFF_JPEG_QT      = MFX_MAKEFOURCC('J','P','G','Q'), /*!< This extended buffer defines quantization tables for JPEG encoder. */
    MFX_EXTBUFF_JPEG_HUFFMAN = MFX_MAKEFOURCC('J','P','G','H')  /*!< This extended buffer defines Huffman tables for JPEG encoder. */
};

/*! The JPEGColorFormat enumerator itemizes the JPEG color format options. */
enum {
    MFX_JPEG_COLORFORMAT_UNKNOWN = 0, /*! Unknown color format. The SDK decoder tries to determine color format from available in bitstream information.
                                          If such information is not present, then MFX_JPEG_COLORFORMAT_YCbCr color format is assumed. */
    MFX_JPEG_COLORFORMAT_YCbCr   = 1, /*! Bitstream contains Y, Cb and Cr components. */
    MFX_JPEG_COLORFORMAT_RGB     = 2  /*! Bitstream contains R, G and B components. */
};

/*! The JPEGScanType enumerator itemizes the JPEG scan types. */
enum {
    MFX_SCANTYPE_UNKNOWN        = 0, /*!< Unknown scan type. */
    MFX_SCANTYPE_INTERLEAVED    = 1, /*!< Interleaved scan. */
    MFX_SCANTYPE_NONINTERLEAVED = 2  /*!< Non-interleaved scan. */
};

enum {
    MFX_CHROMAFORMAT_JPEG_SAMPLING = 6 /*!< Color sampling specified via mfxInfoMFX::SamplingFactorH and SamplingFactorV. */
};

MFX_PACK_BEGIN_USUAL_STRUCT()
/*!
   The mfxExtJPEGQuantTables structure specifies quantization tables. The application may specify up to 4 quantization tables. The SDK encoder assigns ID to each table.
   That ID is equal to table index in Qm array. Table “0” is used for encoding of Y component, table “1” for U component and table “2”
   for V component. The application may specify fewer tables than number of components in the image. If two tables are specified,
   then table “1” is used for both U and V components. If only one table is specified then it is used for all components in the image.
   Table below illustrate this behavior.

   @internal
   +------------------+---------+------+---+
   | Table ID         | 0       | 1    | 2 |
   +------------------+---------+------+---+
   | Number of tables |         |      |   |
   +==================+=========+======+===+
   | 0                | Y, U, V |      |   |
   +------------------+---------+------+---+
   | 1                | Y       | U, V |   |
   +------------------+---------+------+---+
   | 2                | Y       | U    | V |
   +------------------+---------+------+---+
   @endinternal
*/
typedef struct {
    mfxExtBuffer    Header; /*!< Extension buffer header. Header.BufferId must be equal to MFX_EXTBUFF_JPEG_QT. */

    mfxU16  reserved[7];
    mfxU16  NumTable;       /*!< Number of quantization tables defined in Qmarray. */

    mfxU16    Qm[4][64];    /*!< Quantization table values. */
} mfxExtJPEGQuantTables;
MFX_PACK_END()

MFX_PACK_BEGIN_USUAL_STRUCT()
/*!
   The mfxExtJPEGHuffmanTables structure specifies Huffman tables. The application may specify up to 2 quantization table pairs for baseline process. The SDK encoder
   assigns ID to each table. That ID is equal to table index in DCTables and ACTables arrays. Table “0” is used for encoding of Y component,
   table “1” for U and V component. The application may specify only one table in this case it will be used for all components in the image.
   Table below illustrate this behavior.

   @internal
   +------------------+---------+------+
   | Table ID         | 0       | 1    |
   +------------------+---------+------+
   | Number of tables |         |      |
   +==================+=========+======+
   | 0                | Y, U, V |      |
   +------------------+---------+------+
   | 1                | Y       | U, V |
   +------------------+---------+------+
   @endinternal
*/
typedef struct {
    mfxExtBuffer    Header; /*!< Extension buffer header. Header.BufferId must be equal to MFX_EXTBUFF_JPEG_HUFFMAN. */

    mfxU16  reserved[2];
    mfxU16  NumDCTable;      /*!< Number of DC quantization table in DCTables array. */
    mfxU16  NumACTable;      /*!< Number of AC quantization table in ACTables array. */

    struct {
        mfxU8   Bits[16];    /*!< Number of codes for each code length. */
        mfxU8   Values[12];  /*!< List of the 8-bit symbol values. */
    } DCTables[4];           /*!< Array of DC tables. */

    struct {
        mfxU8   Bits[16];    /*!< Number of codes for each code length. */
        mfxU8   Values[162]; /*!< Array of AC tables. */
    } ACTables[4];           /*!< List of the 8-bit symbol values. */
} mfxExtJPEGHuffmanTables;
MFX_PACK_END()

#ifdef __cplusplus
} // extern "C"
#endif /* __cplusplus */

#endif // __MFX_JPEG_H__
