
/*Exercice 1*/

Créer le processus

Si le processus n’est pas crée

Alors sortir avec erreur

Sinon créer le fils -> pid fils

            Case -1 : sortir avec erreur

                           Break;

            Case 0 : /*proc fils*/

                        Si saise au clavier
                        Alors tuer le proc

                                    Sortir;

                                    Break;

                        Tant que rien au clavier

                                    Afficher “alors ca vient”

                                    Attendre 15 sec

                        FIN Tant que

            Default : /*proc père*/

                        Calcul (attente 50sec)

                        Sortir;

                        Break;
            Fin Case
Fin Sinon

FIN

/*Exercice 2*/
Créer le processus

Si le processus n’est pas crée

Alors sortir avec erreur

Sinon créer le fils -> pid fils

            Case -1 : sortir avec erreur
                           Break;

            Case 0 : /*proc fils*/

                        SI saise au clavier:
                        ALORS tuer le proc:
                                    Sortir;
                                    Break;

                        Tant que rien au clavier
                                    SI Attente 15s:
                                    ALORS : Afficher “alors ca vient”

                                    Si Attente 30s:
                                    Alors:  Afficher “Bon j abandonne”
                                            Sortir;
                                            Break;

                        Fin tant que

            Default : /*proc père*/

                        Calcul (attente 0sec)
                        Sortir;
                        Break;

            Fin Case
Fin SI