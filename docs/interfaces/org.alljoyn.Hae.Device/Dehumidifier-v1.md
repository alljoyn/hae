# org.alljoyn.Hae.Device.Dehumidifier version 1

## Theory of Operation

Dehumidifier is a home appliance used to reduces the level of humidity in the
air, usually for health or comfort reasons. This dehumidifier interface provides
capabilities to control and monitor dehumidifier specific functions and
resources. A controller can recognize this device as a dehumidifier if object
descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for dehumidifier.

  * **org.alljoyn.Hae.OperationalControl** --- for start/stop operation.
  * **org.alljoyn.Hae.TargetHumidity** --- for setting target humidity
  * **org.alljoyn.Hae.RepresentedHumidity** --- for display of current humidity

The following is an example of a shared interface expected to be commonly used
for an Dehumidifier with water tank.

  * **org.alljoyn.Hae.WaterLevel**

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
    every appliance supporting the Dehumidifier interface
  * 0x8000-0xFFFF --- **proprietary mode id** : the meaning depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists modes of **standard mode id**.

  * **0** --- **Auto** : The dehumidifier removes the humidity whenever current
    humidity is higher than target humidity. Then, it stops its operation if
    current humidity reaches target humidity. The wind strength as well as
    target humidity could be controlled.
  * **1** --- **Continuous** : The dehumidifier keeps removing the humidity
    regardless of target humidity. The wind strength could be controlled.
  * **2** --- **Fan Only** : The dehumidifier doesn't remove the humidity and
    just lets the fan run to clean the air. The wind strength could be
    controlled.

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

#### SetOperationalModeId (operationalModeId)

Set an operational mode id. An dehumidifier starts its operational mode
immediately after setting or changing its target operational mode id. If the
device receives an invalid operational mode id or can't accept a valid
operational mode id due to its internal state, then an appropriate error shall
be returned.

Input arguments:

  * **operationalModeId** --- uint16 --- an operational mode id to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value is invalid.
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is
    not acceptable due to internal state.
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- Remote control is
    disabled.

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get added information about the modes which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary modees supported by the appliance, so they can be available by the
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
  * **name** --- string --- name of the operational mode (e.g. "Auto", ...)
  * **description** --- string --- description of the operational mode, it can
    be empty string in case there is no description

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                  |
|--------------------------------------------------------------|------------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value is invalid.                              |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state. |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled.                    |
| org.alljoyn.Hae.Device.Error.NotSupported                    | The language specified is not supported.       |

## References

  * The XML definition of the [Dehumidifier interface](Dehumidifier-v1.xml)
  * The definition of the [TargetHumidity interface](/org.alljoyn.Hae/TargetHumidity-v1)
  * The definition of the [RepresentedHumidity interface](/org.alljoyn.Hae/RepresentedHumidity-v1)
  * The definition of the [RepresentedHumidityLevel interface](/org.alljoyn.Hae/RepresentedHumidityLevel-v1)
