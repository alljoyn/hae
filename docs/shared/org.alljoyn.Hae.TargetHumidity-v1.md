# org.alljoyn.Hae.TargetHumidity version 1

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

### Properties

#### TargetValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

 Target value for relative humidity. Relative humidity is the ratio of the partial pressure of water vapor to the equilibrium vapor pressure of water at the same temperature. If the controller tries to set a target value which is out of range, then an error should be returned. In case that the TargetValue is in range defined in MinValue and MaxValue, but it is not on the grid in terms of StepValue, the controllee can set an appropriate value without returning an error, or it can refuse to accept the TargetValue and return an appropriate error. If StepValue = 0, it means there is no step value information available for the controllee device. In this case, the controllee will go to an appropriate value that can be accepted without returning an error.

#### MinValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Minimum value allowed for TargetValue. MinValue can’t be less than 0.

#### MaxValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Maximum value allowed for TargetValue. MaxValue can’t be greater than 100.

#### StepValue

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                           |
| Access                | read                                                                  |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Step value allowed for TargetValue(%) setting. The step of humidity increment or decrement can be different for each device. The step can be 1%, 5%, and 10%, etc. Starting from MinValue, valid target value will be represented. Difference between MaxValue and MinValue should be an integer multiple of StepValue.

### Methods

#### SetTargetHumidity ('y')

Set target value for relative humidity. Relative humidity is the ratio of the partial pressure of water vapor to the equilibrium vapor pressure of water at the same temperature. If the controller tries to set a target value which is out of range, then an error should be returned. In case that the TargetValue is in range defined in MinValue and MaxValue, but it is not on the grid in terms of StepValue, the controllee can set an appropriate value without returning an error, or it can refuse to accept the targetValue and return an appropriate error. If StepValue = 0, it means there is no step value information available for the controllee device. In this case, the controllee will go to an appropriate value that can be accepted without returning an error.

Input arguments:
    
  * **y** --- byte --- Target humidity value.
  
Errors raised by this method:

  * org.alljoyn.Error.OutOfRange --- Value is out of range
  * org.alljoyn.Error.NoPreciseStep --- Value doesn't match the grid of step
  * org.alljoyn.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state
  

### Signals

No signals are emitted by this interface.

## References

In this section, list references for the Interface definition (standards, RFCs,
related interfaces, etc.). Make sure to include at least the following
references:

  * The XML definition of the [TargetHumidity interface](org.alljoyn.Hae.TargetHumidity-v1.xml)
  * t.b.d.: the formal XML definition of the Interface described in this document
  * t.b.d.: the Theory of Operation document, if you decided to split it off
  * t.b.d.: the interface definition document for related interfaces (especially those
    that are described in the same Theory of Operation document)

