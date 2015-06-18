# org.alljoyn.SmartSpaces.Environment.CurrentPm2_5Concentration version 1

## Specification

|             |                                                 |
|-------------|-------------------------------------------------|
| Version     | 1                                               |
| Annotation  | org.alljoyn.Bus.Secure = true                   |

### Properties

#### RepresentedValue

|             |                                                           |
|-------------|-----------------------------------------------------------|
| Type        | RepresentedConcentration                                  |
| Access      | read-only                                                 |
| Annotation  | org.freedesktop.DBus.Property.EmitsChangedSignal = true   |

The represented value of current concentration of PM2.5.
If above the MaxValue,the <significand> and <exponent> of RepresentedValue shall be
set to 0xFFFF and 0x7FFF, respectively.
If below the MinValue, the <significand> and <exponent> of RepresentedValue shall
be set to 0x0 and 0x8000, respectively.
0 is a valid represented value except the case where both <significand> and
<exponent> equal to 0x0 and 0x8000, respectively.
The value is expressed in ug/m3.


#### MinValue

|             |                                                           |
|-------------|-----------------------------------------------------------|
| Type        | RepresentedConcentration                                  |
| Access      | read-only                                                 |
| Annotation  | org.freedesktop.DBus.Property.EmitsChangedSignal = true   |

The minimum value allowed for RepresentedValue.
The minimum value provided by device.
If there is no minimum value available, <significand> and <exponent> of this shall
be set to 0x0 and 0x8000, respectively.
The value is expressed in ug/m3.


#### MaxValue

|             |                                                           |
|-------------|-----------------------------------------------------------|
| Type        | RepresentedConcentration                                  |
| Access      | read-only                                                 |
| Annotation  | org.freedesktop.DBus.Property.EmitsChangedSignal = true   |

The maximum value allowed for RepresentedValue.
The maximum value provided by device.
If there is no maximum value available, <significand> and <exponent> of this shall
be set to 0xFFFF and 0x7FFF, respectively.
The value is expressed in ug/m3.

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types

#### struct RepresentedConcentration

RepresentedConcentration struct express a fixed-point number.
  * **significand**  ---uint16--- significand of PM2.5 concentration value.
  * **exponent**  ---int16--- exponent of PM2.5 concentration value.

PM2.5 concentration representing property(e.g. RepresentedValue, MinValue, MaxValue)
are defined using a struct where:
  * first element is the significand.
  * second element is the exponent and base is 10.The actual PM2.5 concentration value
    can be represented by significand(10^exponent).

## References

  * the XML definition of the [CurrentPm2_5Concentration interface]
    (CurrentPm2_5Concentration-v1.xml)

