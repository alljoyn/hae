# org.alljoyn.Hae.AutoWindStrength version 1

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

Holds the state of the control mode, true if automatic, false otherwise.

### Methods

#### TurnOnAutoControl(b)

Input arguments:

  * **b** --- boolean --- Controls the state of the automatic control of wind
    strength. Set TRUE/FALSE to turn on/off the automatic control.

## References

  * [The XML definition of AutoWindStrength](AutoWindStrengh-v1.xml)
  * [WindStrength](WindStrength-v1.md)
