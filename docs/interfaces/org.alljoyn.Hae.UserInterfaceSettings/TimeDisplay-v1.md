# org.alljoyn.Hae.UserInterfaceSettings.TimeDisplay version 1

## Theory of Operation

See [Namespace Theory of Operation](UserInterfaceSettingsTheoryOfOperation)

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has limited control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer if required.

### Properties

#### DisplayTimeFormat

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

0 = "12 hour" format
1 = "24 hour" format

#### SupportedDisplayTimeFormatSettings

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte[]                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

List of allowable settings.  If list is empty then the SetDisplayTimeFormat
method will never return success.

### Methods

#### SetDisplayTimeFormat(displayTimeFormat)

User by remote device to attempt to set the displayed time format on the 
device.  SupportedDisplayTimeFormatSettings should be read first.

Input arguments:

* **displayTimeFormat** --- byte --- Desired format for displaying time in the 
device UI.


Errors raised by this method:

* org.alljoyn.Hae.UserInterfaceSettings.Error.NotAcceptableDueToInternalState 
--- Value is not acceptable due to internal state.  Caller should try again at a 
later time.  This potentially could be raised if local user was interacting with 
the UI.

* org.alljoyn.Hae.UserInterfaceSettings.Error.InvalidSetting --- Value is not 
supported.  Caller should read SupportedDisplyTimeSettings for acceptable values.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors


The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                                                            | Error message                                 |
|---------------------------------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.UserInterfaceTheoryOfOperations.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.UserInterfaceTheoryOfOperations.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |



## References

* [Namespace Theory of Operation](UserInterfaceSettingsTheoryOfOperation)

* The XML definition of the [TimeDisplay interface](TimeDisplay-v1.xml)
