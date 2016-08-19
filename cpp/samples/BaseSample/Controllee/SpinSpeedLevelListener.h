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

#ifndef SPINSPEEDLEVELLISTENER_H_
#define SPINSPEEDLEVELLISTENER_H_

#include "InterfaceCommands.h"
#include <alljoyn/cdm/interfaces/operation/SpinSpeedLevelIntfControllee.h>
#include <alljoyn/cdm/interfaces/operation/SpinSpeedLevelIntfControlleeListener.h>

using namespace ajn;
using namespace services;

class SpinSpeedLevelListener : public SpinSpeedLevelIntfControlleeListener
{
  public:
    virtual QStatus OnGetMaxLevel(uint8_t& maxLevel);

    virtual QStatus OnSetMaxLevel(const uint8_t& maxLevel);

    virtual QStatus OnGetTargetLevel(uint8_t& targetLevel);

    virtual QStatus OnSetTargetLevel(const uint8_t& targetLevel);

    virtual QStatus OnGetSelectableLevels(std::vector<uint8_t>& selectableLevels);

    virtual QStatus OnSetSelectableLevels(const std::vector<uint8_t>& selectableLevels);
};

class SpinSpeedLevelCommands : public InterfaceCommands
{
  public:
    static ControlleeCommands* CreateCommands(ControlleeSample* sample, const char* objectPath);

    SpinSpeedLevelCommands(ControlleeSample* sample, const char* objectPath);
    virtual ~SpinSpeedLevelCommands();

    virtual void Init();
    virtual void InitializeProperties();

    SpinSpeedLevelIntfControllee* GetInterface() { return m_intfControllee; }
    static void OnCmdGetMaxLevel(Commands* commands, std::string& cmd);
    static void OnCmdSetMaxLevel(Commands* commands, std::string& cmd);

    static void OnCmdGetTargetLevel(Commands* commands, std::string& cmd);
    static void OnCmdSetTargetLevel(Commands* commands, std::string& cmd);

    static void OnCmdGetSelectableLevels(Commands* commands, std::string& cmd);
//    static void OnCmdSetSupportedCyclePhases(Commands* commands, std::string& cmd);

  private:
    SpinSpeedLevelIntfControllee* m_intfControllee;
    SpinSpeedLevelListener m_listener;
};


#endif /* SPINSPEEDLEVELLISTENER_H_ */
