.DATA
coordX DSW 1
coordY DSW 1
largeur DW 100
hauteur DW 100

.CODE
LEA SP,STACK

	LD R0,0
	OUT R0,5 ; efface l'écran 

attend_clic: IN R0,0
			 CMP R0,%11000111 ; Comparaison de l'action avec le clic sur l'écran
			 BEQ carreClic ; Si c'est égal on crée le carré avec les coordonnées du clic
			 JMP attend_clic ; Sinon on recommence la boucle
	
carreClic: IN R0,6 ; R0 prend la coordX du clic
		   SUB R0,50 ; On soustrait 50 pour avoir la coordX du coin haut gauche du carré
		   ST R0,coordX ; on remet la valeur dans coordX
		   IN R0,7 ; R0 prend la coordY du clic
		   SUB R0,50 ; On soustrait 50 pour avoir la coordX du coin haut gauche du carré
		   ST R0, coordY ; on remet la valeur dans coordY
		   PUSH coordX ; empile coordX
		   PUSH coordY ; empile coordy
		   PUSH largeur ; empile largeur
		   PUSH hauteur ; empile hauteur
		   CALL carreInitial ; appel de la procédure carreInitial

boucle: IN R1,0 ; R1 prend la valeur de l'action qui est exécuté à l'instant
		CMP R1,%11000101 ;A appuyé
		BEQ APush
		CMP R1,%10000101 ;A lâché
		BEQ APull
		CMP R1,%11000110 ;B appuyé
		BEQ BPush
		JMP boucle ; retour au début de la boucle
	
APush: LD R2,largeur
	   SUB R2,50 ; on soustrait 50 à la largeur initiale
	   ST R2,largeur
	   LD R2,hauteur
	   SUB R2,50 ; on soustrait 50 à la hauteur initiale
	   ST R2,hauteur
	   LD R2,coordX
	   ADD R2,25 ; on ajoute 25 à la coordonnée de x initiale du coin haut gauche du carré
	   ST R2,coordX
	   LD R2,coordY 
	   ADD R2,25 ; on ajoute 25 à la coordonnée de y initiale du coin haut gauche du carré
	   ST R2,coordY
	   PUSH coordX ;empile coordX
	   PUSH coordY ;empile coordY
	   PUSH largeur ;empile largeur
	   PUSH hauteur ;empile hauteur
	   CALL carreReduit ; appel de la procédure carreReduit
	   JMP boucle ; retour à la boucle lorsque la procédure carreReduit est terminée

APull: LD R2,largeur
	   ADD R2,50 ; on ajoute 50 à la largeur initiale
	   ST R2,largeur
	   LD R2,hauteur
	   ADD R2,50 ; on ajoute 50 à la hauteur initiale
	   ST R2,hauteur
	   LD R2,coordX
	   SUB R2,25 ; on soustrait 25 à la coordonnée de x initiale du coin haut gauche du carré
	   ST R2,coordX
	   LD R2,coordY
	   SUB R2,25 ; on soustrait 25 à la coordonnée de y initiale du coin haut gauche du carré
	   ST R2,coordY
	   PUSH coordX ;empile coordX
	   PUSH coordY ;empile coordY
	   PUSH largeur ;empile largeur
	   PUSH hauteur ;empile hauteur
	   CALL carreInitial ; appel de la procédure carreInitial
	   JMP boucle ; retour à la boucle lorsque la procédure carreInitial est terminée

BPush: HLT ; arrêt du processeur
	
carreInitial: LD R0,0
			  OUT R0,5 ; efface l'écran
			  PUSH R0
			  LD R0,[SP+5]
		      OUT R0,1 ; coord X dans le port 1
		      LD R0,[SP+4]
		      OUT R0,2 ; coord Y dans le port 2
		      LD R0,[SP+3]
		      OUT R0,3 ; largeur dans le port 3
		      LD R0,[SP+2]
		      OUT R0,4 ; hauteur dans le port 4
		      LD R0,%11000011
		      OUT R0,5 ; affichage du carreInitial rouge à l'écran
		      PULL R0
			  RET 5
		   
carreReduit: LD R0,0
		     OUT R0,5 ; efface l'écran
			 PUSH R0
			 LD R0,[SP+5]
		     OUT R0,1 ; coord X dans le port 1
		     LD R0,[SP+4]
		     OUT R0,2 ; coord Y dans le port 2
		     LD R0,[SP+3]
		     OUT R0,3 ; largeur dans le port 3
		     LD R0,[SP+2]
		     OUT R0,4 ; hauteur dans le port 4
		     LD R0,%11000011
		     OUT R0,5 ; affichage du carreInitial rouge à l'écran
		     PULL R0
		     RET 5

.STACK 15