    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    AREA mydata, DATA, READONLY
    VAL DCD 0xAB34
    AREA strvar, DATA, READWRITE
    DST DCD 0x0
    ALIGN
    AREA mycode, CODE, READONLY
    EXPORT Reset_Handler
    ENTRY

Reset_Handler
    LDR R1, =VAL
    LDR R1, [R1]
    LDR R2, =DST
    MOV R7, #0
    MOV R10, #0
MNS
    MOV R3, #0
    MOV R4, #0
    MOV R6, #10
    MOV R5, R1
    DSA CMP R5, R6
BGE RSA
    B DDN
    RSA ADD R3, #1
    SUB R5, R6
    B DSA
    DDN MOV R4, R5
    LSL R4, R7
    ORR R10, R4
    MOV R1, R3
    ADD R7, #4
    CMP R1, #0x0
    BNE MNS
    STR R10, [R2]

STOP 
    B STOP
    END