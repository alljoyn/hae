# org.alljoyn.Hae.Device.AirConditioner version 1

## Theory of Operation

Air Conditioner is a home appliance used to alter the properties of air
(primarily temperature and humidity) to more comfortable conditions.
This air conditioner interface provides capabilities to control and monitor
air conditioner specific functions and resources. A controller can recognize
this device as an air conditioner if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation
  * **org.alljoyn.Hae.TargetTemperature** --- for setting target temperature
  * **org.alljoyn.Hae.RepresentedTemperature** --- for display of current
  temperature

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

This interface has no critical information that should be protected, so does not
require security.

### Properties

#### OperationalModeId

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational mode identifier.

The property values are organized in two ranges

  * 0x0000-0x7FFF --- **standard mode id** --- the meanings are shared among
    every appliance supporting the AirConditioner interface
  * 0x8000-0xFFFF --- **proprietary mode id** --- the meanings depend on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists modes of **standard mode id**.

  * **0** --- **Cool** : Set the room temperature at your preference cooling
  comfort.
  * **1** --- **Heat** : Enable you to enjoy the warming effect at your
  preferred setting temperature.
  * **2** --- **Dry** : Provide dehumidifying surroundings commonly with setting
    the desired temperature.
  * **3** --- **Fan Only** : Circulate the air without cooling or heating.
  * **4** --- **Auto** : Change automatically the mode of operation by sensing
    the difference between the ambient room temperature and the target
    temperature.
  * **5** --- **Economy** : Reduce electrical power consumption.

#### SupportedOperationalModeIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

An array of supported operational modes. After getting the list of supported
operational modes, a valid one should be chosen out of the list.

It lists the values of operational mode identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalModeId** can assume.

The elements of the array belongs to the **standard mode id** and
**proprietary mode id** ranges. In case there can be only element of one of the
range.
If the array is empty the appliance doesn't communicate the operational mode
identifier value information to the controller.

#### SelectableOperationalModeIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It lists the values of operational mode identifiers of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalModeId** property using the
**SetOperationalModeId** method.

The elements of the array belongs to the **standard mode id** and
**proprietary mode id** ranges.
If the array is empty the operational mode identifier of the appliance can not
be set from remote.

The elements **SelectableOperationalModeIds** shall be a subset of the elements
of **SupportedOperationalModeIds**.


### Methods

#### SetOperationalModeId (operationalModeId)

Set an operational mode id. An air conditioner starts its operational mode immediately
after setting or changing its target operational mode. If the device receives
an invalid operational mode id or can’t accept a valid operational mode id due to
its internal state, then an appropriate error shall be returned.

Input arguments:

  * **operationalModeId** --- uint16 --- an operational mode id to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Returned if
  value is not acceptable due to internal state.
  * org.alljoyn.Hae.Device.NotSupported --- Returend if there is no selectable
  operational mode id.
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- Returned if remote
  control is disabled.

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get added information about the modes which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary modes supported by the appliance, so they can be available by the
remote controller.
In principle standard modes have standard names and descriptions which are
defined at specification level, anyway the method can be give information

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **modesDescription** --- OperationalModeDescriptor[] --- the list of mode
    descriptions, they contain only **proprietary mode id**

Errors raised by this method:

  * org.alljoyn.Hae.NotSupportedLanguage --- The language specified
    is not supported.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalModeDescriptor

This structure is used to give added information about a mode, using its
operational mode id as reference.

  * **modeId** --- uint16 --- operational mode id
  * **name** --- string --- name of the operational mode (e.g. "Cool", "Heat", ...)
  * **description** --- string --- description of the operational mode, it can
  be empty string in case there is no description


### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                  |
|--------------------------------------------------------------|------------------------------------------------|
| org.alljoyn.Error.LanguageNotSupported                       | The language specified is not supported.       |
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value is not valid.                            |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state. |
| org.alljoyn.Hae.Device.Error.NotSupported                    | Request is not supported.                      |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled.                    |

## References

  * The XML definition of the [AirConditioner interface](AirConditioner-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)
