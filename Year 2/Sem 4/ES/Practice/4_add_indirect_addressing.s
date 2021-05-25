    AREA myCode, CODE, READWRITE
    ENTRY

    ADR r4, TheData;    pointing to the data area
    LDR r1, [r4, #Q];   addressing Q into R1 through R4
    LDR r2, [r4, #R] 
    LDR r3, [r4, #S] 

    ADD r0, r1, r2
    ADD r0, r0, r3

    STR r0, [r4, #P];   saving result in memory

Stop B Stop

P   EQU 0;  Defining Offsets
Q   EQU 4
R   EQU 8
S   EQU 12

    AREA myCode, CODE, READWRITE
TheData SPACE 4
    DCD 2
    DCD 4
    DCD 5
    
    END