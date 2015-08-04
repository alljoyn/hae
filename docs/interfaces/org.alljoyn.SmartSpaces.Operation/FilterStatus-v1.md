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

#### FilterInformation

|            |                                                          |
|------------|----------------------------------------------------------|
| Type       | FilterData                                               |
| Access     | read-only                                                |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = false |

Holds information about the fiter sufficient to replace it.


#### IsCleanable

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | boolean                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

This is a static property of the filter.  If the property is true a new filter 
does not need to be ordered, just clean.

#### OrderPercent

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                  |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

If non-zero the lifetime percentage at which ordering is recommended.  
If 0 filter is cleanable and there is no reason to order.

#### FilterLifespanDays

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | integer                                                               |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = false              |

Day a new filter will last.  Used to convert percentage into days remaining.
If -1 there is no predicted life.
If 0 the life is less than 1 day

#### FilterLifeRemaining

|                       |                                                                       |
|-----------------------|-----------------------------------------------------------------------|
| Type                  | byte                                                                |
| Access                | read-only                                                             |
| Annotation            | org.freedesktop.DBus.Property.EmitsChangedSignal = true               |

Lifespan Remaining in percentage (100 - 0).  0 indicates replace/clean. 
OrderPercent indicates order.  A simple device may just implement 100/0 or 
100/OrderPercent/0 instead of implementing the entire range of values

### Methods


#### GetFilterDescription (languageTag) -> (description)

Get descriptive information about filter.  It is possible no information is 
provided as output (i.e. empty string is returned).

Input arguments:

* **languageTag** --- string --- language to be used in the output strings
using IETF language tags specified by RFC 5646.

Output arguments:

* **info** --- string --- the filter info

Errors raised by this method:

* org.alljoyn.LanguageNotSupported --- the language specified is not supported


### Signals

No signals are emitted by this interface.

### Named Types

#### struct FilterData

* **filterManufacturer** --- string
* **filterPartNumber** --- string
* **urlForOrdering** --- string
* **IsCleanable** --- boolean     
static property which indicates this is a cleanable filter.  
If false, it must be replaced when dirty.


### Interface Errors

The table below shows the possible raised by this inteface.

| Error name                             | Error message         |
|----------------------------------------|-----------------------|
| org.alljoyn.LanguageNotSupported       | the language specified is not supported      |

## References

* The XML definition of the [FilterStatus interface](FilterStatus-v1.xml)
