# org.alljoyn.SmartSpaces.Environment.CurrentAirQuality version 1

## Specification
|                   |                                   |
|-------------------|-----------------------------------|
| Version           | 1                                 |
| Annotation        | org.alljoyn.Bus.Secure = true     |

### Properties

#### Version

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | uint16                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

interface version.

#### AirQualityType

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | byte                                                    |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

the type of air quality.
0 : CH2O
1 : CO2
2 : CO
3 : PM2.5
4 : PM10
5 : VOC

#### AirQualityUnit

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | byte                                                    |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

the unit of current value.
0 : ppm
1 : ug/m3

#### CurrentValue

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | double                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The current value of concentration of air quality.

#### MaxValue

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | double                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The maximum value allowed for CurrentValue.
The maximum value provided by device.
If the MaxValue is not supported by the specific appliance , 
the MaxValue shall be set to 0XFFF0 0000 0000 0000.
The default value of MaxValue is 0X7FF0 0000 0000 0000.

#### MinValue

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | double                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The minimum value allowed for CurrentValue.
The minimum value provided by device.
If the MinValue is not supported by the specific appliance, 
the MinValue shall be set to 0XFFF0 0000 0000 0000.
The default value of MinValue is 0X0.
 
### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

## References

  * the XML definition of the [CurrentAirQuality interface]
    (CurrentAirQuality-v1.xml)

