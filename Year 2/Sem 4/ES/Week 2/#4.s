    AREA RESET,DATA,READONLY
    EXPORT __Vectors

__Vectors
            DCD 0X40001000
            DCD Reset_Handler
            ALIGN
            AREA mycode,CODE,READONLY
            ENTRY
            EXPORT Reset_Handler

Reset_Handler
	        LDR R0,=N1
	        LDR R1,=N2
	        LDR R4,=DST
	        MOV R5,#4
	        LDR R6,=0xFFFFFFFF
	        MSR XPSR,R6
	        MOV R8,#0
UP	        LDR R2,[R0],#4
	        LDR R3,[R1],#4
	        SBCS R7,R2,R3
	        STR R7,[R4],#4
	        SUBS R5,1
	        BNE UP
	        ADC R8,#0
	        STR R8,[R4]

STOP
	    B STOP

N1 DCD 1,2,3,4

N2 DCD 1,2,3,4
	    AREA mydata, DATA, READWRITE

DST DCD 0
	    END