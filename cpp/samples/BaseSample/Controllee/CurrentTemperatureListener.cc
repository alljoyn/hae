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

#include <iostream>
#include "CurrentTemperatureListener.h"

using namespace std;

QStatus CurrentTemperatureListener::OnGetCurrentValue(double& value)
{
    cout << "CurrentTemperatureListener::OnGetCurrentValue() - CurrentValue : " << value << endl;
    return ER_OK;
}

QStatus CurrentTemperatureListener::OnGetPrecision(double& precision)
{
    cout << "CurrentTemperatureListener::OnGetPrecision() - precision : " << precision << endl;
    return ER_OK;
}

QStatus CurrentTemperatureListener::OnGetUpdateMinTime(uint16_t& updateMinTime)
{
    cout << "CurrentTemperatureListener::OnGetUpdateMinTime() - updateMinTime : " << updateMinTime << endl;
    return ER_OK;
}
