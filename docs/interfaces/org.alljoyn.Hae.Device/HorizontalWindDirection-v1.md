# org.alljoyn.Hae.HorizontalWindDirection version 1

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

Holds the horizontal direction of the fan.  0 is the leftmost position.

#### MaxValue

|               |                                                             |
|---------------|-------------------------------------------------------------|
| Type          | uint16                                                      |
| Access        | read-only                                                   |

Indicates the rightmost position of the fan.

### Methods

#### ChangeWindDirection(q)

Sets the horizontal direction of the fan.

Input arguments:

  * **q** --- uint16 --- Value between 0 (leftmost) and MaxValue (rightmost).

Errors raised by this method:

 * org.alljoyn.Error.InvalidArgument --- If a value greater than MaxValue is given.

## References

  * [The XML definition of HorizontalWindDirection](HorizontalWindDirection-v1.xml)
  * [AutoHorizontalWindDirection](AutoHorizontalWindDirection-v1.md)
