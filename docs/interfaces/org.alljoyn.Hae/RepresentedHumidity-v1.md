# org.alljoyn.Hae.RepresentedHumidity version 1

## Theory of Operation
This RepresentedHumidity interface provides capability to represent current
relative humidity.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### RepresentedValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The represented value of current relative humidity. Relative humidity is the
ratio of the partial pressure of water vapor to the equilibrium vapor pressure
of water at the same temperature.

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [RepresentedHumidity interface](RepresentedHumidity-v1.xml)
