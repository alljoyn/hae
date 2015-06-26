# org.alljoyn.Hae.Device.SetTopBox version 1

## Theory of Operation

Set top box(STB) is a home appliance which can receive audio and visual
contents such as broadcasting program and network streaming and convert them
for showing on a display device such as TV. This STB interface provides
capabilities to control and monitor STB specific resources. A controller can
recognize this device as an STB if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for STB.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation

The operation states that STB supports are:
  * **0** --- **Off**
  * **2** --- **Working**

The operation commands that STB supports are:
  * **0** --- **Off**
  * **1** --- **On**

A typical STB could have some other shared interfaces and the followings are
examples.
  * **org.alljoyn.Hae.Channel** --- for control of channel selection
  * **org.alljoyn.Hae.AvInput** --- for control of external input
  * **org.alljoyn.Hae.KeyInput** --- for control of a STB remote 
  * **org.alljoyn.Hae.Mouse** --- for control of STB by mouse device

## Specification
|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

No Properties are implemented by this interface.

### Methods

No Methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

  * The XML definition of the [SetTopBox interface](org.alljoyn.Hae.Device.SetTopBox-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [Channel interface](/org.alljoyn.Hae/Channel-v1)
  * The definition of the [AvInput interface](/org.alljoyn.Hae/AvInput-v1)
  * The definition of the [KeyInput interface](/org.alljoyn.Hae/KeyInput-v1)
  * The definition of the [Mouse interface](/org.alljoyn.Hae/Mouse-v1)
