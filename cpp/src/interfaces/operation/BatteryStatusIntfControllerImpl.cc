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

#include <qcc/Util.h>

#include <alljoyn/cdm/LogModule.h>
#include <alljoyn/cdm/CdmProxyBusObject.h>
#include <alljoyn/cdm/interfaces/operation/BatteryStatusIntfControllerListener.h>

#include "BatteryStatusIntfControllerImpl.h"

using namespace qcc;
using namespace std;

namespace ajn {
namespace services {

CdmInterface* BatteryStatusIntfControllerImpl::CreateInterface(BusAttachment& busAttachment, InterfaceControllerListener& listener, CdmProxyBusObject& cdmProxyObject)
{
    return new BatteryStatusIntfControllerImpl(busAttachment, dynamic_cast<BatteryStatusIntfControllerListener&>(listener), cdmProxyObject);
}

BatteryStatusIntfControllerImpl::BatteryStatusIntfControllerImpl(BusAttachment& busAttachment, BatteryStatusIntfControllerListener& listener, CdmProxyBusObject& cdmProxyObject) :
    InterfaceController(cdmProxyObject),
    m_busAttachment(busAttachment),
    m_interfaceListener(listener)
{
}

BatteryStatusIntfControllerImpl::~BatteryStatusIntfControllerImpl()
{
}

QStatus BatteryStatusIntfControllerImpl::Init()
{
    QStatus status = CdmInterface::Init();
    if (ER_OK != status) {
        QCC_LogError(status, ("%s: Interface init failed.", __func__));
        return status;
    }

    status = m_proxyObject.RegisterPropertiesChangedListener(GetInterfaceName().c_str(), NULL, 0, *this, NULL);
    if (ER_OK != status) {
        QCC_LogError(status, ("%s: RegisterPropertiesChangedListener failed.", __func__));
    }

    return status;
}

void BatteryStatusIntfControllerImpl::PropertiesChanged(ProxyBusObject& obj, const char* ifaceName, const MsgArg& changed, const MsgArg& invalidated, void* context)
{
    MsgArg* entries;
    size_t numEntries;

    changed.Get("a{sv}", &numEntries, &entries);
    for (size_t i = 0; i < numEntries; ++i) {
        const char* propName;
        MsgArg* propValue;
        entries[i].Get("{sv}", &propName, &propValue);
        String propNameStr(propName);

        if (!s_prop_CurrentValue.compare(propNameStr)) {
            if (propValue->typeId == ALLJOYN_BYTE) {
                uint8_t value = propValue->v_byte;
                m_interfaceListener.OnCurrentValueChanged(obj.GetPath(), value);
            }
        } else if (!s_prop_IsCharging.compare(propNameStr)) {
            if (propValue->typeId == ALLJOYN_BOOLEAN) {
                bool isCharging = propValue->v_bool;
                m_interfaceListener.OnIsChargingChanged(obj.GetPath(), isCharging);
            }
        }
    }
}

QStatus BatteryStatusIntfControllerImpl::GetCurrentValue(void* context)
{
    QStatus status = ER_OK;

    status = m_proxyObject.GetPropertyAsync(GetInterfaceName().c_str(), s_prop_CurrentValue.c_str(), this, (ProxyBusObject::Listener::GetPropertyCB)&BatteryStatusIntfControllerImpl::GetCurrentValuePropertyCB, context);

    return status;
}

QStatus BatteryStatusIntfControllerImpl::GetIsCharging(void* context)
{
    QStatus status = ER_OK;

    status = m_proxyObject.GetPropertyAsync(GetInterfaceName().c_str(), s_prop_IsCharging.c_str(), this, (ProxyBusObject::Listener::GetPropertyCB)&BatteryStatusIntfControllerImpl::GetIsChargingPropertyCB, context);

    return status;
}

void BatteryStatusIntfControllerImpl::GetCurrentValuePropertyCB(QStatus status, ProxyBusObject* obj, const MsgArg& value, void* context)
{
    if (!obj) {
        return;
    }

    uint8_t currentValue;
    value.Get("y", &currentValue);

    m_interfaceListener.OnResponseGetCurrentValue(status, obj->GetPath(), currentValue, context);
}

void BatteryStatusIntfControllerImpl::GetIsChargingPropertyCB(QStatus status, ProxyBusObject* obj, const MsgArg& value, void* context)
{
    if (!obj) {
        return;
    }

    bool isCharging;
    value.Get("b", &isCharging);

    m_interfaceListener.OnResponseGetIsCharging(status, obj->GetPath(), isCharging, context);
}

} //namespace services
} //namespace ajn
