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
#include <alljoyn/hae/HaeBusObject.h>
#include <alljoyn/hae/interfaces/operation/SpinSpeedLevelIntfControlleeListener.h>

#include "SpinSpeedLevelIntfControlleeImpl.h"

using namespace qcc;
using namespace std;

namespace ajn {
namespace services {

HaeInterface* SpinSpeedLevelIntfControlleeImpl::CreateInterface(BusAttachment& busAttachment, InterfaceControlleeListener& listener, HaeBusObject& haeBusObject)
{
    return new SpinSpeedLevelIntfControlleeImpl(busAttachment, dynamic_cast<SpinSpeedLevelIntfControlleeListener&>(listener), haeBusObject);
}

SpinSpeedLevelIntfControlleeImpl::SpinSpeedLevelIntfControlleeImpl(BusAttachment& busAttachment, SpinSpeedLevelIntfControlleeListener& listener, HaeBusObject& haeBusObject) :
    InterfaceControllee(haeBusObject),
    m_busAttachment(busAttachment),
    m_interfaceListener(listener),
    m_targetLevel(2),
    m_maxLevel(5)
{
}

SpinSpeedLevelIntfControlleeImpl::~SpinSpeedLevelIntfControlleeImpl()
{
}

QStatus SpinSpeedLevelIntfControlleeImpl::Init()
{
    QStatus status = HaeInterface::Init();


    return status;
}

QStatus SpinSpeedLevelIntfControlleeImpl::OnGetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;
    if (!(s_prop_Version.compare(propName))) {
        val.typeId = ALLJOYN_UINT16;
        val.v_uint16 = GetInterfaceVersion();
    } else if (!s_prop_SelectableLevels.compare(propName)) {
        std::vector<uint8_t> levels = GetSelectableLevels();

        uint8_t vals[levels.size()];

        size_t i = 0;

        for(i = 0; i < levels.size(); i++)
        {
            vals[i] = (uint8_t)levels[i];
        }
        val.Set("ay", sizeof(vals)/ sizeof(uint8_t), vals);
        val.Stabilize();
    }
    else {
        if (s_retrievingActualPropertyValue) {
            if(!s_prop_MaxLevel.compare(propName))
            {
                uint8_t maxLvl;
                status = m_interfaceListener.OnGetMaxLevel(maxLvl);
                if(status != ER_OK) {
                    QCC_LogError(status, ("%s: failed to get max level prop", __func__));
                }
                else {
                    //update and emit
                    SetMaxLevel(maxLvl);
                }
                val.typeId = ALLJOYN_BYTE;
                val.v_byte = maxLvl;
            }
            else if (!s_prop_TargetLevel.compare(propName))
            {
                uint8_t targLvl;
                status = m_interfaceListener.OnGetTargetLevel(targLvl);
                if(status != ER_OK) {
                    QCC_LogError(status, ("%s: failed to get max level prop", __func__));
                }
                else {
                    //update and emit
                    SetTargetLevel(targLvl);
                }
                val.typeId = ALLJOYN_BYTE;
                val.v_byte = targLvl;
            }
            else {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }

        } else {
            if(!s_prop_MaxLevel.compare(propName)){
                uint8_t maxLvl = GetMaxLevel();
                val.typeId = ALLJOYN_BYTE;
                val.v_byte = maxLvl;
            } else if(!s_prop_TargetLevel.compare(propName)) {
                uint8_t targLvl = GetTargetLevel();
                val.typeId = ALLJOYN_BYTE;
                val.v_byte = targLvl;
            }
            else {
                status = ER_BUS_NO_SUCH_PROPERTY;
            }
       }
    }
    return status;
}

QStatus SpinSpeedLevelIntfControlleeImpl::OnSetProperty(const String propName, MsgArg& val)
{
    QStatus status = ER_OK;

    if(!s_prop_TargetLevel.compare(propName))
    {
        if(val.typeId != ALLJOYN_BYTE)
        {
            status = ER_BUS_BAD_VALUE_TYPE;
        }
        else
        {
            status = SetTargetLevel(val.v_byte);
            if(status != ER_OK)
            {
                status = ER_BUS_PROPERTY_VALUE_NOT_SET;
            }
        }
    }
    else
    {
        status = ER_BUS_NO_SUCH_PROPERTY;
    }

    return status;
}

void SpinSpeedLevelIntfControlleeImpl::OnMethodHandler(const InterfaceDescription::Member* member, Message& msg)
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
QStatus SpinSpeedLevelIntfControlleeImpl::SetMaxLevel(uint8_t maxLevel)
{
    if(maxLevel != m_maxLevel)
    {
        MsgArg arg;
        arg.typeId = ALLJOYN_BYTE;
        arg.v_byte = maxLevel;
        m_busObject.EmitPropChanged(GetInterfaceName().c_str(), s_prop_MaxLevel.c_str(), arg, 0, ALLJOYN_FLAG_GLOBAL_BROADCAST);
        m_maxLevel = maxLevel;
    }
    return ER_OK;
}

QStatus SpinSpeedLevelIntfControlleeImpl::SetTargetLevel(uint8_t targetLevel)
{
    if(targetLevel != m_targetLevel)
    {
        MsgArg arg;
        arg.typeId = ALLJOYN_BYTE;
        arg.v_byte = targetLevel;
        m_busObject.EmitPropChanged(GetInterfaceName().c_str(), s_prop_TargetLevel.c_str(), arg, 0, ALLJOYN_FLAG_GLOBAL_BROADCAST);
        m_targetLevel = targetLevel;
    }
    return ER_OK;
}

QStatus SpinSpeedLevelIntfControlleeImpl::SetSelectableLevels(std::vector<uint8_t> selectableLevels)
{
    MsgArg arg;
    uint8_t vals[selectableLevels.size()];

    size_t i = 0;

    for(i = 0; i < selectableLevels.size(); i++)
    {
        vals[i] = (uint8_t)selectableLevels[i];
    }
    arg.Set("ay", sizeof(vals)/sizeof(uint8_t), vals);
    arg.Stabilize();

    if(m_selectableLevels.size() > 0)
        m_selectableLevels.clear();

    for(unsigned int i = 0; i < selectableLevels.size(); i ++)
        m_selectableLevels.push_back(selectableLevels[i]);

    m_busObject.EmitPropChanged(GetInterfaceName().c_str(), s_prop_SelectableLevels.c_str(), arg, 0 ,ALLJOYN_FLAG_GLOBAL_BROADCAST);

    return ER_OK;
}

} //namespace services
} //namespace ajn