# org.alljoyn.Hae.Device.Washer version 1

## Theory of Operation

Washer is a home appliance used to wash laundry, such as clothing and sheets.
This washer interface provides capabilities to control and monitor washer
specific functions and resources. A controller can recognize this device
as a washer if object descriptions of the About announcement include this interface.

The followings are minimum required shared interfaces for washer.
  * **org.alljoyn.Hae.OperationalControl** --- for control of operation
  * **org.alljoyn.Hae.OperationalTime** --- for scheduling of operation time

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Properties

#### OperationCycle

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists cycles of operation.

  * **0** --- **Normal** : For washing everyday items like jeans, towels, shirts,
    sheets and mixed loads.
  * **1** --- **Heavy Duty** : For washing heavily soiled cotton fabrics.
  * **2** --- **Bulky/Large** : For washing large items like blankets, comforter,
    pillows, and other items that have difficult absorbing water.
  * **3** --- **Bright Whites** : For washing and maintaining bright white fabrics.
  * **4** --- **Sanitary** : For washing the dirtiest clothing items like work
    clothes, baby diapers or heavily soiled garments.
  * **5** --- **Allergen** : For reducing allergens including common triggers
    such as dust mites and pet dander.
  * **6** --- **Tub Clean** : For cleaning a buildup of mold and germs in the air
    inside the washer tub.
  * **7** --- **Towels** : For washing towels, shirts, jeans, and  mixed loads.
  * **8** --- **Permanent Press** : For minimizing wrinkles for dress shirts and
    pants, wrinkle-free clothing and poly/cotton blend clothing.
  * **9** --- **Handwash/Wool** : For washing shrinkable woolen or hand-washable
    items requiring delicate care.
  * **10** --- **Delicates** : For washing clothes that can get damages easily.
  * **11** --- **Speed Wash** : For washing lightly soiled clothing and small loads,
    this cycle can have clothes clean and fresh faster than a normal cycle.
  * **12** --- **Small Load** : For washing small load.
  * **13** --- **Drain+Spin** : For draining the tub and spinning clothes.

#### SupportedOperationCycles

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported operation cycles. After getting the list of supported operation
cycles, a valid one should be chosen out of list.

#### Cycle Stage

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists cycle stages of operation.

  * **0** --- **Unavailable**
  * **1** --- **Pre-washing**
  * **2** --- **Washing**
  * **3** --- **Rinsing**
  * **4** --- **Spinning**

Current cycle stage of the washer.

#### NumberOfRinse

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Target number of rinse.

#### MaxNumberOfRinse

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Maximum number of rinse. 0 means that device does not offer the capability
to change the number of rinse.

#### WaterTemperatureLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists water temperature levels of washer.

  * **0** --- **Tap cold**
  * **1** --- **Cold**
  * **2** --- **Warm**
  * **3** --- **Hot**
  * **4** --- **Extra Hot**

Target water temperature level for washing.

#### SupportedWaterTemperatureLevels

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported water temperature levels. After getting the list of
supported water temperature levels, a valid one should be chosen out of the list.
Empty list means that device does not offer the capability to set the water
temperature level.

#### SpinSpeedLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists spin speed levels of washer.

  * **0** --- **No spin**
  * **1** --- **Low**
  * **2** --- **Medium**
  * **3** --- **High**
  * **4** --- **Extra High**

Target spin speed level.

#### SupportedSpinSpeedLevels

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

An array of supported spin speed levels. After getting the list of supported spin 
speed levels, a valid one should be chosen out of the list. Empty list means that 
device does not offer the capability to set the spin speed level.

#### SoilLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The enumeration below lists soil levels of washer.

  * **0** --- **Light**
  * **1** --- **Normal**
  * **2** --- **Heavy**

Target soil level for washing

#### SupportedSoilLevels

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte[]                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Array of supported soil levels. After getting the list of supported soil levels, 
a valid one should be chosen out of the enumeration list. Empty list means that
device does not offer the capability to set the soil level.

### Methods

#### SetOperationCycle (operationCycle)

Set an operation cycle. An washer starts its operation cycle immediately after
setting or changing its target operation cycle. If a controllee device receives
an invalid operation cycle or can’t accept a valid operation cycle due to its internal
state, then an appropriate error code shall be returned.

Input arguments:

  * **operationCycle** --- byte --- an operation cycle to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

#### SetNumberOfRinse(numberOfRinse)

Set target number of rinse.

Input arguments:

  * **numberOfRinse** --- byte --- number of rinse to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

#### SetWaterTemperatureLevel(waterTemperatureLevel)

Set target water temperature level.

Input arguments:

  * **waterTemperatureLevel** --- byte --- water temperature level to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

#### SetSpinSpeed(spinSpeedLevel)

Set target soil level

Input arguments:

  * **spinSpeedLevel** --- byte --- spin speed level to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

#### SetSoilLevel(soilLevel)

Set target soil level

Input arguments:

  * **soilLevel** --- byte --- soil level to set

Errors raised by this method:

  * org.alljoyn.Hae.Device.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Device.Error.NotAcceptableDueToInternalState --- Value is not
    acceptable due to internal state

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

  * The XML definition of the [Washer interface](org.alljoyn.Hae.Device.Washer-v1.xml)
  * The definition of the [OperationalControl interface](org.alljoyn.Hae.OperationalControl-v1.md)
  * The definition of the [OperationalTime interface](org.alljoyn.Hae.OperationalTime-v1.md)
