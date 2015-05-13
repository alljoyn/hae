# org.alljoyn.Hae.OperationalTime version 1

## Specification

|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### TargetTimeToStart

|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Relative target time to start the operation, expressed in seconds.

#### TargetTimeToStop

|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Relative target time to stop the operation, expressed in seconds.

#### EstimatedTimeToEnd

|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Estimated relative time to the end of operation, expressed in seconds.
It is calculated at runtime by device itself; at the begin of operation it should be equal to TargetTimeToStop propriety, 
but then it can be recalculated and differentiate because of environmental conditions. (e.g. in a Washing Machine the real duration depends on water temperature, load ... so the duration showed at selection is just a forecast).

#### TargetDuration

|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Target duration of the operation as per user selection, expressed in seconds.

### Methods

#### SetTargetTimeToStart (i)

This method allows to set the relative time/delay to start the operation. It is written when a user wants that a device operation/cycle starts at a defined time.

  * **i** --- int32 --- Target time to start

Errors raised by this method:

  * org.alljoyn.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### SetTargetTimeToStop (i)

This method allows to set the relative time to stop the operation. It is written when a user wants that a device cycle (i.e. a time limited operation) stops at a defined time.

  * **i** --- int32 --- Target time to stop

Errors raised by this method:

  * org.alljoyn.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

### Signals

No signals are emitted by this interface.

### Interface Errors

[Delete this section if not applicable.]

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                        | Error message                                 |
|---------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |


## References

In this section, list references for the Interface definition (standards, RFCs,
related interfaces, etc.). Make sure to include at least the following
references:

  * The XML definition of the [OperationalTime interface](OperationalTime-v1.xml)
  * t.b.d.: the formal XML definition of the Interface described in this document
  * t.b.d.: the Theory of Operation document, if you decided to split it off
  * t.b.d.: the interface definition document for related interfaces (especially those
    that are described in the same Theory of Operation document)

