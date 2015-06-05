# org.alljoyn.Hae.Device.RobotCleaner version 1

## Theory of Operation

Robot cleaner is an autonomous robotic vacuum cleaner that has intelligent
programming and a limited vacuum cleaning system. This robot cleaner interface
provides capabilities to control and monitor robot cleaner specific functions
and resources. A controller can recognize this device as a robot cleaner if
object descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for robot cleaner.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### OperationCycle

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Current operation cycle. The enumeration below lists cycles of device operation.

  * **0** --- **Cell-by-Cell** : Clean the area by dividing it into rectangular
  spaces.
  * **1** --- **Zigzag** : Repeat a zigzag operation to clean every and each
  spot in the cleaning area.
  * **2** --- **Spot** : Clean the spot by moving in a spiral.

#### SupportedOperationCycles

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operation cycles. After getting the list of supported
operation cycles, a valid one should be chosen out of the list.

#### CycleStage

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Current cycle stage. The enumeration below lists stages of cycle.

  * **0** --- **Cleaning** : Clean the area.
  * **1** --- **Homing** : Come back to the home station.
  * **2** --- **Charging** : Charge the battery in the home station.

#### TurboMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | boolean                                                        |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner runs more powerful giving cleaner results.

  * **true** --- **On** : turbo mode on
  * **false** --- **Off** : turbo mode off

#### RepeatMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | boolean                                                        |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Robot Cleaner will continuously clean until the battery runs out.

  * **true** --- **On** : repeat mode on
  * **false** --- **Off** : repeat mode off

### Methods

#### SetOperationCycle (operationCycle)

Set an operation cycle. A robot cleaner starts its operation cycle immediately
after setting or changing its target operation cycle. If the device receives
an invalid operation cycle or can’t accept a valid operation cycle due to its
internal state, then an appropriate error shall be returned.

Input arguments:

  * **operationCycle** --- byte --- an operation cycle to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

#### EnableTurboMode (turboMode)

Enable/disable the turbo mode. The turbo mode is an additional feature for
a powerful clean, so it can be applied to all operation cycles. If the device
can’t enable/disable the turbo mode due to its internal state, then an
appropriate error shall be returned.

Input arguments:

  * **turboMode** --- boolean --- true: enable, false: disable

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState  --- Value is
    not acceptable due to internal state

#### EnableRepeatMode (repeatMode)

Enable/disable the repeat mode. The repeat mode is an additional feature that
repeats the cleaning in progress until the battery runs out, so it can be
applied to all operation cycles. If the device can’t enable/disable
the repeat mode due to its internal state, then an appropriate error
shall be returned.

Input arguments:

  * **repeatMode** --- boolean --- true: enable, false: disable

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [RobotCleaner interface](org.alljoyn.Hae.Device.RobotCleaner-v1.xml)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae.OperationalControl-v1.md)