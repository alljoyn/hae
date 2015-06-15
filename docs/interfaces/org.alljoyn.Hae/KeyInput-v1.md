# org.alljoyn.Hae.KeyInput version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = false                                 |

### Methods

#### KeyInput (keyCode)

Send the key code of the pressed key input. The reply is not needed. If the controllee
doesn't support a key input, it just ignore it without returning error. Regarding to
Key Code enumeration, follow the existing standard "CEA-2014-B - CE-HTML Annex F"

Input arguments:
  * **keyCode** --- uint16 --- the key code of the pressed key input

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

### Signals

No signals are emitted by this interface.

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## Examples
Sample Key List (keys using CEA-2014-B - CE-HTML Annex F spec.)

| Virtual Key Name | Function Name       | Key Code |
|------------------|---------------------|----------|
| VK_POWER         | Power               | 409      |
| VK_0 to VK_9     | Numeric Keys 0 to 9 | 48-57    |
| VK_LEFT          | Cursor Left         | 37       |
| VK_UP            | Cursor Up           | 38       |
| VK_RIGHT         | Cursor Right        | 39       |
| VK_DOWN          | Cursor Down         | 40       |
| VK_ENTER         | Enter (OK)          | 13       |
| VK_HOME          | Home                | 36       |
| VK_CHANNEL_UP    | Channel Up          | 427      |
| VK_CHANNEL_DOWN  | Channel Down        | 428      |
| VK_VOLUME_UP     | Volume Up           | 447      |
| VK_VOLUME_DOWN   | Volume Down         | 448      |
| VK_MUTE          | Mute                | 449      |
| VK_GUIDE         | Guide               | 458      |
| VK_BACK          | Back                | 461      |
| VK_MENU          | Menu                | 462      |


## References

  * The XML definition of the [KeyInput interface](KeyInput-v1.xml)
  * [CEA-2014-B](https://www.ce.org/Standards/Standard-Listings/R7-Home-Network-Committee)
