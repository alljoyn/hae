#ifndef CYCLE_CONTROL_INTERFACE_DATA_TYPES_H_
#define CYCLE_CONTROL_INTERFACE_DATA_TYPES_H_

#include <vector>

#define	OPERATIONAL_STATE_IDLE 0x00
#define	OPERATIONAL_STATE_WORKING 0x01
#define	OPERATIONAL_STATE_READY_TO_START 0x02
#define	OPERATIONAL_STATE_DELAYED_START 0x03
#define	OPERATIONAL_STATE_PAUSED 0x04
#define	OPERATIONAL_STATE_END_OF_CYCLE 0x05

#define	OPERATIONAL_COMMAND_START 0x00
#define	OPERATIONAL_COMMAND_STOP 0x01
#define	OPERATIONAL_COMMAND_PAUSE 0x02
#define	OPERATIONAL_COMMAND_RESUME 0x03

static qcc::String OPERATIONAL_STATE_STRINGS[6]= {
		"Idle",
		"Working",
		"Ready to start",
		"Delayed start",
		"Paused",
		"End of cycle"
};
static qcc::String OPERATIONAL_COMMAND_STRINGS[4] = {
		"Start",
		"Stop",
		"Pause",
		"Resume"
};

typedef std::vector<uint8_t> SupportedOperationalCommands;
typedef std::vector<uint8_t> SupportedOperationalStates;

#endif /* CYCLE_CONTROL_INTERFACE_DATA_TYPES_H_ */
