# org.alljoyn.SmartSpaces.Operation.InsertionStatus version 1

## Theory of Operation

This interface provides the status of any object that can report a two state
"inserted"/"not inserted" condition.
It is used for some a components can work only if it is inserted or connected to
the hosting device: e.g. a Food Probe to be used with an oven.

## Specification

|            |                               |
| ---------- | ----------------------------- |
| Version    | 1                             |
| Annotation | org.alljoyn.Bus.Secure = true |

### Properties

#### IsInserted

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | boolean                                                 |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

True indicates that device is inserted, false indicates the it is not inserted.

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

  * The XML definition of the [InsertionStatus interface](InsertionStatus-v1.xml)
  * The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)


