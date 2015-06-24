# org.alljoyn.Hae.Device.Thermostat version 1

## Theory of Operation

Thermostat is a home appliance used to alter the air temperature to more
comfortable conditions. This thermostat interface provides capabilities to
control and monitor a thermostat specific functions and resources. A controller
can recognize this device as a thermostat if object descriptions of the About
announcement include this interface.

The followings are minimum required shared interfaces for thermostat.
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
  * 0x0000-0x7FFF --- **standard mode id** : the meaning is shared among
    every appliance supporting the Thermostat interface
  * 0x8000-0xFFFF --- **proprietary mode id** : the meaning depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists modes of device operation.

  * **0** --- **Cool** : Set the room temperature at your preference cooling
  comfort.
  * **1** --- **Heat** : Enable you to enjoy the warming effect at your
  preferred
    setting temperature.
  * **2** --- **Auto** : Change automatically the mode of operation by sensing
    the difference between the ambient room temperature and the target
    temperature.
  * **3** --- **FanOnly** : Fan only runs continuously without heating or
  cooling.
  * **4** --- **Circulation** : Fan runs randomly for a balance of energy
  savings and air circulation.

#### SupportedOperationalModeIds

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operational mode ids. After getting the list of supported
operational mode ids, a valid one should be chosen out of the list.

It lists the values of operational mode identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalModeId** can assume.

The elements of the array belongs to the **standard mode id** and
**proprietary mode id** ranges. In case there can be only element of one of the
range.
If the array is empty the appliance doesn't communicate the operational mode
identifier value information to the controller.

### Methods

#### SetOperationModeId (operationModeId)

Set an operation mode id. An thermostat starts its operation mode immediately
after setting or changing its target operation mode id. If the device receives
an invalid operation mode id or can’t accept a valid operation mode id due to
its internal state, then an appropriate error shall be returned.

Input arguments:

  * **operationModeId** --- uint16 --- an operation mode id to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value is invalid.
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state.
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- Remote control is
    disabled.

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get added information about the modes which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary modes supported by the appliance, so they can be available by the
remote controller.
In principle standard modes have standard names and descriptions which are
defined at specification level, anyway the method can give information.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **modesDescription** --- OperationalModeDescriptor[] --- the list of mode
    descriptions, they contain only **proprietary mode id**

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotSupported --- The language specified is not
    supported.


### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalModeDescriptor

This structure is used to give added information about a mode, using its
operational mode id as reference.

  * **modeId** --- uint16 --- operational mode id
  * **name** --- string --- name of the operational mode (e.g. "Heat", "Cool",
  ...)
  * **description** --- string --- description of the operational mode, it can
    be empty string in case there is no description

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value is invalid                              |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled.                   |
| org.alljoyn.Hae.Device.Error.NotSupported                    | The language specified is not supported.      |

## References

  * The XML definition of the [Thermostat interface](Thermostat-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)
