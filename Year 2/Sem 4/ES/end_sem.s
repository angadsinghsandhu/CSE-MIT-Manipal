    AREA RESET,DATA,READONLY
    EXPORT __Vectors


__Vectors
            DCD 0X10001000
            DCD Reset_Handler
            ALIGN
            AREA mycode,CODE,READONLY
            ENTRY
            EXPORT Reset_Handler

Reset_Handler
            LDR R1, =LIST       ; defined array   
            LDR R2, =checksum   ; the sum variable
            MOV R3, #0          ; sum to be stored
            
            LDR R12, =LENGTH
            LDR R12, [R12]      ; length variable

            CMP R12, #0         ; zero check for length
            BLE STOP

LOOP
            LDRB R4, [R1]       ; intermediate
            ADD R3, R3, R4      ; add array to sum
            AND R3, R3, #0xFF   ; performing `and` operation to ignore carry

            ADD R1,R1,#1       ; increment list
    
            SUBS R12,R12,#1     ; decrement length
            BNE LOOP            ; loop again if condition not satisfied

            STRB R3, [R2]       ; final output into `checksum` 


STOP B STOP

        AREA mydata1, DATA, READONLY
LIST DCB 0x28, 0x55, 0x26, 0x70, 0x45, 0x30, 0x62, 0x85

        AREA mydata2, DATA, READWRITE
checksum DCB 0

        AREA mydata3, DATA, READONLY
LENGTH DCD 3


        END