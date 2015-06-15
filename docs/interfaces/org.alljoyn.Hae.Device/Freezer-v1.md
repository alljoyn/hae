# org.alljoyn.Hae.Freezer version 1

## Theory of Operation

This information provides the Freezer appliance interface.
Freezer is a home appliance used to store food at temperatures which are a few
degrees below the freezing point of water (typically about -18 °C), so the food
itself is safe indefinitely.

The followings are minimum required shared interfaces for air conditioner.
  * **org.alljoyn.Hae.TargetTemperature** --- for setting target temperature
  * **org.alljoyn.Hae.RepresentedTemperature** --- for display of current temperature

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security.

### Properties

### SuperMode

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates if super mode is activated or not.
True means that the super mode is currently active.
Super mode is a way of working to speed up the process of freezing the food
(e.g. associated to huge quantity of food inserted in the freezer cavity).

### Methods

### SetSuperMode (boolean)

Methods used to enable or disable the SuperMode function (see relative property).
Input arguments:

  * **boolean** --- boolean value.
  	*	true to enable the SuperMode function,
  	*	false to disable the SuperMode function. 

If a _producer_ device can not execute the setting an appropriate error shall be
returned. The refusal of command execution may be associated to internal
operation state of appliance.

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable

### Signals

No signals are emitted by this interface.

### Named Types

No name types are associated with this interface.

### Interface Errors
The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |


## Examples

## Example_1
User wants to activate the super freezing mode while the appliance is working.
1. the _comsumer_ invokes the method with the input parameter set to "true";
  * the appliance accepts the setting; 
  * superMode propriety becomes "true" and it is emitted to remote;  

## Example_2
User wants to activate the super freezing mode while the appliance is off.
1. the _comsumer_ invokes the method with the input parameter set to "true";
  * the appliance does not accepts the setting; 
  * superMode propriety does not change its value;
  * error code is reported to remote: org.alljoyn.Hae.Error.NotAcceptableDueToInternalState    


## References

  * The XML definition of the [Freezer interface](Freezer-v1.xml)
  * The definition of the [TargetTemperature interface](/org.alljoyn.Hae/TargetTemperature-v1)
  * The definition of the [RepresentedTemperature interface](/org.alljoyn.Hae/RepresentedTemperature-v1)
