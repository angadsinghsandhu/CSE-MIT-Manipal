    AREA addition, CODE, READONLY
    ENTRY

    MOV r1, #Q
    MOV r2, #R
    MOV r3, #S

    ADD r0, r1, r2
    ADD r0, r0, r3
    
Stop B Stop    
    
Q   EQU 2
R   EQU 4
S   EQU 5
    END