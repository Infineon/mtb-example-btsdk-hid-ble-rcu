/*
 * Copyright 2016-2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 *
 * BR/EDR function and data
 *
 */
#ifndef __APP_BT_H__
#define __APP_BT_H__

#include "ble.h"

extern wiced_bt_cfg_settings_t bt_cfg;
extern uint8_t dev_local_name[];
extern uint8_t blehid_rpt_map[];

#if defined(MOUSE_XY_SIZE_16)
# define MOUSE_XY_SIZE 16
#elif defined(MOUSE_XY_SIZE_12)
# define MOUSE_XY_SIZE 12
#else
# define MOUSE_XY_SIZE 8
#endif

#define STD_KB_REPORT_DESCRIPTOR \
    /* RPT_ID_IN_STD_KEY */ \
    /* Input Report, 8 bytes */ \
    /* 1st byte:Keyboard LeftControl/Keyboard Right GUI */ \
    /* 2nd byte:Constant, 3rd ~ 6th: keycode */ \
    /* Output Report, 1 byte: LED control */ \
    0x05, 0x01,                    /* USAGE_PAGE (Generic Desktop) */ \
    0x09, 0x06,                    /* USAGE (Keyboard) */ \
    0xA1, 0x01,                    /* COLLECTION (Application) */ \
    0x85, RPT_ID_IN_STD_KEY,       /*    REPORT_ID */ \
    0x75, 0x01,                    /*    REPORT_SIZE (1) */ \
    0x95, 0x08,                    /*    REPORT_COUNT (8) */ \
    0x05, 0x07,                    /*    USAGE_PAGE (Keyboard) */ \
    0x19, 0xE0,                    /*    USAGE_MINIMUM (Keyboard LeftControl) */ \
    0x29, 0xE7,                    /*    USAGE_MAXIMUM (Keyboard Right GUI) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x25, 0x01,                    /*    LOGICAL_MAXIMUM (1) */ \
    0x81, 0x02,                    /*    INPUT (Data,Var,Abs) */ \
    0x95, 0x01,                    /*    REPORT_COUNT (1) */ \
    0x75, 0x08,                    /*    REPORT_SIZE (8) */ \
    0x81, 0x03,                    /*    INPUT (Cnst,Var,Abs) */ \
    0x95, 0x05,                    /*    REPORT_COUNT (5) */ \
    0x75, 0x01,                    /*    REPORT_SIZE (1) */ \
    0x05, 0x08,                    /*    USAGE_PAGE (LEDs) */ \
    0x19, 0x01,                    /*    USAGE_MINIMUM (Num Lock) */ \
    0x29, 0x05,                    /*    USAGE_MAXIMUM (Kana) */ \
    0x91, 0x02,                    /*    OUTPUT (Data,Var,Abs) */ \
    0x95, 0x01,                    /*    REPORT_COUNT (1) */ \
    0x75, 0x03,                    /*    REPORT_SIZE (3) */ \
    0x91, 0x03,                    /*    OUTPUT (Cnst,Var,Abs) */ \
    0x95, 0x06,                    /*    REPORT_COUNT (6) */ \
    0x75, 0x08,                    /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF, 0x00,              /*    LOGICAL_MAXIMUM (255) */ \
    0x05, 0x07,                    /*    USAGE_PAGE (Keyboard) */ \
    0x19, 0x00,                    /*    USAGE_MINIMUM (Reserved (no event indicated)) */ \
    0x29, 0xFF,                    /*    USAGE_MAXIMUM (Reserved (no event indicated)) */ \
    0x81, 0x00,                    /*    INPUT (Data,Ary,Abs) */ \
    0xC0,                          /* END_COLLECTION */

#define USAGE_POWER         0x09, 0x30
#define USAGE_MENU          0x09, 0x40
#define USAGE_MENU_PICK     0x09, 0x41
#define USAGE_MENU_UP       0x09, 0x42
#define USAGE_MENU_DOWN     0x09, 0x43
#define USAGE_MENU_LEFT     0x09, 0x44
#define USAGE_MENU_RIGHT    0x09, 0x45
#define USAGE_MENU_ESC      0x09, 0x46
#define USAGE_RECALL_LAST   0x09, 0x83
#define USAGE_ODR_MOVIE     0x09, 0x85
#define USAGE_CH            0x09, 0x86
#define USAGE_CH_UP         0x09, 0x9C
#define USAGE_CH_DOWN       0x09, 0x9D
#define USAGE_FAST_FORWRD   0x09, 0xB3
#define USAGE_REWIND        0x09, 0xB4
#define USAGE_NEXT_TRACK    0x09, 0xB5
#define USAGE_PREV_TRACK    0x09, 0xB6
#define USAGE_PLAY_PAUSE    0x09, 0xCD
#define USAGE_MUTE          0x09, 0xE2
#define USAGE_VOL_UP        0x09, 0xE9
#define USAGE_VOL_DOWN      0x09, 0xEA
#define USAGE_SHOPPING      0x0A, 0xC1, 0x01
#define USAGE_AC_SEARCH     0x0A, 0x21, 0x02
#define USAGA_AC_HOME       0x0A, 0x23, 0x02
#define USAGE_AC_BACK       0x0A, 0x24, 0x02
#define USAGE_VIEW_TOGGLE   0x0A, 0x32, 0x02
#define USAGE_NUMBER_LIST   0x0A, 0x58, 0x02
#define USAGE_PR_REVIEW     0x0A, 0x67, 0x02

