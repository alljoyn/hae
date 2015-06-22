# org.alljoyn.Hae.Device.Tv version 1

## Theory of Operation

Television(TV) is a home appliance used to show audio and visual contents
such as broadcasting program and network streaming. This TV interface provides
capabilities to control and monitor TV specific resources. A controller can
recognize this device as a TV if object descriptions of the About announcement
include this interface.

The followings are minimum required shared interfaces for TV.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation
  * **org.alljoyn.Hae.VolumeControl** --- for control of audio volume

A typical TV could have some other shared interfaces and the followings are
examples.
  * **org.alljoyn.Hae.Channel** --- for control of channel selection
  * **org.alljoyn.Hae.AvInput** --- for control of external input selection
  * **org.alljoyn.Hae.KeyInput** --- for control of TV by its remote
  * **org.alljoyn.Hae.Mouse** --- for control of TV by mouse device
  * **org.alljoyn.Hae.Display** --- for exposing display characteristics

## Specification
|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

No Properties are implemented by this interface.

### Methods

No Methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

  * The XML definition of the [TV interface](org.alljoyn.Hae.Device.Tv-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [VolumeControl interface](/org.alljoyn.Hae/VolumeControl-v1)
  * The definition of the [Channel interface](/org.alljoyn.Hae/Channel-v1)
  * The definition of the [AvInput interface](/org.alljoyn.Hae/AvInput-v1)
  * The definition of the [KeyInput interface](/org.alljoyn.Hae/KeyInput-v1)
  * The definition of the [Mouse interface](/org.alljoyn.Hae/Mouse-v1)
  * The definition of the [Display interface](/org.alljoyn.Hae/Display-v1)
