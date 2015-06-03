# org.alljoyn.Hae.DoorStatus version 1

## Theory of Operation


This interface provides the status of a door.  It is intended to be part of a 
larger object that might have multiple doors.  Example a refrigerator 
compartment door or oven door.  
Some of these doors have locks during some
operational states.  Examples:  Washer Door in operation or an oven door
during self-clean.
It is not intended to represent an access door to a living space, gate, garage
door or similar barrier.  Those devices will have more elaborate interfaces and
security concerns.
The _producer_ has one or more doors and implements a separate interface for 
each door.  The _consumer_ is an application that is interested in the state of 
the door.  Possibly to provide an email or push notification to a consumer if a 
door is open at an unexpected time or for an excessive duration.  (The consumer 
notification portion of the use case is outside the scope of AllJoyn HAE).

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
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

True indicates that door is open, false indicates the door is closed.  

#### DoorLockedState

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

True indicates that door is locked, false indicates the door is unlocked.  

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


