# org.alljoyn.SmartSpaces.Operation.DoorStatus version 1

## Theory of Operation


This interface provides the status of any object that can report a two state 
open/closed condition.  It can be a stand alone door or window, or a opening to
a larger device such as a refrigerator door.
The _producer_ has one or more doors and implements a separate interface for 
each door.  The _consumer_ is an application that is interested in the state of 
the door.  Possibly to provide an email or push notification to a consumer if a 
door is open at an unexpected time or for an excessive duration.  (The consumer 
notification portion of the use case is outside the scope of AllJoyn HAE).

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = true                                         |

### Properties

#### IsClosed

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

True indicates that device is closed, false indicates the door is open.  

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

* The XML definition of the [ClosedStatus interface](ClosedStatus-v1.xml)


