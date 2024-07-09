
/*
 * Copyright (c) 2022 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */


#ifndef MESON_DISPLAY_MODE_PRIVATE_H
#define MESON_DISPLAY_MODE_PRIVATE_H

/* RX support deep color */
#define DISPLAY_HDMI_DEEP_COLOR         "/sys/class/amhdmitx/amhdmitx0/dc_cap"
/* testing if tv support this displaymode and  deepcolor combination, then if cat result is 1: support, 0: not */
#define DISPLAY_HDMI_VALID_MODE         "/sys/class/amhdmitx/amhdmitx0/valid_mode"

#define DV_MODE_720P50HZ                "720p50hz"
#define DV_MODE_720P                    "720p60hz"
#define DV_MODE_1080P24HZ               "1080p24hz"
#define DV_MODE_1080P50HZ               "1080p50hz"
#define DV_MODE_1080P                   "1080p60hz"
#define DV_MODE_4K2K24HZ                "2160p24hz"
#define DV_MODE_4K2K25HZ                "2160p25hz"
#define DV_MODE_4K2K30HZ                "2160p30hz"
#define DV_MODE_4K2K50HZ                "2160p50hz"
#define DV_MODE_4K2K60HZ                "2160p60hz"
#define DV_MODE_LIST_SIZE               10

/*for check high frame rate support dv or not*/
#define DV_VSVDB_PARITY                 "Parity: 1"

#define MODE_576CVBS                    "576cvbs"
#define MODE_480CVBS                    "480cvbs"

#define MODE_480I                       "480i60hz"
#define MODE_480P                       "480p60hz"
#define MODE_640x480P                   "640x480p60hz"
#define MODE_576I                       "576i50hz"
#define MODE_576P                       "576p50hz"
#define MODE_720P50HZ                   "720p50hz"
#define MODE_720P                       "720p60hz"
#define MODE_720P100HZ                  "1280x720p100hz"
#define MODE_720P120HZ                  "1280x720p120hz"
#define MODE_768P                       "768p60hz"
#define MODE_1080P24HZ                  "1080p24hz"
#define MODE_1080P25HZ                  "1080p25hz"
#define MODE_1080P30HZ                  "1080p30hz"
#define MODE_1080I50HZ                  "1080i50hz"
#define MODE_1080P50HZ                  "1080p50hz"
#define MODE_1080I                      "1080i60hz"
#define MODE_1080P                      "1080p60hz"
#define MODE_1080P100HZ                 "1920x1080p100hz"
#define MODE_1080P120HZ                 "1920x1080p120hz"
#define MODE_4K2K24HZ                   "2160p24hz"
#define MODE_4K2K25HZ                   "2160p25hz"
#define MODE_4K2K30HZ                   "2160p30hz"
#define MODE_4K2K50HZ                   "2160p50hz"
#define MODE_4K2K60HZ                   "2160p60hz"
#define MODE_4K2K100HZ                  "3840x2160p100hz"
#define MODE_4K2K120HZ                  "3840x2160p120hz"
#define MODE_4K2KSMPTE24HZ              "smpte24hz"
#define MODE_4K2KSMPTE30HZ              "smpte30hz"
#define MODE_4K2KSMPTE50HZ              "smpte50hz"
#define MODE_4K2KSMPTE60HZ              "smpte60hz"
#define MODE_8K4K24HZ                   "7680x4320p24hz"
#define MODE_8K4K25HZ                   "7680x4320p25hz"
#define MODE_8K4K30HZ                   "7680x4320p30hz"
#define MODE_8K4K48HZ                   "7680x4320p48hz"
#define MODE_8K4K50HZ                   "7680x4320p50hz"
#define MODE_8K4K60HZ                   "7680x4320p60hz"

#define MODE_PANEL                      "panel"
#define MODE_PAL_M                      "pal_m"
#define MODE_PAL_N                      "pal_n"
#define MODE_NTSC_M                     "ntsc_m"


#define COLOR_YCBCR444_12BIT             "444,12bit"
#define COLOR_YCBCR444_10BIT             "444,10bit"
#define COLOR_YCBCR444_8BIT              "444,8bit"
#define COLOR_YCBCR422_12BIT             "422,12bit"
#define COLOR_YCBCR422_10BIT             "422,10bit"
#define COLOR_YCBCR422_8BIT              "422,8bit"
#define COLOR_YCBCR420_12BIT             "420,12bit"
#define COLOR_YCBCR420_10BIT             "420,10bit"
#define COLOR_YCBCR420_8BIT              "420,8bit"
#define COLOR_RGB_12BIT                  "rgb,12bit"
#define COLOR_RGB_10BIT                  "rgb,10bit"
#define COLOR_RGB_8BIT                   "rgb,8bit"

static const char* DV_MODE_LIST[DV_MODE_LIST_SIZE] = {
    DV_MODE_720P50HZ,
    DV_MODE_720P,
    DV_MODE_1080P24HZ,
    DV_MODE_1080P50HZ,
    DV_MODE_1080P,
    DV_MODE_4K2K24HZ,
    DV_MODE_4K2K25HZ,
    DV_MODE_4K2K30HZ,
    DV_MODE_4K2K50HZ,
    DV_MODE_4K2K60HZ,
};

