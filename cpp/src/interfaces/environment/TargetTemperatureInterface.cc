
/******************************************************************************
 * Copyright (c) 2013-2014, AllSeen Alliance. All rights reserved.
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

#include <alljoyn/hae/LogModule.h>
#include <alljoyn/hae/interfaces/environment/TargetTemperatureInterface.h>

namespace ajn {
namespace services {

const uint16_t TargetTemperatureInterface::s_interfaceVersion = 1;

const qcc::String TargetTemperatureInterface::s_xml =
        "<node>"
        "    <interface name='org.alljoyn.SmartSpaces.Environment.TargetTemperature'>"
        "        <description language='en'>This interface is for setting target temperature of the HAE devices such as air conditioner, refrigerator, oven, etc.</description>"
        "        <annotation name='org.alljoyn.Bus.Secure' value='false'/>"
        "        <property name='Version' type='q' access='read'>"
        "            <description language='en'>The interface version</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='TargetValue' type='d' access='readwrite'>"
        "            <description language='en'>Target temperature expressed in Celsius</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='MinValue' type='d' access='read'>"
        "            <description language='en'>Minimum value of target temperature</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='MaxValue' type='d' access='read'>"
        "            <description language='en'>Maximum value of target temperature</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='StepValue' type='d' access='read'>"
        "            <description language='en'>Step value allowed for the TargetTemperature setting</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "    </interface>"
        "</node>";

const qcc::String TargetTemperatureInterface::s_prop_Version = "Version";
const qcc::String TargetTemperatureInterface::s_prop_TargetValue = "TargetValue";
const qcc::String TargetTemperatureInterface::s_prop_MinValue = "MinValue";
const qcc::String TargetTemperatureInterface::s_prop_MaxValue = "MaxValue";
const qcc::String TargetTemperatureInterface::s_prop_StepValue = "StepValue";

} //namespace services
} //namespace ajn
