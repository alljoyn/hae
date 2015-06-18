# org.alljoyn.Hae.RepresentedCh2oConcentration version 1

## Specification
|                   |                                   |
|-------------------|-----------------------------------|
| Version           | 1                                 |
| Annotation        | org.alljoyn.Bus.Secure = true     |

### Properties

#### RepresentedValue

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | RepresentedConcentration                                |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The represented value of current concentration of CH2O.
The value is expressed in ug/m3.

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types

#### struct RepresentedConcentration

RepresentedConcentration struct express a fixed-point number.
  * **significand**  ---uint16--- significand of CH2O concentration value
  * **exponent**  ---int16--- exponent of CH2O concentration value

CH2O concentration representing property(RepresentedValue)
is defined using a struct where:
  * first element is the significand;
  * second element is the exponent and base is 10.The actual CH2O concentration
    value can be represented by significand(10^exponent)

## References

  * the XML definition of the [RepresentedCh2oConcentration interface]
    (RepresentedCh2oConcentration-v1.xml)

