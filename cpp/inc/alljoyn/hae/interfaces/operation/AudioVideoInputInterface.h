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

#ifndef AUDIOVIDEOINPUTINTERFACE_H_
#define AUDIOVIDEOINPUTINTERFACE_H_

#include <map>

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/HaeInterface.h>

namespace ajn {
namespace services {

/**
 * AudioVideoInput Interface class
 */
class AudioVideoInputInterface : public HaeInterface {
  public:
    /**
     * InputSource struct
     */
    typedef struct {
        uint16_t sourceType;
        uint8_t signalPresence;
        uint16_t portNumber;
        qcc::String friendlyName;
    } InputSource;
    typedef std::map<uint16_t, InputSource> InputSources;

    /**
     * Constructor of AudioVideoInput
     */
    AudioVideoInputInterface() {}

    /**
     * Destructor of AudioVideoInput
     */
    virtual ~AudioVideoInputInterface() {}

    /**
     * Get Interface Type
     * @return Interface type
     */
    const HaeInterfaceType GetInterfaceType() const { return AUDIO_VIDEO_INPUT_INTERFACE; }

    /**
     * Get Introspection Xml
     * @return Introspection xml
     */
    virtual const qcc::String& GetIntrospectionXml() { return s_xml; }

    /**
     * Get Interface version
     * @return Interface version
     */
    virtual const uint16_t GetInterfaceVersion() const { return s_interfaceVersion; }

  protected:
    static const qcc::String s_prop_Version;
    static const qcc::String s_prop_InputSourceId;
    static const qcc::String s_prop_SupportedInputSources;

  private:
    static const qcc::String s_xml;
    static const uint16_t s_interfaceVersion;
};

} //namespace services
} //namespace ajn

#endif /* AUDIOVIDEOINPUTINTERFACE_H_ */
