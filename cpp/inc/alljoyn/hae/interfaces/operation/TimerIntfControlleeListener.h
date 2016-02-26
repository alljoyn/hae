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

#ifndef TIMERINTFCONTROLLEELISTENER_H_
#define TIMERINTFCONTROLLEELISTENER_H_

#include <qcc/String.h>
#include <alljoyn/Status.h>
#include <alljoyn/hae/interfaces/HaeInterfaceErrors.h>
#include <alljoyn/hae/interfaces/InterfaceControlleeListener.h>

namespace ajn {
namespace services {

/**
 * Timer Interface Controllee Listener class
 */
class TimerIntfControlleeListener : public InterfaceControlleeListener {
  public:
    /**
     * Destructor of TimerIntfControlleeListener
     */
    virtual ~TimerIntfControlleeListener() {}

    virtual QStatus GetReferenceTimer(int32_t& time) = 0;

    virtual QStatus GetTargetTimeToStart(int32_t& time) = 0;

    virtual QStatus GetTargetTimeToStop(int32_t& time) = 0;

    virtual QStatus GetEstimatedTimeToEnd(int32_t& time) = 0;

    virtual QStatus GetRunningTime(int32_t& time) = 0;

    virtual QStatus GetTargetDuration(int32_t& time) = 0;

    virtual QStatus OnSetTargetTimeToStart(int32_t time, ErrorCode& errorCode) = 0;

    virtual QStatus OnSetTargetTimeToStop(int32_t time, ErrorCode& errorCode) = 0;

};

} //namespace services
} //namespace ajn

#endif /* TIMERINTFCONTROLLEELISTENER_H_ */
