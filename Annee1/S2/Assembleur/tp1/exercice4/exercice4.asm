.DATA
chaine DW "uneChaine"
	   DW 0

maximum DSW 1

.CODE
LEA SP,STACK

	LEA R2,chaine ; Adresse de la chaine dans R2
	LD R1,0 ; R1 prend pour valeur 0

boucle: LD R0,[R2] ;
		CMP R0,0 ; On compare R0 à 0
		BEQ egal ; Si contenu de R0 égal à 0 on passe à egal
		CALL max ; Sinon appel la procédure max
		LD R1,R3 ; R1 prend la valeur de R3
		ADD R2,1 ; On passe au rang de la lettre suivante
		JMP boucle ; On recommence la boucle
egal: ST R3,maximum ; maximum prend la valeur de R3
	  HLT ; fin du processeur
max: CMP R0,R1 ; On compare R0 à R1
	 BGE plusgrand ; Si R0 sup ou égal à R1 on passe à plusgrand
	 LD R3,R1 ;R3 prend la valeur de R1
	 JMP finmax ; On passe à finmax
plusgrand: LD R3,R0 ;R3 prend la valeur de R0
finmax: RET ; retour de sous-programme avec vidage de la pile
	    ; pas besoin de rajouter vu que la pile est deja vide

.STACK 10