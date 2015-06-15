# org.alljoyn.Hae.Channel version 1

## Specification

|            |                                                                |
|------------|----------------------------------------------------------------|
| Version    | 1                                                              |
| Annotation | org.alljoyn.Bus.Secure = true                                  |


### Properties

#### ChannelId

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | string                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Current channel ID.

#### TotalNumberOfChannels

|            |                                                                |
|------------|----------------------------------------------------------------|
| Type       | uint16                                                         |
| Access     | read-only                                                      |
| Annotation | org.freedesktop.DBus.Property.EmitsChangedSignal = true        |

Total number of scanned channels.

### Methods

#### GetChannelList (startingRecord, numRecords) -> (listOfChannelInfoRecords)

Retrieve the list of channels supported by the TV. This operation allows to get
the number of ChannelInfoRecords from the starting record number.

Input arguments:
  * **startingRecord** --- uint16 --- Build the list from this record number.
    If the starting Record is out of range, then an error shall be returned.
  * **numRecords** --- uint16 --- Only generate at most this many records. If the
    available number of channels is less than numRecords, then the controllee device
    shall return the available channel list without returning an error.

Output arguments:
  * **listOfChannelInfoRecords** --- ChannelInfoRecord[] --- List of channel information
    records.

Errors raised by this method:
  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

#### UpChannel ()

Move up to the next available channel.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

#### DownChannel ()

Move down to the next available channel.

Input arguments: None.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

#### ChangeChannel (channelId)

Change channel using channelId.

Input arguments:
  * **channelId** --- sting --- The value corresponds to the unique channel ID
    in ChannelInfoRecord.

Output arguments: None.

Errors raised by this method:
  * org.alljoyn.Hae.Error.InvalidValue --- Value not supported
  * org.alljoyn.Hae.Error.NotAcceptableDueToInternalState --- Value is not acceptable
    due to internal state

### Signals

#### ChannelListChanged
|              |             |
|--------------|-------------|
| Signal Type  | sessioncast |

The channel list has changed.

Output arguments: None.

### Named Types

#### struct ChannelInfoRecord

  * **channelID** --- string --- The unique channel ID.
  * **channelMode** --- byte --- The enumeration below lists channel mode.
    * Terrestrial : 1
    * Cable : 2
    * Satellite : 3
    * Common Interface Plus : 4 (DVB only)
  * **channelNumber** --- string --- The display channel number in the device.
    ex) 11-2, 7, 9-1
  * **channelName** --- string --- the channel short name which is user friendly name.
    ex) CNN, NHK, KBS

### Interface Errors

The method calls in this interface use the AllJoyn error message handling feature
(`ER_BUS_REPLY_IS_ERROR_MESSAGE`) to set the error name and error message.
The table below lists the possible errors raised by this interface.

| Error name                                            | Error message                                 |
|-------------------------------------------------------|-----------------------------------------------|
| org.alljoyn.Hae.Error.InvalidValue                    | Value not supported                           |
| org.alljoyn.Hae.Error.NotAcceptableDueToInternalState | Value is not acceptable due to internal state |

## References

  * The XML definition of the [Channel interface](Channel-v1.xml)
