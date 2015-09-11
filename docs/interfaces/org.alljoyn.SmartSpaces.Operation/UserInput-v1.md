# org.alljoyn.SmartSpaces.Operation.UserInput version 1

## Theory of Operation
This interface provides a capability to receive user input event from controller
device. This interface wraps [linux input subsystem](#Linux input subsystem)
which is based on [USB HUT(HID Usage Tables) 1.12](#USB HUT). Therefore, this
interface supports a generic mechanism to inject user input events from various
controllers such as key board, mouse, touch screen, remote controller, key pad,
and joy stick, etc.

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |

### Properties

#### Version

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Interface version

#### SupportedEvents

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | SupportedInputEvent[]                                          |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

List of supported input events by a device.

### Methods

#### InjectEvents (inputEvents)

|            |                                                                |
|------------|----------------------------------------------------------------|
| Annotation | org.freedesktop.DBus.Method.NoReply = true                     |

Send the user input events from controller device. This method is based on
*input_inject_event()* function in [linux input subsystem](#Linux input subsystem).
When occurred multiple events simultaneously, send an array of input events.
The reply is not needed. If the controllee doesn't support event code, it just
ignores the event code without returning error.

Input arguments:
  * **inputEvents** --- InputEvent[] --- input events

Output arguments: None.

### Signals

No signals are emitted by this interface.

### Named Types

#### struct InputEvent

**InputEvent** structure

  * **type** --- uint16 --- Event types are groupings of codes under a logical
    input construct. Each type has a set of applicable codes to be used in
    generating events.
  * **code** --- uint16 --- Event codes define the precise type of event.
  * **value** --- int32 --- Event values used to describe detailed operation or
    status such as describing the distance of mouse movement or a button is pressed.

This named type is based on *input_event* structure in
"input.h" header file of [linux input subsystem](#Linux input subsystem).
Refer to [linux input event codes](#Linux input event codes) for more details.

#### struct SupportedInputEvent

**SupportedInputEvent** structure

  * **type** --- uint16 --- Event types.
  * **code** --- uint16 --- Event codes.
  * **min** --- int32 --- Minimum value of event.
  * **max** --- int32 --- Miximum value of event.

This named type is used to retrieve supported input events.

## Examples

Event types

| Event Type   | Value |
|--------------|-------|
| EV_KEY       | 0x01  |
| EV_REL       | 0x02  |
| EV_ABS       | 0x03  |


Event code of yeys and buttons when event type is *EV_KEY*

| Event Code       | Value      |
|------------------|------------|
| KEY_RESERVED     | 0x0        |
| KEY_Q            | 0x10       |
| KEY_W            | 0x11       |
| KEY_E            | 0x12       |
| KEY_R            | 0x13       |
| KEY_T            | 0x14       |
| KEY_Y            | 0x15       |
| KEY_LEFTSHIFT    | 0x2A       |
| KEY_RIGHTSHIFT   | 0x2B       |
| KEY_MUTE         | 0x71       |
| KEY_VOLUMEDOWN   | 0x72       |
| KEY_VOLUMEUP     | 0x73       |
| BTN_MOUSE        | 0x110      |
| BTN_LEFT         | 0x110      |
| BTN_RIGHT        | 0x111      |
| BTN_MIDDLE       | 0x112      |
| KEY_CHANNELUP    | 0x192      |
| KEY_CHANNELDOWN  | 0x193      |


Event code of relative axes when event type is *EV_REL*

| Event Code       | Value      |
|------------------|------------|
| REL_X            | 0x0        |
| KEY_Y            | 0x1        |
| KEY_Z            | 0x2        |
| KEY_WHEEL        | 0x8        |

### Examples 1 : Key Board
Getting supported input event infomation of key board
```
Get_Property(SupportedEvents)
```
Results :
> SupportedEvents[0].type : EV_KEY
> SupportedEvents[0].code : KEY_Q
> SupportedEvents[0].min : 0
> SupportedEvents[0].max : 1
> ...
> SupportedEvents[n].type : EV_KEY
> SupportedEvents[n].code : KEY_LEFTSHIFT
> SupportedEvents[n].min : 0
> SupportedEvents[n].max : 1
> ...

Pressing *Q* key
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_Q;
inputEvents[0].value = 1;
InjectEvent(inputEvents);
```

Releasing *Q* key
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_Q;
inputEvents[0].value = 0;
InjectEvent(inputEvents);
```

Pressing *Q* key with *Left Shift* key simultaneously
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_Q;
inputEvents[0].value = 1;
inputEvents[1].type = EV_KEY;
inputEvents[1].code = KEY_LEFTSHIFT;
inputEvents[1].value = 1;
InjectEvent(inputEvents);
```

### Examples 2 : Mouse

Moving mouse to (120, -53).
```
inputEvents[0].type = EV_REL;
inputEvents[0].code = REL_X;
inputEvents[0].value = 120;
inputEvents[1].type = EV_REL;
inputEvents[1].code = REL_Y;
inputEvents[1].value = -53;
InjectEvent(inputEvents);
```

Pressing left button
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = BTN_LEFT;
inputEvents[0].value = 1
InjectEvent(inputEvents);
```

Releaseing left button
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = BTN_LEFT;
inputEvents[0].value = 0
InjectEvent(inputEvents);
```

### Examples 3 : Touch Screen

Getting supported input event infomation of touch screen
```
Get_Property(SupportedEvents)
```
Results :
> SupportedEvents[0].type : EV_ABS
> SupportedEvents[0].code : ABS_X
> SupportedEvents[0].min : 0
> SupportedEvents[0].max : 1920
> SupportedEvents[1].type : EV_ABS
> SupportedEvents[1].code : ABS_Y
> SupportedEvents[1].min : 0
> SupportedEvents[1].max : 1080

Touching screen at (950, 658)
```
inputEvents[0].type = EV_ABS;
inputEvents[0].code = ABS_X;
inputEvents[0].value = 950;
inputEvents[1].type = EV_ABS;
inputEvents[1].code = ABS_Y;
inputEvents[1].value = 658;
InjectEvent(inputEvents);
```

### Examples 4 : Remote Controller

Getting supported input event infomation of remote conroller
```
Get_Property(SupportedEvents)
```
Results :
> SupportedEvents[0].type : EV_KEY
> SupportedEvents[0].code : KEY_VOLUMEDOWN
> SupportedEvents[0].min : 0
> SupportedEvents[0].max : 1
> ...
> SupportedEvents[m].type : EV_KEY
> SupportedEvents[m].code : KEY_CHANNELUP
> SupportedEvents[m].min : 0
> SupportedEvents[m].max : 1
> ...
> SupportedEvents[n].type : EV_KEY
> SupportedEvents[n].code : KEY_MUTE
> SupportedEvents[n].min : 0
> SupportedEvents[n].max : 1
> ...


Pressing volume down key
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_VOLUMEDOWN;
inputEvents[0].value = 1;
InjectEvent(inputEvents);
```

Pressing channel up key
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_CHANNELUP;
inputEvents[0].value = 1;
InjectEvent(inputEvents);
```

Pressing volume mute key
```
inputEvents[0].type = EV_KEY;
inputEvents[0].code = KEY_MUTE;
inputEvents[0].value = 1;
InjectEvent(inputEvents);
```
## References

  * The XML definition of the [User Input interface](UserInput-v1.xml)
  * <a name="Linux input subsystem" href="https://git.kernel.org/cgit/linux/kernel/git/stable/linux-stable.git/tree/include/uapi/linux/input.h"> Linux input subsystem </a>
  * <a name="Linux input event codes" href="https://www.kernel.org/doc/Documentation/input/event-codes.txt"> Linux input event codes </a>
  * <a name="USB HUT" href="http://www.usb.org/developers/hidpage#HID_Usage"> USB HUT(HID Usage Tables) 1.12 </a>