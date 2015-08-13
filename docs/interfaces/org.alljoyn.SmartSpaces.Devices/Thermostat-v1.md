# org.alljoyn.SmartSpaces.Devices.Thermostat version 1

## Theory of Operation

Thermostat is a home appliance used to alter the air temperature to more
comfortable conditions. This thermostat interface provides capabilities to
control and monitor a thermostat specific functions and resources. A controller
can recognize this device as a thermostat if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for thermostat.
  * **org.alljoyn.SmartSpaces.Operation.Control** --- for control of
  operation
  * **org.alljoyn.SmartSpaces.Environment.TargetTemperature** --- for setting
  target temperature
  * **org.alljoyn.SmartSpaces.Environment.CurrentTemperature** --- for
  display of current temperature

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
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational mode.
An thermostat starts its operation mode immediately
after setting or changing its target operation mode id. If the device receives
an invalid operation mode id or can’t accept a valid operation mode id due to
its internal state, then an appropriate error shall be returned.

The property values are organized in two ranges
  * 0x0000-0x7FFF --- **standard mode id** : the meaning is shared among
    every appliance supporting the Thermostat interface
  * 0x8000-0xFFFF --- **vendor-defined mode id** : the meaning depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists modes of device operation.

  * **0** --- **Cool** : Set the room temperature at your preference cooling
  comfort.
  * **1** --- **Heat** : Enable you to enjoy the warming effect at your
  preferred setting temperature.
  * **2** --- **Auto** : Change automatically the mode of operation by sensing
    the difference between the ambient room temperature and the target
    temperature.
  * **3** --- **FanOnly** : Fan only runs continuously without heating or
  cooling.
  * **4** --- **Circulation** : Fan runs randomly for a balance of energy
  savings and air circulation.
  * **0x7FFF** --- **not supported** : the reserved special value for
    "not supported". If there is no supported operational mode ids,
    this value can be set as 0x7FFF.

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
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operational mode ids. After getting the list of supported
operational mode ids, a valid one should be chosen out of the list.

It lists the values of operational modes which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalMode** can assume.

The elements of the array belongs to the **standard mode id** and
**vendor-defined mode id** ranges. If the array is empty, OperationalMode
shall be set to 0x7FFF for "not supported".

#### SelectableOperationalModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It lists the values of operational modes of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalMode** property using the
**SetOperationalMode** method.

The elements of the array belongs to the **standard mode id** and
**vendor-defined mode id** ranges.
If the array is empty the operational mode of the appliance can not
be set from remote.

The elements **SelectableOperationalModes** shall be a subset of the elements
of **SupportedOperationalModes**.

### Methods

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get additional information about the modes which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
vendor-defined modes supported by the appliance, so they can be available by the
remote controller.
In principle standard modes have standard names and descriptions which are
defined at specification level, anyway the method can give information.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **modesDescription** --- OperationalModeDescriptor[] --- the list of mode
    descriptions, they contain only **vendor-defined mode id**

Errors raised by this method:

  * org.alljoyn.Error.LanguageNotSupported --- The language specified is not
    supported.


### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalModeDescriptor

This structure is used to give added information about a mode, using its
operational mode id as reference.

  * **mode** --- uint16 --- operational mode
  * **name** --- string --- name of the operational mode (e.g. "Heat", "Cool",
  ...)
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

  * The XML definition of the [Thermostat interface](Thermostat-v1.xml)
  * The definition of the [Operation Control interface](/org.alljoyn.SmartSpaces.Operation/Control-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.SmartSpaces.Environment/TargetTemperature-v1)
  * The definition of the [CurrentTemperature interface](/org.alljoyn.SmartSpaces.Environment/CurrentTemperature-v1)
