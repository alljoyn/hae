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

#include "HaeTest.h"

#include <alljoyn/hae/interfaces/operation/OnOffStatusIntfController.h>
#include <alljoyn/hae/interfaces/operation/OnOffStatusIntfControllerListener.h>

class OnOffStatusListener : public OnOffStatusIntfControllerListener
{
public:
    qcc::Event m_event;
    qcc::Event m_eventSignal;
    QStatus m_status;
    bool m_onOff;
    bool m_onOffSignal;
    qcc::String m_errorName;
    qcc::String m_errorMessage;

    virtual void OnResponseGetOnOff(QStatus status, const qcc::String& objectPath, const bool value, void* context)
    {
        m_errorName = "";
        m_errorMessage = "";

        m_onOff = value;
        m_status = status;
        m_event.SetEvent();
    }

    virtual void OnOnOffChanged(const qcc::String& objectPath, const bool value)
    {
        m_onOffSignal = value;
        m_eventSignal.SetEvent();
    }
};

TEST_F(HAETest, HAE_v1_20)
{
    WaitForControllee (ON_OFF_STATUS_INTERFACE);
    for (size_t i = 0; i < m_interfaces.size(); i++) {
        TEST_LOG_OBJECT_PATH(m_interfaces[i].objectPath);

        OnOffStatusListener listener;
        HaeInterface* interface = m_controller->CreateInterface(ON_OFF_STATUS_INTERFACE, m_interfaces[i].busName, qcc::String(m_interfaces[i].objectPath.c_str()),
                                                                m_interfaces[i].sessionId, listener);
        OnOffStatusIntfController* controller = static_cast<OnOffStatusIntfController*>(interface);
        QStatus status = ER_FAIL;

        TEST_LOG_1("Get initial values for all properties.");
        {
            TEST_LOG_2("Retrieve the OnOff property.");
            status = controller->GetOnOff();
            EXPECT_EQ(status, ER_OK);
            EXPECT_EQ(ER_OK, qcc::Event::Wait(listener.m_event, TIMEOUT));
            listener.m_event.ResetEvent();
            EXPECT_EQ(listener.m_status, ER_OK);
        }
    }
}