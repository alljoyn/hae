# org.alljoyn.Hae.VerticalWindDirection version 1

## Specification

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Version       | 1                                                           |
| Annotation    | org.alljoyn.Bus.Secure = true                               |

### Properties

#### WindDirection

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Type          | uint16                                                      |
| Access        | read-only                                                   |
| Annotation    | org.freedesktop.DBus.Property.EmitsChangedSignal = true     |

Holds the vertical direction of the fan.  0 is the highest position.

#### MaxValue

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Type          | uint16                                                      |
| Access        | read-only                                                   |

Indicates the lowest position of the fan.

### Methods

#### ChangeWindDirection(q)

Sets the vertical direction of the fan.

Input arguments:

  * **q** --- uint16 --- Value between 0 (the highest position) and MaxValue (the lowest position).

Errors raised by this method:

 * org.alljoyn.Error.InvalidArgument --- If a value greater than MaxValue is given.

## References

  * [The XML definition of VerticalWindDirection](VerticalWindDirection-v1.xml)
  * [AutoVerticalWindDirection](AutoVerticalWindDirection-v1.md)
