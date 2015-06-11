# org.alljoyn.Hae.Alerts version 1

## Theory of Operation

This information provides the status of the alerts of an appliance.

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security.

### Properties

#### Alerts

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | AlertRecord[]                                                         |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

The list of current pending alerts.
If there is no pending alert the array is empty.

#### AlertsRequestedAcknowledgement

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates whether there is a need of user acknowledgment to give a feedback
for pending alerts.
True means the user acknowledgment is needed.

### Methods

#### AcknowledgeAlerts()

|                       |                                             |
|-----------------------|---------------------------------------------|
| Annotation            | org.freedesktop.DBus.Method.NoReply = true  |

Reset a pending user acknowledgment request:
AlertsRequestedAcknowledgement property is set to false.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct AlertRecord

AlertRecord structure

  * **severity** --- byte --- enumeration field
  * **alertCode** --- uint16 --- the values depend on the specific appliances

The purpose in define this type is to standardize only data structure;
i.e. a common data structure can be used while the values can be not inter
operable by definition.

Enumeration fields and description of **severity**:

  * 0 --- warning --- "e.g. missing polishing in Dish Washer"
    * there is no risk of damage
    * appliance can work anyway without the best performance
    * it can be removed by user intervention"   
    

  * 1 --- alarm --- "e.g. fridge open door"
    * there is risk of damage of something (e.g. food) after some time
    * appliance can work, but results are not sure
    * it can be removed by user intervention

  * 2 --- fault --- "e.g. broken components like temperature sensor or water pumps"
    * appliance can not work
    * service intervention is needed

Note about **alertCode**:
it is not possible to have interoperability on this codes because they depends
by the specific manufacturer.
To understand the **alertCode** values it is expected that separate
documentation are provided and maintained by manufacturers.
This information can be used by _consumers_ to interpret correctly the alerts.

### Interface Errors

No unique errors are associated with this interface.

## Examples

The following sequence describes an example of "Open Door" alert for refrigeration
appliances.

1. A "Open Door" alert in a refrigerator comes up:
  * the appliance activates visual (User Interface) and acoustic (buzzer) feedbacks
  * the interface properties are updated:
    * an "open door" element is loaded in **Alerts** array
    * **AlertsRequestedAcknowledgement** is set to true

2. the user detect and acknowledge it (locally or remotely):
  * the appliance stops the acoustic (buzzer) feedbacks;
    anyway the alert condition is still present
  * the interface properties are updated:
    * **AlertsRequestedAcknowledgement** is set to false
    * The "open door" element is still present in **Alerts** array

3. the door is closed:
  * the alert is no more present, appliance and its User Interface work in normal way
  * the interface properties are updated:
    * the "open door" element is removed from **Alerts** array

## References

  * The XML definition of the [Alerts interface](Alerts-v1.xml)

