# org.alljoyn.Hae.RepresentedAirQualityLevel version 1

## Theory of Operation

This information provides represented air quality level measured by an 
appliance.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### AirQualityType

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

The air quality type.

* **0** --- **PM2.5**
* **1** --- **PM10**
* **2** --- **CO**
* **3** --- **CO2**
* **4** --- **CH2O**
* **5** --- **VOC**
* **6** --- **Smoke**
* **7** --- **Odor**
* **8** --- **AirPollution**

#### RepresentedLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

The qualitative represented of current relative air quality level.
0 ~ MaxLevel:

* **0** --- **the cleanest level**
* **MaxLevel** --- **the most impure level**

#### MaxLevel

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | byte                                                           |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false       |

Maximum level allowed for represented air quality level.

### Methods

No methods are exposed by this interface.

### Signals

No signals are emitted by this interface.

## References

  * The XML definition of the [RepresentedAirQualityLevel interface](RepresentedAirQualityLevel-v1.xml)
