    AREA RESET ,DATA, READONLY
	EXPORT __Vectors

__Vectors
	
	        DCD 0X10001000
	        DCD Reset_Handler
	        AREA mydata,DATA,READWRITE
DST         DCD 0
	        AREA mycode,CODE,READONLY
	        ENTRY
	        EXPORT Reset_Handler

Reset_Handler

	        LDR R0,=N1
	        LDR R1,[R0]
	        LDR R0,=N2
	        LDR R2,[R0]
	        MOV R3,#0
	        SUBS R3,R2,R1
	        ADC R3,#-1
	        LDR R0,=DST
	        STR R3,[R0]
	        ALIGN

N1 DCD 10

N2 DCD 15

STOP B STOP
	END