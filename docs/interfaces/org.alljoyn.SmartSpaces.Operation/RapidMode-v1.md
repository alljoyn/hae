# org.alljoyn.SmartSpaces.Operation.RapidMode version 1

## Theory of Operation

Interface that exposes the Rapid (or Turbo) mode.  This is the opposite of 
ResourceSaving, the device works in a more aggressive mode, usually at an 
efficiency or noise level penalty.

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

  * [The definition of common interface](/org.alljoyn.SmartSpaces/Common-v1)
  * [The XML definition of RapidMode](RapidMode-v1.xml)
