.DATA
chaine DW "Texte à souligner."

.CODE

LEA SP, STACK
	
	LD R0,0
	OUT R0,5 ;Pour effacer l'écran
	LEA R0,chaine ;Adresse de la chaîne dans R0
	LD R1,50 ; coordX
	LD R2,100 ; coord Y
	CALL afficherChaine
	LD R2,105 ;Nouvelle coord Y pour afficher la ligne juste sous le texte
	IN R3,1 ; On récupère la coord X de la dernière lettre affichée
	OUT R1,1 ; coord X départ de la ligne
	OUT R2,2 ; coord Y départ de la ligne 
	OUT R3,3 ; coord X d'arrivée de la ligne
	OUT R2,4 ; coord Y d'arrivée de la ligne
	LD R1,%11100010 ; Comande d'affichage (ligne jaune)
	OUT R1,5 ; Affichage
	HLT ;Arrêt du processeur

afficherChaine: 
	PUSH R0 ; Sauvegarde de R0 sur la pile
	PUSH R3 ; Sauvegarde de R3 sur la pile
	PUSH R4 ; Sauvegarde de R4 sur la pile

	LD R3,'.'
	OUT R1,1 ; coord X de la chaîne dans le port 1
	OUT R2,2 ; coord Y de la chaîne dans le port 2
	JMP boucle

boucle:
	CMP R3,[R0] ; Si le caractère pointé par R0 est '.', on sort
	BEQ finAffichage
	OUT [R0],3 ; Caractère de la chaîne à afficher dans port 3
	LD R4,%11100111 ; Commande d'affichage (caractère jaune)
	OUT R4,5 ;Affichage du caractère
	INC R0 ; incrémentation de R0
	JMP boucle ; retour à la boucle

finAffichage:
	PULL R4 ; Restauration de R4 depuis la pile
	PULL R3 ; Restauration de R3 depuis la pile
	PULL R0 ; Restauration de R0 depuis la pile
	RET ;retour au programme principal avec vidage de la pile

.STACK 15