# org.alljoyn.SmartSpaces.Environment.CurrentVocConcentration version 1

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

The represented value of current concentration of VOC.
The value is expressed in ug/m3.

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types

#### struct RepresentedConcentration

RepresentedConcentration struct express a fixed-point number.
  * **significand**  ---uint16--- significand of VOC concentration value.
  * **exponent**  ---int16--- exponent of VOC concentration value.

VOC concentration representing property(RepresentedValue)
is defined using a struct where:
  * first element is the significand.
  * second element is the exponent and base is 10.The actual VOC concentration
    value can be represented by significand(10^exponent).

## References

  * the XML definition of the [CurrentVocConcentration interface]
    (CurrentVocConcentration-v1.xml)

