# org.alljoyn.Hae.UserInterfaceSettings.LanguageDisplay version 1

## Theory of Operation

See [Namespace Theory of Operation](UserInterfaceSettingsTheoryOfOperation)

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has limited control properties and does not require security.  

### Properties

#### DisplayLanguage

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | string                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Currently displayed language on the user interface using IETF language tages
specified by RFC 5646.  

#### SupportedDisplayLanguageSettings

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | string[]                                                              |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

List of allowable settings.  If list is empty then the SetDisplayLanguage
method will never return success.


### Methods


#### SetDisplayLanguage(displayLanguage)

User by remote device to attempt to set the displayed language on the device.  
SupportedDisplayLanguageSettings should be read first.

Input arguments:

* **displayLanguage** --- string --- Desired language for displaying on the user
interface using IETF language tages specified by RFC 5646.

Errors raised by this method:

* org.alljoyn.Hae.UserInterfaceSettings.Error.NotAcceptableDueToInternalState 
--- Value is not acceptable due to internal state.  Caller should try again at a 
later time.  This potentially could be raised if local user was interacting with 
the UI.

* org.alljoyn.Hae.UserINterfaceSettings.Error.InvalidSetting --- Value is not 
supported.  Caller should read SupportedDisplayLanguageSettings for acceptable 
values.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The 
table below lists the possible errors raised by this interface.

| Error name                                                                  | Error message                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.UserInterfaceSettings.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.UserInterfaceSettings.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |



## References

* [Namespace Theory of Operation](UserInterfaceSettingsTheoryOfOperation)

* The XML definition of the [LanguangeDisplay interface](LanguageDisplay-v1.xml)
