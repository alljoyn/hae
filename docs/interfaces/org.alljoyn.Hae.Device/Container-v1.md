# org.alljoyn.Hae.Device.Container version 1

## Theory of Operation

Container interface is for comprising of two or more devices as same level under
the root bus object. Container interface can be a container having two or more
other device interfaces. For example, refrigerator can be represented as a
container device which has a Fridge and a Freezer. Use of the container device
interface for just one sub-unit shall be prohibited.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected so does not
require security.

### Properties

No properties are implemented by this interface.

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [Container interface](Container-v1.xml)
