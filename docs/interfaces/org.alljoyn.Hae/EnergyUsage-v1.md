# org.alljoyn.Hae.EnergyUsage version 1

## Specification

|            |                                                          |
|------------|----------------------------------------------------------|
| Version    | 1                                                        |
| Annotation | org.alljoyn.Bus.Secure = true                            |

### Properties

#### RepresentedPower

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | FixedPointNumber                                         |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Holds the instantaneous power consumption of the device.  The value is
expressed in Watt.  The state is unknown when the significand and exponent
hold 0x80000000 and 0x7FFF.

#### UsedEnergy

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | FixedPointNumber                                         |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Holds the cumlative energy consumption of the device.  The value is expressed
in kWh.  The state is unknown when the significand and exponent hold
0x80000000 and 0x7FFF.  ResetUsedEnergy resets the value to 0.

### Methods

#### ResetUsedEnergy ()

Resets the value of UsedEnergy to 0.

### Named Types

#### struct FixedPointNumber

  * **significand** --- int32
  * **exponent** --- int16

For more information, see the definition of [org.alljoyn.Hae.RepresentedTemperature](/org.alljoyn.Hae/RepresentedTemperature-v1).

## References

  * [The XML definition of the EnergyUsage](EnergyUsage-v1.xml)
  * [The definition of RepresentedTemperature](/org.alljoyn.Hae/RepresentedTemperature-v1)
