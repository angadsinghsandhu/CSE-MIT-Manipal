    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0X10001000
    DCD Reset_Handler
    AREA mydata,DATA,READWRITE
DST DCD 0
    AREA mycode,CODE,READONLY
    ENTRY
SRC DCD 1,2,3,4,5,6,7,8,9,10
    EXPORT Reset_Handler

Reset_Handler
        LDR R0,=SRC
        LDR R1,=DST
        MOV R2,#0
        MOV R5,#0
        MOV R3,#10
UP      LDR R4,[R0],#4
        ADDS R2,R4
        ADC R5,#0
        SUBS R3,#1
        BNE UP
        STR R2,[R1],#4
        STR R5,[R1]
            END 