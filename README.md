# tm4c-systick-multitasker
bare-metal multitasker that uses several timers and a state machine
## features

-state machine to switch between LEDs every 1500ms

-heartbeat LED that toggles every 500ms

-uart printing that transmits 'beat' every 4500ms

## requirements & setup
### hardware

-TM4C123GXL

### applications

-any cortex-m development environment, i used code composer studio

-putty configured for 115200 baud rate
