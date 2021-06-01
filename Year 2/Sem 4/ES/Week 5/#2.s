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
    MOV R0,#5
    MOV R1,#1
    BL FACT
    LDR R0, =DST
    STR R1, [R0]

HERE B HERE

FACT CMP R0,#1
    BEQ L
    MUL R1,R1,R0;
    SUB R0,R0,#1
    PUSH {LR}
    BL FACT

L1 POP {LR}
    BX LR

L BX LR

AREA sto, DATA, READWRITE
DST DCD 0x0
END