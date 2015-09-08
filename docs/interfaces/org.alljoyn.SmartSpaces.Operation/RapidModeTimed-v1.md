# org.alljoyn.SmartSpaces.Operation.RapidModeTimed version 1

## Theory of Operation

This interface is for controlling a rapid mode of a device that has a limited 
duration.  For example, a refrigerator Quick Chill drawer, that can be set for
a specific time.  This interface can be implemented independantly of RapidMode.
No guidance is provided on managing the dependancies if both are implemented.

## Specification

|                       |                                                     |
|-----------------------|-----------------------------------------------------|
| Version               | 1                                                   |
| Annotation            | org.alljoyn.Bus.Secure = true                       |

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The Interface version

#### RapidModeMinutesRemaining

|                  |                                                          |
|------------------|----------------------------------------------------------|
| Type             | UInt16                                                   |
| Access           | read-write                                               |
| Annotation       | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Time remaining in RapidMode.  MaxTime means the longest value for setting rapid 
mode.  Step value is always 1.

Special reserved values listed below:
  * 0x00 --- **Off** --- Not in rapid mode. Writing this turns rapid mode off.

If device has a min run time in RapidMode, RapidModeTimeRemaining will update to
that minimum time if a valaue less than that time is written (include zero).

Errors raised when setting this property:

  * org.alljoyn.Error.InvalidValue --- Returned if value is not valid.
  * org.alljoyn.Error.SmartSpaces.NotAcceptableDueToInternalState --- Returned
  if value is not acceptable due to internal state.
  * org.alljoyn.Error.SmartSpaces.RemoteControlDisabled --- Returned if remote
  control is disabled.   See the RemoteControl property in [the definition of 
  common interface](/org.alljoyn.SmartSpaces/Common-v1) for further information.


#### MaxTime

|                  |                                                          |
|------------------|----------------------------------------------------------|
| Type             | UInt16                                                   |
| Access           | read-only                                                |
| Annotation       | org.freedesktop.DBus.Property.EmitsChangedSignal = true  |

Maximum rapid mode set time.  Does not change to accomodate already in rapid 
mode.  For example, if a fan can only do rapid mode for 30 minutes, then needs
to wait before starting a new rapid mode.  This property will read 30.  If 
RapidModeTimeRemaining is set to 15, this property will stay at 30.  Writing to 
RapidModeTimeRemaining may generate NotAcceptableDueToInternalState error if 
device cannot support.

Changed Signal is true so property can be cached.  Can be updated to const when
that feature is available.


### Methods

No methods are implemented by this interface.

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

  * The XML definition of the [RapidModeTimed](RapidModeTimed-v1.xml) interface.
  * The XML definition of the [RapidMode](RapidMode-v1.xml) interface.
  * The definition of the [Common](/org.alljoyn.SmartSpaces/Common-v1) interface.

