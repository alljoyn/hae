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

#ifndef HIDCOMMANDS_H_
#define HIDCOMMANDS_H_

#include "InterfaceCommands.h"
#include <alljoyn/hae/interfaces/input/HidIntfController.h>
#include <alljoyn/hae/interfaces/input/HidIntfControllerListener.h>

class ControllerSample;

using namespace ajn;
using namespace services;

class HidListener : public HidIntfControllerListener {
  public:
    HidListener();
    virtual ~HidListener();
    virtual void OnResponseGetSupportedEvents(QStatus status, const qcc::String& objectPath, const HidInterface::SupportedInputEvents& supportedEvents, void* context);
    virtual void OnSupportedEventsChanged(const qcc::String& objectPath, const HidInterface::SupportedInputEvents& supportedEvents);
};

class HidCommands : public InterfaceCommands
{
  public:
    HidCommands(ControllerSample* sample, DeviceInfoPtr& info, const char* objectPath);
    virtual ~HidCommands();

    virtual void Init();

    HidIntfController* GetInterface() { return m_intfController; }

    static void OnCmdGetSupportedEvents(Commands* commands, std::string& cmd);
    static void OnCmdInjectEvents(Commands* commands, std::string& cmd);

  private:
    HidIntfController* m_intfController;
    HidListener m_listener;
};

#endif /* HIDCOMMANDS_H_ */
