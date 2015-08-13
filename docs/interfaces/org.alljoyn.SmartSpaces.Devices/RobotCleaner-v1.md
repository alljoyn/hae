# org.alljoyn.SmartSpaces.Devices.RobotCleaner version 1

## Theory of Operation

Robot cleaner is an autonomous robotic vacuum cleaner that has intelligent
programming and a limited vacuum cleaning system. This robot cleaner interface
provides capabilities to control and monitor robot cleaner specific functions
and resources. A controller can recognize this device as a robot cleaner if
object descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for robot cleaner.
  * **org.alljoyn.SmartSpaces.Operation.Control** --- for control of operation

For example, A relationship betweeen operational state of the OperationalControl
interface and behavior of robot cleaner can express below:

  * **Idle** --- The robot cleaner is being charged, but the battery level is
  not above threshold to start its cleaning option.
  * **ReadyToStart** --- If the battery charging level goes above that
  threshold, then the operational state will change from Idle to ReadyToStart
  automatically.
  * **Working** --- The robot cleaner is in cleaning operation or on the way
  back to the base station.
  * **Paused** --- During cleaning operaition, if the robot cleaner receives
  "Pause" command, then it pauses its cleaning operation and waits for "Resume"
  command to resume its cleaning operation.
  * **EndOfCycle** --- The robot cleaner has completed its cleaning operation
  and waits for user acknowledge or time-out to move to the next state. After
  user's acknowledge or time-out, it may or may not return back to the base
  station depending on device implementation.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Interface version.

#### OperationalCycle

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational cycle. A robot cleaner starts
its operational cycle immediately after setting or changing its target
operational cycle. If the device receives an invalid operational cycle
or can’t accept a valid operational cycle due to its internal state,
then an appropriate error shall be returned.

The property values are organized in two ranges.

  * 0x0000-0x7FFF --- **standard cycle** --- the meanings are shared among
    every appliance supporting the RobotCleaner interface
  * 0x8000-0xFFFE --- **vendor-defined cycle** --- the meanings depend on
    manufacturer so different appliances can use the same values with different
    meanings
  * 0xFFFF --- **not supported** : the reserved special value for
    "not supported". If there is no supported operational cycles,
    this value can be set as 0xFFFF.

Errors raised when setting this property:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
    operational mode.
  * org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
    if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
    control is disabled.

#### SupportedOperationalCycles

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It lists the values of operational cycles which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalCycle** can assume.

The elements of the array belongs to the **standard mode** and
**vendor-defined mode** ranges. In case there can be only element of one
of the range. If the array is empty, OperationalMode shall be set to 0xFFFF
for "not supported".

#### SelectableOperationalCycles

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It lists the values of operational cycles of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalCycle** property using the
**SetOperationalCycle** method.

The elements of the array belongs to the **standard cycle** and
**vendor-defined cycle** ranges.
If the array is empty the operational cycle of the appliance can not
be set from remote.

The elements **SelectableOperationalCycles** shall be a subset of the elements
of **SupportedOperationalCycles**.

#### CyclePhase

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected cycle phase. The property
values are organized in two ranges.

  * 0x00-0x7F --- **standard phase ** --- the meanings is shared among
    every appliance supporting the RobotCleaner interface
  * 0x80-0xFF --- **vendor-defined phase ** --- the meanings depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists cycles of **standard phase**.

  * **0** --- **Cleaning** : Clean the area.
  * **1** --- **Homing** : Come back to the home station.

#### SupportedCyclePhases

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It lists the values of cycle phases which are supported by the
appliance. It is used to know in advance and which are the values that the
**CyclePhase** can assume.

The elements of the array belongs to the **standard phase** and
**vendor-defined phase** ranges.
If the array is empty the appliance doesn't communicate the cycle phase
value information to the controller.

#### TurboMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner runs more powerful giving cleaner results.
The turbo mode is an additional feature for a powerful clean,
so it can be applied to all operational cycles. If the device
can’t enable/disable the turbo mode due to its internal state, then an
appropriate error shall be returned.

  * **0** --- **Off** : turbo mode off
  * **1** --- **On** : turbo mode on
  * **0xFF** --- **Not Supported** : turbo mode not supported

Errors raised when setting this property:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
  operational mode.
  * org.alljoyn.Error.SmartSpace.NotAcceptableDueToInternalState --- Returned if
  value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpace.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### RepeatMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner will continuously clean until the battery runs out.
The repeat mode is an additional feature that
repeats the cleaning in progress until the battery runs out, so it can be
applied to all operational cycles. If the device can’t enable/disable
the repeat mode due to its internal state, then an appropriate error
shall be returned.

  * **0** --- **Off** : repeat mode off
  * **1** --- **On** : repeat mode on
  * **0xFF** --- **Not Supported** : repeat mode not supported

Errors raised when setting this property:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
  operational mode.
  * org.alljoyn.Error.SmartSpace.NotAcceptableDueToInternalState --- Returned if
  value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpace.RemoteControlDisabled --- Returned if remote
  control is disabled.

### Methods

#### GetOperationalCyclesDescription (languageTag) -> (cyclesDescription)

Get addtional information about the cycles which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
vendor-defined cycles supported by the appliance, so they can be available by
the remote controller.
In principle standard cycles have standards names and descriptions which are
defined at specification level.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- OperationalCycleDescription[] --- the list of cycle
    descriptions, they contain only **vendor-defined cycle**

Errors raised by this method:

  * org.alljoyn.Error.LanguageNotSupported --- the language specified is not
    supported

#### GetCyclePhasesDescription (languageTag) -> (phasesDescription)

Get addtional information about the phases which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
vendor-defined phases supported by the appliance, so they can be available by
the remote controller.
In principle standard phases have standard names and descriptions which are
defined at specification level, anyway the method can be give information

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **phasesDescription** --- CyclePhaseDescription[] --- the list of phase
    descriptions, they contain only **vendor-defined phase**

Errors raised by this method:

  * org.alljoyn.Error.LanguageNotSupported --- the language specified is not
    supported

### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalCycleDescription

This structure is used to give additional information about a cycle, using its
operational cycle as reference.

  * **cycle** --- uint16 --- operational cycle
  * **name** --- string --- name of the operational cycle (e.g. "Zigzag", ...)
  * **description** --- string --- description of the operational cycle, it can
  be empty string in case there is no description

#### struct CyclePhaseDescription

This structure is used to give addtional information about a phase, using its
cycle phase as reference.

  * **phase** --- byte --- cycle phase
  * **name** --- string --- name of the cycle phase (e.g. "Cleaning", ...)
  * **description** --- string --- description of the cycle phase, it can
  be empty string in case there is no description


### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.FeatureNotAvailable                         | Feature not supported                              |
| org.alljoyn.Error.InvalidValue                                | Invalid value                                      |
| org.alljoyn.Error.LanguageNotSupported                        | The language specified is not supported            |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

# References

  * The XML definition of the [RobotCleaner interface](RobotCleaner-v1.xml)
  * The definition of the [Operation Control interface](/org.alljoyn.SmartSpaces.Operation/Control-v1)
