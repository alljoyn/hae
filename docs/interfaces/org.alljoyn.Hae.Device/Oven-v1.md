# org.alljoyn.Hae.Device.Oven version 1

## Theory of Operation

The Oven is a home appliance used to roast and heat food in a complete stove.
This interface is applicable to different types of Ovens: Gas Ovens, Electrical
Ovens, Steam ovens, Microwave Ovens ...

An oven may have more cavities and so it may be a complex structure device.

The followings are minimum required shared interfaces for these appliances.
  * **org.alljoyn.Hae.OperationalControl** --- for monitoring and controlling the appliance operation state
  * **org.alljoyn.Hae.OperationalTime** --- for monitoring and controlling the appliance operation time
  * **org.alljoyn.Hae.TargetTemperature** --- for setting target temperature
  * **org.alljoyn.Hae.RepresentedTemperature** --- for display of current temperature

The temperature interfaces can have multiple instances related to:
- the oven cavities temperatures
- the food probe temperatures, if any.

In case of more cavities oven (complex device) the above interfaces are present
in each cavity sub-unit and not in the root device.

To explain these cases the following pictures represents the hierarchical
structure of some oven:

- the simple device (just one cavity)
![Hae One Cavity Oven Structure][Hae One Cavity Oven Structure]

[Hae One Cavity Oven Structure]: hae_simple_oven_stucture.png
- the complex device (oven with two one cavities)

![Hae More Cavities Oven Structure][Hae More Cavities Oven Structure]

[Hae More Cavities Oven Structure]: hae_complex_oven_stucture.png

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is to be included in a higher level device which can provide
application layer security.    

### Properties

### CyclePhase

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                         		      |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of cycle phases of the oven appliance.
It is an enumeration field.
  * **0** --- **Boost**
  * **1** --- **Normal**
  * **2** --- **HeatAndHold**
  * **3** --- **PureMicrowave**
  * **4** --- **TimeEstension** 
  * **5** --- **ResidualHeat**

### InsertedFoodProbe

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of level of moisture. 
It is an enumeration field.
  * **0** --- **not inserted**
  * **1** --- **inserted**
  * **0xFF** --- **not supported**
  
### Methods

No methods are associated to this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [Oven interface](Oven-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)


