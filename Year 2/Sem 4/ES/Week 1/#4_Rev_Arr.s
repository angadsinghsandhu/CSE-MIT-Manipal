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
            MOV R3, #10
            LDR R0, =NUM
            LDR R1, =DST

LOOP1   
            LDR R2, [R0]
            STR R2, [R1]
            ADD R0,R0,#4
            ADD R1,R1,#4
            SUBS R3,R3,#1
            BNE LOOP1

            MOV R5, #5
            LDR R0, =DST ;beginning of array
            LDR R1, =DST
            ADD R1,R1,#36 ;start from end of array

LOOP2    
            LDR R2, [R0] ;num1 
            LDR R3, [R1] ;num2
            STR R3, [R0] ;num2=num1
            STR R2, [R1] ;num1=tmp
            ADD R0,R0,#4
            SUB R1,R1,#4
            SUBS R5,R5,#1
            BNE LOOP2

STOP B STOP
        AREA mydata1, DATA, READONLY

NUM DCD 1,2,3,4,5,6,7,8,9,10
        AREA mydata2, DATA, READWRITE

DST DCD 0
        END