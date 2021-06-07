    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    AREA mydata, DATA, READONLY
VAL DCD 0x12345678
    AREA strvar, DATA, READWRITE
DST DCD 0x0
    ALIGN
    AREA mycode, CODE, READONLY
    EXPORT Reset_Handler
    ENTRY

Reset_Handler
    LDR R1, =VAL
    LDR R1, [R1]
    LDR R2, = DST
    MOV R0, #0 
    MOV R4, #1 
    MOV R5, #10 
    B MSK

MSK AND R3, R1, #0xF 
    MUL R3, R3, R4
    ADD R0, R3
    MUL R4, R4, R5

    LSR R1, #4
    CMP R1, #0
    BNE MSK
    
    STR R0, [R2]

STOP B STOP
    END