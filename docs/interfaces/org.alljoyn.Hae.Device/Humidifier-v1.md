# org.alljoyn.Hae.Device.Humidifier version 1

## Theory of Operation

Humidifier is a home appliance used to increase humidity (moisture) in a single
room or an entire building. This humidifier interface provides capabilities to
control and monitor humidifier specific functions and resources. A controller
can recognize this device as a humidifier if object descriptions of the About
announcement include this interface

The followings are minimum required shared interfaces for humidifier.
  * **org.alljoyn.Hae.OperationalControl** --- for start/stop operation

Some humidifiers have capablities to control and monitor target humidity or
moisture output rate.

In those cases following shared interfaces are implemented:

  * **org.alljoyn.Hae.TargetHumidity --- for setting target humidity
  * **org.alljoyn.Hae.MoistureOutput** --- for setting moisture output rate

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

No Properties are implemented by this interface.

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

  * The XML definition of the [Humidifier interface](Humidifier-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetHumidity interface](/org.alljoyn.Hae/TargetHumidity-v1)
  * The definition of the [MoistureOutputinterface](/org.alljoyn.Hae/MoistureOutput-v1)
