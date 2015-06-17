# org.alljoyn.Hae.Device.DishWasher version 1

## Theory of Operation

DishWasher is an home appliance used to clean dishes and eating utensils.
This interface provides capabilities to control and monitor dish washer
specific functions and resources.

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.Hae.OperationaControl** --- for monitoring and controlling the appliance operation state
  * **org.alljoyn.Hae.OperationaControl** --- for monitoring and controlling the appliance operation time


## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security that have a high security value.    

### Properties

### CyclePhase

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the list of cycle phases of appliance.
It is an enumeration field.
  * **0** --- **Prewash**
  * **1** --- **Wash**
  * **2** --- **Rinse**
  * **3** --- **Dry**

### Methods

### Signals

No signals are emitted by this interface.

### Named Types

No data types associated to this interface.

### Interface Errors

No error associated to this interface.

## Examples

No examples associated to this interface.

## References

  * The XML definition of the [DishWasher interface](DishWasher-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalControl-v1)
