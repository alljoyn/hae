# org.alljoyn.SmartSpaces.Environment.SoilLevel version 1

## Theory of Operation

This interface provides the capability to set a target level of soil in Clothes
Washers or Clothes Washer-Dryers.
The values are usually associated to descriptive labels.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The interface version.

#### MaxLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of soil level.

#### TargetLevel

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-write                                              |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Current value of soil level. The valid values are in the range from 0 (the
lowest one) to ***MaxLevel** (the highest one).

Errors raised when setting this property:

  * org.alljoyn.Error.InvalidValue --- if the level value is not one of the
    **SelectableLevels** list
  * org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- when the
    level value is not accepted by the _producer_, because it is in a state
    which doesn't allow the execution
  * org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- when the remote
    control is disabled

#### SelectableLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It lists the values of soil level which can be selected; it can be
different because of the appliance state (e.g. different selected operational
cycles can have a different list of selectable soil levels). It is used to know
in advance which are the values of **TargetLevel** property that can be set by
_consumer_.

If the array is empty the target soil level can be only monitored.

The elements of the array shall be in ascending order and not bigger than
**MaxLevel**.

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                     |
|---------------------------------------------------------------|---------------------------------------------------|
| org.alljoyn.Error.InvalidValue                                | Invalid value                                     |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                           |

## References

  * The XML definition of the [SoilLevel interface](SoilLevel-v1.xml)
  * The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)

  