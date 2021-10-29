DATA SEGMENT
    NUM DW 0019,0038;        
    LCM DW ?;                   ;LCM OF TWO NUMBERS = PRODUCT OF TWO NUMBERS / HCF OF THE NUMBERS
    DATA ENDS
CODE SEGMENT
    ASSUME DS:DATA CS:CODE
    START:MOV AX,DATA
    MOV DS,AX
    MOV AX,NUM            ; LOAD AX WITH FIRST NUMBER
    MOV BX,NUM+2          ; LOAD BX WITH SECOND NUMBER
    LOOP1:MOV DX,0        ; USE A LOOP TO FIND THE GCD. INITIALIZE DX WITH 0    
    MOV CX,BX             ; MOVE THE VALUE OF BX TO CX                 
    DIV BX                ; DIVIDE BY BX                    
    MOV BX,DX             ; MOVE THE VALUE OF DX TO BX                
    MOV AX,CX             ; MOVE THE VALUE OF CX TO AX
    CMP BX,0              ; COMPARE IF BX IS EQUAL TO 0
    JNE LOOP1             ; LOOP UNTIL BX IS NOT EQUAL TO 0               
    MOV CX,AX             ; STORE THE GCD IN CX
    MOV AX,NUM            ; LOAD AX WITH FIRST NUMBER
    MOV BX,NUM+2          ; LOAD BX WITH SECOND NUMBER
    MUL BX                ; MULTIPLY AX WITH BX                    
    DIV CX                ; DIVIDE AX BY CX 
    MOV LCM,AX            ; STORE THE RESULT INTO THE VARIABLE LCM                 
    MOV AH,4CH
    INT 21H
    ENDS
END START
