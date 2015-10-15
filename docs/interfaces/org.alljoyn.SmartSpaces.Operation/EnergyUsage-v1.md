# org.alljoyn.SmartSpaces.Operation.EnergyUsage version 1


## Theory of Operation
This interface allows a device to communicate its power and energy consumption.
The rate and precision of the updates are determined by the device, and governed
by the intended function of the device, its knowledge of significant changes 
and the need to avoid side-channel attacks.

In order for the consumer to know what update rate is expected it should read 
from the EnergyPrecision and PowerPrecision attributes to understand the amount 
of change required in the measured value before the property will update.  Note 
that reading the CurrentPower or CumulativeEnergy between updates should not
return a different value than the last changed signal, as that would violate the
org.freedesktop.DBus.Property.EmitsChangedSignal = true contract.

The Precision properties may change based on the state of the device, either 
based on user settings or the dynamic range of the power consumption.  Also 
these are Precision properties, not accuracy properties.  Accuracy should not be
implied from them.

NOTE: “Energy usage can be used to implement side-channel attacks on security 
sensitive hardware and software.  Manufacturers of devices implementing this 
interface should be aware of this possibility.  Based on their implementation 
specifics, these methods may leak information that may undermine the security of 
the AllJoyn protocol.  Limiting the resolution of the measurement, or the rate 
that the methods may be called may be sufficient protection.”

## Specification

|            |                                                          |
|------------|----------------------------------------------------------|
| Version    | 1                                                        |
| Annotation | org.alljoyn.Bus.Secure = true                            |

### Properties

#### Version

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | uint16                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

#### CurrentPower

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | double                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Holds the instantaneous power consumption of the device in Watts.
7fff ffff ffff ffff (NaN) indicates an unknown value.

#### PowerPrecision

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | double                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

The precision of the CurrentPower property.  i.e. the number of watts the
actual power consumption (the physical value which is measured) must change 
before the CurrentPower property is updated.

#### PowerUpdateRate

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | uint16                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

The minimum time between updates in seconds, if changes occur faster, even if 
they exceed PowerPrecision property value they willnot be reported.

#### CumulativeEnergy

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | double                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Holds the cumulative energy consumption of the device in kWh.
7fff ffff ffff ffff (NaN) indicates an unknown value.  ResetCumulativeEnergy 
resets the value to 0.

#### EnergyPrecision

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | double                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

The precision of the CumulativeEnergy property.  i.e. the number of kWh the
actual energy consumption (the physical value which is measured)must change 
before CumulativeEnergy property is updated.

#### EnergyUpdateRate

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | uint16                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

The minimum time between updates in seconds, if changes occur faster, even if 
they exceed EnergyPrecision property value they will not be reported.

### Methods

#### ResetCumulativeEnergy ()

Resets the value of CumulativeEnergy to 0.

Errors raised by this method:
  * org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- Indicates that
    control request from a remote site is currently disabled.  See the
    RemoteControl property in the [RemoteControllability interface](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) for
further information.


### Named Types

No Named Types are required by this interface.

### Interface Errors

The table below shows the possible raised by this inteface.

| Error name                                    | Error message         |
|-----------------------------------------------|-----------------------|
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled   | Control request from a remote site is currently disabled.       |

## References

  * [The XML definition of the EnergyUsage](EnergyUsage-v1.xml)
  * The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)
  * The definition of the [RemoteControllability interface](RemoteControllability-v1)
