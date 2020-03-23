<title>Manager Component Dictionary</title>
# Manager Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|MGR_IS_ENABLED|0 (0x0)|Do a math operation| | |
| | | |isEnabled|bool||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|MGR_IS_ENABLED|0 (0x0)|bool|The first value|
|MGR_MSG|1 (0x1)|F32|The second value|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|MGR_MSG_RECV|0 (0x0)|| | | | |
| | | |messageRecv|bool||The val1 argument|
|MGR_MSG_SENT|1 (0x1)|| | | | |
| | | |messageSent|bool||The val1 argument|
|MGR_MSG_BLCKD|2 (0x2)|| | | | |
| | | |messageBlckd|bool||The val1 argument|
|DRVR_MSG_RECV|3 (0x3)|| | | | |
| | | |message|F32||The val1 argument|
