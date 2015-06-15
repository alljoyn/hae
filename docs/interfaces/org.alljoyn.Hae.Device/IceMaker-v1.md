# org.alljoyn.Hae.IceMaker version 1

## Theory of Operation

This information provides the way of working of the Ice Maker.
Ice maker typically is an auxiliary device, that belongs to an appliance like a
Refrigerator, together with other devices like Fridge, Freezer.  

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security for doors that have a high security value.

### Properties

#### IceMakerMode 

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | IceMakerMode                                                          |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It is an enumeration field describing the possible modes of operation of the
Ice Maker appliance. 

#### SupportedIceMakerMode 
|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | IceMakerMode[]                                                        |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

The list of supported IceMakerMode values.

### Methods

No methods are associated to this interface.

### Signals

No signals are emitted by this interface.

### Named Types

### IceMakerMode

IceMakerMode enumeration description:
  * 0 --- dispense water --- 
    * no ice: the Ice maker dispenses water
  * 1 --- cube ice --- 
    * cube ice is produced,
  * 2 --- dropping cube ice ---  
    * cube ice is dropping from Ice Maker
  * 4 --- crush ice ---  
    * crush ice is produced
  * 5 --- dropping crush ice ---    
    * crush ice is dropping from Ice Maker
  * 7 --- fast dropping cube ice ---    
    * crush ice is fast dropping from Ice Maker

### Interface Errors

No unique errors are associated with this interface.

## Examples

No examples are associated with this interface.

## References

  * The XML definition of the [IceMaker interface](IceMaker-v1.xml)




