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
#include "DishWashingCyclePhaseListener.h"

using namespace std;


QStatus DishWashingCyclePhaseListener::OnGetCyclePhase(uint8_t& cyclePhase)
{
    QStatus status = ER_OK;
    cout << "DishWashingCyclePhaseListener::OnGetCyclePhase" << endl;
    return status;
}

QStatus DishWashingCyclePhaseListener::OnGetSupportedCyclePhases(DishWashingCyclePhaseInterface::SupportedCyclePhases& listOfSupportedCyclePhases)
{
    QStatus status = ER_OK;
    cout << "DishWashingCyclePhaseListener::OnGetSupportedCyclePhases" << endl;
    return status;
}

QStatus DishWashingCyclePhaseListener::OnGetCyclePhasesDescriptions(const qcc::String& language, DishWashingCyclePhaseInterface::CyclePhaseDescriptions& listOfPhaseDescs, ErrorCode& errorCode)
{
    QStatus status = ER_OK;
    cout << "DishWashingCyclePhaseListener::OnGetCyclePhasesDescriptions" << endl;

    if(language == "en")
    {
        DishWashingCyclePhaseInterface::DishWashingPhaseDescriptor disc;
        disc.phase = 1;
        disc.name = "phase1";
        disc.description = "this is phase 1";
        listOfPhaseDescs.push_back(disc);

        disc.phase = 2;
        disc.name = "phase2";
        disc.description = "this is phase 2";
        listOfPhaseDescs.push_back(disc);

        disc.phase = 3;
        disc.name = "phase3";
        disc.description = "this is phase 3";
        listOfPhaseDescs.push_back(disc);

        disc.phase = 4;
        disc.name = "phase4";
        disc.description = "this is phase 4";
        listOfPhaseDescs.push_back(disc);

        disc.phase = 0x80;
        disc.name = "VendorPhase1";
        disc.description = "this is vendor defined phase 1 for dish washer";
        listOfPhaseDescs.push_back(disc);

        disc.phase = 0x81;
        disc.name = "VendorPhase2";
        disc.description = "this is vendor defined phase 2 dish washer";
        listOfPhaseDescs.push_back(disc);
    }
    else 
    {
        errorCode = LANGUAGE_NOT_SUPPORTED;
        status = ER_LANGUAGE_NOT_SUPPORTED;
    }
    return status;
}

