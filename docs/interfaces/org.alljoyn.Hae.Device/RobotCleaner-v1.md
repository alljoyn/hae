# org.alljoyn.Hae.Device.RobotCleaner version 1

## Theory of Operation

Robot cleaner is an autonomous robotic vacuum cleaner that has intelligent
programming and a limited vacuum cleaning system. This robot cleaner interface
provides capabilities to control and monitor robot cleaner specific functions
and resources. A controller can recognize this device as a robot cleaner if
object descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for robot cleaner.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation

For example, A relationship betweeen operational state of the OperatoinalControl
interface and behavior of robot cleaner can express below:

  * **Idle** --- The robot cleaner is being charged, but the battery level is
  not above threshold to start its cleaning option.
  * **ReadyToStart** --- If the battery charging level goes above that
  threshold, then the operational state will change from Idle to ReadyToStart
  automatically.
  * **Working** --- The robot cleaner is in cleaning operation or on the way
  back to the base station.
  * **Pasued** --- During cleaning operaition, if the robot cleaner receives
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

#### OperationalCycleId

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational cycle identifier. The property
values are organized in two ranges.

  * 0x0000-0x7FFF --- **standard cycle id** --- the meanings is shared among
    every appliance supporting the RobotCleaner interface
  * 0x8000-0xFFFF --- **proprietary cycle id** --- the meanings depends on
    manufacturer so different appliances can use the same values with different
    meanings

  * stadard...

#### SupportedOperationalCycleIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It lists the values of operational cycle identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalCycleId** can assume.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges. In case there can be only element of one of the
range.
If the array is empty the appliance doesn't communicate the operational cycle
identifier value information to the controller.

#### SelectableOperationalCycleIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It lists the values of operational cycle identifiers of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalCycleId** property using the
**SetOperationalCycleId** method.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges.
If the array is empty the operational cycle identifier of the appliance can not
be set from remote.

The elements **SelectableOperationalCycleIds** shall be a subset of the elements
of **SupportedOperationalCycleIds**.

#### CyclePhaseId

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected cycle phase identifier. The property
values are organized in two ranges.

  * 0x00-0x7F --- **standard phase id** --- the meanings is shared among
    every appliance supporting the RobotCleaner interface
  * 0x80-0xFF --- **proprietary phase id** --- the meanings depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists cycles of **standard phase id**.

  * **0** --- **Cleaning** : Clean the area.
  * **1** --- **Homing** : Come back to the home station.

#### SupportedCyclePhaseIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It lists the values of cycle phase identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**CyclePhaseId** can assume.

The elements of the array belongs to the **standard phase id** and
**proprietary phase id** ranges. In case there can be only element of one of the
range.
If the array is empty the appliance doesn't communicate the cycle phase
identifier value information to the controller.


#### TurboMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner runs more powerful giving cleaner results.

  * **0** --- **Off** : turbo mode off
  * **1** --- **On** : turbo mode on
  * **0xFF** --- **Not Supported** : turbo mode not supported

#### RepeatMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner will continuously clean until the battery runs out.

  * **0** --- **Off** : repeat mode off
  * **1** --- **On** : repeat mode on
  * **0xFF** --- **Not Supported** : repeat mode not supported

### Methods

#### SetOperationalCycleId (operationalCycleId)

Set an operational cycle id. A robot cleaner starts its operational cycle immediately
after setting or changing its target operational cycle id. If the device receives
an invalid operational cycle id or can’t accept a valid operational cycle due to its
internal state, then an appropriate error shall be returned.

Input arguments:

  * **operationalCycleId** --- uint16 --- an operational cycle id to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetOperationalCyclesDescription (languageTag) -> (cyclesDescription)

Get added information about the cycle which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary cycles supported by the appliance, so they can be available by the
remote controller.
In principle standard cycles have standards names and descriptions which are
defined at specification level, anyway the method can be give information

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- OperationalCycleDescriptor[] --- the list of cycle
    descriptions, they contain only **proprietary cycle id**

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotSupported --- the language specified is not
    supported

#### GetCyclePhasesDescription (languageTag) -> (phasesDescription)

Get added information about the phase which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary phase supported by the appliance, so they can be available by the
remote controller.
In principle standard phase have standard names and descriptions which are
defined at specification level, anyway the method can be give information

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **phasesDescription** --- CyclePhaseDescriptor[] --- the list of phase
    descriptions, they contain only **proprietary phase id**

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotSupported --- the language specified is not
    supported

#### EnableTurboMode (turboMode)

Enable/disable the turbo mode. The turbo mode is an additional feature for
a powerful clean, so it can be applied to all operational cycles. If the device
can’t enable/disable the turbo mode due to its internal state, then an
appropriate error shall be returned.

Input arguments:

  * **turboMode** --- boolean --- true: enable, false: disable

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState  --- Value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled
  * org.alljoyn.Hae.Device.Error.NotSupported --- turbo mode is not supported by device

#### EnableRepeatMode (repeatMode)

Enable/disable the repeat mode. The repeat mode is an additional feature that
repeats the cleaning in progress until the battery runs out, so it can be
applied to all operational cycles. If the device can’t enable/disable
the repeat mode due to its internal state, then an appropriate error
shall be returned.

Input arguments:

  * **repeatMode** --- boolean --- true: enable, false: disable

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled
  * org.alljoyn.Hae.Device.Error.NotSupported --- repeat mode is not supported by device

### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalCycleDescriptor

This structure is used to give added information about a cycle, using its
operational cycle id as reference.

  * **cycleId** --- uint16 --- operational cycle id
  * **name** --- string --- name of the operational cycle (e.g. "Zigzag", ...)
  * **description** --- string --- description of the operational cycle, it can
  be empty string in case there is no description

#### struct CyclePhaseDescriptor

This structure is used to give added information about a phase, using its
cycle phase id as reference.

  * **phaseId** --- byte --- cycle phase id
  * **name** --- string --- name of the cycle phase (e.g. "Cleaning", ...)
  * **description** --- string --- description of the cycle phase, it can
  be empty string in case there is no description


### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled                    |
| org.alljoyn.Hae.Device.Error.NotSupported                    | Mode is not supported by device               |

## References

  * The XML definition of the [RobotCleaner interface](RobotCleaner-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
