## Theory of Operation
This document describes the theory of operation how the Home Appliances and
Entertainment Service Framework should work. It contains the device model,
semantic relationship between interfaces and the standard device types for the
HAE Service Framework.

### Overview

The goal of the HAE Service Framework is to standardize AllJoyn interfaces for
Home Appliances & Entertainment(HAE) category devices and provide common open
source implementation.

#### Benefits

##### Cross-vendor interoperability

The standardization of AllJoyn interfaces for home appliances and entertainment
devices is mightily important to establish the cross-vendor interoperability.
These standard interfaces will enable to control and monitor devices from
different vendors by using a controller application or device from another
vendor. Such standard interfaces define common functionalities among devices
under the same categories by each vendor. This approach provides common
interfaces and functionalities to developers but also the same user experiences
to end-users. It will guarantee the interoperability of controller application
for each vendor.

##### Background Control & Monitoring

AllJoyn provides the control panel service framework to control devices, but it
requires human's interpretation and interaction from the controller side to
control devices. To support various automation services for IoT, background
control and monitoring should be enabled. Users do not need to see and touch
their mobile or smart watch. Voice or text based control and monitoring will
be enabled. Even machine to machine control and interaction can be possible by
using these predefined standard interfaces.

##### Tailor-made UI for each controller screen

Using the control panel might be unsuitable for smart watch or non-screen
devices. With a single control panel UI data, it is not easy to satisfy all the
various screen sizes and shapes of the controller devices such as smart watch,
phone, tablet and TV. The HAE Service Framework is targeted to provide
predefined device functionalities so that controller application developers can
deliver tailor-made UI targeted for each controller screen to end-users.

#### Use Cases

The HAE Service Framework has two types of use cases such as monitoring and
controlling. A HAE controller monitors the current operational status of the HAE
controllee and the controller is warned about interested situation of the HAE
controllee. The HAE controller interacts with one or more HAE controllees to
control their operations. Figure1 illustrates the usecases between the HAE
controllee and the HAE controller.

![](hae_usecase.png)
Figure1: Usecases of controlling and monitoring

#### Overall Architecture

The Controllee App works on the HAE devices such as a refrigerator, a air
conditioner or a washer. The Controller App is an application software that runs
on the user’s terminal such as a smart phone or a tablet, and communicates with
a HAE controllee through the AllJoyn bus. The HAE Service Framework must be
implemented by an application on a controllee. And the Controller App must be
implemented using the Controller API of the HAE Service Framework. Figure2
illustrates the relationship between a controllee app and controller app.

![](hae_overall_architecture.png)
Figure2: HAE service framework architecture within the AllJoyn framework

### Device Model
AllJoyn representation of HAE device model follows the AllJoyn bus object
structure and for that, 3 categories of interfaces are defined. AllJoyn bus
object structure carries both the hierarchy and the capability information.
In the HAE Service Framework, this hierarchy reveals the relationship between
a device and children devices. Figure3 illustrates the general device model
for HAE devices.

![](hae_device_model.png)
Figure3: HAE device model

#### 3 Categories of interfaces

##### Common Interface
The Common Interface is a common AllJoyn interface for all HAE devices. The name
of common interface is fixed as "org.alljoyn.Hae". Per About announcement, there
shall be one and only one common interface for HAE service framework and the bus
object where the common interface reside is the root HAE bus object.

##### Shared Interface
The Shared Interface is sharable or reusable interface by HAE devices. Minimum
mandatory requirements on the shared interfaces to have shall be specified for
each HAE device type.

##### Device Interface
The name of the device interface indicates the HAE device type. Under a root bus
object, there shall be one and only one device interface. Each standard HAE
device type shall have one and only one device interface. The root HAE bus
object might have children bus objects, and some of its children bus objects
might have another device interface to represenet its sub-units. But, in any
case, at most one device interface shall be allowed for any given bus object.
The name of device interface shall start with "org.alljoyn.Hae.Device". Table
below shows the standard device types for the HAE Service Framework and their
minimum required shared interfaces.

