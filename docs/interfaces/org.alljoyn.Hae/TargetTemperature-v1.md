# org.alljoyn.Hae.TargetTemperature version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### TargetValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | Temperature                                                    |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Target temperature, expressed in Celsius.
See fixed-point representation for more information in the Temperature struct
definition of named types section.

#### MinValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | Temperature                                                    |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Minimum value of target temperature, expressed in Celsius.
See fixed-point representation for more information in the Temperature struct
definition of named types section. If there is no minimum value available,
<significand> and <exponent> of this shall be set to 0x8000 and 0x7FFF,
respectively.

#### MaxValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | Temperature                                                    |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value of target temperature, expressed in Celsius.
See fixed-point representation for more information in the Temperature struct
definition of named types section. If there is no minimum value available, and
of this shall be set to 0x7FFF and 0x7FFF, respectively.

#### StepValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | Temperature                                                    |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Step value allowed for TargetTemperature setting, expressed in Celsius.
See fixed-point representation for more information in the Temperature struct
definition of named types section. It shall be a positive value (data type
representation is unsigned for consistency with other temperature properties)

### Methods

#### SetTargetTemperature (temperature)

Set target temperature, expressed in Celsius. If the controller tries to set
a target value which is out of range, then an error should be returned. If the
controller tries to set a target value which doesn't match with the granularity
of the current step, the device has to make one of the following operations:

  * raising an error (it could be ER_INVALID_DATA or a specific error to be defined).
  * setting TargetValue to an appropriate value.
  * the decision is up to the device itself.

Input arguments:

  * **temperature** --- Temperature --- target temperature value

Errors raised by this method:

  * org.alljoyn.Hae.Error.OutOfRange --- Value is out of range
  * org.alljoyn.Hae.Error.NoPreciseStep --- Value doesn't match the grid of step
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state


### Signals

No signals are emitted by this interface.

### Named Types

#### struct Temperature

Temperature struct express a fixed-point number.

  * **significand** --- int32 --- significand of temperature value
  * **exponent** --- int32 --- exponent of temperature value

Temperatures representing properties (e.g. TargetValue, MinValue and MaxValue)
are defined using a struct where:
  * first element is the significand;
  * second element is the exponent and base is 10.The actual temperature value
  can be represented by significand (10^exponent)
  * Refer to http://en.wikipedia.org/wiki/Significand

> Example:
> the value 10.2 can be represented as 102 in a fixed-point data type with
> scaling factor of 1/10, which is given by the exponent equal to -1 and
> base is 10.
> (102, -1) = 102 \* 10^(-1) = 10.2, (32442, -3) = 32442 \* 10^(-3) = 32.442
> If the device does not limit minimum temperature, the MinValue is represented
> as (0x8000, 0x7FFF).If the device does not limit maximum temperature, the
> MaxValue is represented as (0x7FFF, 0x7FFF).

**Note**: this representation gives some flexibility to manage different levels
of approximation; e.g. "10.0°C" can be represented as (1, 1), (10, 0), (100, -1)...
It is strongly suggested to use the minimum approximation which fits with the
application requirements; e.g. if the device manage temperatures with a "0.1°C"
accuracy, the exponent has to be set to "-1" (it can not be higher for
information loss, but it ha no sense to set it lower because it add complexity
in the calculation without having any advantage).It is also suggested to keep
fixed the exponent in any specific application and not change at run-time.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.OutOfRange                      | Value is out of range                         |
| org.alljoyn.Hae.Error.NoPreciseStep                   | Value doesn't match the grid of step          |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [TargetTemperature interface](TargetTemperature-v1.xml)
