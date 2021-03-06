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

#ifndef PLUGINUNITSINTFCONTROLLEELISTENER_H_
#define PLUGINUNITSINTFCONTROLLEELISTENER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/cdm/interfaces/CdmInterfaceErrors.h>
#include <alljoyn/cdm/interfaces/InterfaceControlleeListener.h>
#include <alljoyn/cdm/interfaces/operation/PlugInUnitsInterface.h>

namespace ajn {
namespace services {

/**
 * PlugInUnits Interface Controllee Listener class
 */
class PlugInUnitsIntfControlleeListener : public InterfaceControlleeListener {
  public:
    /**
     * Destructor of PlugInUnitsIntfControlleeListener
     */
    virtual ~PlugInUnitsIntfControlleeListener() {}

    /**
     * Handler for getting list of plug in uint
     * This function is only called, when InterfaceControllee::s_retrievingActualPropertyValue is true.
     * @param[out] plugInUnits list of plug in unit
     * @return ER_OK on success
     */
    virtual QStatus OnGetPlugInUnits(PlugInUnitsInterface::PlugInUnits& plugInUnits) = 0;

};

} //namespace services
} //namespace ajn

#endif /* PLUGINUNITSINTFCONTROLLEELISTENER_H_ */
