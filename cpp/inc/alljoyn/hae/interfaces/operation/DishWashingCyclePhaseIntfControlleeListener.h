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

#ifndef DISHWASHINGCYCLEPHASEINTFCONTROLLEELISTENER_H_
#define DISHWASHINGCYCLEPHASEINTFCONTROLLEELISTENER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/HaeInterfaceErrors.h>
#include <alljoyn/hae/interfaces/InterfaceControlleeListener.h>
#include <alljoyn/hae/interfaces/operation/DishWashingCyclePhaseInterface.h>

namespace ajn {
namespace services {

/**
 * DishWashingCyclePhase Interface Controllee Listener class
 */
class DishWashingCyclePhaseIntfControlleeListener : public InterfaceControlleeListener {
  public:
    /**
     * Destructor of DishWashingCyclePhaseIntfControlleeListener
     */
    virtual ~DishWashingCyclePhaseIntfControlleeListener() {}

    virtual QStatus OnGetCyclePhase(DishWashingCyclePhaseInterface::DishWashingCyclePhase& cyclePhase) = 0;

    virtual QStatus OnGetSupportedCyclePhases(DishWashingCyclePhaseInterface::SupportedCyclePhases& listOfSupportedCyclePhases) = 0;

    virtual QStatus OnGetCyclePhasesDescriptions(const qcc::String language,
                                                 DishWashingCyclePhaseInterface::CyclePhaseDescriptions& listOfPhaseDescs,
                                                 ErrorCode& errorCode) = 0;

};

} //namespace services
} //namespace ajn

#endif /* DISHWASHINGCYCLEPHASEINTFCONTROLLEELISTENER_H_ */
