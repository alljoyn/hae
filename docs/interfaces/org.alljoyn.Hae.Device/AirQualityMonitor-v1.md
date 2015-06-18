# org.alljoyn.Hae.Device.AirQualityMonitor version 1

## Theory of Operation

Air Quality Monitor is a type of home appliances that has the capability of
monitoring pollutants in the air.This interface is an abstract type so that
it covers any home appliance who has the function of getting the quantitative
load or qualitative level of any air pollutants.

The followings are minimum required shared interfaces for an Air Quality 
Monitor.
  * **org.alljoyn.Hae.OperationControl** --- for start/stop operation

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
  * **org.alljoyn.Hae.RepresentedAirQualityLevel**

## Specification

|               |                                                       |
|---------------|-------------------------------------------------------|
| Version       | 1                                                     |
| Annotation    | org.alljoyn.Bus.Secure = false                        |

There is no critical information that should be protected.

## References

  * [The XML definition of AirQualityMonitor]
    (AirQualityMonitor-v1.xml)
  * [The definition of OperationalControl]
    (/org.alljoyn.Hae/OperationalControl-v1)
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
