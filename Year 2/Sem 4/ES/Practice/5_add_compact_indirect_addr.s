    AREA myCode, CODE, READWRITE
    ENTRY

    ADR r0, TheData;
    LDR r1, [r0, #4]
    LDR r2, [r0, #8]
    ADD r2, r1, r2

    LDR r1, [r0, #12]
    ADD r2, r1, r2

Stop B Stop

    AREA myCode, CODE, READWRITE
P   SPACE 4
Q   DCD 2
R   DCD 5
S   DCD 6

    END
