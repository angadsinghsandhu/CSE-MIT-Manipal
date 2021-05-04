    AREA RESET, DATA, READONLY
    EXPORT __Vectors

__Vectors
        DCD 0X10001000
        DCD Reset_Handler
        ALIGN
        AREA mycode, CODE, READONLY 
        ENTRY
        EXPORT Reset_Handler

Reset_Handler
        LDR R0, =SRC          ; Source memory base address 
        LDR R1, =DST          ; Destination memory base address
        LDR R3, [R0]          ; Loading value to temporary register
        STR R3, [R1]          ; Storing the value at destination memory

STOP
        B STOP
        AREA mydata, DATA, READWRITE

SRC DCD 8

DST DCD 0
        END

