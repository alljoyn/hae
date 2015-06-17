# Theory of Operation

This document describes the common theory of operation for HAE project
interfaces which describe the appliances in to "fabric care" area/cluster.
These appliances are:

  * Dryers
  * Washers
  * Washer-Dryers
  * composed appliances which implements Washers and Dryers as sub-units

In a WasherDryers the washing and drying processes are made using the same
cavity at different times.
In composed appliances the processes are made in different cavities.

So the information of this documents are valid for the following interfaces:

  * **org.alljoyn.Hae.Device.Dryers** --- to represent Dryer appliances and
    sub-units
  * **org.alljoyn.Hae.Device.Washers** --- to represent Washer and sub-units
  * **org.alljoyn.Hae.Device.WasherDryers**  --- to represent WasherDryers

The above interfaces provide a set of properties and methods, which let the
 _producer_ (i.e. the appliance) to be monitored and controlled by a _consumer_
(usually it is a remote application).

Washers and Dryers executes their specific operations using cycle. These cycle
are made of following phases:

  * **Pre-washing** --- the appliance is executing a preliminary wash, to remove
    some particular dirt (not used by Dryers)
  * **Washing** --- the appliance is executing the main wash (not used by
    Dryers)
  * **Rinsing** --- the appliance is rinsing the clothes to remove soap (not
    used by Dryers)
  * **Spinning** --- the appliance is spinning to partially dry the clothes (not
    used by Dryers)
  * **Steam** --- the appliance is treating the clothes with steam
  * **Drying** --- the appliance is drying the clothes (not used by Washers)
  * **Cooling** --- the appliance is reducing the internal temperature (not used
    by Washers)
  * **AntiCreasing** --- the appliance is drying executing some operation to
    prevent the formation of creases in the clothes (not used by Washers)

Specific appliance cycles can execute just a sub-set of above phases.

## References

  * The definition of the [Dryer interface](Dryer-v1)
  * The definition of the [Washer interface](Washer-v1)
  * The definition of the [WasherDryer interface](WasherDryer-v1)
  