# org.alljoyn.Hae.Refrigerator version 1

## Theory of Operation

This information provides the refrigerator appliance interface.
Refrigerator is a complex appliance, composed by other devices, that are 
Fridge(s), Freezer(s) and eventually other auxiliary compartment like 
Ice Maker(s).

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security for doors that have a high security value.

### Properties

No Properties are associated to this interface.
Proprietaries are specific of device(s) composing the Refrigerator
(i.e. Fridge,...)   

### Methods

No methods are associated to this interface.
Methods are specific of device(s) composing the Refrigerator (i.e. Fridge,...)   

### Signals

No signals are emitted by this interface.

### Named Types

No name types are associated with this interface.

### Interface Errors

No unique errors are associated with this interface.

## Examples

Example of the hierarchical structure of a refrigerator composed by a fridge,
a freezer and an ice-maker.

![Hae Refrigerator Structure][Hae Refrigerator Structure]

[Hae Refrigerator Structure]: hae_refrigerator_device_hierarchy.png


## References

  * no XML definition associated to this interface
  * The definition of the [Freezer interface](Freezer-v1)
  * The definition of the [Fridge interface](Fridge-v1)
  * The definition of the [IceMaker interface](IceMaker-v1)
