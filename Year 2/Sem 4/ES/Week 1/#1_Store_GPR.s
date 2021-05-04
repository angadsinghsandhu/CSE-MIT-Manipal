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
        MOV R0, #5
        MOV R1, #5

STOP
        B STOP