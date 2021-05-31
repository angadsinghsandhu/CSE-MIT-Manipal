    AREA myCode, CODE, READWRITE
    ENTRY   @ Performing (A + 8B + 7C + -27)/4  [ A=27, B=19, C=99 ]

    MOV r0, #25
    MOV r1, #19
    ADD r0, r0, r1, LSL #3; Adding 8x of B to A

    MOV r1, #99
    MOV r2, #7
    MLA r0, r1, r2, r0; Adding r2 x r1 to r0 nad saving to r0

    SUB r0, r0, #27;    Subtarct 27 from total
    MOV r0, r0, ASR #2; divide by 4

    END