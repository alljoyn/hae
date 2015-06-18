# org.alljoyn.Hae.Device.Oven version 1

## Theory of Operation

The Cooker-hood is a home appliance that usually hangs above the stove or cook-top and
it is used to removes airborne grease, combustion products, fumes, smoke, odors,
heat, and steam from the air by evacuation of the air and filtration.

The followings are minimum required shared interfaces for these appliances.
  * **org.alljoyn.Hae.FilterStatus** --- for monitoring the filter state
  * **org.alljoyn.Hae.WindStrength** --- for monitoring and controlling the fan

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is to be included in a higher level device which can provide
application layer security.    

### Properties

### HoodMode

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                         		      |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the working mode of hood. 
It is an enumeration field.
  * **0** --- **manual**
  * **1** --- **automatic**
  * **0xFF** --- **not supported**

### AirFlowExtractionMode

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the mode of air flow extraction. 
It is an enumeration field.
  * **0** --- **exhaust**
  * **1** --- **recirculation**
  * **0xFF** --- **not supported**

### NumberOfLight

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

It indicates the number of light spots which can be controlled individually. 

### LightLevels

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte[]                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the the dimming level for each light spot in percentage.

  
### Methods

### SetLightLevels (levels)

Methods used to set the dimming level of the light spots (see relative property).
Input arguments:

  * **levels** --- **byte[]** --- dimming levels percentages.

### Signals

No signals are emitted by this interface.

### Named Types

### Interface Errors

No error associated to this interface.

## Examples

No example associated to this interface.

## References

  * The XML definition of the [CookerHood interface](CookerHood-v1.xml)
  * The definition of the [FilterStatus interface](/org.alljoyn.Hae/FilterStatus-v1)
  * The definition of the [WindStrength interface](/org.alljoyn.Hae/WindStrength-v1)

