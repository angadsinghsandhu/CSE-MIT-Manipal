    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0x10001000
    DCD Reset_Handler
    AREA mydata, DATA, READONLY
    VAL1 DCD 0x0025
    VAL2 DCD 0x0015
    AREA strvar, DATA, READWRITE
    DST DCD 0x0
    ALIGN
    AREA mycode, CODE, READONLY
    EXPORT Reset_Handler
    ENTRY

Reset_Handler
    LDR R1, =VAL1
    LDR R1, [R1]
    MOV R0, #0
    MOV R4, #1 
    MOV R5, #10 
    MOV R12, #0
    B MSK
CONT1
    MOV R10, R0
    LDR R1, =VAL2
    LDR R1, [R1]
    MOV R0, #0 
    MOV R4, #1
    MOV R5, #10
    MOV R12, #1
    B MSK
CONT2
    B DONE
    MSK AND R3, R1, #0xF
    MUL R3, R3, R4
    ADD R0, R3
    MUL R4, R4, R5
    LSR R1, #4
    CMP R1, #0
    BNE MSK
    CMP R12, #0
    BEQ CONT1
    BGT CONT2DONE
    MOV R1, R10
    MUL R2, R0, R1
    MOV R1, R2
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
    LDR R3, =DST
    STR R10, [R3]

STOP 
    B STOP
    END