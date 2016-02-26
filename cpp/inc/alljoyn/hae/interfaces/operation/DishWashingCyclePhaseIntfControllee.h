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

#ifndef DISHWASHINGCYCLEPHASEINTFCONTROLLEE_H_
#define DISHWASHINGCYCLEPHASEINTFCONTROLLEE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/operation/DishWashingCyclePhaseInterface.h>

namespace ajn {
namespace services {

/**
 * DishWashingCyclePhase Interface Controllee class
 */
class DishWashingCyclePhaseIntfControllee : public DishWashingCyclePhaseInterface {
  public:
    /**
     * Constructor of DishWashingCyclePhaseIntfControllee
     */
    DishWashingCyclePhaseIntfControllee() {}

    /**
     * Destructor of DishWashingCyclePhaseIntfControllee
     */
    virtual ~DishWashingCyclePhaseIntfControllee() {}

    virtual const DishWashingCyclePhase GetCyclePhase() const = 0;

    virtual QStatus SetCyclePhase(const DishWashingCyclePhase cyclePhase) = 0;

    virtual const SupportedCyclePhases& GetSupportedCyclePhases() const = 0;

    virtual QStatus SetSupportedCyclePhases(const SupportedCyclePhases& descriptions) = 0;

    virtual QStatus SetVendorDefinedCyclePhases(const std::vector<uint8_t>& vendorPhases) = 0;

};

} //namespace services
} //namespace ajn

#endif /* DISHWASHINGCYCLEPHASEINTFCONTROLLEE_H_ */
