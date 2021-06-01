    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0X10001000
    DCD Reset_Handler
    ALIGN
    AREA mycode,CODE,READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR R0,=NUM
    LDR R1,=KEY
    MOV R2,#0
    MOV R3,#9
    LDR R4,[R1]
    MOV R7,#4
    B LOOP

LOOP
    CMP R2,R3
    BHI HERE
    MUL R8,R2,R7
    LDR R5,[R0,R8]
    CMP R5,R4
    BEQ L
    ADD R2,R2,#1
    B LOOP

L
    LDR R6,=RESULT
    STR R2,[R6]     ;key index

HERE B HERE
NUM DCD 1,2,3,4,5, 6, 7, 8, 9, 10
KEY DCD 7
AREA mydata,DATA,READWRITE
RESULT DCD 0
END