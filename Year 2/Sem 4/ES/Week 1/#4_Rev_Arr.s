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
	
	    LDR R0, =SRC
	    LDR R1, =SRC
	    ADD R1, #36
	    MOV R5, #5
up      LDR R2, [R0]
	    LDR R3, [R1]
	    STR R2, [R0], #-4
	    STR R3, [R0], #4
	    SUBS R5, #1
	    BNE up
	
STOP
	    B STOP

SRC DCD 8
	    AREA mydata, DATA, READWRITE

DST DCD 0
	    END