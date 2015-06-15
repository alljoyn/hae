## Theory of Operation
This document describes the theory of operation how to the Home Appliances and
Entertainment Service Framework should work. It contains the device model,
semantic relationship for interfaces and the standard device types for the HAE
Service Framework.

### Overview

The goal of the HAE Service Framework is to standardize functionalities and
interfaces for Home Appliances & Entertainment(HAE) category devices and provide
independent interfaces with a control UI. This framework develops the common way
of controlling and monitoring HAE category devices, regardless of device
manufacturers. Furthermore, The framework enable to control each appliance in
the background and allow developers to make proper user experience for devices
with different screen size and shape.

#### Purpose

##### Cross-vendor interoperability
The standardization of AllJoyn interfaces for appliances is mightily important
to establish the cross-vendor interoperability. These standard interfaces will
enable to control devices from different vendors using an identical controller.
Such standard interfaces define common functionalities among devices under the
same categories by each vendor. This approach provides common interfaces and
functionalities to developers but also the same user experiences to end-users.
It will guarantee the interoperability of controller application for each vendor.

##### Background Control & Monitoring

AllJoyn provides a control panel service to control devices but end-user only
can start controlling the device after a control panel must be launched on
screen. To support various automation services for IoT, background control and
monitoring should be possible. Users do not need to see and touch their mobile or
smart watch. Voice or text based control and monitoring will be enabled. Even
machine to machine control and interaction can be possible using these interfaces.

##### Tailor-made UI for each controller screen

Using the control panel might be unsuitable for smart watch or none-screen
devices. With a single control panel UI data, it is not easy to satisfy all the
various screen sizes and shapes of the controller devices such as smart watch,
phone, tablet and TV. If the HAE Service Framework defines the standard interfaces,
controller application developers would implement their applications with different
screen sizes and shapes. The HAE Service Framework is targeted to provide
predefined device functionalities so that controller application developers can
deliver tailor-made UI for each controller screen to end-users.

#### Usecases

The HAE Service Framework has two types of usecase as monitoring and controlling.
A HAE controller monitors the current operational status of the HAE controllee.
And the controller is warned about interested situation of the HAE controllee.
A HAE controller interacts with one or more HAE controllees to activate operations.
Figure1 illustrates the usecases between the HAE controllee and the HAE controller.

![](hae_usecase.png)
Figure1: Usecases of controlling and monitoring

#### Overall Architecture

The Controllee App works on the home appliances such as a refrigerator, a air 
conditioner or a washer. The Controller App is an application software that runs
on the user’s terminal such as a smart phone or a tablet, and communicates with
a HAE controllee through the AllJoyn bus. The HAE Service Framework must be
implemented by an application on a controllee. And the Controller App must be 
implemented using the Controller API of the HAE Service Framework. Figure2 
illustrates the relationship between a controllee app and controller app. 

![](hae_overall_architecture.png)
Figure2: HAE service framework architecture within the AllJoyn framework

### Device Model
AllJoyn representation of HAE device model follows the AllJoyn bus object structure
and for that, 3 categories of interfaces are defined. AllJoyn bus object structure
carries both the hierarchy and the capability information. In the HAE Service Framework,
this hierarchy reveals the relationship between a device and children devices.
Figure3 illustrates the general device model for HAE devices. 

![](hae_device_model.png)
Figure3: HAE device model

#### 3 Categories of interfaces

##### Common Interface
The Common Interface is a common AllJoyn interface for all HAE devices. The name of
common interface is fixed as "org.alljoyn.Hae". There shall be one and only one common
interface under the root HAE bus object.

##### Shared Interface
The Shared Interface can be shared or reused by HAE devices. Minimum mandatory requirements
on the shared interfaces shall be specified for each HAE device type to have.
The name of shared interface shall start with "org.alljoyn.Hae.Shared".

##### Device Interface
The Device Interface indicates whether the bus object it belongs to a HAE device or not.
Under a root bus object, there shall be one and only one device interface. Under a
given bus object, at most one device interface shall be allowed. Each HAE device types
shall have one and only one device interface. The name of device interface shall start
with "org.alljoyn.Hae.Device". Table below shows the standard device types for the HAE
Service Framework.

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
discovery phase via an announcement which includes array of pairs consisting of
object path and interface name. Device interfaces reveal the hierarchical
relationship between the root and its children devices. Along with the device
interfaces, the shared interfaces provide the device capability information.
An object path of given bus object cannot figure out their capability or semantic
meaning. Capabilities and semantic meaning of each interface only can be expressed
by interface name and their hierarchy. Figure4 illustrates an example of the
device model for a refrigerator.

![](hae_device_hierarchy.png)
Figure4: Device model for refrigerator

A refrigerator consists of three children device Freezer, Fridge and Ice Maker.
The refrigerator allows to change its target temperature and display the current
temperature for its freezer and fridge, respectively. In addition to that, it
has an additional capability of ice making and this capability can be independently
controlled. 

##### Semantic relationship

Hierarchical relationship between bus objects/interfaces will be translated into
their semantic relationship. The same interfaces can be shared between the Freezer
and the Fridge. The semantic meaning of those two temperatures can be identified
by the name of a device-specific interface to which they belong.


### Discovery

HAE devices are discovered via an AllJoyn announcement of About feature. Each
HAE device uses the About feature to announce basic device information like device
name, manufacturer and model name. In the additional discovery phase, a controller
can recognize hierarchy and capabilities of the HAE device via list of object paths
and interface names. For example, if object descriptions include refrigerator device
interface, a controller can be aware of  this device as a refrigerator. Also a
controller can get more detailed device information such as corporate brand and
product brand via common interface of the HAE Service Framework in this phase.

#### Discovery call flow
Figure5 illustrates a call flow for a HAE device.

![](hae_discovery_call_flow.png)
Figure5: Discovery call flow

