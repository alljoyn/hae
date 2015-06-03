# org.alljoyn.Hae.RepresentedHumidityLevel version 1

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### RepresentedValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The qualitative representation of current relative humidity level.
The scope of value is 0 to MaxValue.

#### MaxValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

Maximum value allowed for represented relative humidity level.

### Methods

No methods are exposed by this interface.  

### Signals

No signals are emitted by this interface.

## References

In this section, list references for the Interface definition (standards, RFCs,
related interfaces, etc.). Make sure to include at least the following
references:

  * The XML definition of the [RepresentedHumidityLevel interface](org.alljoyn.Hae.RepresentedHumidityLevel-v1.xml)
  * t.b.d.: the formal XML definition of the Interface described in this document
  * t.b.d.: the Theory of Operation document, if you decided to split it off
  * t.b.d.: the interface definition document for related interfaces (especially those
    that are described in the same Theory of Operation document)

