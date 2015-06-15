# org.alljoyn.Hae.HorizontalWindDirection version 1

## Theory of Operation

HorizontalWindDirection interface is for controlling horizontal wind direction
of an electric fan. If device has the AutoHorizontalWindDirection interface,
the value of WindDirection property should be changed according to changing
auto wind direction.

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = true                                         |

### Properties

#### WindDirection

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | uint16                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Wind direction of a fan. 0 means the maximum left position. MaxValue means
maximum right position. An error code shall be returned if a setpoint value is
greater than MaxValue. Step value for WindDirection is always 1. Left or right
direction is based on the direction of air conditioner point of view.

#### MaxValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | uint16                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

Maximum value allowed for a target wind direction.

### Methods

#### ChangeWindDirection(windDirection)

Change the wind direction. If the controller tries to set a target value which is out of range,
then an appropriate error shall be returned.

Input arguments:

  * **windDirection** --- uint16 --- target value of wind direction

Errors raised by this method:

  * org.alljoyn.Hae.Error.OutOfRange --- Value is out of range
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not
  acceptable due to internal state


### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                               | Error message                                 |
|----------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.OutOfRange                         | Value is out of range                         |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState    | Value is not acceptable due to internal state |

## References

  * The XML definition of the [HorizontalWindDirection interface](HorizontalWindDirection-v1.xml)
  * [The definition of AutoHorizontalWindDirection](AutoHorizontalWindDirection-v1)


