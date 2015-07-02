# org.alljoyn.Hae.MoistureOutputRate version 1

## Theory of Operation

This interface provides capabilities to control and monitor the moisture output
rate. Humidifier or air purifier can have this MoistureOutputRate interface to
adjust the moisture output rate for humidification.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### Level

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the current level of moisture output rate.
0 ~ MaxLevel:
  * **0** --- **the smallest level of moisture output rate **
  * **MaxLevel** --- **the largest level of moisture output rate **

For example, if there are 6 levels of moisture output rate then MaxLevel = 5,
and the levels will be {0, 1, 2, 3, 4, 5}.
If a device that includes on/off operations cannot control moisture output rate,
MaxLevel shall be 1. The levels will be {0, 1}.

#### MaxLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It indicates a maximum level of moisture output rate.

#### AutomaticMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

If AutomaticMode is on, the device decide the level of moisture output rate for
providing comfortable surroundings automatically. If AutomaticMode is off,
the device keeps the selected level of moisture output rate.

  * **0** --- **Off** : Automatic mode off
  * **1** --- **On** : Automatic mode on
  * **0xFF** --- **Not Supported** : Automatic mode not supported

### Methods

#### SetMoistureOutputRateLevel (level)

Set the level of moisture output rate.

Input arguments:

  * **level** --- byte --- the level of moisture output rate to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

#### GetMoistureOutputRateLevelInfo (languageTag) -> (moistureOutputRateLevelDescription)

Get added information about the level of moisture output rate which are
supported by the appliance.
It is used to communicate to controller the names and descriptions of levels
supported by the appliance, so they can be available by the remote controller.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **moistureOutputRateLevelDescription**
  --- MoistureOutputRateLevelDescriptor[] --- the list of moisture output rate

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotSupported --- the language specified is not
    supported

#### SetAutomaticMode (automaticMode)

Set the level of moisture output rate.

Input arguments:

  * **automaticMode** --- byte --- AutomaticMode property to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

### Signals

No signals are emitted by this interface.

### Named Types

#### struct MoistureOutputRateLevelDescriptor

This structure is used to give added information about a level of moisture
output rate, using the id of level as reference.

  * **levelId** --- int16 --- level id
  * **name** --- string --- name of level for moisture output rate (e.g. "low", 
    "mid" ...)
  * **description** --- string --- description of the level, it can be empty
    string in case there is no description

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.NotSupported                    | Mode is not supported by device               |

## References

  * The XML definition of the [MoistureOutputRate interface](MoistureOutputRate-v1.xml)



