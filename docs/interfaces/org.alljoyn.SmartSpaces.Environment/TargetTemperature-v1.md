# org.alljoyn.SmartSpaces.Environment.TargetTemperature version 1

## Theory of Operation
This interface is for setting target temperature of the HAE devices such as air
conditioner, refrigerator, oven, etc. The temperature is expressed in celsius.

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


#### TargetValues

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | dictionary{string:double}                                      |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

List of target temperature setpoints, expressed in Celsius.  This will return 
the entire list of possible setpoints, if the value is not set it should be set 
to NaN 7FFFFFFFFFFFFFFF.
 

#### MinValues

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | dictionary{string:double}                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Minimum value all target temperatures, expressed in Celsius.  If there is no 
minimum value available, this shall be set to 0xFFF0000000000000.
The EmitsChangedSignal value of this property can be updated to "const" once 
that feature is available in Core.

#### MaxValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value of target temperature, expressed in Celsius.
If there is no maximum value available, this shall be set to 0x7FF0000000000000.
The EmitsChangedSignal value of this property can be updated to "const" once 
that feature is available in Core.


#### StepValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | double                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Step value allowed for TargetTemperature setting, expressed in Celsius.
~~It shall be a positive value (data type representation is unsigned for
consistency with other temperature properties)~~
The EmitsChangedSignal value of this property can be updated to "const" once 
that feature is available in Core.


#### UpperActiveSetpoint
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The dictionary key for a temperature that the device is attempting to keep the 
temperature below.  This should be "" for a heating device like an oven.  This 
property is not intended to reflect any hysteresis.

Errors raised when setting this property:

* org.alljoyn.Error.InvalidValue --- Returned if value is not valid.  This
will be returned becuase the string is not a valid key, if setting to the same 
key as LowerActiveSetpoint, or setting to a setpoint which is NaN.
* org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
if value is not acceptable due to internal state.
* org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
control is disabled.   See the RemoteControl property in the 
[RemoteControllability interface](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) for further information.




#### LowerActiveSetpoint
|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-write                                                     |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The dictionary key for a temperature that the device is attempting to keep the 
temperature below.  This should be "" for a cooling device like arefrigerator.  
This property is not intended to reflect any hysteresis.

Errors raised when setting this property:

* org.alljoyn.Error.InvalidValue --- Returned if value is not valid.  This
will be returned becuase the string is not a valid key, if setting to the same 
key as LowerActiveSetpoint, or setting to a setpoint which is NaN.
* org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
if value is not acceptable due to internal state.
* org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
control is disabled.   See the RemoteControl property in the 
[RemoteControllability interface](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) for further information.


### Methods

#### SetTargetTemperature(key, degC)

Used to set a TargetTemperature for a specific key.

Input arguments:

* **key** --- string --- The TargetTemperature to be set.

* **degC**  ---double --- The value to set the TargetTemperature.


If the controller tries to set a target value which is out of range, the value 
shall be then set to the limit of the range.  
If the controller tries to set a target value which doesn't match with the 
granularity of the current step, the device has shall round TargetValue using a
device specific algorithm.


Errors raised by this method:
* org.alljoyn.Error.InvalidValue --- if the key is not in the list of TargetValues.
* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- when the
key or celcius value is not accepted by the _producer_
* org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- when the remote
control is disabled.   See the RemoteControl property in the 
[RemoteControllability interface](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1) for further information.



### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message. The table below lists the possible errors raised by this interface.

| Error name                                                    | Error message                                      |
|---------------------------------------------------------------|----------------------------------------------------|
| org.alljoyn.Error.InvalidValue                                | Invalid value                                      |
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | The value is not acceptable due to internal state  |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled           | Remote control disabled                            |

## References

* The XML definition of the [TargetTemperature interface](TargetTemperature-v1.xml)
* The [RemoteControllability interface](/org.alljoyn.SmartSpaces.Operation/RemoteControllability-v1)
* The theory of operation of the HAE service framework [Theory of Operation](/org.alljoyn.SmartSpaces/theory-of-operation-v1)


