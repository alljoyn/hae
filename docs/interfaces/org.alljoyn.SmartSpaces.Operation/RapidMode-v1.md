# org.alljoyn.SmartSpaces.Operation.RapidMode version 1

## Theory of Operation

Interface that exposes the Rapid (or Turbo) mode.  This is the opposite of 
ResourceSaving, the device works in a more aggressive mode, usually at an 
efficiency or noise level penalty.  This interface is appropriate for a device 
that has On/Off control of Rapid Mode.  RapidModeTimed is for a device that 
wants to provide more explicit control of the duration of RapidMode to a
controller.  No guidance is provided on managing the dependancies if both are
implemented.

## Specification

|            |                                                              |
|------------|--------------------------------------------------------------|
| Version    | 1                                                            |
| Annotation | org.alljoyn.Bus.Secure = true                                |

### Properties

#### Version

|                   |                                                         |
|-------------------|---------------------------------------------------------|
| Type              | uint16                                                  |
| Access            | read-only                                               |
| Annotation        | org.freedesktop.DBus.Property.EmitsChangedSignal = true |

Can be modified to const once that feature is available.

#### RapidMode

|            |                                                              |
|------------|--------------------------------------------------------------|
| Type       | boolean                                                      |
| Access     | read-write                                                   |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true      |

True if the device is currently operating in rapid mode.

Errors raised by the set method of this property:

* org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState --- Indicates
that the given value was not acceptable due to internal state.
* org.alljoyn.SmartSpaces.Error.RemoteControlDisabled --- Indicates that
control from a remote site is currently disabled.  See the RemoteControl 
property in [the definition of common interface](/org.alljoyn.SmartSpaces/Common-v1) for
further information.

### Methods

No methods defined for this interface.

### Interface Errors

The table below shows the possible errors raised by this interface.

| Error name                    | Error message                         |
|-------------------------------|---------------------------------------|
| org.alljoyn.SmartSpaces.Error.NotAcceptableDueToInternalState | Given value was not acceptable due to internal state. |
| org.alljoyn.SmartSpaces.Error.RemoteControlDisabled | Control from a remote site is currently disabled. |

## References

  * The definition of the [Common](/org.alljoyn.SmartSpaces/Common-v1) interface.
  * The XML definition of the [RapidMode](RapidMode-v1.xml) interface.
  * The XML definition of the [RapidModeTimed](RapidModeTimed-v1.xml) interface.

