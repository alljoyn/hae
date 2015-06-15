# org.alljoyn.Hae.HorizontalWindDirection version 1

## Theory of Operation

HorizontalWindDirection interface is for controlling horizontal wind direction
of an electric fan. AutoMode supports to control horizontal wind direction
anautomatically.

## Specification

|                       |                                                     |
|-----------------------|-----------------------------------------------------|
| Version               | 1                                                   |
| Annotation            | org.alljoyn.Bus.Secure = false                      |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### WindDirection

|                  |                                                          |
|------------------|----------------------------------------------------------|
| Type             | uint16                                                   |
| Access           | read-only                                                |
| Annotation       | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Wind direction of a fan. 0 means the maximum left position. MaxValue means
maximum right position. An error code shall be returned if a setpoint value is
greater than MaxValue. Step value for WindDirection is always 1. Left or right
direction is based on the direction of air conditioner point of view.

#### MaxDirection

|                  |                                                          |
|------------------|----------------------------------------------------------|
| Type             | uint16                                                   |
| Access           | read-only                                                |
| Annotation       | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value allowed for a target wind direction. 0 means that device doesn't
support to set and represent the wind direction.

#### AutoMode

|                  |                                                          |
|------------------|----------------------------------------------------------|
| Type             | byte                                                     |
| Access           | read-only                                                |
| Annotation       | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

AutoMode is for controlling horizontal wind direction of an electric fan
automatically. If the AutoMode is eanbled, a high level device of this interface
controls the horizontal wind direction automatically and the WindDirection
property of the interface should be changed according to changing wind direction.
If the AutoMode is disabled, the wind direction will remain at an appropriate
fixed direction determined by the device. (At this time, the value of wind
direction can be a default value or the value when the AutoMode is disabled.
This operation of auto control direction depends on the device manufacturer.)

The property data type is an enumeration and its allowed value are listed below:
  * 0x00 --- **Off** --- Auto mode is disabled.
  * 0x01 --- **On** --- Auto mode is enabled.
  * 0xFF --- **Not supported** --- Auto mode is not supported by the specific
  appliance.

### Methods

#### SetWindDirection(windDirection)

Set the wind direction. If the controller tries to set a target value which is
out of range, then an appropriate error shall be returned.

Input arguments:

  * **windDirection** --- uint16 --- target value of wind direction

Errors raised by this method:

  * org.alljoyn.Hae.Error.InvalidValue --- Value is invalid
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not
  acceptable due to internal state
  * org.alljoyn.Hae.Error.RemoteControlDisabled --- Remote control is disabled

#### EnableAutoMode(autoMode)

Enable/Disable control of horizontal wind direction. If auto mode is disabled,
horizontal wind direction will remain at an appropriate fixed direction
determined by the controllee device. If the Automode is 0xFF(not supported),
this method shall not be used. In this case, if contoller call this method,
org.alljoyn.Hae.Error.NotSupported shall be returned.

Input arguments:

  * **autoMode** --- boolean --- Enable/Disable auto mode

Errors raised by this method:

  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not
  acceptable due to internal state
  * org.alljoyn.Hae.Error.RemoteControlDisabled --- Remote control is disabled
  * org.alljoyn.Error.NotSupported --- Auto mode is not supported by device

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                               | Error message                                 |
|----------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.InvalidValue                       | Value is invalid                              |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState    | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Error.RemoteControlDisabled              | Remote control is disabled                    |
| org.alljoyn.Hae.Error.NotSupported                       | Auto mode is not supported                    |

## References

  * The XML definition of the [HorizontalWindDirection interface](HorizontalWindDirection-v1.xml)
