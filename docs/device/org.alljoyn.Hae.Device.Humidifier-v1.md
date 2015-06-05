# org.alljoyn.Hae.Device.Humidifier version 1

## Theory of Operation

Humidifier is a home appliance used to increase humidity (moisture) in a single
room or an entire building. This humidifier interface provides capabilities to
control and monitor humidifier specific functions and resources. A controller
can recognize this device as a humidifier if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for humidifier.
  * **org.alljoyn.Hae.TargetHumidity** --- for setting target humidity
  * **org.alljoyn.Hae.RepresentedHumidity**
    or **org.alljoyn.Hae.RepresentedHumidityLevel** --- for display of current
    humidity or humidity level

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### OperationMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists modes of device operation.

  * **0** --- **Auto** : Control amount of moisture automatically.
  * **1** --- **Low** : Spread low rate of moisture continuously.
  * **2** --- **Mid** : Spread middle rate of moisture continuously.
  * **3** --- **High** : Spread high rate of moisture continuously.

#### SupportedOperationModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operation modes. After getting the list of supported
operation modes, a valid one should be chosen out of the list.

### Methods

#### SetOperationMode (operationMode)

Set an operation mode. A humidifier starts its operation mode immediately after
setting or changing its target operation mode. If the device receives
an invalid operation mode or can’t accept a valid operation mode due to its
internal state, then an appropriate error shall be returned.

Input arguments:

  * **operationMode** --- byte --- an operation mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [Humidifier interface](org.alljoyn.Hae.Device.Humidifier-v1.xml)
  * The definition of the [TargetHumidity interface](org.alljoyn.Hae.TargetHumidity-v1.md)
  * The definition of the [RepresentedHumidity interface](org.alljoyn.Hae.RepresentedHumidity-v1.md)
  * The definition of the [RepresentedHumidityLevel interface](org.alljoyn.Hae.RepresentedHumidityLevel-v1.md)
