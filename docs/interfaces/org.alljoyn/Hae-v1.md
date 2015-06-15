# org.alljoyn.Hae version 1

## Theory of Operation
This interface is a common AllJoyn interface for all HAE devices. Per About
announcement, there shall be one and only one common interface for HAE service
framework and the bus object where the common interface reside is the root HAE
bus object.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### CountryOfProduction

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Country of production

#### Location

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Location of a device

#### CorporateBrand

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Corporate level brand name. for example, AEG for Electrolux and Sanyo for
Panasonic, etc.

#### ProductBrand

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Product level brand name. Walkman and Bravia for Sony, Viera for Panasonic.

#### RemoteControl

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | boolean                                                        |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The meaning of "remote" covers both proximal network and remote access from
outside home. If true, the device is controllable by remote devices. Otherwise,
it is not controllable.

### Methods

#### SetLocation (location)

Set location information of a device.

Input arguments:

  * **location** --- string --- location information of a device to set

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [HAE interface](Hae-v1.xml)
