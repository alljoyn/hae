# org.alljoyn.Hae.RepresentedTemperature version 1

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### RepresentedValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | Temperature                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The represented value of current temperature, expressed in Celsius.
See fixed-point representation for more information in Temperature struct definition.

### Methods

No methods are exposed by this interface.  

### Signals

No signals are emitted by this interface.

### Named Types

#### struct Temperature

  * **n** --- int32 --- significand of temperature value
  * **n** --- int32 --- exponent of temperature value
  
## References

In this section, list references for the Interface definition (standards, RFCs,
related interfaces, etc.). Make sure to include at least the following
references:

  * The XML definition of the [RepresentedTemperature interface](org.alljoyn.Hae.RepresentedTemperature-v1.xml)
  * t.b.d.: the formal XML definition of the Interface described in this document
  * t.b.d.: the Theory of Operation document, if you decided to split it off
  * t.b.d.: the interface definition document for related interfaces (especially those
    that are described in the same Theory of Operation document)

