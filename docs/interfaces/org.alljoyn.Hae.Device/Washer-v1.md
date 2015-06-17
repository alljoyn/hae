# org.alljoyn.Hae.Device.Washer version 1

## Theory of Operation

Washer is a home appliance used to wash laundry, such as clothing and sheets.
This washer interface provides capabilities to control and monitor washer
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
The interface is designed to be included in a higher level device which can
provide application layer security.    

### Properties

### CyclePhase

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
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

### WaterTemperatureLevel

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | WaterTemperatureLevelType                                             |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It represents the water temperature, in a "qualitative way" (enumeration of 
level of temperature) or in a numerical way (Celsius degree). 
It is a structured data type.

### SpinSpeedLevel

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | SpinSpeedLevelType                                                    |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It represents the spin speed level, in a "qualitative way" (enumeration of 
level of speed) or in a numerical way (RPM: Revolutions per minute). 
It is a structured data type.

### Methods

### Signals

No signals are emitted by this interface.

### Named Types

#### struct WaterTemperatureLevelType

WaterTemperatureLevelType structure

  * **Representation** --- byte --- enumeration field
  * **WaterTemperatureLevelValue** --- byte --- value depends on representation field

representation enumeration field and description:
  * 0 --- qualitative --- the water temperature is represented in a qualitative way
  * 1 --- numerical --- the water temperature is represented in Celsius degree     

TemperatureLevelValue depends on the Representation filed.
If Representation field is 0 (qualitative) it is an enumeration:
  * **0** --- **sanity**            
  * **1** --- **hot**            
  * **2** --- **eco_hot**        
  * **3** --- **warm**        
  * **4** --- **eco_warm**         
  * **5** --- **cold**      
  * **6** --- **eco_cold**       
  * **7** --- **tap_cold**        
If Representation field is 1 (numerical) the value is in Celsius degree 
(e.g 90 is 90 Celsius degree).

#### struct SpinSpeedLevelType

SpinSpeedLevelType structure

  * **Representation** --- byte --- enumeration field
  * **SpinSpeedLevelValue** --- uint16 --- value depends on representation field

representation enumeration field and description:
  * 0 --- qualitative --- the spin speed is represented in a qualitative way
  * 1 --- numerical --- the spin speed is represented in RPM     

SpinSpeedLevelvalue depends on the Representation filed.
If Representation field is 0 (qualitative) it is an enumeration:
  * **0** --- **no spin**        
  * **1** --- **min**       
  * **2** --- **low**  
  * **3** --- **medium**    
  * **4** --- **med-low**         
  * **5** --- **high**       
  * **6** --- **med-high**       
  * **7** --- **max**          
If Representation field is 1 (numerical) the value is in RPM (e.g. 1200 is 1200
RPM).


### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [Washer interface](Washer-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalControl-v1)
