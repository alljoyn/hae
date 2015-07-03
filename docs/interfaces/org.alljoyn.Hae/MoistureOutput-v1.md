# org.alljoyn.Hae.MoistureOutput version 1

## Theory of Operation

This interface provides capabilities to control and monitor the moisture output
rate. Humidifier or air purifier can have this MoistureOutput interface to
adjust the moisture output rate for humidification.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### MoistureOutputRate

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the current level of moisture output rate.
0 ~ MaxMoistureOutputRate:
  * **0** --- **the smallest level of moisture output rate **
  * **MaxMoistureOutputRate** --- **the largest level of moisture output rate **

For example, if there are 6 levels of moisture output rate then 
MaxMoistureOutputRate = 5, and the levels will be {0, 1, 2, 3, 4, 5}.
If a device that includes on/off operations cannot control moisture output 
rate, MaxMoistureOutputRate shall be 1. The levels will be {0, 1}.

#### MaxMoistureOutputRate

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It indicates a maximum level of moisture output rate.

#### AutoMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

If AutoMode is on, the device decide the level of moisture output rate for
providing comfortable surroundings automatically. If AutoMode is off, the 
device keeps the selected level of moisture output rate.

  * **0** --- **Off** : Auto mode off
  * **1** --- **On** : Auto mode on
  * **0xFF** --- **Not Supported** : Auto mode not supported

### Methods

#### SetMoistureOutputRate (moistureOutputRate)

Set the level of moisture output rate.

Input arguments:

  * **moistureOutputRate** --- byte --- the level of moisture output rate to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

#### GetMoistureOutputRateDescription (languageTag) -> (moistureOutputRateDescription)

Get added information about the level of moisture output rate which are
supported by the appliance.
It is used to communicate to controller the names and descriptions of levels
supported by the appliance, so they can be available by the remote controller.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **moistureOutputRateDescription**
  --- MoistureOutputRateDescriptor[] --- the list of moisture output rate

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotSupported --- the language specified is not
    supported

#### EnableAutoMode (autoMode)

Enable/disable AutoMode. 

Input arguments:

  * **autoMode** --- byte --- AutoMode property to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state

### Signals

No signals are emitted by this interface.

### Named Types

#### struct MoistureOutputRateDescriptor

This structure is used to give added information about a level of 
MoistureOutputRate, using the id of MoistureOutputRate as reference.

  * **moistureOutputRateId** --- int16 --- MoistureOutputRate id
  * **name** --- string --- name of MoistureOutputRate (e.g. "low", "mid" ...)
  * **description** --- string --- description of MoistureOutputRate, it can be
    empty string in case there is no description

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

  * The XML definition of the [MoistureOutput interface](MoistureOutput-v1.xml)



