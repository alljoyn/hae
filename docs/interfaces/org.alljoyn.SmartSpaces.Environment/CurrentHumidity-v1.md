# org.alljoyn.SmartSpaces.Environment.CurrentHumidity version 1

## Theory of Operation
This interface provides capability to represent current
relative humidity.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The interface version.

#### CurrentValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The current relative humidity, expressed in percentage(0~100%). Relative humidity
is the ratio of the partial pressure of water vapor to the equilibrium vapor
pressure of water at the same temperature.

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [CurrentHumidity interface](CurrentHumidity-v1.xml)
