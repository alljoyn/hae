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

#ifndef PLUGINUNITSINTERFACE_H_
#define PLUGINUNITSINTERFACE_H_

#include <vector>
#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/HaeInterface.h>

namespace ajn {
namespace services {

/**
 * PlugInUnits Interface class
 */
class PlugInUnitsInterface : public HaeInterface {
  public:
    /**
     * Constructor of PlugInUnits
     */
    PlugInUnitsInterface() {}

    /**
     * Destructor of PlugInUnits
     */
    virtual ~PlugInUnitsInterface() {}

    /**
     * Get Interface Type
     * @return interface type
     */
    const HaeInterfaceType GetInterfaceType() const { return PLUG_IN_UNITS_INTERFACE; }

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


    struct PlugInInfo {
        qcc::String objectPath;
        uint32_t deviceId;
        bool pluggedIn;
        inline bool operator==(const PlugInInfo& info) const {
            return (info.objectPath == objectPath &&
                    info.deviceId == deviceId &&
                    info.pluggedIn == pluggedIn);
        }
    };

    typedef std::vector<PlugInInfo> PlugInUnits;

  protected:
    static const qcc::String s_prop_Version;
    static const qcc::String s_prop_PlugInUnits;

  private:
    static const qcc::String s_xml;
    static const uint16_t s_interfaceVersion;
};

} //namespace services
} //namespace ajn

#endif /* PLUGINUNITSINTERFACE_H_ */
