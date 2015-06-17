# org.alljoyn.Hae.ResourceSaving version 1

## Theory of Operation

Resource Saving is one of the operation modes of an appliance, in which the
appliance consumes less energy or resources than that in another, usually with
some restrictions in its performance and/or functions.  The examples of
resources are electricity, water and gas.

## Specification

|            |                                                              |
|------------|--------------------------------------------------------------|
| Version    | 1                                                            |
| Annotation | org.alljoyn.Bus.Secure = true                                |

### Properties

#### ResourceSavingMode

|            |                                                              |
|------------|--------------------------------------------------------------|
| Type       | boolean                                                      |
| Access     | read-only                                                    |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true      |

Indicates the running mode of device from the aspect of resource saving.  It
holds TRUE if the device runs in the resource saving mode, FALSE otherwise.

### Methods

#### EnableResourceSaving (b)

Enables or disables the resource saving mode.

Input arguments:

  * **b** --- boolean --- Set TRUE to enable or FALSE to disable.

Errors raised by this method:

  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState

## References

  * [The XML definition of ResourceSaving](ResourceSaving-v1.xml)
