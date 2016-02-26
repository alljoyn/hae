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
#include "CycleControlListener.h"

using namespace std;


QStatus CycleControlListener::OnGetOperationalState(uint8_t& state)
{
    cout << "CycleControlListener::OnGetOperationalState()" << endl;
    return ER_OK;
}

QStatus CycleControlListener::OnExecuteCommand(uint8_t command, uint8_t& newState, ErrorCode& error)
{
	QStatus status = ER_OK;
	cout << "CycleControlListener::OnExecuteCommand. Command: " << (int)command << ". Command name: " << OPERATIONAL_COMMAND_STRINGS[command] <<endl;
	error = NOT_ERROR;
	newState = OPERATIONAL_STATE_END_OF_CYCLE;
	return status;
}
