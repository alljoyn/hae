# org.alljoyn.Hae.UserInterfaceSettings.TemperatureDisplay version 1

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

#### DisplayTemperatureUnit

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

0 = Celsius
1 = Farenheit
2 = Kelvin

#### SupportedDisplayTemperatureUnitSettings

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | bytes[]                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

List of allowable settings.  If list is empty then the SetDisplayTemperatureUnit
method will never return success.

### Methods

#### SetDisplayTemperatureUnit(displayTemperatureUnit)

User by remote device to attempt to set the displayed temperature unit on the 
device.  SupportedDisplayTemperatureUnitSettings should be read first.

Input arguments:

* **displayTemperatureUnit** --- byte --- Desired units for displaying 
temperature in the device UI.

Errors raised by this method:

* org.alljoyn.Hae.UserInterfaceSettings.Error.NotAcceptableDueToInternalState 
--- Value is not acceptable due to internal state.  Caller should try again at a 
later time.  This potentially could be raised if local user was interacting with 
the UI.

* org.alljoyn.Hae.UserInterfaceSettings.InvalidValue --- Value is not supported.  
Caller should read SupportedDisplyTemperatureUnitSettings for acceptable values.

* org.alljoyn.Hae.UserInterfaceSettings.Error.RemoteControlDisabled --- 
remote control is disabled

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors


The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                                                  | Error message                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.UserInterfaceSettings.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.UserInterfaceSettings.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.UserInterfaceSettings.Error.RemoteControlDisabled           | Remote control is disabled |



## References

* [Namespace Theory of Operation](UserInterfaceSettingsTheoryOfOperation)

* The XML definition of the [TemperatureDisplay interface](TemperatureDisplay-v1.xml)
