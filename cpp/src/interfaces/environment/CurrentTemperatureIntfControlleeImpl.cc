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

#include <qcc/Util.h>

#include <alljoyn/hae/LogModule.h>
#include <alljoyn/hae/interfaces/environment/CurrentTemperatureIntfControlleeListener.h>
#include <alljoyn/hae/HaeBusObject.h>
#include "CurrentTemperatureIntfControlleeImpl.h"

using namespace qcc;
using namespace std;

namespace ajn {
namespace services {


HaeInterface* CurrentTemperatureIntfControlleeImpl::CreateInterface(BusAttachment& busAttachment, InterfaceControlleeListener& listener, HaeBusObject& haeBusObject)
{
    return new CurrentTemperatureIntfControlleeImpl(busAttachment, static_cast<CurrentTemperatureIntfControlleeListener&>(listener), haeBusObject);
}


CurrentTemperatureIntfControlleeImpl::CurrentTemperatureIntfControlleeImpl(BusAttachment& busAttachment, CurrentTemperatureIntfControlleeListener& listener, HaeBusObject& haeBusObject) :
    InterfaceControllee(haeBusObject),
    m_busAttachment(busAttachment),
    m_interfaceListener(listener),
    m_CurrentValue(0)
{
}

CurrentTemperatureIntfControlleeImpl::~CurrentTemperatureIntfControlleeImpl()
{
}

QStatus CurrentTemperatureIntfControlleeImpl::Init()
{
    QStatus status = HaeInterface::Init();

    return status;
}

QStatus CurrentTemperatureIntfControlleeImpl::OnGetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;


    if (!(s_prop_Version.compare(propName))) {
        val.typeId = ALLJOYN_UINT16;
        val.v_uint16 = GetInterfaceVersion();
    } else {
        if (s_retrievingActualPropertyValue) {
            if (!(s_prop_CurrentValue.compare(propName))) {
                double value;
                status = m_interfaceListener.OnGetCurrentValue(value);
                if (status != ER_OK) {
                    value = GetCurrentValue();
                    QCC_LogError(status, ("%s: failed to get actual property value from application. use previous value.", __func__));
                    status = ER_OK;
                } else {
                    SetCurrentValue(value); // update the value in CurrentTemperatureIntfControllee.
                }

                val.typeId = ALLJOYN_DOUBLE;
                val.v_double = value;
            } else {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }

        } else {
            if (!(s_prop_CurrentValue.compare(propName))) {
                const double value = GetCurrentValue();
                val.typeId = ALLJOYN_DOUBLE;
                val.v_double = value;
            } else {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }
        }
    }

    return status;
}

QStatus CurrentTemperatureIntfControlleeImpl::OnSetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;

    if (!(s_prop_CurrentValue.compare(propName))) {
        if (val.typeId != ALLJOYN_DOUBLE) {
            status = ER_BUS_NO_SUCH_PROPERTY;
            return status;
        }
        status = ER_BUS_PROPERTY_VALUE_NOT_SET;

    } else {
        status = ER_BUS_NO_SUCH_PROPERTY;
    }

    return status;
}

void CurrentTemperatureIntfControlleeImpl::OnMethodHandler(const InterfaceDescription::Member* member, Message& msg)
{
    QStatus status = ER_OK;
    bool isFound = false;
    MethodHandlers::const_iterator it;
    for (it = m_methodHandlers.begin(); it != m_methodHandlers.end(); ++it) {
        if (it->first == member) {
            MessageReceiver::MethodHandler handler = it->second;
            (this->*handler)(member, msg);
            isFound = true;
        }
    }

    if (!isFound) {
        status = ER_BUS_METHOD_CALL_ABORTED;
        QCC_LogError(status, ("%s: could not found method handler.", __func__));
        m_busObject.ReplyMethodCall(msg, status);
    }
}


QStatus CurrentTemperatureIntfControlleeImpl::SetCurrentValue(const double value)
{
    if (m_CurrentValue != value) {
        MsgArg val;
        val.typeId = ALLJOYN_DOUBLE;
        val.v_double = value;
        m_busObject.EmitPropChanged(GetInterfaceName().c_str(), s_prop_CurrentValue.c_str(), val, 0, ALLJOYN_FLAG_GLOBAL_BROADCAST);
        m_CurrentValue = value;
    }

    return ER_OK;
}


} //namespace services
} //namespace ajn