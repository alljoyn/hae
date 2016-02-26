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

#ifndef CYCLECONTROLINTERFACE_H_
#define CYCLECONTROLINTERFACE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/HaeInterface.h>
#include <alljoyn/hae/interfaces/CycleControlInterfaceDataTypes.h>

namespace ajn {
namespace services {
/**
 * CycleControl Interface class
 */
class CycleControlInterface : public HaeInterface {
  public:
    /**
     * Constructor of CycleControl
     */
    CycleControlInterface() {}

    /**
     * Destructor of CycleControl
     */
    virtual ~CycleControlInterface() {}

    /**
     * Get Interface Type
     * @return interface type
     */
    const HaeInterfaceType GetInterfaceType() const { return CYCLE_CONTROL_INTERFACE; }

    /**
     * Get Introspection Xml
     * @return xml
     */
    virtual const qcc::String& GetIntrospectionXml() { return s_xml; }

    /**
     * Get Interface version
     * @return interface version
     */
    virtual const uint16_t GetInterfaceVersion() const { return s_interfaceVersion; }

  protected:
    static const qcc::String s_prop_Version;
    static const qcc::String s_prop_OperationalState;
    static const qcc::String s_prop_SupportedOperationalCommands;
    static const qcc::String s_prop_SupportedOperationalStates;
    static const qcc::String s_method_ExecuteCommand;
    static const qcc::String s_signal_EndOfCycle;
  private:
    static const qcc::String s_xml;
    static const uint16_t s_interfaceVersion;
};

} //namespace services
} //namespace ajn

#endif /* CYCLECONTROLINTERFACE_H_ */
