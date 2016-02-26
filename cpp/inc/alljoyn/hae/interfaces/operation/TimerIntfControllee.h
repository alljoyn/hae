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

#ifndef TIMERINTFCONTROLLEE_H_
#define TIMERINTFCONTROLLEE_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/operation/TimerInterface.h>

namespace ajn {
namespace services {

/**
 * Timer Interface Controllee class
 */
class TimerIntfControllee : public TimerInterface {
  public:
    /**
     * Constructor of TimerIntfControllee
     */
    TimerIntfControllee() {}

    /**
     * Destructor of TimerIntfControllee
     */
    virtual ~TimerIntfControllee() {}

    virtual const int32_t GetReferenceTimer() const = 0;

    virtual QStatus SetReferenceTimer(const int32_t time) = 0;

    virtual const int32_t GetTargetTimeToStart() const = 0;

    virtual const int32_t GetTargetTimeToStop() const = 0;

    virtual const int32_t GetEstimatedTimeToEnd() const = 0;

    virtual QStatus SetEstimatedTimeToEnd(const int32_t time) = 0;

    virtual const int32_t GetRunningTime() const = 0;

    virtual QStatus SetRunningTime(const int32_t time) = 0;

    virtual const int32_t GetTargetDuration() const = 0;

    virtual QStatus SetTargetDuration(const int32_t time) = 0;

};

} //namespace services
} //namespace ajn

#endif /* TIMERINTFCONTROLLEE_H_ */
