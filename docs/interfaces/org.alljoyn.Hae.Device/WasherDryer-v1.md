# org.alljoyn.Hae.Device.WasherDryer version 1

## Theory of Operation

Washer-Dryers is a home appliance used to wash and dry laundry in the same
cavity, such as clothing and sheets. It integrate functionalities of Washers and
Dryers.
This interface provides capabilities to control and monitor resources of
Washer-Dryers.

It belongs to "fabric care" area/cluster together with other appliances like
dryer, washing dryer. Those devices may share similar features.

The followings are minimum required shared interfaces for Washer-Dryers.

  * **org.alljoyn.Hae.OperationalControl** --- for monitoring and controlling
  the appliance operational state

Some Washer-Dryers have also capabilities allowing:

  * to monitor and control the time of operations
  * to communicate the status of the alerts

in those cases following shared interface are implemented:

  * **org.alljoyn.Hae.OperationalTime** --- for monitoring and controlling the
    appliance operational times
  * **org.alljoyn.Hae.Alerts** --- to communicate alerts

## Specification

|            |                                |
| ---------- | ------------------------------ |
| Version    | 1                              |
| Annotation | org.alljoyn.Bus.Secure = false |

This interface has no information that should be protected so it does not
require security.

### Properties

#### CyclePhase

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It indicates the current phase of the operational cycle.

The data type is an enumeration and its allowed values and descriptions are
listed below:

  * 0x00 --- **Unavailable** --- the phase value is not available (no phase is
    selected)
  * 0x01 --- **Pre-washing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x02 --- **Washing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x03 --- **Rinsing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x04 --- **Spinning** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x05 --- **Steam** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x06 --- **Drying** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x07 --- **Cooling** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x08 --- **AntiCreasing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 0x7F --- **Not Supported** --- the phase value is not communicated to
    _consumer_

If the appliance doesn't implement the functionality of monitoring the phase,
this property is always **Not Supported**.

#### OperationalCycleId

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | uint16                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It indicates the currently selected operational cycle identifier.

The property values are organized in two ranges:

  * 0x0000-0x7FFF --- **standard cycle id** --- the meanings is shared among
    every appliance supporting the Washer-Dryers interface
  * 0x8000-0xFFFF --- **proprietary cycle id** --- the meanings depends on
    manufacturer so different appliances can use the same values with different
    meanings

At the moment the list of **standard cycle ids** is still under discussion.

#### SupportedOperationalCycleIds

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | uint16[]                                                 |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It lists the values of operational cycle identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalCycleId** property can assume.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges. The list can be composed by:

  * both standard and proprietary cycle ids
  * only standard cycle ids
  * only proprietary cycle ids

If the array is empty the appliance doesn't communicate the operational cycle
identifier value information to the _consumer_.

#### SelectableOperationalCycleIds

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | uint16[]                                                 |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It lists the values of operational cycle identifiers of the appliances which can
be selected by the _consumer_. It is used to know in advance which are the
values that can be used to set the **OperationalCycleId** property using the
**SetOperationalCycleId** method.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges.
If the array is empty the operational cycle identifier of the appliance can not
be set by _consumer_.

The elements **SelectableOperationalCycleIds** shall be a subset of the elements
of **SupportedOperationalCycleIds**.

#### MaxWaterTemperatureLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of water temperature level.
If value is 0, **WaterTemnperatureLevel** is always 0 and it is meaningless (can
not be monitored by controller).

#### WaterTemperatureLevel

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Current value of water temperature level. The valid values are in the range from
0 (the lowest one) to **MaxWaterTemperatureLevel** (the highest one).

#### SelectableWaterTemperatureLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It lists the values of water temperature level which can be selected, each
selected operational cycle can have a different list. It is used to know in
advance which are the values of **WaterTemperatureLevel** property that can be
set by _consumer_ using the **SetWaterTemperatureLevel** method.

If the array is empty the water temperature level can be only monitored.

The elements of the array shall be in ascending and order not bigger than
**MaxWaterTemperatureLevel**.

#### MaxSpinSpeedLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of spin speed level.
If value is 0, **SpinSpeedLevel** is always 0 and it is meaningless (can not
be monitored by controller).

#### SpinSpeedLevel

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Current value of spin speed level. The valid values are in the range from 0 (the
lowest one) to **MaxSpinSpeedLevel** (the highest one).

#### SelectableSpinSpeedLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It lists the values of spin speed level which can be selected, each selected
operational cycle can have a different list. It is used to know in
advance which are the values that can be used to set the **SpinSpeedLevel**
property using the **SetSpinSpeedLevel** method.

If the array is empty the spin level level can be only monitored.

The elements of the array shall be in ascending order and not bigger than
**MaxWaterSpinSpeed**.

#### MaxSoilLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of soil level.
If value is 0, **SoilLevel** is always 0 and it is meaningless (can not
be monitored by controller).

#### SoilLevel

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Current value of soil level. The valid values are in the range from 0 (the
lowest one) to **MaxSoilLevel** (the highest one).

#### SelectableSoilLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It lists the values of soil level which can be selected, each selected
operational cycle can have a different list. It is used to know in advance which
are the values that can be used to set the **SoilLevel** property using the
**SetSoilLevel** method.

If the array is empty the soil level can be only monitored.

The elements of the array shall be in ascending order and not bigger than
**MaxSoilLevel**.

#### MaxHumidityLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of humidity level.
If value is 0, **HumidityLevel** is always 0 and it is meaningless (can not
be monitored by controller).

#### HumidityLevel

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte                                                    |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Current value of humidity level. The valid values are in the range from 0 (the
lowest one) to **MaxHumidityLevel** (the highest one).

#### SelectableHumidityLevels

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | byte[]                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It lists the values of humidity level which can be selected, each selected
operational cycle can have a different list. It is used to know in advance which
are the values that can be used to set the **HumidityLevel** property using the
**SetHumidityLevel** method.

If the array is empty the humidity level can be only monitored.

The elements of the array shall be in ascending order and not bigger than
**MaxHumidityLevel**.

### Methods

#### SetOperationalCycleId (cycleId)

Set the value of operational cycle id.
If the _consumer_ tries to set value which is not supported (i.e. it is not in
the list of **SelectableOperationalCycleIds** property), then a "value not
supported" error should be returned.

Input arguments:

  * **cycleId** --- int16 --- the operational cycle id value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetOperationalCyclesDescription (languageTag) -> (description)

Get information about the cycle which are supported by the appliance.
It is used to communicate to _consumer_ the names and descriptions of the
proprietary cycles supported by the appliance, so they can be available
remotely.
In principle standard cycles have standards names and descriptions (in English
language) which are defined at specification level and so this method returns
information only about operational cycles belonging to "proprietary" range
[0x8000 - 0xFFFF] of **OperationalCycleId** propriety.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **description** --- OperationalCycleDescriptor[] --- the list of cycle
    descriptions

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetWaterTemperatureLevel (level)

Set the value of water temperature level.
If the _consumer_ tries to set value which is not supported (i.e. it is not in
the list of **SelectableWaterTemperatureLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the water temperature level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetWaterTemperatureLevelInfo (languageTag) -> (info)

Get information about the water temperature levels in string format.
It is used to communicate to _consumer_ the strings associated to the water
temperature level supported values, so it can display them.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **info** --- string[] --- the list of strings associated to the water
    temperature levels, each element of the array refers to the level expressed
    by its index; the array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxWaterTemperatureLevel**
    examples of output are:
      1. "cold", "warm", "hot", "very hot"
      2.  "30 °C", "60 °C", "70 °C" ,"90 °C"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetSpinSpeedLevel (level)

Set the value of spin speed level.
If the _consumer_ tries to set value which is not supported (i.e. it is not in
the list of **SelectableSpinSpeedLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the spin speed level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetSpinSpeedLevelInfo (languageTag) -> (info)

Get information about the spin speed levels in string format.
It is used to communicate to _consumer_ the strings associated to the spin speed
level supported values, so it can display them.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
  using IETF language tags specified by RFC 5646.

Output arguments:

  * **info** --- string[] --- the list of strings associated to the spin speed
    levels, each element of the array refers to the level expressed by its
    index; the array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxSpinSpeedLevel**
    examples of output are:
      1. "400 RPM", "1000 RPM", "12000 RPM"
      2. "no - spin", "low", "medium", "max"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetSoilLevel (level)

Set the value of soil level.
If the _consumer_ tries to set value which is not supported (i.e. it is not in
the list of **SelectableSoilLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the soil level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetSoilLevelInfo (languageTag) -> (info)

Get added information about the soil levels in string format.
It is used to communicate to _consumer_ the strings associated to the soil level
supported values, so it can display them.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **info** --- string[] --- the list of strings associated to the soil levels,
    each element of the array refers to the level expressed by its index; the
    array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxSoilLevel**
    examples of output are:
      1. "dirty", "very dirty"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetHumidityLevel (level)

Set the value of humidity level.
If the _consumer_ tries to set value which is not supported (i.e. it is not in
the list of **SelectableHumidityLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the humidity level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetHumidityLevelInfo (languageTag) -> (info)

Get added information about the humidity levels in string format.
It is used to communicate to _consumer_ the strings associated to the humidity
level supported values, so it can display them.

Input arguments:

  * **languageTag** --- string --- language to be used in the output strings
    using IETF language tags specified by RFC 5646.

Output arguments:

  * **info** --- string[] --- the list of strings associated to the humidity
    levels, each element of the array refers to the level expressed by its
    index; the array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxHumidityLevel**
    examples of output are:
      1. "wet", "damp", "dry"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

### Signals

No signals are emitted by this interface.

### Named Types

#### struct OperationalCycleDescriptor

This structure is used to give added information about a cycle, using its
operational cycle id as reference.

  * **cycleId** --- uint16 --- operational cycle id
  * **name** --- string --- name of the operational cycle (e.g. "Cottons", ...)
  * **description** --- string --- description of the operational cycle, it can
  be empty string in case there is no description

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

|                          Error name                          |                     Error                     |
| ------------------------------------------------------------ | --------------------------------------------- |
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value is not supported                        |
| org.alljoyn.Hae.Device.Error.LanguageNotSupported            | Language specified is not supported           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled                    |

## Examples

Refer the analog paragraphs of Washer or Dryer interfaces the see an example
about exchanged messages between _producer_ and _consumer_ to select from
remote:
  * the operational cycle
  * the water level option

## References

  * The XML definition of the [WasherDryer interface](WasherDryer-v1.xml)
  * [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalTime-v1)
  * The definition of the [Washer interface](Washer-v1)
  * The definition of the [Washer interface](Dryers-v1)
