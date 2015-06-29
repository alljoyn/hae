# org.alljoyn.Hae.Device.AirQualityMonitor version 1

## Theory of Operation

Air Quality Monitor is a type of home appliances that has the capability of
monitoring pollutants in the air.This interface is an abstract type so that
it covers any home appliance who has the function of getting the quantitative
load or qualitative level of any air pollutants.

The minimum required shared interface for Air Quality Monitor is as follows:
  * **org.alljoyn.Hae.RepresentedAirQualityLevel** -- for Air Quality Level


There are many kinds of air pollutants that can be monitored, such as PM2.5,
PM10,VOC,CH2O,CO and CO2. Each specific Air Quality Monitor can monitor
certain or all air pollutants.
Considering the specific function of Air Quality Monitor, the following shared
interfaces may be implemented:
  * **org.alljoyn.Hae.RepresentedPm2_5Concentration**
  * **org.alljoyn.Hae.RepresentedPm10Concentration**
  * **org.alljoyn.Hae.RepresentedVocConcentration**
  * **org.alljoyn.Hae.RepresentedCh2oConcentration**
  * **org.alljoyn.Hae.RepresentedCoConcentration**
  * **org.alljoyn.Hae.RepresentedCo2Concentration**

## Specification

|               |                                                       |
|---------------|-------------------------------------------------------|
| Version       | 1                                                     |
| Annotation    | org.alljoyn.Bus.Secure = false                        |

There is no critical information that should be protected.

## References

  * [The XML definition of AirQualityMonitor]
    (AirQualityMonitor-v1.xml)
  * [The definition of RepresentedAirQualityLevel]
    (/org.alljoyn.Hae/RepresentedAirQualityLevel-v1)
  * [The definition of RepresentedPm2_5Concentration]
    (/org.alljoyn.Hae/RepresentedPm2_5Concentration-v1)
  * [The definition of RepresentedPm10Concentration]
    (/org.alljoyn.Hae/RepresentedPm10Concentration-v1)
  * [The definition of RepresentedVocConcentration]
    (/org.alljoyn.Hae/RepresentedVocConcentration-v1)
  * [The definition of RepresentedCh2oConcentration]
    (/org.alljoyn.Hae/RepresentedCh2oConcentration-v1)
  * [The definition of RepresentedCoConcentration]
    (/org.aljoyn.Hae/RepresentedCoConcentration-v1)
  * [The definition of RepresentedCo2Concentration]
    (/org.alljoyn.Hae/RepresentedCo2Concentration-v1)
