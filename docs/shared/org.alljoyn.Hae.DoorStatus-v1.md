# org.alljoyn.Hae.DoorStatus version 1

## Theory of Operation


This interface provides the status of a door.  It is intended to be part of a 
larger object that might have multiple doors.  The _producter_ has a door one 
or more doors and implements a separate interface for each door.  The _consumer_
is an application tht is interested in the state of the door.  Possibly to 
provide a notification if a door is open at an unexpected time or for an 
excessive duration.

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security for doors that have a high security value.



### Properties

#### DoorClosedState

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | b - Boolean                                                           |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

True indicates that door is open, false indicates the door is closed.  

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

* The XML definition of the [DoorStatus interface](org.alljoyn.Hae.DoorStatus-v1.xml)


