# org.alljoyn.Hae.AutoVerticalWindDirection version 1

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### AutoControl 

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The state of auto wind direction control mode.

### Methods

#### TurnOnAutoControl(autoControl)

Turn on/off automatic control of wind direction. If it is False, then the wind direction will remain
at an appropriate fixed direction determined by the controllee device.

Input arguments:

  * **autoControl** --- boolean --- auto control mode on/off

Errors raised by this method:

  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to 
    internal state

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.
    
| Error name                                                                 | Error message                                 |
|----------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState    | Value is not acceptable due to internal state |

## References

  * The XML definition of the [AutoVerticalWindDirection interface](AutoVerticalWindDirection-v1.xml)



