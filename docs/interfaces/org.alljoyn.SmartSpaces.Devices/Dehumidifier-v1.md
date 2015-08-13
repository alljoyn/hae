# org.alljoyn.SmartSpaces.Devices.Dehumidifier version 1

## Theory of Operation

Dehumidifier is a home appliance used to reduces the level of humidity in the
air, usually for health or comfort reasons. This dehumidifier interface provides
capabilities to control and monitor dehumidifier specific functions and
resources. A controller can recognize this device as a dehumidifier if object
descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for dehumidifier.

  * **org.alljoyn.SmartSpaces.Operation.Control** --- for start/stop operation.
  * **org.alljoyn.SmartSpaces.Environment.TargetHumidity** --- for setting
  target humidity
  * **org.alljoyn.SmartSpaces.Environment.CurrentHumidity** --- for display
  of current humidity

The following is an example of a shared interface expected to be commonly used
for an Dehumidifier with water tank.

  * **org.alljoyn.SmartSpaces.Environment.WaterLevel**

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
An dehumidifier starts its operational mode immediately
after setting or changing its target operational mode. If the
device receives an invalid operational mode or can't accept a valid
operational mode due to its internal state, then an appropriate error shall
be returned.

The property values are organized in two ranges

  * 0x0000-0x7FFF --- **standard mode** : the meaning is shared among
    every appliance supporting the Dehumidifier interface
  * 0x8000-0xFFFE --- **vendor-defined mode** : the meaning depends on
    manufacturer so different appliances can use the same values with different
    meanings

The enumeration below lists modes of **standard mode**.

  * **0** --- **Auto** : The dehumidifier removes the humidity whenever current
    humidity is higher than target humidity. Then, it stops its operation if
    current humidity reaches target humidity. The wind strength as well as
    target humidity could be controlled.
  * **1** --- **Continuous** : The dehumidifier keeps removing the humidity
    regardless of target humidity. The wind strength could be controlled.
  * **2** --- **Fan Only** : The dehumidifier doesn't remove the humidity and
    just lets the fan run to clean the air. The wind strength could be
    controlled.
  * **0x7FFF** --- **not supported"** : the reserved special value for
    "not supported". If there is no supported operational modes,
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

An array of supported operational modes. After getting the list of supported
operational modes, a valid one should be chosen out of the list.

It lists the values of operational modes which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalMode** can assume.

The elements of the array belongs to the **standard mode** and
**vendor-defined mode** ranges. If the array is empty, OperationalMode shall
be set to 0x7FFF for "not supported".

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

The elements of the array belongs to the **standard mode** and
**vendor-defined mode** ranges.
If the array is empty the operational mode of the appliance can not
be set from remote.

The elements **SelectableOperationalModes** shall be a subset of the elements
of **SupportedOperationalModes**.


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

#### GetOperationalModesDescription (languageTag) -> (modesDescription)

Get additional information about the modes which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
vendor-defined modees supported by the appliance, so they can be available by
the remote controller.
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

This structure is used to give additional information about a mode, using its
operational mode as reference.

  * **mode** --- uint16 --- operational mode
  * **name** --- string --- name of the operational mode (e.g. "Auto", ...)
  * **description** --- string --- description of the operational mode, it can
    be empty string in case there is no description

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

## References

  * The XML definition of the [Dehumidifier interface](Dehumidifier-v1.xml)
  * The definition of the [Operation Control interface](/org.alljoyn.SmartSpaces.Operation/Control-v1)
  * The definition of the [TargetHumidity interface](/org.alljoyn.SmartSpaces.Environment/TargetHumidity-v1)
  * The definition of the [CurrentHumidity interface](/org.alljoyn.SmartSpaces.Environment/CurrentHumidity-v1)
