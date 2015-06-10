# org.alljoyn.Hae.Device.Dehumidifier version 1

## Theory of Operation

Dehumidifier is a home appliance used to reduces the level of humidity in the air,
usually for health or comfort reasons. This dehumidifier interface provides
capabilities to control and monitor dehumidifier specific functions and resources.
A controller can recognize this device as a dehumidifier if object descriptions
of the About announcement include this interface.

The followings are minimum required shared interfaces for dehumidifier.
  * **org.alljoyn.Hae.TargetHumidity** --- for setting target humidity
  * **org.alljoyn.Hae.RepresentedHumidity**
  or **org.alljoyn.Hae.RepresentedHumidityLevel** --- for display of current
  humidity or humidity level
  * **org.alljoyn.Hae.WindStrength** --- for setting wind strength

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
  * **0** --- **Auto** : The dehumidifier removes the humidity whenever current
  humidity is higher than target humidity. Then, it stops its operation if current
  humidity reaches target humidity. The wind strength as well as target humidity
  could be controlled.
  * **1** --- **Continuous** : The dehumidifier keeps removing the humidity
  regardless of target humidity. The wind strength could be controlled.
  * **2** --- **Fan Only** : The dehumidifier doesn't remove the humidity and
  just lets the fan run to clean the air. The wind strength could be controlled.

#### SupportedOperationModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operation modes. After getting the list of supported
operation modes, a valid one should be chosen out of the list.

#### Defrosting
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | boolean                                                        |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

If defrosting is true, dehumidifier makes free of frost or ice.

  * **true** --- **On**
  * **false** --- **Off**

### Methods

#### SetOperationMode (operationMode)

Set an operation mode. A dehumidifier starts its operation mode immediately after
setting or changing its target operation mode. If the device receives an invalid
operation mode or can’t accept a valid operation mode due to its internal state,
then an appropriate error shall be returned.

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
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The
table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [Dehumidifier interface](Dehumidifier-v1.xml)
  * The definition of the [TargetHumidity interface](/org.alljoyn.Hae/TargetHumidity-v1)
  * The definition of the [RepresentedHumidity interface](/org.alljoyn.Hae/RepresentedHumidity-v1)
  * The definition of the [RepresentedHumidityLevel interface](/org.alljoyn.Hae/RepresentedHumidityLevel-v1)
  * The definition of the [WindStrength interface](/org.alljoyn.Hae/WindStrength-v1)