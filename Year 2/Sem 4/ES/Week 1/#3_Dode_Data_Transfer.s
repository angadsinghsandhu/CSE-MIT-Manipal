    AREA RESET,CODE,READONLY
	EXPORT __Vectors

__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN

	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	MOV R2,#10
L1  LDR R3,[R0],#4
	STR R3,[R1],#4
	SUBS R2,R2,#1
	BNE L1

HERE B HERE


SRC DCD 0x12345678,0x23456781,0x34567812,0x45678123,0x56789123,0x67812345,0x78123456,0x81234567,0x91234567,0x12345678
	AREA mydata,DATA,READWRITE

DST DCD 0	
	END