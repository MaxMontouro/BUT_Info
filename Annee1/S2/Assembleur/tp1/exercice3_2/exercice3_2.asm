.DATA 
        valeurInit DW 13
        fact DSW 1

.CODE
    LD R0,1
    LD R1,2
boucle: CMP R1, valeurInit
        BGT Fin 
        MULU R0,R1
        INC R1
        JMP boucle
Fin:    ST R0, fact
        HLT 

.STACK 10