# org.alljoyn.Hae.Device.Humidifier version 1

## Theory of Operation

Humidifier is a home appliance used to increase humidity (moisture) in a single
room or an entire building. This humidifier interface provides capabilities to
control and monitor humidifier specific functions and resources. A controller
can recognize this device as a humidifier if object descriptions of the About
announcement include this interface

The followings are minimum required shared interfaces for humidifier.
  * **org.alljoyn.Hae.OperationalControl** --- for start/stop operation
  * **org.alljoyn.Hae.MoistureOutputRate** --- for setting moisture output rate

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
  * The definition of the [MoistureOutputRate interface](/org.alljoyn.Hae/MoistureOutputRate-v1)
  * The definition of the [TargetHumidity interface](/org.alljoyn.Hae/TargetHumidity-v1)
  * The definition of the [RepresentedHumidity interface](/org.alljoyn.Hae/RepresentedHumidity-v1)
  * The definition of the [RepresentedHumidityLevel interface](/org.alljoyn.Hae/RepresentedHumidityLevel-v1)
