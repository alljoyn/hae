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
#include <alljoyn/hae/interfaces/operation/CurrentPowerInterface.h>

namespace ajn {
namespace services {

const uint16_t CurrentPowerInterface::s_interfaceVersion = 1;

// Below none secure xml is only for test
const qcc::String CurrentPowerInterface::s_xml =
"<node xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xsi:noNamespaceSchemaLocation='http://www.allseenalliance.org/schemas/introspect.xsd'>"
"    <interface name='org.alljoyn.SmartSpaces.Operation.CurrentPower'>"
"        <description language='en'>Interface that exposes information on Power consumption of the device.</description>"
"        <annotation name='org.alljoyn.Bus.Secure' value='true' />"
"        <property name='Version' type='q' access='read'>"
"            <description language='en'>The version of this interface</description>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"        </property>"
"        <property name='CurrentPower' type='d' access='read'>"
"            <description language='en'>The instantaneous power consumption of the device in watts (W).</description>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"        </property>"
"        <property name='Precision' type='d' access='read'>"
"            <description language='en'>The precision of the CurrentPower property.  i.e. the number of watts the"
"                actual power consumption must change before CurrentPower is updated.</description>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"        </property>"
"        <property name='UpdateMinTime' type='q' access='read'>"
"            <description language='en'>The minimum time between updates of the CurrentPower property in milliseconds.</description>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"        </property>"
"    </interface>"
"</node>"
;

const qcc::String CurrentPowerInterface::s_prop_Version = "Version";
const qcc::String CurrentPowerInterface::s_prop_CurrentPower = "CurrentPower";
const qcc::String CurrentPowerInterface::s_prop_Precision = "Precision";
const qcc::String CurrentPowerInterface::s_prop_UpdateMinTime = "UpdateMinTime";

} //namespace services
} //namespace ajn