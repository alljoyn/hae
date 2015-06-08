# org.alljoyn.Hae.UserInterfaceSettings version 1

## Theory of Operation


This interface provides access to the setting choices appliances often allow
consumers to select on the User Interface.  It is intended to be part of a 
larger object that has other features.  Typically implemented at the top of the
tree as part of the device opject.  It is expected tht most devices will only 
implement one of these interfaces.
The _producer_ has a user interface wishes to expose the settings to a remote 
object.  In order to minimize the number of interfaces, there will likely be
attributes that a device either does not have or does not epose.  These have a
special value of "Unavailable".  The producer also may choose to allow a remote
device to change the settings.  If so the supported settings attribute provides
a list of the possible changes.  If the supported settings array is empty then
the device either does not have the interface or does not allow remote changes.
The _consumer_ is an application that is interested in the user interface 
settings.  Use cases:  
Display temperature in the same units as on the device.
For example a consumert in the United States chooses to have thermostat display
in degrees Farenheit, but they cook with old family recipies and have the oven
set to deg Celcius.
Help the consumer set the language.
The device defaults to a Japanese user interface.  The UI has a change language
feature, but the consumer cannot find it.  The mobile application knows the 
consumers preference is Spanish. It can interrogate the device over AllJoyn,
determine if Spanish is supported, and offer a choice to the consumer to change
the language to one they can read,

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

#### DisplayTimeFormatUnit

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

#### SetDisplayTemperatureUnit(displayTemperatureUnit)

User by remote device to attempt to set the displayed temperatre unit on the 
device.  SupportedDisplayTemperatureUnitSettings should be read first.

Input arguments:

***displayTemperatureUnit** --- byte --- Desired units for displaying 
temperature in the device UI.

Errors raised by this method:

* org.alljoyn.Hae.TargetTemperature.Error.NotAcceptableDueToInternalState --- 
Value is not acceptable due to internal state.  Caller should try again later.
This potentially could be raised if local user was interacting with the UI.
* org.alljoyn.Hae.TargetTemperature.Error.InvalidSetting --- Value is not 
supported.  Caller should read SupportedDisplyTemperatureUnitSettings for 
acceptable values.

#### SetDisplayLanguage(displayLanguage)

User by remote device to attempt to set the displayed temperatre unti on the 
device.  SupportedDisplayLanguageSettings should be read first.

Input arguments:

***displayLanguage** --- string --- Desired language for displaying on the user
interface using IETF language tages specified by RFC 5646.

Errors raised by this method:

* org.alljoyn.Hae.TargetTemperature.Error.NotAcceptableDueToInternalState --- 
Value is not acceptable due to internal state.  Caller should try again later.
This potentially could be raised if local user was interacting with the UI.
* org.alljoyn.Hae.TargetTemperature.Error.InvalidSetting --- Value is not 
supported.  Caller should read SupportedDisplyTemperatureUnitSettings for 
acceptable values.

#### SetDisplayTimeFormat(displayTimeFormat)

User by remote device to attempt to set the displayed time format on the 
device.  SupportedDisplayTimeFormatSettings should be read first.

Input arguments:

***displayTimeFormat** --- byte --- Desired format for displaying time in the 
device UI.


Errors raised by this method:

* org.alljoyn.Hae.TargetTemperature.Error.NotAcceptableDueToInternalState --- 
Value is not acceptable due to internal state.  Caller should try again later.
This potentially could be raised if local user was interacting with the UI.
* org.alljoyn.Hae.TargetTemperature.Error.InvalidSetting --- Value is not 
supported.  Caller should read SupportedDisplyTemperatureUnitSettings for 
acceptable values.


### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

* The XML definition of the [UserInterfaceSettings interface](org.alljoyn.Hae.UserInterfaceSettings-v1.xml)
