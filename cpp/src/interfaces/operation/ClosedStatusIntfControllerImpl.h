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

#ifndef CLOSEDSTATUSINTFCONTROLLERIMPL_H_
#define CLOSEDSTATUSINTFCONTROLLERIMPL_H_

#include <alljoyn/Status.h>
#include <alljoyn/BusAttachment.h>
#include <alljoyn/hae/interfaces/InterfaceController.h>
#include <alljoyn/hae/interfaces/operation/ClosedStatusIntfController.h>

namespace ajn {
namespace services {

class ClosedStatusIntfControllerListener;
class HaeProxyBusObject;

/**
 * ClosedStatus Interface Controller implementation class
 */
class ClosedStatusIntfControllerImpl : public InterfaceController, public ClosedStatusIntfController {
  public:
    /**
     * Create interface
     */
    static HaeInterface* CreateInterface(BusAttachment& busAttachment, InterfaceControllerListener& listener, HaeProxyBusObject& haeProxyObject);

    /**
     * Constructor of ClosedStatusIntfControllerImpl
     */
    ClosedStatusIntfControllerImpl(BusAttachment& busAttachment, ClosedStatusIntfControllerListener& listener, HaeProxyBusObject& haeProxyObject);

    /**
     * Destructor of ClosedStatusIntfControllerImpl
     */
    virtual ~ClosedStatusIntfControllerImpl();

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
    * Set isClosed
    * @param[in] isClosed
    * @param[in] context
    * @return status
    */
   //virtual QStatus SetIsClosed(const bool isClosed, void* context);

   /**
    * Get mute
    * @param[in] context
    * @return status
    */
   virtual QStatus GetIsClosed(void* context);

    /**
     * TODO: define set/get properties
     * GetProperty function of read-only property must not be defined in the controller side.
     */

    /*
     * TODO: define methods
     */

  private:
    ClosedStatusIntfControllerImpl();

    void PropertiesChanged(ProxyBusObject& obj, const char* ifaceName, const MsgArg& changed, const MsgArg& invalidated, void* context);
    /*
     * TODO: define set/get properties async callback
     */
    //void SetIsClosedPropertyCB(QStatus status, ProxyBusObject* obj, void* context);
    void GetIsClosedPropertyCB(QStatus status, ProxyBusObject* obj, const MsgArg& value, void* context);

    /*
     * TODO: define method reply handler
     */

    /*
     * TODO: define signal handler
     */


    BusAttachment& m_busAttachment;
    ClosedStatusIntfControllerListener& m_interfaceListener;
};

} //namespace services
} //namespace ajn

#endif /* CLOSEDSTATUSINTFCONTROLLERIMPL_H_ */
