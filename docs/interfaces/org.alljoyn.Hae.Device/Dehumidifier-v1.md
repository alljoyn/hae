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


#### Defrosting
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Dehumidifier only can turn on/off defrosting according to its internal state.
Defrosting cannot be controlled by user remotely or locally. This information is
for monitoring. If defrosting is true, dehumidifier makes free of frost or ice.

  * **0** --- **Off** : turn off defrosting
  * **1** --- **On** : turn on defrosting
  * **0xFF** --- **Not Supported** : defrosting is not supported

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

  * org.alljoyn.Hae.Device.NotSupported --- Returend if there is no selectable
  operational mode id.
  * org.alljoyn.Hae.Device.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Returned if
  value is not acceptable due to internal state.
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- Returned if remote
  control is disabled.

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

  * org.alljoyn.Error.NotSupportedLanguage --- The language specified is not
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
| org.alljoyn.Error.LanguageNotSupported                       | The language specified is not supported.       |
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value is not valid.                            |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state. |
| org.alljoyn.Hae.Device.Error.NotSupported                    | Request is not supported.                      |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled.                    |

## References

  * The XML definition of the [Dehumidifier interface](Dehumidifier-v1.xml)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetHumidity interface](/org.alljoyn.Hae/TargetHumidity-v1)
  * The definition of the [RepresentedHumidity interface](/org.alljoyn.Hae/RepresentedHumidity-v1)
