# org.alljoyn.SmartSpaces.Environment.TargetTemperature version 1

## Theory of Operation
This interface is for setting target temperature of the HAE devices such as a
space heater, oven, etc. The temperature is expressed in degrees celsius.
This is for the active temperature based on the device state. For example an 
oven may have a number of temperatures in memory for fish, lasagna, chicken etc 
or a thermostat for different days of the week and times of day.  Only the one 
currently being used to Target a specific temperature in the appliance is 
exposed by this interface.

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

The interface version.  The EmitsChangedSignal annotation of this property
should change to const once that feature is available in core.

#### TargetValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Target temperature, expressed in Celsius.

If the controller tries to set a target value which is out of range, then
the controllee should adjust the value to min/max value. If the controller
tries to set a target value which doesn't match with the granularity of
the current step, the device should set an appropriate value that can be
accepted.
If no target temperature is available this wil read 7fff ffff ffff ffff (NaN).

Errors raised when setting this property:

* org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
if value is not acceptable due to internal state.
* org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
control is disabled.

#### MinValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Minimum value of target temperature, expressed in Celsius.
If no minimum value is available this wil read 7fff ffff ffff ffff (NaN).

#### MaxValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value of target temperature, expressed in Celsius.
If no maximum value is available this wil read 7fff ffff ffff ffff (NaN).

#### StepValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Step value allowed for TargetTemperature setting, expressed in Celsius.
~~It shall be a positive value.~~
If no step value is available this wil read 7fff ffff ffff ffff (NaN).


### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.


### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

## References

* The XML definition of the [TargetTemperatureHeating](TargetTemperatureHeating-v1.xml) interface.
* The TargetTemperatureCooling (TargetTemperatureCooling-v1) interface.
* The [RemoteControllability](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) interface.
* The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)


