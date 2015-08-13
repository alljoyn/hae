# org.alljoyn.SmartSpaces.Devices.AirConditioner version 1

## Theory of Operation

Air Conditioner is a home appliance used to alter the properties of air
(primarily temperature and humidity) to more comfortable conditions.
This air conditioner interface provides capabilities to control and monitor
air conditioner specific functions and resources.

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.SmartSpaces.Operation.Control** --- for control of operation
  * **org.alljoyn.SmartSpaces.Environment.TargetTemperature** --- for setting
  target temperature
  * **org.alljoyn.SmartSpaces.Evnironment.CurrentTemperature** --- for display
  of current temperature

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Interface version.

#### OperationalMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational mode.
An air conditioner starts its operational mode
immediately after setting or changing its target operational mode. If the
device receives an invalid operational mode or can’t accept a valid
operational mode due to its internal state, then an appropriate error
shall be returned.

The property values are organized in two ranges

  * 0x0000-0x7FFF --- **standard mode** --- the meanings are shared among
    every appliance supporting the AirConditioner interface
  * 0x8000-0xFFFE --- **vendor-defined mode** --- the meanings depend on
    manufacturer so different appliances can use the same values with different
    meanings
  * 0xFFFF --- **not supported** : the reserved special value for
    "not supported". If there is no supported operational modes,
    this value can be set as 0xFFFF.

The enumeration below lists modes of **standard mode**.

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

Errors raised when setting this property:

  * org.alljoyn.Error.FeatureNotAvailable --- Returend if there is no selectable
    operational mode.
  * org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
    if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
    control is disabled.

#### SupportedOperationalModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

An array of supported operational modes. After getting the list of supported
operational modes, a valid one should be chosen out of the list.

It lists the values of operational modes which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalMode** can assume.

The elements of the array belongs to the **standard mode** and
**vendor-defined mode** ranges. If the array is empty, OperationalMode shall
be set to 0xFFFF for "not supported".

#### SelectableOperationalModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It lists the values of operational modes of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalMode** property.

The elements of the array belongs to the **standard mode** and
**vendor-defined mode** ranges. If the array is empty the operational mode
of the appliance can not be set from remote.

The elements **SelectableOperationalModes** shall be a subset of the elements
of **SupportedOperationalModes**.

### Methods

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get additional information about the modes which are supported by the appliance.
It is used to communicate to the controller the names and descriptions of the
vendor-defined modes supported by the appliance, so they can be available by the
remote controller.
In principle standard modes have standard names and descriptions which are
defined at specification level.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **modesDescription** --- OperationalModeDescription[] --- the list of mode
    descriptions, they contain only **vendor-defined mode**

Errors raised by this method:

  * org.alljoyn.Error.LanguageNotSupported --- The language specified is not
    supported.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalModeDescription

This structure is used to give addtional information about a mode, using its
operational mode as reference.

  * **mode** --- uint16 --- operational mode
  * **name** --- string --- name of the operational mode (e.g. "Cool", "Heat", ...)
  * **description** --- string --- description of the operational mode, it can
    be empty string in case there is no description


### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.FeatureNotAvailable                         | Feature not supported                              |
| org.alljoyn.Error.InvalidValue                                | Invalid value                                      |
| org.alljoyn.Error.LanguageNotSupported                        | The language specified is not supported            |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

## References

  * The XML definition of the [AirConditioner interface](AirConditioner-v1.xml)
  * The definition of the [Operation Control interface](/org.alljoyn.SmartSpaces.Operation/Control-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.SmartSpaces.Environment/TargetTemperature-v1)
  * The definition of the [CurrentTemperature interface](/org.alljoyn.SmartSpaces.Environment/CurrentTemperature-v1)
