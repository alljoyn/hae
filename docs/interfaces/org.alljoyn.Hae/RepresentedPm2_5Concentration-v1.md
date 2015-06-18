# org.alljoyn.hae.RepresentedPm2_5Concentration version 1

## Specification

|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

There is no critical information that should be protected.

### Properties

#### RepresentedValue

|-----------------------|-----------------------------------------------------------------------|
| Type                  | Concentration                                                         |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The represented value of current concentration of PM2.5.
If above the MaxValue,the <significand> and <exponent> of RepresentedValue shall be
set to 0xFFFF and 0x7FFF, respectively.
If below the MinValue, the <significand> and <exponent> of RepresentedValue shall 
be set to 0x0 and 0x8000, repectively.
0 is a valid represented value except the case where both <significand> and 
<exponent> equal to 0x0 and 0x8000, respectively.
The value is expressed in ug/m3.


#### MinValue

|-----------------------|-----------------------------------------------------------------------|
| Type                  | Concentration                                                         |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = ture               |

The minimum value allowed for RepresentedValue.
The minimum value provided by device.
If there is no minimum value available, <significand> and <exponent> of this shall 
be set to 0x0 and 0x8000, respectively.
The value is expressed in ug/m3.


#### MaxValue

|-----------------------|-----------------------------------------------------------------------|
| Type                  | Concentration                                                         |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = ture               |

The maximum value allowed for RepresentedValue.
The maxmum value provided by device.
If there is no maximum value available, <significand> and <exponent> of this shall
be set to 0xFFFF and 0x7FFF, respectively.
The value is expressed in ug/m3.

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types
#### struct Concentration
Concentration struct express a fixed-point number.
  * **significand**  ---uint16--- significand of PM2.5 concentration value
  * **exponent**  ---int16--- exponent of PM2.5 concentration value

PM2.5 concentration reprensenting property(e.g. RepresentedValue, MinValue, MaxValue)
are defined using a struct where:
  * first element is the significand;
  * second element is the exponent and base is 10.The actual PM2.5 concentration value 
    can be represented by significan(10^exponent)
## References
  * the XML definition of the [RepresentedPm2_5Concentration interface]
    (RepresentedPm2_5Concentration-v1.xml)

