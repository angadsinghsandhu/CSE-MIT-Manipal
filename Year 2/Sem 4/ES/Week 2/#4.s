    AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	
	        DCD 0X10001000
	        DCD Reset_Handler

	        AREA mydata,DATA,READWRITE
DST         DCD 0
	        AREA mycode,CODE,READONLY
N1          DCD 4,3,2,1
N2          DCD 0,0,0,1
	        ENTRY
	        EXPORT Reset_Handler
	
Reset_Handler
	
	        LDR R0,=N1
	        LDR R1,=N2
	        LDR R2,[R0]
	        LDR R3,[R1]
	        LDR R4 ,=DST
	        MOV R5,#4
	        MOV R6,#0
UP	        SUBS R2,R2,R3
	        ADC R6,#-1
	        STR R2,[R4],#4
	        LDR R2,[R0,#4]!
	        LDR R3,[R1,#4]!
	        SUBS R5,#1
	        BNE UP
	        STR R6,[R4]
	
	ALIGN
STOP B STOP	END