# org.alljoyn.Hae.Device.AirPurifier version 1

## Theory of Operation

Air purlifier is a home appliance used to purify air in a single room or 
an entire building. 

The followings are minimum required shared interfaces for an air purifier.

  * **org.alljoyn.Hae.OperationControl** --- for start/stop operation

The followings are examples of shared interfaces expected to be commonly 
used for an air purifier.

If there are a plurality of air quality types measurable by an air 
purifier, then a plurality of bus objects with air quality level 
interfaces with different air quality types are expected as direct 
children of the bus object with this (air purifier device) interface.

  * **org.alljoyn.Hae.RepresentedAirQuarityLevel**
  * **org.alljoyn.Hae.RepresentedCo2Concentration**
  * **org.alljoyn.Hae.RepresentedCoConcentration**
  * **org.alljoyn.Hae.RepresentedPm2_5Concentration**
  * **org.alljoyn.Hae.RepresentedPm10Concentration**
  * **org.alljoyn.Hae.RepresentedCh2oConcentration**
  * **org.alljoyn.Hae.RepresentedVocConcentration**
  * **org.alljoyn.Hae.WindStrength**
  * **org.alljoyn.Hae.FilterStatus**
 
The following is an example of a shared interface expected to be 
commonly used for an air purifier with a water tank.

  * **org.alljoyn.Hae.WaterLevel**

The following is an example of a shared interface expected to be 
commonly used for an air purifier with humidifying capability.

  * **org.alljoyn.Hae.MoistureOutput**

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### TurboMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Turbo on/off status.
When turbo mode is on, the effect of purifying air increases.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

### Methods

#### EnableTurboMode (turboMode)

Enable turbo mode. 
If the device cannot enable/disable turbo mode due to its internal state, 
then an appropriate error shall be returned.

Input arguments:

  * **turboMode** --- boolean --- true: enable, false: disable

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state
  * org.alljoyn.Hae.Device.Error.RemoteContolDisabled --- Remote control is currently disabled
  * org.alljoyn.Hae.Device.Error.NotSupported --- Turbo mode is not supported by the device

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message. The table
below lists the possible errors raised by this interface.

| Error name                                                   | Error message                                 |
|--------------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Device.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Device.Error.RemoteControlDisabled           | Remote control is currently disabled          |
| org.alljoyn.Hae.Device.Error.NotSupported                    | Mode is not supported by the device           |

## References

  * The XML definition of the [AirPurifier interface](AirPurifier-v1.xml)
