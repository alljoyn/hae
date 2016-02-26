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

#ifndef OVENCYCLEPHASECOMMANDS_H_
#define OVENCYCLEPHASECOMMANDS_H_

#include "InterfaceCommands.h"
#include <alljoyn/hae/interfaces/operation/OvenCyclePhaseIntfController.h>
#include <alljoyn/hae/interfaces/operation/OvenCyclePhaseIntfControllerListener.h>

class ControllerSample;

using namespace ajn;
using namespace services;

class OvenCyclePhaseListener : public OvenCyclePhaseIntfControllerListener{
  public:
    OvenCyclePhaseListener();
    virtual ~OvenCyclePhaseListener();
    virtual void OnResponseGetCyclePhase(QStatus status, const qcc::String& objectPath, const OvenCyclePhaseInterface::OvenCyclePhase& cyclePhase, void* context);

    virtual void OnResponseGetSupportedCyclePhases(QStatus status, const qcc::String& objectPath, const OvenCyclePhaseInterface::SupportedCyclePhases& listOfCyclePhases, void* context);

    virtual void OnCyclePhasePropertyChanged(const qcc::String& objectPath, const OvenCyclePhaseInterface::OvenCyclePhase cyclePhase);

    virtual void OnSupportedCyclePhasesPropertyChanged(const qcc::String& objectPath, const OvenCyclePhaseInterface::SupportedCyclePhases listOfCyclePhases);

    virtual void OnResponseGetCyclePhasesDescriptions(QStatus status, const qcc::String& objectPath, const OvenCyclePhaseInterface::CyclePhaseDescriptions& listOfCycleDescriptions, void* context, const char* errorName, const char* errorMessage);
};

class OvenCyclePhaseCommands : public InterfaceCommands
{
  public:
    OvenCyclePhaseCommands(ControllerSample* sample, DeviceInfoPtr& info, const char* objectPath);
    virtual ~OvenCyclePhaseCommands();

    virtual void Init();

    OvenCyclePhaseIntfController* GetInterface() { return m_intfController; }
    static void OnCmdGetCyclePhase(Commands* commands, std::string& cmd);

    static void OnCmdGetSupportedCyclePhases(Commands* commands, std::string& cmd);

    static void OnCmdGetCyclePhasesDescriptions(Commands* commands, std::string& cmd);
  private:
    OvenCyclePhaseIntfController* m_intfController;
    OvenCyclePhaseListener m_listener;
};


#endif /* OVENCYCLEPHASECOMMANDS_H_ */