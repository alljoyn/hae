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

#ifndef CURRENTTEMPERATUREINTFCONTROLLEE_H_
#define CURRENTTEMPERATUREINTFCONTROLLEE_H_

#include <vector>
#include <map>
#include <utility>

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/cdm/interfaces/environment/CurrentTemperatureInterface.h>

namespace ajn {
namespace services {

/**
 * CurrentTemperature Interface Controllee class
 */
class CurrentTemperatureIntfControllee : public CurrentTemperatureInterface {
  public:
    /**
     * Constructor of CurrentTemperatureIntfControllee
     */
    CurrentTemperatureIntfControllee() {}

    /**
     * Destructor of CurrentTemperatureIntfControllee
     */
    virtual ~CurrentTemperatureIntfControllee() {}

    /**
     * Get current temperature
     * @return Current temperature
     */
    virtual const double GetCurrentValue() const = 0;

    /**
     * Set current temperature
     * @param[in] value current temperature
     * @return ER_OK on success
     */
    virtual QStatus SetCurrentValue(const double value) = 0;

    /**
     * Get precision
     * @return Precision
     */
    virtual const double GetPrecision() const = 0;

    /**
     * Set precision
     * @param[in] precision precision
     * @return ER_OK on success
     */
    virtual QStatus SetPrecision(const double precision) = 0;

    /**
     * Get the minimum update time
     * @return The minimum update time
     */
    virtual const uint16_t GetUpdateMinTime() const = 0;

    /**
     * Set the minimum update time
     * @param[in] updateMinTime the minimum update time
     * @return ER_OK on success
     */
    virtual QStatus SetUpdateMinTime(const uint16_t updateMinTime) = 0;
};

} //namespace services
} //namespace ajn

#endif /* CURRENTTEMPERATUREINTFCONTROLLEE_H_ */
