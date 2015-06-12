# org.alljoyn.Hae.AutoVerticalWindDirection version 1

## Specification

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Version       | 1                                                           |
| Annotation    | org.alljoyn.Bus.Secure = true                               |

### Properties

#### AutoControl

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Type          | boolean                                                     |
| Access        | read-only                                                   |
| Annotation    | org.freedesktop.DBus.Property.EmitsChangedSignal = true     |

Holds the state of automatic control of wind direction.  True if the direction
is automatically controlled, false otherwise.

### Methods

#### TurnOnAutoControl(b)

Input arguments:

  * **b** --- boolean --- Controls the state of the automatic control of wind
    direction. Set TRUE/FALSE to turn on/off the automatic control.

## References

  * [The XML definition of AutoVerticalWindDirection](AutoVerticalWindDirection-v1.xml)
  * [VerticalWindDirection](VerticalWindDirection-v1.md)
