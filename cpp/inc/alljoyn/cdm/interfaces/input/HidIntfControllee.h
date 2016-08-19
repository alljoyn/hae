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

#ifndef HIDINTFCONTROLLEE_H_
#define HIDINTFCONTROLLEE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/cdm/interfaces/input/HidInterface.h>

namespace ajn {
namespace services {

/**
 * Hid Interface Controllee class
 */
class HidIntfControllee : public HidInterface {
  public:
    /**
     * Constructor of HidIntfControllee
     */
	HidIntfControllee() {}

    /**
     * Destructor of HidIntfControllee
     */
    virtual ~HidIntfControllee() {}

    /**
     * Get supported events
     * @return Supported events
     */
    virtual const SupportedInputEvents& GetSupportedEvents() const = 0;

    /**
     * Set supported events
     * @param[in] supportedEvents supported events
     * @return ER_OK on success
     */
    virtual QStatus SetSupportedEvents(const SupportedInputEvents& supportedEvents) = 0;
};

} //namespace services
} //namespace ajn

#endif /* HIDINTFCONTROLLEE_H_ */