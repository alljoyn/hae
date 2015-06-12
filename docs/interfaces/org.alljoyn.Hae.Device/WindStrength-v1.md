# org.alljoyn.Hae.WindStrength version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### WindStrength
|            |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Holds the level of the strength of the wind that is produced by the fan.
The lowest level is 0.  A signal is emitted when the level is changed.

#### MaxValue
|            |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |

Indicates the highest level of the strength of the wind.

### Methods

#### ChangeWindStrength (y)

Sets the level of the strength of the wind.

Input arguments:

  * **y** --- byte --- The level of the strength of the wind.
    Positive numbers are only allowed.

Errors raised by this method:

 * org.alljoyn.Error.InvalidArgument

## References

  * [The XML definition of the WindStrength](WindStrength-v1.xml)
  * [AutoWindStrength](AutoWindStrength-v1.md)
