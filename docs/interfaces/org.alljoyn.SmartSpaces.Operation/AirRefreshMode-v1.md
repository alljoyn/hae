# org.alljoyn.SmartSpaces.Operation.AirRefreshMode version 1

## Theory of Operation

The interface is used to control air recirculation in a ventillation product.


## Specification

|            |                               |
| ---------- | ----------------------------- |
| Version    | 1                             |
| Annotation | org.alljoyn.Bus.Secure = true |

### Properties

#### Version

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | uint16                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The interface version.  This property should be const once that feature is 
implemented in core.

### Mode

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It indicates the mode of air flow extraction.

The data type is an enumeration and its allowed values and descriptions are
listed below:

  * 0x00 --- **exhaust** --- the device removes air from the premises through a
    pipe to the outside
  * 0x01 --- **recirculation** ---  the device recycles the air back into the
    premises.

Errors raised by setting this property:

* org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- Returned
if value is not acceptable due to internal state.
* org.alljoyn.SmartSpaces.Operation.Error.RemoteControlDisabled --- Returned if 
remote control is disabled.

#### SupportedModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true       |

An array of supported  modes. After getting the list of supported modes, a valid 
one should be chosen out of the list.  It lists the values that the **Mode** can 
assume.

This property should be const once that feature is implemented in core.

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.InvalidValue                                | Value not supported                                       |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control is disabled                         |

## Examples

No example associated to this interface.

## References

  * The XML definition of the [AirRefreshMode interface](AirRefreshMode-v1.xml)
  * The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)

