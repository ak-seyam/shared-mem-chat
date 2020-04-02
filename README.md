# Inter process communication chat 

## how it works
* acknowledgement
* receiver waits for message [the string inside a memory] to be anything rather than nullend
* sender change the message string
* recevicer print the messege
* sender waits for completion character
* reciver send compilition character
* a little stall for sync
* done
