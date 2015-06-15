# org.alljoyn.Hae.Device.AirPurifier version 1

## Theory of Operation

Home appliance used to purify air in a single room or an entire building. 
The followings are minimum required shared interfaces for air purifier.

  * **org.alljoyn.Hae.OperationControl** --- for start/stop operation

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### OpticalCatalystMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Optical catalyst on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### IonEmissionMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Ion Emission on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### SterilizeMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Sterilize on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### PowerfulMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Powerful mode on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### SleepMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Sleep mode on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### AutoMode

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Auto mode on/off status.

  * **0** --- **Off**
  * **1** --- **On**
  * **255** --- **Not Available or Unknown**

#### WaterAmountLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Water level of the device.
0 ~ MaxWaterAmountLevel:

* **0** --- **empty**
* **MaxWaterAmountLevel** --- **maximum amount of water

#### MaxWaterAmountLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Maximum value allowed for water amount level.

### Methods

#### ChangeOpticalCatalystMode (opticalCatalystMode)

Change optical catalyst mode. 

Input arguments:

  * **opticalCatalystMode** --- byte --- an optical catalyst mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### ChangeIonEmissionMode (ionEmissionMode)

Change ion emission mode. 

Input arguments:

  * **ionEmissionMode** --- byte --- an ion emission mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### ChangeSterilizeMode (sterilizeMode)

Change sterilize mode. 

Input arguments:

  * **sterilizeMode** --- byte --- an sterilize mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### ChangePowerfulMode (powerfulMode)

Change powerful mode. 

Input arguments:

  * **powerfulMode** --- byte --- a powerful mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### ChangeSleepMode (sleepMode)

Change sleep mode. 

Input arguments:

  * **sleepMode** --- byte --- an sleep mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

#### ChangeAutoMode (autoMode)

Change auto mode. 

Input arguments:

  * **autoMode** --- byte --- an auto mode to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not acceptable due to internal state

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

## References

  * The XML definition of the [AirPurifier interface](AirPurifier-v1.xml)
