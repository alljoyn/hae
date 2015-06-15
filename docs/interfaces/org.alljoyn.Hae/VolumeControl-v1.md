# org.alljoyn.Hae.VolumeControl version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### Volume

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Speaker volume index of the device. Minimum volume is always 0.

#### StepValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Step value of volume control.

#### MaxValue

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Maximum value allowed for Volume.

### Methods

#### UpVolume ()

Up volume to the next available value.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

#### DownVolume ()

Down volume to the next available value.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

#### ChangeVolume (volume)

Change the volume. If the controller tries to set a target value which is out of
range, then an appropriate error should be returned. In case that the Volume is
in range defined by MaxValue, but it is not on the grid in terms of StepValue,
the controllee can set an appropriate value without returning an error, or it
can refuse the target value and return an appropriate error. If StepValue = 0,
it means there is no step value information available for the controllee device.
In this case, the controllee will go to an appropriate value that can be accepted
without returning an error.

Input arguments:

  * **volume** --- byte --- target volume value

Output arguments: None.

Errors raised by this method:

  * org.alljoyn.Hae.Error.OutOfRange --- Value is out of range
  * org.alljoyn.Hae.Error.NoPreciseStep --- Value doesn't match the grid of step
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state


### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.OutOfRange                      | Value is out of range                         |
| org.alljoyn.Hae.Error.NoPreciseStep                   | Value doesn't match the grid of step          |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [VolumeControl interface](VolumeControl-v1.xml)