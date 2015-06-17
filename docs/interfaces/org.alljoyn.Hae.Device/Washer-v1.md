# org.alljoyn.Hae.Device.Washer version 1

## Theory of Operation

Washer is a home appliance used to wash laundry, such as clothing and sheets.
This interface provides capabilities to interact an specific functions and
resources of washers.

It belongs to "fabric care" area/cluster together with other appliances like
dryer, washing dryer. Those devices may share similar features.

The followings are minimum required shared interfaces for air conditioner.

  * **org.alljoyn.Hae.OperationalControl** --- for monitoring and controlling
  the appliance operational state

Some the Washers have also the capabilities

  * to monitor and control the time of operations
  * to communicate the status of the alerts

  * they send the current temperature
  * the the temperature can be set from remote
  * they communicate alerts

in those cases following shared interface are implemented:

  * **org.alljoyn.Hae.OperationalTime** --- for monitoring and controlling the
    appliance operational times
  * **org.alljoyn.Hae.Alerts** --- to communicate alerts

## Specification

|            |                                |
| ---------- | ------------------------------ |
| Version    | 1                              |
| Annotation | org.alljoyn.Bus.Secure = false |

This interface has no information that should be protected so does not require
security.

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

  * 0 --- **Unavailable** --- the phase value is not available or can not be
    sent remotely
  * 1 --- **Pre-washing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 2 --- **Washing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 3 --- **Rinsing** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 4 --- **Spinning** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 5 --- **Steam** --- see
    [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * 6 --- ~~**Drying**~~ ---
  * 7 --- ~~**Cooling**~~ ---
  * 8 --- ~~**AntiCreasing**~~ ---

~~Strikethrough~~ values are not used for Washers.

If the appliance doesn't implement the functionality of monitoring the phase,
this property is always 0.

#### OperationalCycleId

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | int16                                                   |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

It indicates the currently selected operational cycle identifier.

The property values are organized in two ranges

  * 0x0000-0x7FFF --- **standard cycle id** --- the meanings is shared among
    every appliance supporting the Washer interface
  * 0x8000-0xFFFF --- **proprietary cycle id** --- the meanings depends on
    manufacturer so different appliances can use the same values with different
    meanings

At the moment the list of **standard cycle ids** is still under discussion.

#### SupportedOperationalCycleIds

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | int16[]                                                  |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It lists the values of operational cycle identifiers which are supported by the
appliance. It is used to know in advance and which are the values that the
**OperationalCycleId** can assume.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges. In case there can be only element of one of the
range.
If the array is empty the appliance doesn't communicate the operational cycle
identifier value information to the controller.

#### SelectableOperationalCycleIds

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | int16[]                                                  |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

It lists the values of operational cycle identifiers of the appliances which can
be selected remotely. It is used to know in advance which are the values that
can be used to set from remote the **OperationalCycleId** property using the
**SetOperationalCycleId** method.

The elements of the array belongs to the **standard cycle id** and
**proprietary cycle id** ranges.
If the array is empty the operational cycle identifier of the appliance can not
be set from remote.

The elements **SelectableOperationalCycleIds** shall be a subset of the elements
of **SupportedOperationalCycleIds**.

#### MaxWaterTemperatureLevel

|            |                                                          |
| ---------- | -------------------------------------------------------- |
| Type       | byte                                                     |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Maximum value of water temperature level.

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
advance which are the values that can be used to set from remote the
**WaterTemperatureLevel** property using the **SetWaterTemperatureLevel**
method.

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
advance which are the values that can be used to set from remote the
**SpinSpeedLevel** property using the **SetSpinSpeedLevel** method.

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
are the values that can be used to set from remote the **SoilLevel** property
using the **SetSoilLevel** method.

If the array is empty the soil level can be only monitored.

The elements of the array shall be in ascending order and not bigger than 
**MaxSoilLevel**.

### Methods

#### SetOperationalCycleId (cycleId)

Set the value of operational cycle id.
If the controller tries to set value which is not supported (i.e. it is not in
the list of **SelectableOperationalCycleIds** property), then a "value not
supported" error should be returned.

Input arguments:

  * **cycleId** --- int16 --- the operational cycle id value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported.  
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetOperationalCyclesDescription (language) -> (cyclesDescription)

Get added information about the cycle which are supported by the appliance.
It is used to communicate to controller the names and descriptions of the
proprietary cycles supported by the appliance, so they can be available by the
remote controller.
In principle standard cycles have standards names and descriptions which are
defined at specification level, anyway the method can be give information 

Input arguments:

  * **language** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- OperationalCycleDescriptor[] --- the list of cycle
    descriptions, they contain only **proprietary cycle id**

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetWaterTemperatureLevel (level)

Set the value of water temperature level.
If the controller tries to set value which is not supported (i.e. it is not in
the list of **SelectableWaterTemperatureLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the water temperature level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported.  
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetWaterTemperatureLevelInfo (languageTag) -> (info)

Get added information about the water temperature levels in string format.
It is used to communicate to controller the strings associated to the water
temperature level supported values, so it can display them.

Input arguments:

  * **language** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- string[] --- the list of strings associated to the
    water temperature levels, each element of the array refers to the level
    expressed by its index; the array can be:
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
If the controller tries to set value which is not supported (i.e. it is not in
the list of **SelectableSpinSpeedLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the spin speed level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported.  
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetSpinSpeedLevelInfo (languageTag) -> (info)

Get added information about the spin speed levels in string format.
It is used to communicate to controller the strings associated to the spin speed
level supported values, so it can display them.

Input arguments:

  * **language** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- string[] --- the list of strings associated to the
    spin speed levels, each element of the array refers to the level expressed
    by its index; the array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxSpinSpeedLevel**
    examples of output are:
      1. "400 RPM", "1000 RPM", "12000 RPM"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

#### SetSoilLevel (level)

Set the value of soil level.
If the controller tries to set value which is not supported (i.e. it is not in
the list of **SelectableSoilLevels** property), then a "value not
supported" error should be returned.

Input arguments:

  * **level** --- byte --- the soil level value to be set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- value is not supported.  
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is
    not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is
    disabled

#### GetSoilLevelInfo (languageTag) -> (info)

Get added information about the soil levels in string format.
It is used to communicate to controller the strings associated to the soil
level supported values, so it can display them.

Input arguments:

  * **language** --- string --- language to be used in the output strings using
    IETF language tags specified by RFC 5646.

Output arguments:

  * **cyclesDescription** --- string[] --- the list of strings associated to the
    soil levels, each element of the array refers to the level expressed by its
    index; the array can be:
      * empty: there are no string to communicate
      * list a string for each element from 0 to **MaxSoilLevel**
    examples of output are:
      1. "dirty", "very dirty"

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.LanguageNotSupported --- the language specified
    is not supported

### Named Types

#### struct OperationalCycleDescriptor

This structure is used to give added information about a cycle, using its
operational cycle id as reference.

  * **cycleId** --- int16 --- operational cycle id
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

No example associated to this interface.

## References

  * The XML definition of the [Washer interface](Washer-v1.xml)
  * [Washer and Dryers Theory Of Operation](WasherAndDryerTheoryOfOperation)
  * The definition of the [OperationalControl interface](/org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [OperationalTime interface](/org.alljoyn.Hae/OperationalControl-v1)

