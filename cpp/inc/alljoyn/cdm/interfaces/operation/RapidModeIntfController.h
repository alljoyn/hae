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

#ifndef RAPIDMODEINTFCONTROLLER_H_
#define RAPIDMODEINTFCONTROLLER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/cdm/interfaces/operation/RapidModeInterface.h>

namespace ajn {
namespace services {

/**
 * RapidMode Interface Controller class
 */
class RapidModeIntfController : public RapidModeInterface {
  public:
    /**
     * Constructor of RapidModeIntfController
     */
    RapidModeIntfController() {}

    /**
     * Destructor of RapidModeIntfController
     */
    virtual ~RapidModeIntfController() {}

    /**
     * Get rapid mode
     * @param[in] context the context that is passed to the callback handler
     * @return ER_OK on success
     */
    virtual QStatus GetRapidMode(void* context = NULL) = 0;

    /**
     * Set rapid mode
     * @param[in] rapidMide rapid mode
     * @param[in] context the context that is passed to the callback handler
     * @return ER_OK on success
     */
    virtual QStatus SetRapidMode(const bool rapidMode, void* context = NULL) = 0;
};

} //namespace services
} //namespace ajn

#endif /* RAPIDMODEINTFCONTROLLER_H_ */
