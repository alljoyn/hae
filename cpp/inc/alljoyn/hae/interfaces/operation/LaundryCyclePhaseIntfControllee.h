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

#ifndef LAUNDRYCYCLEPHASEINTFCONTROLLEE_H_
#define LAUNDRYCYCLEPHASEINTFCONTROLLEE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/operation/LaundryCyclePhaseInterface.h>

namespace ajn {
namespace services {

/**
 * LaundryCyclePhase Interface Controllee class
 */
class LaundryCyclePhaseIntfControllee : public LaundryCyclePhaseInterface {
  public:
    /**
     * Constructor of LaundryCyclePhaseIntfControllee
     */
    LaundryCyclePhaseIntfControllee() {}

    /**
     * Destructor of LaundryCyclePhaseIntfControllee
     */
    virtual ~LaundryCyclePhaseIntfControllee() {}

    virtual const LaundryCyclePhase GetCyclePhase() const = 0;

    virtual QStatus SetCyclePhase(const LaundryCyclePhase cyclePhase) = 0;

    virtual const SupportedCyclePhases& GetSupportedCyclePhases() const = 0;

    virtual QStatus SetSupportedCyclePhases(const SupportedCyclePhases& descriptions) = 0;

    virtual QStatus SetVendorDefinedCyclePhases(const std::vector<uint8_t>& vendorPhases) = 0;

};

} //namespace services
} //namespace ajn

#endif /* LAUNDRYCYCLEPHASEINTFCONTROLLEE_H_ */
