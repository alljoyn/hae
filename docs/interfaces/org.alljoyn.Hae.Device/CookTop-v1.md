# org.alljoyn.Hae.Device.CookTop version 1

## Theory of Operation

The CookTop is a home appliance with a flat framework used to place pots to be
heated, so the food inside is cooked. This interface is applicable to different
types of CookTop: Gas based, Electrical, Induction ...

There are no minimum required shared interfaces for these appliances.

Following interfaces can be supported when a specific Oven implements extra
features:

  * **org.alljoyn.Hae.OperationalControl** --- for monitoring and controlling
    the appliance operation time

  * **org.alljoyn.Hae.OperationalTime** --- for monitoring and controlling the
    appliance operation time

  * **org.alljoyn.Hae.Alerts** --- for communicating alerts

  * **org.alljoyn.Hae.RepresentedTemperature** --- for monitoring the
    temperature of the cavity

The **org.alljoyn.Hae.OperationalControl** property is optional because in some
case, for safety reason, it is a device to be used when the user is in front of
it; so its on/off status can not be only monitor.
Anyway when it is allowed, some specific appliances can implement the following
features:

  * communicate the on/off status
  * turning off the device remotely

This interface can be used:
  * stand alone, to describe one or more heating zones that can be controlled
    (if **org.alljoyn.Hae.OperationalControl** is supported) together.
  * as sub-unit of a complex device; e.g. a CookTop with different heating zones
    which can be controlled separatel

## Specification

|            |                               |
| ---------- | ----------------------------- |
| Version    | 1                             |
| Annotation | org.alljoyn.Bus.Secure = true |

### Properties

### NumberOfHeatingZones

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It indicates the total number of heating zones of the CookTop.
The zones can be activated dynamically if the CookTop implement pot recognition.
The value is 1 for CookTop with just a fixed zone.

### MaxHeatingLevels

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte[]                                                   |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It indicates the max power levels for each the heating zone.

### HeatingLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |
	
It indicates the list of current heating levels of the different zones of the
CookTop.
For each element the value range is from 0 (indication that the zone is not
heating) to the value of related element of **MaxHeatingLevels**.

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [CookTop interface](CookTop-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalTime-v1)
  * The definition of the [Alerts interface](/org.alljoyn.Hae/Alerts-v1)
