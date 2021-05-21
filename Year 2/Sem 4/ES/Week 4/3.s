    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    AREA mydata, DATA, READONLY
    VAL1 DCD 0x12345678
    VAL2 DCD 0x00121743
    AREA strvar, DATA, READWRITE
    DST DCD 0x0
    ALIGN
    AREA mycode, CODE, READONLY
    EXPORT Reset_Handler
    ENTRY

Reset_Handler
    LDR R1, =VAL1
    LDR R1, [R1]
    LDR R2, =VAL2
    LDR R2, [R2]
    MOV R8, #1
    MOV R9, #10
    MOV R7, #0
START
    AND R4, R1, #0xF
    AND R5, R2, #0xF
    ADD R6, R4, R5
    MUL R6, R6, R8
    ADD R7, R6
    MUL R8, R8, R9
    LSR R1, #4
    LSR R2, #4
    CMP R1, #0
    BNE START
    MOV R1, R7
    MOV R7, #0
    MOV R10, #0
MNS
    MOV R3, #0
    MOV R4, #0
    MOV R6, #10
    MOV R5, R1DSA CMP R5, R6
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
    LDR R1, =DST
    STR R10, [R1]

STOP 
    B STOP
    END