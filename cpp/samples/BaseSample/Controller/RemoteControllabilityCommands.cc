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

#include "RemoteControllabilityCommands.h"
#include "ControllerSample.h"

RemoteControllabilityListener::RemoteControllabilityListener()
{
}

RemoteControllabilityListener::~RemoteControllabilityListener()
{
}


void RemoteControllabilityListener::IsControllablePropertyChanged(const qcc::String& objectPath, const bool isControllable)
{
    cout << __func__ << endl;
    cout << "# path: " << objectPath << endl;
    cout << "# isControllable: " << isControllable << endl;
}


void RemoteControllabilityListener::GetIsControllablePropertyCallback(QStatus status, const qcc::String& objectPath, const bool isControllable, void* context)
{
    cout << __func__ << endl;
    cout << "# status: " << QCC_StatusText(status) << endl;
    cout << "# path: " << objectPath << endl;
    cout << "# isControllable: " << isControllable<< endl;
}


RemoteControllabilityCommands::RemoteControllabilityCommands(ControllerSample* sample, DeviceInfoPtr& info, const char* objectPath)
: InterfaceCommands(sample, info, objectPath),
  m_intfController(NULL)
{
}

RemoteControllabilityCommands::~RemoteControllabilityCommands()
{

}

void RemoteControllabilityCommands::Init()
{
    if (!m_intfController) {
        CdmInterface* cdmInterface = m_sample->CreateInterface(REMOTE_CONTROLLABILITY_INTERFACE, m_deviceInfo->GetBusName(), m_objectPath, m_deviceInfo->GetSessionId(), m_listener);
        if (!cdmInterface) {
            cout << "Interface creation failed." << endl;
            return;
        }

        m_intfController = static_cast<RemoteControllabilityIntfController*>(cdmInterface);
    }

    RegisterCommand(&RemoteControllabilityCommands::OnCmdGetIsControllable, "grc", "get isControllable");
    PrintCommands();
}


void RemoteControllabilityCommands::OnCmdGetIsControllable(Commands* commands, std::string& cmd)
{
    RemoteControllabilityIntfController* intfController = static_cast<RemoteControllabilityCommands*>(commands)->GetInterface();

    if (!intfController) {
        cout << "Interface is not exist." << endl;
        return;
    }

    intfController->GetIsControllable();
}

