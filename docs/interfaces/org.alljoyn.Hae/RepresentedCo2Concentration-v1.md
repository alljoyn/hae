# org.alljoyn.hae.RepresentedCo2Concentration version 1

## Specification

|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### RepresentedValue

|-----------------------|-----------------------------------------------------------------------|
| Type                  | Co2Concentration                                                    |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The represented value of current relative concentration of CO2.
Relative concentration of CO2 is the ratio of CO2 to the monitered mixture of gases.
The valus is expressed in ppm( Parts Per Million ).

### Methods

No methods are exposed by this interface.

### Signals

No signals are exposed by this interface.

###Named Types
#### struct Co2Concentration
Co2Contration struct express a fixed-point number.
  * **significand**  ---uint32--- significand of CO2 concentration value
  * **exponent**  ---int16--- exponent of CO2 concentration value

CO2 concentration reprensenting property(RepresentedValue)
is defined using a struct where:
  * first element is the significand;
  * second element is the exponent and base is 10.The actual CO2 concentration value 
  can be represented by significan(10^exponent)
## References
  * the XML definition of the [RepresentedCo2Concentration interface] (RepresentedCo2Concentration-v1.xml)

