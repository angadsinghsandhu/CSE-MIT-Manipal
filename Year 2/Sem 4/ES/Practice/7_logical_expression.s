    AREA myCode, CODE, READONLY
    ENTRY   @ Evaluate expression f = A.B + (C.D)'

    MOV r1, #A
    MOV r2, #B
    AND r3, r1, r2

    MOV r1, #C
    MOV r2, #D
    AND r4, r1, r2
    MVN r4, r4

    ORR r1, r3, r4
    END

    @ P = 2_00000000001111110000

    @ to get all the 1s

    @ MOV r1, #P, LSR #4; Left Shifting by 4 digits [ 2_0000000000111111 ]
    @ AND r1, r1, #0x3F;  getting only the last 6 digits from mask (111111=0x3F) [ 2_111111 ]




