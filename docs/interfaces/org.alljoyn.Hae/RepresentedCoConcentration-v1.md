# org.alljoyn.Hae.RepresentedCoConcentration version 1

## Specification

|              |                                      |
|--------------|--------------------------------------|
| Version      | 1                                    |
| Annotation   | org.alljoyn.Bus.Secure = false       |

There is no critical information that should be protected.

### Properties

#### RepresentedValue

|               |                                                         |
|---------------|---------------------------------------------------------|
| Type          | CoConcentration                                         |
| Access        | read-only                                               |
| Annotation    | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The represented value of current relative concentration of CO.
Relative concentration of CO is the ratio of CO to the monitered mixture of gases.
The valus is expressed in ppm( Parts Per Million ).

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types

#### struct CoConcentration

CoConcentration struct express a fixed-point number.
  * **significand**  ---uint32--- significand of CO concentration value
  * **exponent**  ---int16--- exponent of CO concentration value

CO concentration reprensenting property(RepresentedValue)
is defined using a struct where:
  * first element is the significand;
  * second element is the exponent and base is 10.The actual CO concentration
    value can be represented by significand(10^exponent)

## References

  * the XML definition of the [RepresentedCoConcentration interface]
    (RepresentedCoConcentration-v1.xml)

