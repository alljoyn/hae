# org.alljoyn.SmartSpaces.Environment.MoistureOutput version 1

## Theory of Operation

This interface provides capabilities to control and monitor the moisture output
rate. Humidifier or air purifier can have this MoistureOutput interface to
adjust the moisture output rate for humidification. For example, if the device
has a capability to adjust qualitative rate of moisture output such like "Low",
"Med", "High" then this MoistureOutput interface can be used by the device.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### MoistureOutputRate

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the current rate of moisture output.
1 means the smallest rate of moisture output. MaxMoistureOutputRate means
the largest setting of moisture output rate.
MoistureOutputRate can be set 0 where the AutoMode is true and the device stops
the moisture output to provide users with comfortable surroundings.

Special reserved values listed below:
  * 0x00 --- **Off** --- Moisture output is turned off

For example, if there are 6 rates of moisture output then
MaxMoistureOutputRate = 5, and the rates will be {0, 1, 2, 3, 4, 5}.

#### MaxMoistureOutputRate

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

It indicates a maximum rate of moisture output.

#### AutoMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

If AutoMode is enabled, the device decides the moisture output rate for
providing comfortable surroundings automatically and the MoistureOutputRate
property shall be changed according to changing moisture output rate.
If AutoMode is disabled, the moisture output rate will remain at an appropriate
fixed moisture output rate determined by the device. (The fixed value of
moisture output rate can be a default value or the value when the AutoMode
is disabled. This operation of auto control moisture output rate depends on
the device manufacturer.)

The property data type is an enumeration and its allowed value are listed below:

  * **0x00** --- **Off** : Auto mode is disabled
  * **0x01** --- **On** : Auto mode is enalbed
  * **0xFF** --- **Not Supported** : Auto mode is not supported by specific
  appliance.

### Methods

#### SetMoistureOutputRate (moistureOutputRate)

Set the moisture output rate.

Input arguments:

  * **moistureOutputRate** --- byte --- Target moisture output rate

Errors raised by this method:

  * org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### GetMoistureOutputRateInfo (languageTag) -> (info)

Get added information about the moisture output rate which are supported by
the appliance. It is used to communicate to controller the names and
descriptions of rates supported by the appliance, so they can be available by
the remote controller.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **info** --- string[] --- the list of moisture output rate
     * empty: there are no string to communicate
     * list a string for each element from 0 to **MaxMoistureOutputRate**
     examples of output are: "low", "med", "high"

Errors raised by this method:

  * org.alljoyn.Error.LanguageNotSupported --- The language specified is not
    supported.

#### EnableAutoMode (autoMode)

Enable/disable auto control of moisture output rate.

Input arguments:

  * **autoMode** --- boolean --- Enable/Disable auto mode

Errors raised by this method:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
  operational mode id.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct MoistureOutputRateDescriptor

This structure is used to give added information about the MoistureOutputRate,
using the id of MoistureOutputRate as reference.

  * **moistureOutputRateId** --- int16 --- MoistureOutputRate id
  * **name** --- string --- name of MoistureOutputRate (e.g. "low", "med" ...)
  * **description** --- string --- description of MoistureOutputRate, it can be
    empty string in case there is no description

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.FeatureNotAvailable                         | Feature not supported                              |
| org.alljoyn.Error.InvalidValue                                | Invalid value                                      |
| org.alljoyn.Error.LanguageNotSupported                        | The language specified is not supported            |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

### References

  * The XML definition of the [MoistureOutput interface](MoistureOutput-v1.xml)
