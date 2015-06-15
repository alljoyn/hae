# org.alljoyn.Hae.Device.Fridge version 1

## Theory of Operation

Fridge is a home appliance used to store food at temperatures which are a few
degrees above the freezing point of water.
This interface provides capabilities to interact an specific functions and
resources of fridges.

The minimum required shared interface for the Fridge is:

  * **org.alljoyn.Hae.DoorStatus** --- to monitor the opening status of the fridge door

Some Fridges have the capability to be monitored and in case controlled by a
remote controller, in this case the following shared interface is implemented:

  * **org.alljoyn.Hae.OperationalControl** --- to monitor and control

The operational states that the Fridge supports to be monitored are:

  * **0** --- **Off**
  * **2** --- **Working**

If the Fridge can only be monitored it doesn't support any operational commands
(empty array).

If it can be also controlled from remote, the operational commands that it
supports are:

  * **0** --- **Off**
  * **1** --- **On**

Moreover some Fridges have one or more of the following features:

  * they send the current temperature
  * the the temperature can be set from remote
  * they communicate alerts

in those cases following shared interface are implemented:

  * **org.alljoyn.Hae.RepresentedTemperature** --- to send the temperature
  * **org.alljoyn.Hae.TargetTemperature** --- to send the temperature from remote
  * **org.alljoyn.Hae.Alerts** --- to communicate alerts

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no information that should be protected so does not require
security.

### Properties

#### RapidCooling

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The "Rapid Cooling" mode is a way of working of the fridge which speed up the
process of cooling the food by activating at maximum the reducing temperature
functionality of the appliance; it is selected by the user, usually when a big
quantity of food is inserted in the fridge cavity at the same time.
Sometimes it is called in different way like "Super", "Turbo" or "Fast" ...

The property data type is an enumeration and its allowed value are listed below:

  * 0x00 --- **Off** --- Rapid Cooling is disabled
  * 0x01 --- **On** --- Rapid Cooling is enabled
  * 0xFF --- **Not Supported** --- Rapid Cooling is not supported by the
  specific appliance

### Methods

#### SetRapidCoolingMode (mode)

Methods used to enable or disable the Rapid Cooling mode (see relative
RapidCooling property).

Input arguments:

  * **mode** --- byte --- the value to be set: 0x00 to disable, 0x01 to enable

If the device can not execute the setting, an appropriate error shall be
returned. The refusal of command execution may be associated to internal
operation state of appliance or to the fact that remote control feature is
disabled.

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- value is not acceptable
  * org.alljoyn.Hae.Device.Error.RemoteControlDisabled --- remote control is disabled

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is disabled                    |

## Examples

### Example 1

User wants to activate the "Rapid Cooling" mode in a Fridge that support this
feature while the appliance is working.

  * the controller invokes the method with the input parameter set to **0x01**, when **RapidCooling** propriety is equal to **0x00**
  * the appliance accepts the setting
  * **RapidCooling** propriety value turn to **0x01** and it is emitted to remote

### Example 2

User wants to activate the "Rapid Cooling" mode in a Fridge while the appliance
is off.

  * the controller invokes the method with the input parameter set to **0x01**
  * the appliance does not accepts the setting, so **RapidCooling** propriety does not change its value
  * error code is reported to remote using **org.alljoyn.Hae.Error.NotAcceptableDueToInternalState**

## References

  * The XML definition of the [Fridge interface](Fridge-v1.xml)
  * The definition of the [DoorStatus interface](org.alljoyn.Hae/DoorStatus-v1)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae/OperationalControl-v1)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)
  * The definition of the [Alerts interface](org.alljoyn.Hae/Alerts-v1)
