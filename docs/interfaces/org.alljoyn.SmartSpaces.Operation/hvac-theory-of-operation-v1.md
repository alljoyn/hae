DRAFT

This theory of operation explains the interaction of various interfaces to 
assemble an air conditioner or thermostat.


AC picture.


The AC Will need to implement several interfaces, they can all co-exist on the 
same bus object:

CurrentTemperature
TargetTemperature
ClmateControlMode
HvacFanMode   (optional - required to have a fan mode other than auto).
            Votes on if this can be optional?
WindStrength (optional -only required if multiple fan speeds available).

The minimum supported modes for ClimateControlMode are Off & Cool.
The minimum supported modes for HvacFanMode is Auto.  Auto support only is 
assumed if interface is not implemented.


The simplest Thermostat with two temps.  A heat only or cool only 
thermostat would look like the AC.  



Thermostat Picture


This thermostat has just heat/cool and a 1 speed fan.

Mimimum Interfaces:
The root thermostat bus object has 3 interfaces that apply to the device.  It 
also has two child bus objects /Heat and /Cool.  The minimum required interface 
are:

CurrentTemperature
ClmateControlMode
HvacFanMode   (optional ??).
/Heat  bus object
        TargetTemperature Interface (this target temperature is used when ClimateControlMode = Heat)
/Cool  bus object
        TargetTemperature Interface (this target temperature is used when ClimateControlMode = Heat)

The bus object children names match up with the names of the modes that apply.


The most complex structure.



Thermostat Picture 2




Consider a PTAC (Packaged Terminal Air Conditioner) that supports Heat/Cool/Auto
/AuxillaryHeat and a ResourceSavingsMode (Often called Home/Away, Day/Night,
Occupied/Unoccupied or EnergySavings).  This device also supports two fan 
speeds and a circulate mode for the fan.

The root thermostat bus object has 5 interfaces that apply to the device.  It 
also multiple child bus objects.  The child bus objects and interfaces are:

CurrentTemperature
ClmateControlMode
HvacFanMode
WindStrength
EnergySavingsMode
/Heat  bus object
        TargetTemperature Interface (this target temperature is used when ClimateControlMode = Heat)
/Heat/ResourceSaving 
        TargetTemperature Interface (this target temp is used when ReSourceSavings is enabled)
/Cool  bus object
        TargetTemperature Interface (this target temperature is used when ClimateControlMode = Heat)
/Cool/ResourceSaving 
        TargetTemperature Interface (this target temp is used when ReSourceSavings is enabled)
/AuxillaryHeat
/AuxiliaryHeat/ResourceSaving
        If a separate AuxillaryHeat setting is desired then these could be populated.  If non-existat default to "Heat"
/Auto      
/Auto/ResourceSaving
        If a single auto setpoint was desired these could be populated. [just for SK]  If not default to "Heat" and "Cool"

The bus object children names match up with the names of the modes that apply, just like the simple example.


Wind Interactions.

There is an Auto in HvacFanModes and an Auto in WindStrength
This causes some confusion, but they are two different items.  One controls how
often the fan is on (Duty Cyle).  The other controls the speed of operation.
Consider 

|  HvacFanMode | WindStrength | WindStrength Auto | Behavior         |
|--------------|--------------|-------------------|------------------|
| Continuous   |   1          |   Off             | Fan Always on Low |
|--------------|--------------|-------------------|-------------------|
| Continuous   |   1          |   On              | Fan Always on Speed Varies |
|--------------|--------------|-------------------|-------------------|
| Continuous   |   2          |   Off             | Fan Always on High |
|--------------|--------------|-------------------|-------------------|
| Continuous   |   2          |   On              | Fan Always on Speed Varies |
|--------------|--------------|-------------------|------------------|
| Auto         |   1          |   Off             | Fan Intermittent on Low |
|--------------|--------------|-------------------|-------------------|
| Auto         |   1          |   On              | Fan Intermittent on Speed Varies |
|--------------|--------------|-------------------|-------------------|
| Auto         |   2          |   Off             | Fan Always on High |
|--------------|--------------|-------------------|-------------------|
| Auto         |   2          |   On              | Fan Always on Speed Varies |
|--------------|--------------|-------------------|-------------------|
