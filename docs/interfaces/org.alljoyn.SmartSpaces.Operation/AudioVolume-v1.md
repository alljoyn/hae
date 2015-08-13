# org.alljoyn.SmartSpaces.Operation.AudioVolume version 1

## Theory of Operation
This interface provides capabilites to control and monitor volume.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

#### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Interface version

#### Volume

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Speaker volume index of the device. Minimum volume is always 0.

Errors raised when setting this property:

  * org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### StepValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Step value of volume control.

#### MaxVolume

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value allowed for Volume.

#### Mute

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Volume mute state. If mute value is changed, changing value of volume property
depends on device implementation.

The property data type is an enumeration and its allowed value are listed below:
  * 0x00 --- **Not mute** --- Volume not mute
  * 0x01 --- **Mute** --- Volume mute
  * 0xFF --- **Not supported** --- Volume mute is not supported by the specific
  appliance.

The controller shall not set 0xFF(not supported).
If the controller tries to set a value when the value is 0xFF,
org.alljoyn.Error.FeatureNotAvailable shall be returned.

Errors raised when setting this property:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
  operational mode id.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

### Methods

#### UpVolume ()

Up volume to the next available value.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### DownVolume ()

Down volume to the next available value.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.FeatureNotAvailable                         | Feature not supported                              |
| org.alljoyn.Error.InvalidValue                                | Invalid value                                      |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

## References

  * The XML definition of the [AudioVolume interface](AudioVolume-v1.xml)
