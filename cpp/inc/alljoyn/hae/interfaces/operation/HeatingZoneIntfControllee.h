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

#ifndef HEATINGZONEINTFCONTROLLEE_H_
#define HEATINGZONEINTFCONTROLLEE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <vector>
#include <alljoyn/hae/interfaces/operation/HeatingZoneInterface.h>

namespace ajn {
namespace services {

/**
 * HeatingZone Interface Controllee class
 */
class HeatingZoneIntfControllee : public HeatingZoneInterface {
  public:
    /**
     * Constructor of HeatingZoneIntfControllee
     */
    HeatingZoneIntfControllee() {}

    /**
     * Destructor of HeatingZoneIntfControllee
     */
    virtual ~HeatingZoneIntfControllee() {}

    /**
     * Get number of heating zones
     * @return NumberOfHeatingZones
     */
    virtual const uint8_t GetNmberOfHeatingZones() const = 0;

    /**
     * Set NumberOfHeatingZones
     * @param[in] numberOfZones number of heating zones
     * @return ER_OK on success
     */
    virtual QStatus SetNmberOfHeatingZones(const uint8_t numberOfZones) = 0;

    /**
     * Get MaxHeatingLevels
     * @return the list of maximum heating levels
     */
    virtual const std::vector<uint8_t>& GetMaxHeatingLevels() const = 0;

    /**
     * Set MaxHeatingLevels
     * @param[in] maxHeatingLevels maxHeatingLevels
     * @return ER_OK on success
     */
    virtual QStatus SetMaxHeatingLevels(std::vector<uint8_t> maxHeatingLevels) = 0;

    /**
     * Get HeatingLevels
     * @return the list of heating levels
     */
    virtual const std::vector<uint8_t>& GetHeatingLevels() const = 0;

    /**
     * Set HeatingLevels
     * @param[in] heatingLevels heatingLevels
     * @return ER_OK on success
     */
    virtual QStatus SetHeatingLevels(std::vector<uint8_t> heatingLevels) = 0;
};

} //namespace services
} //namespace ajn

#endif /* HEATINGZONEINTFCONTROLLEE_H_ */