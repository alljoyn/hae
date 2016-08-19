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

#ifndef CLIMATECONTROLMODEINTFCONTROLLEEIMPL_H_
#define CLIMATECONTROLMODEINTFCONTROLLEEIMPL_H_

#include <alljoyn/Status.h>
#include <alljoyn/BusAttachment.h>
#include <alljoyn/InterfaceDescription.h>
#include <alljoyn/cdm/interfaces/InterfaceControllee.h>
#include <alljoyn/cdm/interfaces/InterfaceControlleeListener.h>
#include <alljoyn/cdm/interfaces/operation/ClimateControlModeIntfControllee.h>

namespace ajn {
namespace services {

class ClimateControlModeIntfControlleeListener;
class CdmBusObject;

/**
 * ClimateControlMode interface controllee implementation class
 */
class ClimateControlModeIntfControlleeImpl : public InterfaceControllee, public ClimateControlModeIntfControllee {
  public:

    /**
     * Create interface
     */
    static CdmInterface* CreateInterface(BusAttachment& busAttachment, InterfaceControlleeListener& listener, CdmBusObject& cdmBusObject);

    /**
     * Constructor of ClimateControlModeIntfControlleeImpl
     */
    ClimateControlModeIntfControlleeImpl(BusAttachment& busAttachment, ClimateControlModeIntfControlleeListener& listener, CdmBusObject& cdmBusObject);

    /**
     * Destructor of ClimateControlModeIntfControlleeImpl
     */
    virtual ~ClimateControlModeIntfControlleeImpl();

    /**
     * Initialize interface
     * @return status
     */
    virtual QStatus Init();

    /**
     * a callback function for getting property.
     * @param propName   Identifies the property to get
     * @param[out] val   Returns the property value. The type of this value is the actual value type.
     * @return status
     */
    virtual QStatus OnGetProperty(const qcc::String& propName, MsgArg& val);

    /**
     * a callback function for setting property.
     * @param propName  Identifies the property to set
     * @param val       The property value to set. The type of this value is the actual value type.
     */
    virtual QStatus OnSetProperty(const qcc::String& propName, MsgArg& val);

    /**
     * method handler
     * @param member    Method interface member entry.
     * @param message   The received method call message.
     */
    virtual void OnMethodHandler(const InterfaceDescription::Member* member, Message& msg);

    /**
     * Get bus attachment
     * @return bus attachment
     */
    virtual BusAttachment& GetBusAttachment() const { return m_busAttachment; }

    /**
     * Get method handlers
     * @return MethodHandlers
     */
    virtual const MethodHandlers& GetMethodHanders() const { return m_methodHandlers; }

    /**
     * Set Mode
     * @param[in] mode
     * @return status
     */
    virtual QStatus SetMode(const uint16_t mode);

    /**
     * Get Mode
     * @return mode
     */
    virtual const uint16_t GetMode() const { return m_Mode; }

    /**
     * Set SupportedModes
     * @param[in] modes
     * @return status
     */
    virtual QStatus SetSupportedModes(const SupportedModes& modes);

    /**
     * Get SupportedModes
     * @return SupportedModes
     */
    virtual const SupportedModes& GetSupportedModes() const { return m_SupportedModes; }

    /**
     * Set OperationalState
     * @param[in] state
     * @return status
     */
    virtual QStatus SetOperationalState(const uint16_t state);

    /**
     * Get OperationalState
     * @return state
     */
    virtual const uint16_t GetOperationalState() const { return m_OperationalState; }

  private:
    ClimateControlModeIntfControlleeImpl();

    BusAttachment& m_busAttachment;
    ClimateControlModeIntfControlleeListener& m_interfaceListener;
    uint16_t m_Mode;                       // read-write, EmitsChangedSignal
    uint16_t m_OperationalState;        // read-only, EmitsChangedSignal
    SupportedModes m_SupportedModes;         // read-only, EmitsChangedSignal
    MethodHandlers m_methodHandlers;
};

} //namespace services
} //namespace ajn

#endif /* CLIMATECONTROLMODEINTFCONTROLLEEIMPL_H_ */
