    AREA myCode, CODE, READWRITE
    ENTRY

    LDR r1, P
    LDR r2, Q
    LDR r3, R

    ADD r0, r1, r2
    ADD r0, r0, r3

    STR r0, Q;  Storing result in Q

Stop B Stop

    AREA myCode, CODE, READWRITE
O   SPACE 4
P   DCD 2
Q   DCD 4
R   DCD 5 

    END
