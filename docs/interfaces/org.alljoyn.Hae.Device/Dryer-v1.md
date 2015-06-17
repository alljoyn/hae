# org.alljoyn.Hae.Device.Dryer version 1

## Theory of Operation

Dryer is a home appliance used to wash laundry, such as clothing and sheets.
This dryer interface provides capabilities to control and monitor dryer
specific functions and resources.
It belongs to "fabric care" area/cluster together with other appliances like
dryer, washing dryer. Those devices may share similar features.  

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.Hae.OperationaControl** --- for monitoring and controlling the appliance operation state
  * **org.alljoyn.Hae.OperationaControl** --- for monitoring and controlling the appliance operation time

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designCyclePhaseed to be included in a higher level device
which can provide application layer security.    

### Properties

### CyclePhase

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                         		      |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of cycle phases of appliance, belonging to Fabric Care 
Area/cluster.
It is an enumeration field.
  * **0** --- **Unavailable**
  * **1** --- **Pre-washing**
  * **2** --- **Washing**
  * **3** --- **Rinsing**
  * **4** --- **Spinning**
  * **5** --- **Steam**
  * **6** --- **Drying**
  * **7** --- **Cooling**
  * **8** --- **AntiCreasing**  

### Moisture

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of level of moisture. 
It is an enumeration field.
  * **0** --- **no humidity**
  * **1** --- **wet**
  * **2** --- **damp**
  * **3** --- **less**
  * **4** --- **normal**
  * **5** --- **more**
  * **6** --- **max**
  
### Methods

### Signals

No signals are emitted by this interface.

### Named Types

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [Dryer interface](Dryer-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalControl-v1)
