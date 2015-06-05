# org.alljoyn.Hae.Device.AirConditioner version 1

## Theory of Operation

Air Conditioner is a home appliance used to alter the properties of air
(primarily temperature and humidity) to more comfortable conditions.
This air conditioner interface provides capabilities to control and monitor
an air conditioner specific functions and resources. A controller can recognize
this device as an air conditioner if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation
  * **org.alljoyn.Hae.TargetTemperature** --- for setting target temperature
  * **org.alljoyn.Hae.RepresentedTemperature** --- for display of current temperature
  * **org.alljoyn.Hae.WindStrength** --- for control of wind strength

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

  * **0** --- **Cool** : Set the room temperature at your preference cooling comfort.
  * **1** --- **Heat** : Enable you to enjoy the warming effect at your preferred
    setting temperature.
  * **2** --- **Dry** : Set the desired temperature and provide dehumidifying surroundings.
  * **3** --- **Fan Only** : Circulate the air without cooling or heating.
  * **4** --- **Auto** : Change automatically the mode of operation by sensing
    the difference between the ambient room temperature and the target temperature.
  * **5** --- **Economy** : Reduce electrical power consumption.

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

Set an operation mode. An air conditioner starts its operation mode immediately
after setting or changing its target operation mode. If the device receives
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

  * The XML definition of the [AirConditioner interface](org.alljoyn.Hae.Device.AirConditioner-v1.xml)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae.OperationalControl-v1.md)
  * The definition of the [TargetTemperature interface](org.alljoyn.Hae.TargetTemperature-v1.md)
  * The definition of the [RepresentedTemperature interface](org.alljoyn.Hae.RepresentedTemperature-v1.md)
  * The definition of the [WindStrength interface](org.alljoyn.Hae.WindStrength-v1.md)
