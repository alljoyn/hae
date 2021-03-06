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

#ifndef CYCLECONTROLLISTENER_H_
#define CYCLECONTROLLISTENER_H_
#include "InterfaceCommands.h"
#include <alljoyn/cdm/interfaces/operation/CycleControlIntfControllee.h>
#include <alljoyn/cdm/interfaces/operation/CycleControlIntfControlleeListener.h>

using namespace ajn;
using namespace services;


class CycleControlListener : public CycleControlIntfControlleeListener
{
public:
    virtual QStatus OnGetOperationalState(CycleControlInterface::CycleControlOperationalState& state);

    virtual QStatus OnExecuteCommand(CycleControlInterface::CycleControlOperationalCommand command, CycleControlInterface::CycleControlOperationalState& newState, ErrorCode& error);

};

class CycleControlCommands : public InterfaceCommands
{
  public:
    static ControlleeCommands* CreateCommands(ControlleeSample* sample, const char* objectPath);

    CycleControlCommands(ControlleeSample* sample, const char* objectPath);
    virtual ~CycleControlCommands();

    virtual void Init();
    virtual void InitializeProperties();

    CycleControlIntfControllee* GetInterface() { return m_intfControllee; }
    static void OnCmdGetOperationalState(Commands* commands, std::string& cmd);
    static void OnCmdSetOperationalState(Commands* commands, std::string& cmd);

    static void OnCmdGetSupportedOperationalCommands(Commands* commands, std::string& cmd);
    static void OnCmdGetSupportedOperationalStates(Commands* commands, std::string& cmd);

  private:
    CycleControlIntfControllee* m_intfControllee;
    CycleControlListener m_listener;
};

#endif /* CYCLECONTROLLISTENER_H_ */
