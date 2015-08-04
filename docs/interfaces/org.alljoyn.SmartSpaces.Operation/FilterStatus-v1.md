# org.alljoyn.SmartSpaces.Operation.FilterStatus version 1

## Theory of Operation


This interface provides the status of a filter.  It is intended to be part of a 
larger object that might have multiple filters.  Example a refrigerator with a 
water filter and odor filter.
The _producer_ has one or more filters and implements a separate interface for 
each filter.  The _consumer_ is an application that is interested in the state 
of the filter.  Possibly to provide an email or push notification to a consumer 
when a filter needs to be replaced.  (The consumer notification portion of the 
use case is outside the scope of AllJoyn HAE).

## Specification

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Version               | 1                                                                     |
| Annotation            | org.alljoyn.Bus.Secure = true                                         |

### Properties

#### FilterType

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

0 = Water
1 = Air


#### IsCleanable

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

If true a new filter does not need to be ordered, just replace

#### OrderPercent

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

If non-zero the lifetime percentage at which ordering is recommended.  
If 0 filter is cleanable and there is no reason to order.

#### ExpectedDaysLife

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | integer                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

Expected Days Life of filter to turn percent into days remaining.  
If -1 there is no predicted life.  
If 0 the life is <1 day

#### FilterStatus

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Lifespan Remaining in percentage (100 - 0).  0 indicates replace/clean. 
OrderPercent indicates order.  A simple device may just implement 100/0 or 
100/OrderPercent/0 instead of implementing the entire range of values

### Methods

No methods are implemented by this interface.

### Signals

No signals are emitted by this interface.

### Named Types

No Named Types are required by this interface.

### Interface Errors

No unique errors are associated with this interface.

## References

* The XML definition of the [FilterStatus interface](FilterStatus-v1.xml)