#define BITMAPPED_REPORT_DESCRIPTOR \
    /* Bit mapped report, BITMAPPED_REPORT_ID */ \
    0x05, 0x0C,                    /* USAGE_PAGE (Consumer Devices) */ \
    0x09, 0x01,                    /* USAGE (Consumer Control) */ \
    0xA1, 0x01,                    /* COLLECTION (Application) */ \
    0x85, RPT_ID_IN_BIT_MAPPED,    /*    REPORT_ID (2) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x25, 0x01,                    /*    LOGICAL_MAXIMUM (1) */ \
    0x75, 0x01,                    /*    REPORT_SIZE (1) */ \
    0x95, BITMAP_MAX,              /*    REPORT_COUNT (8) */ \
    /* byte 0 */ \
    USAGE_AC_SEARCH,               /*0   USAGE (AC Search) */ \
    USAGA_AC_HOME,                 /*1   USAGE (AC Home) */ \
    USAGE_AC_BACK,                 /*2   USAGE (AC Back) */ \
    USAGE_FAST_FORWRD,             /*3   USAGE (Fast Forward) */ \
    USAGE_PLAY_PAUSE,              /*4   USAGE (Play/Pause) */ \
    USAGE_REWIND,                  /*5   USAGE (Rewind) */ \
    USAGE_MENU,                    /*6   USAGE (Menu) */ \
    USAGE_MENU_ESC,                /*7   USAGE (Menu ESC) */ \
    0x81, 0x02,                    /*    INPUT (Data,Var,Abs) */ \
    0xC0,                          /* END_COLLECTION */

#define MEDIA_KEY_REPORT_DESCRIPTOR \
    /* Media key report */ \
    0x05, 0x0C,                    /* Usage Page (Consumer Devices) */ \
    0x09, 0x01,                    /* Usage (Consumer Control) */ \
    0xA1, 0x01,                    /* Collection (Application) */ \
    0x85, RPT_ID_IN_MEDIA_KEY,     /*    Report ID */ \
    0x95, 0x08,                    /*    REPORT_COUNT (8) */ \
    0x75, KEY_NUM_BYTES_IN_USER_DEFINED_REPORT, /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF , 0x00,             /*    LOGICAL_MAXIMUM (255) */ \
    0x05, 0x07,                    /*    USAGE_PAGE (Keyboard) */ \
    0x19, 0x00,                    /*    USAGE_MINIMUM (Reserved (no event indicated)) */ \
    0x29, 0xFF,                    /*    USAGE_MAXIMUM (Reserved (no event indicated)) */ \
    0x81, 0x00,                    /*    INPUT (Data,Ary,Abs) */ \
    0xC0,                          /* END_COLLECTION */

#ifdef HID_AUDIO
#define AUDIO_LE_REPORT_DESCRIPTOR \
    /*audio report, WICED_HIDD_VOICE_REPORT_ID */ \
    0x05, 0x0C,                                         /* Usage Page (Consumer Devices) */ \
    0x09, 0x01,                                         /* Usage (Consumer Control) */ \
    0xA1, 0x01,                                         /* Collection (Application) */ \
    0x85, RPT_ID_IN_AUDIO_DATA,                         /*    Report ID */ \
    0x96, AUDIO_MTU_SIZE & 0xff, AUDIO_MTU_SIZE >> 8,   /*    REPORT_COUNT (audio data size) */ \
    0x75, 0x08,                                         /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                                         /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF, 0x00,                                   /*    LOGICAL_MAXIMUM (255) */ \
    0x81, 0x00,                                         /*    INPUT (Data,Ary,Abs) */ \
    0xC0,                                               /* END_COLLECTION */

