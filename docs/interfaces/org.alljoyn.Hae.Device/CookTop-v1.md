# org.alljoyn.Hae.Device.CookTop version 1

## Theory of Operation

The CookTop is a home appliance with a flat framework used to place pots to be
heated, so the food inside is cooked.

There are no minimum required shared interfaces for these appliances.

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is to be included in a higher level device which can provide
application layer security.

### Properties

### ZonesNumber

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

It indicates the total number of heating zones of the cook-top.

### MaxPowerLevel

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

It indicates the max power level of the power zones.
It is assumed that the max power level is the same for every zone.

### ZonesPowerLevels

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte[]                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of current power level of the different zones of the
cook-top.
The values range is from 0 (indication that the zone is off) to
**MaxPowerLevel** value.

### Methods

No methods are associated to this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [CookTop interface](CookTop-v1.xml)

