# org.alljoyn.SmartSpaces.Operation.HvacClimate version 1

## Theory of Operation

This interface controls the heating and cooling  of a  home appliance used to 
alter the properties of air(primarily temperature and humidity) to more 
comfortable conditions.
If the control is physically part of the device it is typically called an air 
conditioner or heater.  If the control is remote from the appliance it is 
typically called a thermostat.  A controller can recognize this device as an air 
conditioner or thermosta by the object descriptions of the About announcement 
include this interface.


## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### Version

|            |                                                         |
| ---------- | ------------------------------------------------------- |
| Type       | uint16                                                  |
| Access     | read-only                                               |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

The interface version.  This property should be const once that feature is 
implemented in core.

#### Mode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-write                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

It indicates the currently selected operational mode identifier.

The property values are organized in two ranges

  * 0x0000-0x7FFF --- **standard mode id** --- the meanings are shared among
    every appliance supporting the AirConditioner interface

The enumeration below lists modes of **standard mode id**.

  * **0** --- **Off** :  No heating or cooling activity.
  * **1** --- **Heat** : Enable you to enjoy the warming effect at your
    preferred setting temperature.
  * **2** --- **Cool** : Set the room temperature at your preference cooling
    comfort.
  * **3** --- **Auto** : Change automatically the mode of operation by sensing
    the difference between the ambient room temperature and the target
    temperature.
  * **4** -- **Auxilliary Heat** : Sometimes called Emergency Heat.  Heat pumps 
    loose their efficiciency when outdoor temperatures drop.  Used to bypass the 
    heat pump in cold weather
  * **5** --- **Target Dry** : Provide dehumidifying surroundings to a target 
    dryness.  Depending on construction may also provide cooling.  Cycles based 
    on target humidity instead of target temperature.
  * **6** --- **Continuous Dry** : Provide dehumidifying surroundings 
continuously while On.
  * **7** --- **FanOnly** : Fan only runs continuously without heating or
cooling.
  * **8** --- **Circulation** : Fan runs randomly for a balance of energy
savings and air circulation.
  


Errors raised by setting this property:

* org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- Returned
if value is not acceptable due to internal state.
* org.alljoyn.SmartSpaces.Operation.Error.RemoteControlDisabled --- Returned if 
remote control is disabled.




#### SupportedModes

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16[]                                                       |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true       |

An array of supported  modes. After getting the list of supported modes, a valid 
one should be chosen out of the list.  It lists the values that the **Mode** can 
assume.

The elements of the array belongs to the **standard mode id** and
**vendor-defined mode id** ranges. In case there can be only element of one
of the range. SupportedOperationalModeIds must have at least one item.

This property should be const once that feature is implemented in core.

#### Status

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

This indicates the current operating status.  For example if the AC is in cool 
mode set to 72F and the current room temperature is 68F the MODE = Cool and the 
STATUS = Idle.  The enumerated values:

* **0** --- **Idle**
* **1** --- **Heating**
* **2** --- **Cooling**
* **3** --- **Pending Heat** :   This feature is implemented in heat pump systems to
  protect the compressor.
* **4** --- **Pending Cool** :   Same as pending heat.
* **5** --- **Auxilliary Heat** : Sometimes called Emergency Heat.  May occur in 
  Heat or Auxilliary Heat mode. 


### Methods

No methods are implemented by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.InvalidValue                                | Value not supported                                       |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control is disabled                         |

## References

  * The XML definition of the [HvacClimate interface](HvacClimate-v1.xml)