static const char* DISPLAY_MODE_LIST[] = {
    MODE_480I,
    MODE_480P,
    MODE_640x480P,
    MODE_576I,
    MODE_576P,
    MODE_720P,
    MODE_720P50HZ,
    MODE_1080P24HZ,
    MODE_1080P25HZ,
    MODE_1080P30HZ,
    MODE_1080I50HZ,
    MODE_1080P50HZ,
    MODE_1080I,
    MODE_1080P,
    MODE_4K2K24HZ,
    MODE_4K2K25HZ,
    MODE_4K2K30HZ,
    MODE_4K2K50HZ,
    MODE_4K2K60HZ,
    MODE_4K2KSMPTE24HZ,
    MODE_4K2KSMPTE30HZ,
    MODE_4K2KSMPTE50HZ,
    MODE_4K2KSMPTE60HZ,
    MODE_480CVBS,
    MODE_576CVBS,
    MODE_768P,
    MODE_PANEL,
    MODE_PAL_M,
    MODE_PAL_N,
    MODE_NTSC_M,
};

static const char* MODE_RESOLUTION_FIRST[] = {
    MODE_480I,
    MODE_576I,
    MODE_1080I50HZ,
    MODE_1080I,
    MODE_480P,
    MODE_576P,
    MODE_720P50HZ,
    MODE_720P,
    MODE_1080P50HZ,
    MODE_1080P,
    MODE_4K2K24HZ,
    MODE_4K2K25HZ,
    MODE_4K2K30HZ,
    MODE_4K2K50HZ,
    MODE_4K2K60HZ,
};

static const char* MODE_FRAMERATE_FIRST[] = {
    MODE_480I,
    MODE_576I,
    MODE_1080I50HZ,
    MODE_1080I,
    MODE_480P,
    MODE_576P,
    MODE_720P50HZ,
    MODE_720P,
    MODE_4K2K24HZ,
    MODE_4K2K25HZ,
    MODE_4K2K30HZ,
    MODE_1080P50HZ,
    MODE_1080P,
    MODE_4K2K50HZ,
    MODE_4K2K60HZ,
};

//for check hdr 4k support or not
static const char* MODE_4K_LIST[] = {
    MODE_4K2K60HZ,
    MODE_4K2K50HZ,
};

//for check hdr non-4k support or not
static const char* MODE_NON4K_LIST[] = {
    MODE_1080P,
    MODE_1080P50HZ,
    MODE_720P,
    MODE_720P50HZ,
    MODE_576P,
    MODE_480P,
    MODE_1080I,
    MODE_1080I50HZ,
    MODE_576I,
    MODE_480I,
};

//this is prior selected list for sdr of 4k2k50hz, 4k2k60hz smpte50hz, smpte60hz
//for user change resolution case
static const char* COLOR_ATTRIBUTE_LIST1[] = {
    COLOR_YCBCR420_10BIT,
    COLOR_YCBCR422_12BIT,
    COLOR_YCBCR420_8BIT,
    COLOR_YCBCR444_8BIT,
    COLOR_RGB_8BIT,
};

//this is prior selected list for hdr and sdr  of non 4k display mode
//for user change resolution case
static const char* COLOR_ATTRIBUTE_LIST2[] = {
    COLOR_YCBCR422_12BIT,
    COLOR_YCBCR444_10BIT,
    COLOR_RGB_10BIT,
    COLOR_YCBCR444_8BIT,
    COLOR_RGB_8BIT,
};

//this is prior selected list for sdr  of non 4k display mode
static const char* SDR_NON4K_COLOR_ATTRIBUTE_LIST[] = {
    COLOR_YCBCR444_8BIT,
    COLOR_RGB_8BIT,
    COLOR_YCBCR422_12BIT,
    COLOR_YCBCR444_10BIT,
    COLOR_RGB_10BIT,
};

//this is prior selected list  of Low Power Mode 4k2k50hz, 4k2k60hz smpte50hz, smpte60hz
static const char* COLOR_ATTRIBUTE_LIST3[] = {
    COLOR_YCBCR420_8BIT,
    COLOR_YCBCR420_10BIT,
    COLOR_YCBCR422_8BIT,
    COLOR_YCBCR422_10BIT,
    COLOR_YCBCR444_8BIT,
    COLOR_RGB_8BIT,
    COLOR_YCBCR420_12BIT,
    COLOR_YCBCR422_12BIT,
};

//this is prior selected list of Low Power Mode other display mode
static const char* COLOR_ATTRIBUTE_LIST4[] = {
    COLOR_YCBCR444_8BIT,
    COLOR_YCBCR422_8BIT,
    COLOR_RGB_8BIT,
    COLOR_YCBCR444_10BIT,
    COLOR_YCBCR422_10BIT,
    COLOR_RGB_10BIT,
    COLOR_YCBCR444_12BIT,
    COLOR_YCBCR422_12BIT,
    COLOR_RGB_12BIT,
};

//this is prior selected list of HDR non 4k colorspace
static const char* HDR_NON4K_COLOR_ATTRIBUTE_LIST[] = {
    COLOR_YCBCR422_12BIT,
    COLOR_YCBCR444_10BIT,
    COLOR_RGB_10BIT,
    COLOR_YCBCR444_12BIT,
    COLOR_RGB_12BIT,
};

//this is prior selected list of HDR 4k colorspace(2160p60hz/2160p50hz)
static const char* HDR_4K_COLOR_ATTRIBUTE_LIST[] = {
    COLOR_YCBCR420_10BIT,
    COLOR_YCBCR422_12BIT,
};

#endif // MESON_DISPLAY_MODE_PRIVATE_H
