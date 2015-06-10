# org.alljoyn.Hae.OperationalTime version 1

## Theory of Operation

This interface provides information about the time when the appliance executes
its operations (i.e. when it starts, when it ends ...).
Note that an appliance executes some operation in order to carry on a task;
in general these operation can have following characteristic:
* they have a start time;
* they have a end time;
* they can be set to start after a delay.
So it is useful to describe the appliance behavior in term of timers and
counters which represent the above features.
Note that a specifIC appliance can support just a subset of these features.

The below properties are described with a signed data type for following reasons:
* the same data type is used for every time properties
* negative values are reserved for some special meanings
* in case negative relative time values can be use in the future to describe the
past: i.e. in ">0" means "in the future", "<0" could mean "in the past".

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = false                                        |

This interface has no control properties and does not require security.  
The interface is designed to be included in a higher level device which can
provide application layer security for doors that have a high security value.

### Properties

#### TargetTimeToStart

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the time or delay which has been set before appliance starts its
operation. It is supposed to be down counting.
It is a relative time with a resolution of one second.
The special values 0x80000000 (i.e. the lowest representable value with int32)
is used to indicate:
* it is not supported by the specific appliance
* it is not applicable due to appliance operation internal state
* no setting has been applied on it.  

For an example on how the property works, see the below line chart.
![TargetTimeToStart][TargetTimeToStart]

[TargetTimeToStart]: TargetTimeToStart_chart.png

#### TargetTimeToStop

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the time which has been set to stop appliance operation. It is
supposed to be down counting.
It is a relative time with a resolution of one second.
The special values 0x80000000 (i.e. the lowest representable value with int32)
is used to indicate:
* it is not supported by the specific appliance
* it is not applicable due to appliance operation internal state
* no setting has been applied on it.  

For an example on how the property works, see the below line chart.
![TargetTimeToStop][TargetTimeToStop]

[TargetTimeToStop]: TargetTimeToStop_chart.png

#### EstimatedTimeToEnd
|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the time to the ends of appliance operation.  
It is a relative time with a resolution of one second.
It is calculated at runtime by device itself during the execution of its
operation; at the begin of operation it should be equal to TargetTimeToStop, but
then it is recalculated and may differentiate from that one because of 
environmental conditions (e.g. in a Washing Machine the real duration depends on
water temperature, load ...so the duration showed at selection is just a
forecast).
The special values 0x80000000 (i.e. the lowest representable value with int32)
is used to indicate:
* it is not supported by the specific appliance
- it is not applicable due to appliance operation internal state,
- no setting has been applied on it.

For an example on how the property works, see the below line chart.
![EstimatedTimeToEnd][EstimatedTimeToEnd]

[EstimatedTimeToEnd]: EstimatedTimeToEnd_chart.png

#### RunningTime
|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates the elapsed time from the start of the operation. It is supposed to
be up counting.
It is a relative time with a resolution of one second.
It is calculated at runtime by device itself during the execution of its
operation.
The special values 0x80000000 (i.e. the lowest representable value with int32)
is used to indicate:
* it is not supported by the specific appliance
- it is not applicable due to appliance operation internal state,
- no setting has been applied on it.

For an example on how the property works, see the below line chart.
![RunningTime][RunningTime]

[RunningTime]: RunningTime_chart.png

#### TargetDuration

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | int32                                                                 |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

It indicates a time, representing the Target duration of the operation as per 
user selection. 
It is a relative time with a resolution of one second.
Before the start of the operation, it is equal to the difference between 
TargetTimeToStop and TargetTimeToStart.
The special values 0x80000000 (i.e. the lowest representable value with int32)
is used to indicate:
* it is not supported by the specific appliance
- it is not applicable due to appliance operation internal state,
- no setting has been applied on it.

For an example on how the property works, see the below line chart.
![TargetDuration][TargetDuration]

[TargetDuration]: TargetDuration_chart.png

### Methods

#### SetTargetTimeToStart (TargetTimeToStart)

|                       |                                             |
|-----------------------|---------------------------------------------|
| Annotation            | org.freedesktop.DBus.Method.NoReply = true  |

Execute the setting of the TargetTimeToStart propriety.
It is called when a user wants that a device operation starts at a defined time.
If a _producer_ device can not execute the setting or doesn't support the 
feature appropriate errors shall be returned.

Input arguments:

  * **TargetTimeToStart** --- int32 --- time to be set

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported
    

#### SetTargetTimeToStop (TargetTimeToStop)

|                       |                                             |
|-----------------------|---------------------------------------------|
| Annotation            | org.freedesktop.DBus.Method.NoReply = true  |


Execute the setting of the TargetTimeToStop propriety.
It is called when a user wants that a device operation (i.e. a time limited 
operation) stops at a defined time.
If a _producer_ device can not execute the setting or doesn't support the 
feature appropriate errors shall be returned.

Input arguments:

  * **TargetTimeToStop** --- int32 --- time to be set

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported


### Signals

No signals are emitted by this interface.

### Interface Errors
The method calls in this interface use the AllJoyn error message handling
feature (`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error
message.
The table below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |
| org.alljoyn.Hae.Error.InvalidValue                    | Value not supported                           |


## References
  * The XML definition of the [OperationalTime interface](OperationalTime-v1.xml)
