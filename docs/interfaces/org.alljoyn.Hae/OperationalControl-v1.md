# org.alljoyn.Hae.OperationalControl version 1

## Theory of Operation

This interface provides capability:
  * to get information about operational states of an appliance,
  * to control appliance with a specific set of commands linked to appliance
  operational state.  

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security.

### Properties

#### OperationalState

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | OperationalState                                                      |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the current operational state of an appliance.

#### SupportedOperationalStates

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | OperationalState[]                                                    |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates which are the supported operational states by the specific appliance.
A device may support just a subset of operational states, depending on its type
(e.g. a fridge does not support "pause" state,...) or on specific
implementation.

#### SupportedOperationalCommands

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | OperationalCommand[]                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates which are the supported operational commands by the appliance.
A device may support just a subset of operational commands, depending on its
type (e.g. a fridge does not support "pause" command,...), on the current
appliance operational state or on specific implementation.

### Methods

#### ExecuteOperationalCommand(OperationCommand)

|                       |                                             |
|-----------------------|---------------------------------------------|
| Annotation            | org.freedesktop.DBus.Method.NoReply = true  |

Execute an operation command. After getting the supported operational states and
the supported operational commands, a valid operational command should be chosen
out of the supported commands list. If a _producer_ device receives an invalid
operational command or can not execute a valid command due to its internal
operational state, then an appropriate error shall be returned.

Input arguments:

  * **OperationalCommand** --- OperationalCommand --- sent operational command

Errors raised by this method:
  * org.alljoyn.Hae.Error.InvalidValue --- Value is not supported
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    
### Signals

No signals are emitted by this interface.

### Named Types

#### OperationState
|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |

It is an enumeration type. 
Enumeration description:
  * 0 --- Off --- 
    * the device makes no physical effect and waits for the On command,
  * 1 --- Idle --- 
    * cycle Selection is unfinished,
    * the device has no selected cycle so it can not start to execute any operation,
  * 2 --- Working --- 
    * The device is executing its peculiar operation
  * 3 --- RadyToStart --- 
    * The Cycle has been selected and the device is waiting the start to execute it,
  * 4 --- DelayedStart --- 
    * The execution of the cycle is being delayed until the specified delay time elapses.
  * 5 --- Paused --- 
    * The device is in pause, its operation is on hold,
  * 6 --- EndOfCycle --- 
    * The device has completed a cycle and waits for user acknowledge or time-out to 
    move to the next state, typically ReadyToStart or Idle.  
    The device can make some post-Cycle operations in this state.  
    E.g. buzzing, making a half spin periodically (for Tumble Dryer), etc..

#### OperationalCommand
|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |

It is an enumeration type. 
Enumeration description:
  * 0 --- Off --- 
    * turn off the device operation,
  * 1 --- On --- 
    * turn on the device operation,
  * 2 --- Start --- 
    * start the device operation,
  * 3 --- Stop --- 
    * Stop the device operation,
  * 4 --- pause --- 
    * pause the device operation,
  * 5 --- Resume --- 
    * resume the device operation from pause operation state,

### Interface Errors
The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.InvalidValue                    | Value is not supported                        |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |


## Examples

**Example1**
The following sequence describes an example of an execution of a cycle and a
following stop command from remote.

1. user power on air conditioner appliance:
  * the appliance operation state moves from "Off" into "Working" state,

2. the user stops the activity of the appliance:
  * the appliance receives the "stop" operation command, accepts the command and 
  moves to "Off" operational state

**Example2**    
The following sequence describes an example of a refused operational command
from appliance.

1. appliance state executing a cycle:
  * the appliance operation state is "working",

2. the remote _consumer_ try to start the appliance:
  * the appliance receives a "start" operation command; it is refused because
  its internal state (appliance is already working). The error reported is:
  org.alljoyn.Hae.Error.NotAcceptableDueToInternalState.

## References
  * The XML definition of the [OperationalControl interface](OperationalControl-v1.xml)

