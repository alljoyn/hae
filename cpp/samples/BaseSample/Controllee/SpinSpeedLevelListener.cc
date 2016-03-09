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

#include "SpinSpeedLevelListener.h"

using namespace std;


QStatus SpinSpeedLevelListener::OnGetMaxLevel(uint8_t& maxLevel)
{
    cout << " SpinSpeedLevelListener::OnGetMaxLevel" << endl;
    return ER_OK;
}

QStatus SpinSpeedLevelListener::OnSetMaxLevel(const uint8_t& maxLevel)
{
    cout << "SpinSpeedLevelListener::OnSetMaxLevel " << endl;
    return ER_OK;
}

QStatus SpinSpeedLevelListener::OnGetTargetLevel(uint8_t& targetLevel)
{
    cout << "SpinSpeedLevelListener::OnGetTargetLevel " << endl;
    return ER_OK;
}

QStatus SpinSpeedLevelListener::OnSetTargetLevel(const uint8_t& targetLevel)
{
    cout << " SpinSpeedLevelListener::OnSetTargetLevel" << endl;
    return ER_OK;
}

QStatus SpinSpeedLevelListener::OnGetSelectableLevels(std::vector<uint8_t>& selectableLevels)
{
    cout << "SpinSpeedLevelListener::OnGetSelectableLevels " << endl;
    return ER_OK;
}

QStatus SpinSpeedLevelListener::OnSetSelectableLevels(const std::vector<uint8_t>& selectableLevels)
{
    cout << "SpinSpeedLevelListener::OnSetSelectableLevels " << endl;
    return ER_OK;
}
