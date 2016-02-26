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

#ifndef LAUNDRYCYCLEPHASEINTFCONTROLLERLISTENER_H_
#define LAUNDRYCYCLEPHASEINTFCONTROLLERLISTENER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/InterfaceControllerListener.h>
#include <alljoyn/hae/interfaces/operation/LaundryCyclePhaseInterface.h>

namespace ajn {
namespace services {

/**
 * LaundryCyclePhase Interface Controller Listener class
 */
class LaundryCyclePhaseIntfControllerListener : public InterfaceControllerListener {
  public:
    virtual ~LaundryCyclePhaseIntfControllerListener() {}

    virtual void OnResponseGetCyclePhase(QStatus status, const qcc::String& objectPath, const LaundryCyclePhaseInterface::LaundryCyclePhase& cyclePhase, void* context) {}

    virtual void OnResponseGetSupportedCyclePhases(QStatus status, const qcc::String& objectPath, const LaundryCyclePhaseInterface::SupportedCyclePhases& listOfCyclePhases, void* context) {}

    /*
     * TODO: define functions that receives the PropertyChanged and other signals
     */
    virtual void OnCyclePhasePropertyChanged(const qcc::String& objectPath, const LaundryCyclePhaseInterface::LaundryCyclePhase cyclePhase) {}

    virtual void OnSupportedCyclePhasesPropertyChanged(const qcc::String& objectPath, const LaundryCyclePhaseInterface::SupportedCyclePhases listOfCyclePhases) {}

    virtual void OnResponseGetCyclePhasesDescriptions(QStatus status, const qcc::String& objectPath, const LaundryCyclePhaseInterface::CyclePhaseDescriptions& listOfCycleDescriptions,
                                                      void* context, const char* errorName, const char* errorMessage) {}
};

} //namespace services
} //namespace ajn

#endif /* LAUNDRYCYCLEPHASEINTFCONTROLLERLISTENER_H_ */
