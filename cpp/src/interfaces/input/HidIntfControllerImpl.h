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

#ifndef HIDINTFCONTROLLERIMPL_H_
#define HIDINTFCONTROLLERIMPL_H_

#include <alljoyn/Status.h>
#include <alljoyn/BusAttachment.h>
#include <alljoyn/hae/interfaces/InterfaceController.h>
#include <alljoyn/hae/interfaces/input/HidIntfController.h>

namespace ajn {
namespace services {

class HidIntfControllerListener;
class HaeProxyBusObject;

/**
 * Hid Interface Controller implementation class
 */
class HidIntfControllerImpl : public InterfaceController, public HidIntfController {
  public:
    /**
     * Create interface
     */
    static HaeInterface* CreateInterface(BusAttachment& busAttachment, InterfaceControllerListener& listener, HaeProxyBusObject& haeProxyObject);

    /**
     * Constructor of HidIntfControllerImpl
     */
    HidIntfControllerImpl(BusAttachment& busAttachment, HidIntfControllerListener& listener, HaeProxyBusObject& haeProxyObject);

    /**
     * Destructor of HidIntfControllerImpl
     */
    virtual ~HidIntfControllerImpl();

    /**
     * Initialize interface
     * @return status
     */
    virtual QStatus Init();

    /**
     * Get bus attachment
     * @return bus attachment
     */
    virtual BusAttachment& GetBusAttachment() const { return m_busAttachment; }

    /**
     * Get supported events
     * @param[in] context
     * @return status
     */
    virtual QStatus GetSupportedEvents(void* context);

    /**
     * Inject events
     * @param[in] input events
     * @return status
     */
    virtual QStatus InjectEvents(HidInterface::InputEvents& inputEvents);

  private:
    HidIntfControllerImpl();

    void PropertiesChanged(ProxyBusObject& obj, const char* ifaceName, const MsgArg& changed, const MsgArg& invalidated, void* context);
    void GetSupportedEventsPropertyCB(QStatus status, ProxyBusObject* obj, const MsgArg& value, void* context);

    BusAttachment& m_busAttachment;
    HidIntfControllerListener& m_interfaceListener;
};

} //namespace services
} //namespace ajn

#endif /* HIDINTFCONTROLLERIMPL_H_ */
