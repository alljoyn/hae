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
#include <alljoyn/hae/interfaces/operation/SoilLevelInterface.h>

namespace ajn {
namespace services {

const uint16_t SoilLevelInterface::s_interfaceVersion = 1;

// Below none secure xml is only for test
const qcc::String SoilLevelInterface::s_xml =
"<node xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xsi:noNamespaceSchemaLocation='http://www.allseenalliance.org/schemas/introspect.xsd'>"
"    <interface name='org.alljoyn.SmartSpaces.Operation.SoilLevel'>"
"        <description language='en'>This interface provides a capability to set target soil level</description>"
"        <annotation name='org.alljoyn.Bus.Secure' value='false'/>"
"        <property name='Version' type='q' access='read'>"
"            <description language='en'>The interface version</description>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"        </property>"
"        <property name='MaxLevel' type='y' access='read'>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"            <description language='en'>Maximum value allowed for target soil level setting</description>"
"        </property>"
"        <property name='TargetLevel' type='y' access='readwrite'>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"            <description language='en'>Target set-point value of soil level</description>"
"        </property>"
"        <property name='SelectableLevels' type='ay' access='read'>"
"            <annotation name='org.freedesktop.DBus.Property.EmitsChangedSignal' value='true'/>"
"            <description language='en'>List of the values of soil level which can be selected</description>"
"        </property>"
"    </interface>"
"</node>"
;

const qcc::String SoilLevelInterface::s_prop_Version = "Version";
const qcc::String SoilLevelInterface::s_prop_MaxLevel = "MaxLevel";
const qcc::String SoilLevelInterface::s_prop_TargetLevel = "TargetLevel";
const qcc::String SoilLevelInterface::s_prop_SelectableLevels = "SelectableLevels";
/**
 * TODO: initialize property, method and signal name variable
 */

} //namespace services
} //namespace ajn