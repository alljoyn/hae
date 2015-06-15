# org.alljoyn.Hae.WindStrength version 1

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### WindStrength 

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Wind Strength of a fan operation. 0 means the lowest setting of continuous fan operation. MaxValue
means the highest setting of continuous fan operation. Step value is always 1.

#### MaxValue 

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

Maximum value allowed for target wind strength.

### Methods

#### ChangeWindStrength(windStrength)

Change the wind strength. If the controller tries to set a target value which is out of range,
then an appropriate error shall be returned.

Input arguments:

  * **windStrength** --- byte --- target value of wind strength

Errors raised by this method:

  * org.alljoyn.Hae.Error.OutOfRange --- Value is out of range
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
| org.alljoyn.Hae.Error.OutOfRange                         | Value is out of range                         |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState    | Value is not acceptable due to internal state |

## References

  * The XML definition of the [WindStrength interface](WindStrength-v1.xml)