#define AUDIO_BREDR_REPORT_DESCRIPTOR \
    /*audio report, WICED_HIDD_VOICE_REPORT_ID */ \
    0x05, 0x0C,                                         /* Usage Page (Consumer Devices) */ \
    0x09, 0x01,                                         /* Usage (Consumer Control) */ \
    0xA1, 0x01,                                         /* Collection (Application) */ \
    0x85, RPT_ID_IN_AUDIO_DATA,                         /*    Report ID */ \
    0x95, 0x0B,                                         /*    REPORT_COUNT (11) */ \
    0x75, 0x08,                                         /*    REPORT_SIZE (8) */ \
    0x81, 0x00,                                         /*    INPUT (Data,Ary,Abs) */ \
    0x15, 0x00,                                         /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF, 0x00,                                   /*    LOGICAL_MAXIMUM (255) */ \
    0x96, AUDIO_MTU_SIZE & 0xff, AUDIO_MTU_SIZE >> 8,   /*    REPORT_COUNT (audio data size) */ \
    0x75, 0x08,                                         /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                                         /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF, 0x00,                                   /*    LOGICAL_MAXIMUM (255) */ \
    0x81, 0x00,                                         /*    INPUT (Data,Ary,Abs) */ \
    0xC0,                                               /* END_COLLECTION */

#define AUDIO_CTRL_REPORT_DESCRIPTOR \
    /*voice ctrl report, WICED_HIDD_VOICE_CTL_REPORT_ID */ \
    0x05, 0x0C,                    /* Usage Page (Consumer Devices) */ \
    0x09, 0x01,                    /* Usage (Consumer Control) */ \
    0xA1, 0x01,                    /* Collection (Application) */ \
    0x85, RPT_ID_IN_AUDIO_CTL,     /*    Report ID=0xF8 */ \
    0x95, 0x0B,                    /*    REPORT_COUNT (11) */ \
    0x75, 0x08,                    /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF , 0x00,             /*    LOGICAL_MAXIMUM (255) */ \
    0x81, 0x00,                    /*    INPUT (Data,Ary,Abs) */ \
    0x95, 0x0B,                    /*    REPORT_COUNT (11) */ \
    0x75, 0x01,                    /*    REPORT_SIZE (8) */ \
    0x15, 0x00,                    /*    LOGICAL_MINIMUM (0) */ \
    0x26, 0xFF , 0x00,             /*    LOGICAL_MAXIMUM (255) */ \
    0xB1, 0x00,                    /*    FEATURE (Data,Ary,Abs) */ \
    0xC0,                          /* END_COLLECTION */
#else
#define AUDIO_LE_REPORT_DESCRIPTOR
#define AUDIO_BREDR_REPORT_DESCRIPTOR
#define AUDIO_CTRL_REPORT_DESCRIPTOR
#endif

// Use BATTERY_REPORT_DESCRIPTOR for the last entry because it has no ',' in the end
#define BATTERY_REPORT_DESCRIPTOR \
    /*Battery report */ \
    0x05, 0x0C,                    /* Usage Page (Consumer Devices), */ \
    0x09, 0x01,                    /* Usage (Consumer Control), */ \
    0xA1, 0x01,                    /* COLLECTION (Application) */ \
    0x85, RPT_ID_IN_BATTERY,       /*    REPORT_ID (3) */ \
    0x05, 0x01,                    /*    Usage Page (Generic Desktop), */ \
    0x09, 0x06,                    /*    Usage (Keyboard) */ \
    0xA1, 0x02,                    /*    Collection: (Logical), */ \
    0x05, 0x06,                    /*        USAGE PAGE (Generic Device Control), */ \
    0x09, 0x20,                    /*        USAGE (Battery Strength), */ \
    0x15, 0x00,                    /*        Log Min (0), */ \
    0x26, 0x64 , 0x00,             /*        Log Max (255), */ \
    0x75, 0x08,                    /*        Report Size (8), */ \
    0x95, 0x01,                    /*        Report Count (1), */ \
    0x81, 0x02,                    /*        Input (Data, Variable, Absolute), */ \
    0xC0,                          /*    END_COLLECTION (Logical) */ \
    0xC0                           /* END_COLLECTION */

#define USB_LE_RPT_DESCRIPTOR \
{\
  STD_KB_REPORT_DESCRIPTOR \
  BITMAPPED_REPORT_DESCRIPTOR \
  MEDIA_KEY_REPORT_DESCRIPTOR \
  AUDIO_LE_REPORT_DESCRIPTOR \
  AUDIO_CTRL_REPORT_DESCRIPTOR \
  BATTERY_REPORT_DESCRIPTOR \
}

/*******************************************************************************
 * Function Name: void bt_init()
 ********************************************************************************
 * Summary: Bluetooth transport init.
 *
 * Parameters:
 *  none
 *
 * Return:
 *  none
 *
 *******************************************************************************/
void bt_init();

#else
#define bt_init()
#endif // __APP_BT_H__
