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

The current value of relative humidity. Relative humidity is the ratio of 
the partial pressure of water vapor to the equilibrium vapor pressure of 
water at the same temperature. If **MaxValue** is equal to 100, this
CurrentVaule will be expressed in percentage (0~100%). Otherwise, it will
represent the qualitative level of current relative humidity by a number.


#### MaxValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value allowed for represented relative humidity. The upper limit of 
this MaxValue is 100. In case the MaxValue equals to 100, the CurrentValue is 
a percentage ratio of relative humidity. Otherwise, the CurrentValue represents
the qualitative level of current relative humidity (0~MaxValue), and the 
MaxValue is the maximum value allowed for qualitative level represenation.

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [CurrentHumidity interface](CurrentHumidity-v1.xml)
