# org.alljoyn.Hae version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### DeviceType

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | array of byte                                                  |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Device type identifier. For "atomic devices" it is one element array representing
the device type; for "complex devices" it is an array of more elements (>1), each
one representing an atomic device component, the first one represent the whole
appliance itself

#### DeviceModelName

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Device Model Name string, the product name or commercial code. S550-PFLUL for 
LG laptop.

#### DeviceManufacturer

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Name of the device manufacturer

#### DeviceId

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

The unique identifier for a physical appliance, the rule to generate the unique
identifier is up to device manufacturer. Covered by About I/F.

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

Corporate level brand name. for example, AEG for Electrolux and Sanyo for Panasonic,
etc.

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

The meaning of “remote” covers both proximal network and remote access from outside
home. If true, the device is controllable by remote devices. Otherwise, it is
not controllable.

### Methods

#### SetLocation (location)

Set location information of a device.

Input arguments:

  * **location** --- string --- location information of a device to set

Errors raised by this method:

  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [HAE interface](Hae-v1.xml)
