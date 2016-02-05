
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
#include <alljoyn/hae/interfaces/operation/AudioVolumeInterface.h>

namespace ajn {
namespace services {

const uint16_t AudioVolumeInterface::s_interfaceVersion = 1;

// Below none secure xml is only for test
const qcc::String AudioVolumeInterface::s_xml =
        "<node>"
        "    <interface name='org.alljoyn.SmartSpaces.Operation.AudioVolume'>"
        "        <description language='en'>This interface provides capabilities to control and monitor volume.</description>"
        "        <annotation name='org.alljoyn.Bus.Secure' value='true'/>"
        "        <property name='Version' type='q' access='read'>"
        "            <description language='en'>Interface version</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='Volume' type='y' access='readwrite'>"
        "            <description language='en'>Speaker volume index of the device</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='MaxVolume' type='y' access='read'>"
        "            <description language='en'>Maximum value allowed for Volume</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "        <property name='Mute' type='b' access='readwrite'>"
        "            <description language='en'>The state of volume muted</description>"
        "            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
        "        </property>"
        "    </interface>"
        "</node>";

const qcc::String AudioVolumeInterface::s_prop_Version = "Version";
const qcc::String AudioVolumeInterface::s_prop_Volume = "Volume";
const qcc::String AudioVolumeInterface::s_prop_Mute = "Mute";
const qcc::String AudioVolumeInterface::s_prop_MaxVolume = "MaxVolume";


} //namespace services
} //namespace ajn
