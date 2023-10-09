.DATA

couleur DW 14
coordX DW 50
coordY DW 80
largeur DW 150
hauteur DW 60

.CODE
LEA SP,STACK

	LD R0,0
	OUT R0,5 ; efface l'écran
	PUSH couleur ; empile couleur
	PUSH coordX ; empile X
	PUSH coordY ; empile Y
	PUSH largeur ; empile largeur
	PUSH hauteur ; empile hauteur
	CALL rectangle
	HLT
	
rectangle: PUSH R0
		   LD R0,[SP+5]
		   OUT R0,1 ; coord X dans le port 1
		   LD R0,[SP+4]
		   OUT R0,2 ; coord Y dans le port 2
		   LD R0,[SP+3]
		   OUT R0,3 ; largeur dans le port 3
		   LD R0,[SP+2]
		   OUT R0,4 ; hauteur dans le port 4
		   LD R0,5 ; on ajoute la commande graphique du rectangle plein dans R0
		   SHL [SP+6] ; décalage arithmétique à gauche
		   SHL [SP+6] ; décalage arithmétique à gauche
		   SHL [SP+6] ; décalage arithmétique à gauche
		   SHL [SP+6] ; décalage arithmétique à gauche
		   ADD R0, [SP+6] ; ajout de la couleur à la commande graphique
		   OUT R0,5 ; affichage du rectangle jaune à l'écran
		   PULL R0
		   RET 5 ; retour après le call dans la boucle et vide la pile
			
.STACK 15