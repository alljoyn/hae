/**
 * @file
 */
/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef HAECONTROLLEE_H_
#define HAECONTROLLEE_H_

#include <ajtcl/services/ServicesCommon.h>
#include <ajtcl/alljoyn.h>

typedef enum { false, true } bool;

typedef enum {
    UNDEFINED_INTERFACE             = 0,
    //INPUT
    HID_INTERFACE,

    //Environment
    CURRENT_AIR_QUALITY_INTERFACE,
    CURRENT_AIR_QUALITY_LEVEL_INTERFACE,
    CURRENT_HUMIDITY_INTERFACE,
    CURRENT_TEMPERATURE_INTERFACE,
    TARGET_HUMIDITY_INTERFACE,
    TARGET_TEMPERATURE_INTERFACE,
    TARGET_TEMPERATURE_LEVEL_INTERFACE,
    WATER_LEVEL_INTERFACE,
    WIND_DIRECTION_INTERFACE,

    //Operation
    AIR_RECIRCULATION_MODE_INTERFACE,
    ALERTS_INTERFACE,
    AUDIO_VIDEO_INPUT_INTERFACE,
    AUDIO_VOLUME_INTERFACE,
    BATTERY_STATUS_INTERFACE,
    CHANNEL_INTERFACE,
    CLIMATE_CONTROL_MODE_INTERFACE,
    CLOSED_STATUS_INTERFACE,
    CURRENT_POWER_INTERFACE,
    CYCLE_CONTROL_INTERFACE,
    DISH_WASHING_CYCLE_INTERFACE,
    ENERGY_USAGE_INTERFACE,
    FAN_SPEED_LEVEL_INTERFACE,
    FILTER_STATUS_INTERFACE,
    HEATING_ZONE_INTERFACE,
    HVAC_FAN_MODE_INTERFACE,
    LAUNDRY_CYCLE_INTERFACE,
    MOISTURE_OUTPUT_LEVEL_INTERFACE,
    ON_OFF_STATUS_INTERFACE,
    OFF_CONTROL_INTERFACE,
    ON_CONTROL_INTERFACE,
    OVEN_CYCLE_INTERFACE,
    PLUG_IN_UNITS_INTERFACE,
    RAPID_MODE_INTERFACE,
    RAPID_MODE_TIMED_INTERFACE,
    REMOTE_CONTROLLABILITY_INTERFACE,
    REPEAT_MODE_INTERFACE,
    RESOURCE_SAVING_INTERFACE,
    ROBOT_CLEANING_CYCLE_INTERFACE,
    SOIL_LEVEL_INTERFACE,
    SPIN_SPEED_LEVEL_INTERFACE,
    TIMER_INTERFACE,

    //UserInterfaceSettings
    LANGUAGE_DISPLAY_INTERFACE,
    TEMPERATURE_DISPLAY_INTERFACE,
    TIME_DISPLAY_INTERFACE,

    //////////////////////////////
    LAST_BASIC_INTERFACE_TYPE,
    NUMBER_OF_BASIC_INTERFACE_TYPE,
    MAX_BASIC_INTERFACE_TYPE        = NUMBER_OF_BASIC_INTERFACE_TYPE,

    // Vendor Defined Interface
    VENDOR_DEFIEND_INTERFACE        = 0x1000,

} HaeInterfaceTypes;

/**
 * Initialize HAE service framework.
 * @return AJ_OK on success.
 */
AJ_Status Hae_Init();

/**
 * Deinitialize HAE service framework.
 */
void Hae_Deinit();

/**
 * Create interface.
 * @param[in] intfType interface type
 * @param[in] objPath the object path including the interface
 * @param[in] listener interface listener
 * @return AJ_OK on success
 */
AJ_Status Hae_CreateInterface(HaeInterfaceTypes intfType, const char* objPath, void* listener);

/**
 * Start HAE service framework.
 * Objects with interfaces are registered.
 * @return AJ_OK on success
 */
AJ_Status Hae_Start();

/**
 * Function used to process HAE messages.
 * @param[in] busAttachment bus attachment
 * @param[in] msg message
 * @param[out] status status
 * @return service status
 */
AJSVC_ServiceStatus Hae_MessageProcessor(AJ_BusAttachment* busAttachment, AJ_Message* msg, AJ_Status* status);

#endif // HAECONTROLLEE_H_