| Device Type | Description                                        | Minimum Mandatory Requirements on Shared Interfaces|
|-------------|----------------------------------------------------|----------------------------------------------------|
|Refrigerator|Device that consists of  multiple compartments of a fridge or a freezer and eventually other auxiliary compartment like an ice maker.|At least, two pairs of {TargetTemperature, RepresentedTemperature}|
|Fridge|Device that stores food at temperatures which are a few degrees above the freezing point of water.|TargetTemperature, RepresentedTemperature|
|Freezer|"Device that stores food at temperatures which are a few degrees below the freezing point of water (typically about -18 °C), so the food itself is safe indefinitely.|TargetTemperature, RepresentedTemperature|
|Ice Maker|Device that makes ice. It exists as a sub-unit inside a refrigerator or as a standalone-device.| None |
|Air Conditioner|Device that alters the properties of air (primarily temperature and humidity) to more comfortable conditions|OperationalControl, TargetTemperature, RepresentedTemperature, WindStrength|
|Humidifier|Device that increases air humidity (moisture) in a single room or an entire building.|TargetHumidity, RepresentedHumidity or RepresentedHumidityLevel|
|Dehumidifier|Device that decreases air humidity (moisture) in a single room or an entire building.|TargetHumidity,  RepresentedHumidity or RepresentedHumidityLevel|
|Air Purifier|Device that has a filter that removes dust from the air.|Filter Status|
|Electric Fan|Traditional style fan usually with blades visible from outside.|WindStrength|
|Air Quality Monitor|Device that checks and reports the air quality.|None|
|Thermostat|Control unit that senses the temperature of a system so that the system's temperature is maintained near a desired set point. The thermostat does this by switching heating or cooling devices on or off or regulating the flow of a heat transfer fluid as needed to maintain the correct temperature.|OperationalControl, TargetTemperature, RepresentedTemperature|
|Washer|Device that washes laundry such as clothing and sheets|OperationalControl, OperationalTime|
|Dryer|"Device that removes moisture from a load of clothing and other textiles usually shortly after they are washed in a washer.|OperationalControl, OperationalTime|
|Washer Dryer|Device that executes the operations of both a washer and a dryer in a single cavity.|OperationalControl, OperationalTime|
|Dish Washer|Device that clean dishes and eating utensils.|OperationalControl, OperationalTime|
|Oven|Device that roasts and heats food in a complete stove|Target Temperature, Represented Temperature|
|Robot Cleaner|An autonomous robotic vacuum cleaner that has intelligent programming and a limited vacuum cleaning system|OperationalControl|
|TV|Television set with integrated capabilities that offers more advanced computing ability and connectivity.|Channel, VolumeControl, AVInput|
|Cooker Hood|"Home appliance that usually hangs above the stove or cooktop and it is used to removes airborne grease, combustion products, fumes, smoke, odours, heat, and steam from the air by evacuation of the air and filtration"|None|
|Cooktop|Home appliance with a flat framework used to place pots to be heated so the food inside is cooked|None|

#### Device hierarchy and capability

AllJoyn bus object structure carries both the hierarchy and the capability
information. A controller can find device hierarchy and capabilities in the
discovery phase via an About announcement which conveys the bus object
description. Device interfaces reveal the hierarchical relationship between
the root and its children devices. Along with the device interfaces, the
shared interfaces provide the device capability information.
Figure4 illustrates an example AllJoyn representation for a refrigerator.

![](hae_device_hierarchy.png)
Figure4: Device model for refrigerator

A refrigerator consists of three children device Freezer, Fridge and Ice Maker.
The refrigerator allows to change its target temperature and display the current
temperature for its freezer and fridge, respectively. In addition to that, it
has an additional capability of ice making and this capability can be
independently controlled.

##### Semantic relationship

Hierarchical relationship between bus objects/interfaces will be translated into
their semantic relationship. The same temperature related interfaces can be
shared between the Freezer and the Fridge. The semantic meaning of those two
temperatures can be identified by the name of a device interface to which they
belong.


### Discovery

HAE devices are discovered via an AllJoyn About announcement. Each HAE device
uses the About feature to announce basic device information like device
name, manufacturer and model name. In the additional discovery phase, a
controller can recognize hierarchy and capabilities of the HAE device via list
of object paths and interface names. For example, if object descriptions include
refrigerator device interface, a controller can be aware of  this device as a
refrigerator. Also a controller can get more detailed device information such as
corporate brand and product brand via common interface of the HAE Service
Framework in this phase.

#### Discovery call flow
Figure5 illustrates a call flow for a HAE device.

![](hae_discovery_call_flow.png)
Figure5: Discovery call flow

