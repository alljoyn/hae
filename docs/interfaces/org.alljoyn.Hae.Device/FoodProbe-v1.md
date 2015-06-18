# org.alljoyn.Hae.Device.FoodProbe version 1

## Theory of Operation

The Food Probe is a device used for checking the preparation of foods (typically
the meat) to ensure that the appropriate and safe internal temperature has been
achieved. Some probes are inserted into the food, other are just placed close to
it.

The Food Probe interface can be used:
  * as stand-alone when it represent an independent device
  * as a sub-unit of another appliance, typically an oven.

The minimum required shared interface for a Food Probe is:

  * **org.alljoyn.Hae.TargetTemperature** --- for monitoring the measured
    temperature

Following interfaces can be supported when a specific Food Probe implements
extra features:

  * **org.alljoyn.Hae.RepresentedTemperature** --- for controlling the
    temperature
  
  * **org.alljoyn.Hae.OperationalControl** --- for controlling the on/off status

## Specification

|            |                               |
| ---------- | ----------------------------- |
| Version    | 1                             |
| Annotation | org.alljoyn.Bus.Secure = true |

### Properties

### FoodProbeInsertionStatus

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

In some case the Food Probe can work only if it is inserted/connected it the
hosting device, e.g. the oven.
This property indicates whether the Food Probe inserted, not inserted or doesn't
support this feature.

The data type is an enumeration and its allowed values and descriptions are
listed below:

  * 0x00 --- **not inserted** ---  the Food Probe is inserted
  * 0x01 --- **inserted** --- the Food Probe is not inserted
  * 0xFF --- **not supported** --- the Food Probe doesn't communicate the
    insertion status

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * [The XML definition of FoodProbe](FoodProbe-v1.xml)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)

  