# org.alljoyn.Hae.Device.IceMaker version 1

## Theory of Operation

Ice maker is a home appliance used to make, store and dispense ice. It can 
be stand-alone or embedded in a bigger refrigeration appliance 
Ice maker typically is an auxiliary device, that belongs to a refrigerator
appliance.

This interface provides capabilities to interact an specific functions and
resources of Ice makers.

There are no minimum required shared interface for the Ice maker:

Some Ice makers have the capability to be monitored and in case controlled by a
remote controller, in this case the following shared interface is implemented:

  * **org.alljoyn.Hae.OperationalControl** --- to monitor and control

The operational states that the Fridge supports to be monitored are:

  * **0** --- **Off**
  * **2** --- **Working**

If the Fridge can only be monitored it doesn't support any operational commands
(empty array).

If it can be also controlled from remote, the operational commands that it
supports are:

  * **0** --- **Off**
  * **1** --- **On**

## Specification

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Version    | 1                                                        |
| Annotation | org.alljoyn.Bus.Secure = false                           |

This interface has no information that should be protected so does not require
security.

### Properties

#### WaterSource

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

This property the information about which is the source of water used to make
ice. It is used because in some cases the source are finite, i.e. a manual user
interaction is requested to continue working.

The data type is an enumeration and its allowed value are listed below:

  * 0x00 --- **Tank** --- water from a tank
  * 0x01 --- **Pipe** --- water from a pipe
  * 0xFF --- **Unknown** --- no water source information

#### MaxWaterLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of water level.

#### WaterLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Current value of water level.
It can vary from 0 to **MaxWaterLevel** (**0** when there is no water,
**MaxWaterLevel** when the water source is full).
Step value is always 1.

If the **WaterSource** value is **Pipe** (i.e. the water doesn't need to be
charged), the **MaxWaterLevel** value is 1 and the **WaterLevel** value is
always 1.

If the **WaterSource** value is **Unknown**, the **MaxWaterLevel** is 0 and the
**WaterLevel** is 0.

### Methods

No methods are associated to this interface.

### Signals

No signals are emitted by this interface.

## Interface Errors

No unique errors are associated with this interface.

## References

  * The XML definition of the [IceMaker interface](IceMaker-v1.xml)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae/OperationalControl-v1)
