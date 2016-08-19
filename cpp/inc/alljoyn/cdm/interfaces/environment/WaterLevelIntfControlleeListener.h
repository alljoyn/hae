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

#ifndef WATERLEVELINTFCONTROLLEELISTENER_H_
#define WATERLEVELINTFCONTROLLEELISTENER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/cdm/interfaces/CdmInterfaceErrors.h>
#include <alljoyn/cdm/interfaces/InterfaceControlleeListener.h>
#include <alljoyn/cdm/interfaces/environment/WaterLevelInterface.h>


namespace ajn {
namespace services {

/**
 * WaterLevel Interface Controllee Listener class
 */
class WaterLevelIntfControlleeListener : public InterfaceControlleeListener {
  public:
    /**
     * Destructor of WaterLevelIntfControlleeListener
     */
    virtual ~WaterLevelIntfControlleeListener() {}

    /**
     * Handler for getting currentLevel
     * This function is only called, when InterfaceControllee::s_retrievingActualPropertyValue is true.
     * @param[out] currentLevel currentLevel
     * @return ER_OK on success
     */
    virtual QStatus OnGetCurrentLevel(uint8_t& currentLevel) = 0;

    /**
     * Handler for getting maxLevel
     * This function is only called, when InterfaceControllee::s_retrievingActualPropertyValue is true.
     * @param[out] maxLevel maxLevel
     * @return ER_OK on success
     */
    virtual QStatus OnGetMaxLevel(uint8_t& maxLevel)  = 0;

    /**
     * Handler for getting supplySource
     * This function is only called, when InterfaceControllee::s_retrievingActualPropertyValue is true.
     * @param[out] supplySource supplySource
     * @return ER_OK on success
     */
    virtual QStatus OnGetSupplySource(WaterLevelInterface::WaterLevelSupplySource& supplySource)  = 0;
};

} //namespace services
} //namespace ajn

#endif /* WATERLEVELINTFCONTROLLEELISTENER_H_ */