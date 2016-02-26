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
#include <vector>
#include <alljoyn/hae/LogModule.h>
#include <alljoyn/hae/HaeBusObject.h>
#include <alljoyn/hae/interfaces/operation/HeatingZoneIntfControlleeListener.h>

#include "HeatingZoneIntfControlleeImpl.h"

using namespace qcc;
using namespace std;

namespace ajn {
namespace services {

HaeInterface* HeatingZoneIntfControlleeImpl::CreateInterface(BusAttachment& busAttachment, InterfaceControlleeListener& listener, HaeBusObject& haeBusObject)
{
    return new HeatingZoneIntfControlleeImpl(busAttachment, dynamic_cast<HeatingZoneIntfControlleeListener&>(listener), haeBusObject);
}

HeatingZoneIntfControlleeImpl::HeatingZoneIntfControlleeImpl(BusAttachment& busAttachment, HeatingZoneIntfControlleeListener& listener, HaeBusObject& haeBusObject) :
    InterfaceControllee(haeBusObject),
    m_busAttachment(busAttachment),
    m_interfaceListener(listener)
{
}

HeatingZoneIntfControlleeImpl::~HeatingZoneIntfControlleeImpl()
{
}

QStatus HeatingZoneIntfControlleeImpl::Init()
{
    QStatus status = HaeInterface::Init();
    /**
     * TODO: add method handler
     */
    return status;
}

QStatus HeatingZoneIntfControlleeImpl::OnGetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;

    if (!(s_prop_Version.compare(propName)))
    {
        val.typeId = ALLJOYN_UINT16;
        val.v_uint16 = GetInterfaceVersion();
    }
    else
    {
        if (s_retrievingActualPropertyValue)
        {
            if(!s_prop_MaxHeatingLevels.compare(propName))
            {
                std::vector<uint8_t> maxHeatingLevels;
                status = m_interfaceListener.OnGetMaxHeatingLevels(maxHeatingLevels);
                if(status != ER_OK)
                {
                    maxHeatingLevels = GetMaxHeatingLevels();
                    QCC_LogError(status, ("%s: failed to get actual property value from application. use previous value.", __func__));
                }
                else
                {
                    //update internal value
                    SetMaxHeatingLevels(maxHeatingLevels);
                }
                uint8_t vals[maxHeatingLevels.size()];
                size_t i = 0;

                for(i = 0; i < maxHeatingLevels.size(); i++)
                {
                    vals[i] = (uint8_t)maxHeatingLevels[i];
                }
                val.Set("ay", sizeof(vals)/ sizeof(uint8_t), vals);
                val.Stabilize();
            }
            else if(!s_prop_HeatingLevels.compare(propName))
            {
                std::vector<uint8_t> heatingLevels;
                status = m_interfaceListener.OnGetHeatingLevels(heatingLevels);
                if(status != ER_OK)
                {
                    heatingLevels = GetHeatingLevels();
                    QCC_LogError(status, ("%s: failed to get actual property value from application. use previous value.", __func__));
                }
                else
                {
                    //update internal value
                    SetHeatingLevels(heatingLevels);
                }
                uint8_t vals[heatingLevels.size()];
                size_t i = 0;

                for(i = 0; i < heatingLevels.size(); i++)
                {
                    vals[i] = (uint8_t)heatingLevels[i];
                }
                val.Set("ay", sizeof(vals)/ sizeof(uint8_t), vals);
                val.Stabilize();
            }
            else if(!s_prop_NumberOfHeatingZones.compare(propName))
            {
                uint8_t numOfZones;
                status = m_interfaceListener.OnGetNumberOfHeatingZones(numOfZones);
                if(status != ER_OK)
                {
                    numOfZones = GetNmberOfHeatingZones();
                    QCC_LogError(status, ("%s: failed to get actual property value from application. use previous value.", __func__));
                }
                else
                {
                    SetNmberOfHeatingZones(numOfZones);
                }
            }
            else
            {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }
        }
        else
        {
            if(!s_prop_HeatingLevels.compare(propName))
            {
                std::vector<uint8_t> heatingLevels;
                heatingLevels = GetHeatingLevels();
                uint8_t vals[heatingLevels.size()];
                size_t i = 0;

                for(i = 0; i < heatingLevels.size(); i++)
                {
                    vals[i] = (uint8_t)heatingLevels[i];
                }
                val.Set("ay", sizeof(vals)/ sizeof(uint8_t), vals);
                val.Stabilize();
            }
            else if(!s_prop_MaxHeatingLevels.compare(propName))
            {
                std::vector<uint8_t> maxHeatingLevels;
                maxHeatingLevels = GetMaxHeatingLevels();
                uint8_t vals[maxHeatingLevels.size()];
                size_t i = 0;

                for(i = 0; i < maxHeatingLevels.size(); i++)
                {
                    vals[i] = (uint8_t)maxHeatingLevels[i];
                }
                val.Set("ay", sizeof(vals)/ sizeof(uint8_t), vals);
                val.Stabilize();
            }
            else if (!s_prop_NumberOfHeatingZones.compare(propName))
            {
                uint8_t numOfZones;
                numOfZones = GetNmberOfHeatingZones();
                val.typeId = ALLJOYN_BYTE;
                val.v_byte = numOfZones;
            }
            else
            {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }
        }
    }

    return status;
}

QStatus HeatingZoneIntfControlleeImpl::OnSetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;

    return status;
}

void HeatingZoneIntfControlleeImpl::OnMethodHandler(const InterfaceDescription::Member* member, Message& msg)
{
    QStatus status = ER_OK;
    bool isFound = false;
    MethodHandlers::const_iterator it;
    for (it = m_methodHandlers.begin(); it != m_methodHandlers.end(); ++it) {
        if (it->first == member) {
            MessageReceiver::MethodHandler handler = it->second;
            (this->*handler)(member, msg);
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        status = ER_BUS_METHOD_CALL_ABORTED;
        QCC_LogError(status, ("%s: could not found method handler.", __func__));
        m_busObject.ReplyMethodCall(msg, status);
    }
}
QStatus HeatingZoneIntfControlleeImpl::SetNmberOfHeatingZones(const uint8_t numberOfZones)
{
    if(m_numberOfHeatingLevels != numberOfZones)
    {
        MsgArg arg;
        arg.typeId = ALLJOYN_BYTE;
        arg.v_byte = numberOfZones;
        m_busObject.EmitPropChanged(GetInterfaceName().c_str(), s_prop_NumberOfHeatingZones.c_str(), arg, 0 , ALLJOYN_FLAG_GLOBAL_BROADCAST);
        m_numberOfHeatingLevels = numberOfZones;
    }
    return ER_OK;
}

QStatus HeatingZoneIntfControlleeImpl::SetMaxHeatingLevels(std::vector<uint8_t> maxHeatingLevels)
{
    QStatus status = ER_OK;

    if(maxHeatingLevels.size() != m_numberOfHeatingLevels)
        return ER_BUS_BAD_VALUE;

    for(unsigned int i =0;i<maxHeatingLevels.size();i++)
        m_maxHeatingLevels.push_back(maxHeatingLevels[i]);

    return status;
}

QStatus HeatingZoneIntfControlleeImpl::SetHeatingLevels(std::vector<uint8_t> heatingLevels)
{
    QStatus status = ER_OK;

    if(heatingLevels.size() != m_numberOfHeatingLevels)
        return ER_BUS_BAD_VALUE;

    for(unsigned int i =0;i<heatingLevels.size();i++)
        m_heatingLevels.push_back(heatingLevels[i]);

    return status;
}

} //namespace services
} //namespace ajn
