# org.alljoyn.SmartSpaces.Environment.TargetTemperature version 1

## Theory of Operation
This interface is for setting target temperature of the HAE devices such as air
conditioner, refrigerator, oven, etc. The temperature is expressed in degrees 
celsius.
While a device can store a number of temeratures in memory for storing or 
cooking different foods or for climate settings at different times of day or
days of the week, this interface only exposes the temperature the appliance is
actively using to maintain a TargetTemperature.

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

The interface version.The EmitsChangedSignal value of this property can be 
updated to "const" once that feature is available in Core.

#### TargetTemperatureCooling
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | SetPoint                                                       |
| Access     | read                                                           |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The seting that the device is attempting to maintain the temperature below.  A 
traditional thermostat would call this a "COOL" setpoint.  This property is not 
intended to reflect any hysteresis.
A device like an Oven, which can never have a valid setting here shall return an
org.alljoyn.Error.FeatureNotAvailable error.
A thermostat in heat mode, a turned off refrigerator, or an air-conditioner
in a dehumidifier mode shall return an
org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState error.

Errors raised when reading this property:

* org.alljoyn.Error.FeatureNotImplemented --- Returned if there is never a TargetTemperatureCooling
* org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
if there is not currently a TargetTemperatureCooling
\
#### TargetTemperatureHeating
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | SetPoint                                                       |
| Access     | read                                                           |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |


The seting that the device is attempting to maintain the temperature above.  A 
traditional thermostat would call this a "HEAT" setpoint.  This property is not 
intended to reflect any hysteresis.
A device like an refrigerator, which can never have a valid setting here shall 
return an org.alljoyn.Error.FeatureNotAvailable error.
A thermostat in cool mode or a turned off oven shall return an
org.allyoyn.SmartSpaces.Error.NotAcceptableDueToInternalState error. 

Errors raised when reading this property:

* org.alljoyn.Error.FeatureNotImplemented --- Returned if there is never a TargetTemperatureHeating
* org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
if there is not currently a TargetTemperatureHeating


### Methods

#### SetTargetTemperatureCooling(degC)

Used to set target temperature for cooling.

Input arguments:

* **degC**  ---double --- Temperature to set

If the controller tries to set a target value which is out of range, the value 
shall be then set to the limit of the range.  
If the controller tries to set a target value which doesn't match with the 
granularity of the current step, the device shall round TargetValue using a
device specific algorithm.

Errors raised by this method:
* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- when the
target temperature cannot be set.
* org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- when the remote
control is disabled. See the RemoteControllability property in the 
[RemoteControllability interface](RemoteControllability-v1) for further information.

#### SetTargetTemperatureHeating(degC)

Used to set target temperature for heating.

Input arguments:

* **degC**  ---double --- Temperature to set

If the controller tries to set a target value which is out of range, the value 
shall be then set to the limit of the range.  
If the controller tries to set a target value which doesn't match with the 
granularity of the current step, the device shall round TargetValue using a
device specific algorithm.

Errors raised by this method:
* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- when the
target temperature cannot be set.
* org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- when the remote
control is disabled. See the RemoteControllability property in the 
[RemoteControllability interface](RemoteControllability-v1) for further information.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct SetPoint

* ** target ** -- double -- the set point temperature.
* ** min ** -- double -- a minimum value allowed for each set point temperature. 
* ** max ** -- double -- a maximum value allowed for each set point temperature. 
* ** step ** -- double -- a step value allowed for each set point temperature.
                        This shall be a non-negative value.

All values expressed in Celsius.  If there is no value available for any field 
it shall be set to 7fff ffff ffff ffff (NaN) indicating an unknown value.


### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.FeatureNotAvailable                         | Feature not available                             |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

## References

* The XML definition of the [TargetTemperature](TargetTemperature-v1.xml) interface.
* The [RemoteControllability](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) interface.
* The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)


