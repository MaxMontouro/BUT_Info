
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 09:09:03 2023

@author: bruyere
"""
###################################################
# Introduction - codage des lettres de l'alphabet #
###################################################

# Numérotation des lettres de l'alphabet



# Fonction corresp(alpha) 

alpha = "abcdefghijklmnopqrstuvwxyz"



# Fonction code(lettre) : renvoie le code à partir de la lettre

def code(lettre : str) -> int:
    for i in range(len(alpha)):
        if(lettre == alpha[i]):
            return i

# Fonction lettre(code) : renvoie la lettre à partir du code


def lettre(code : int) -> str:
    for i in range(len(alpha)):
        if(code == i):
            return alpha[i]

##########################
#  Chiffrement de César  #
##########################

#	Fonction chiffrecesar(message,cle) prenant en entrée le message et la clé 
#   et renvoyant le cryptogramme 

def chiffrecesar(message: str, cle : int):
    ListeCrypter = ""
    for i in range (len(message)):
        ind = code(message[i])
        nouvelleLettre = lettre((ind+cle))
        ListeCrypter += str(nouvelleLettre)
    return ListeCrypter

#	Fonction dechiffrecesar(message,cle) prenant en entrée le cryptogramme et 
#   la clé, et renvoyant le message

def dechiffrecesar(message: str, cle: int) ->str:
    chaineDechiffrer = ""
    
    for i in range(len(message)):
        chaineDechiffrer += message[(i-3)%26]
    return chaineDechiffrer

#########################
#	Cryptanalyse Cesar  #
#########################
crypto1 ='vccvgivjjrjlicruvkvekvkflkvjcvjzuvvjulscfeuzevkjvgrigzccvivektvcrwzklevafczvwcvliurejcvtzvcuyzmvirmrekhlvcvgivdzvigvkrcvvewlkivkfdsvvcrmzvzccvrmrzkivdzjvjferidvurejjfetrsrjvkivgiverzkjriflkvurezvcgveertcrwvvtrirszev'

# Rappel pour l'analyse fréquentiste
'''from collections import Counter
c=Counter(cryptogramme)
freq=c.most_common(10) '''




#########################
#   Chiffrement AFFINE  #
#########################

# Fonction pgcd_euclide_etendu(n,m) prenant en paramètres deux entiers n et m, 
# et renvoyant le tuple (pgcd, u, v) dans lequel : 
#	pgcd=pgcd(n,m)
#	u et v sont les coefficients de Bezout dans l’égalité : pgcd=u×n+v×m



# Inverse modulaire
# Fonction inversemod(nb,mod) prenant en entrée deux entiers nb et mod 
# et renvoyant l’inverse modulaire de nb quand celui-ci existe.
	


# Fonction chiffreaffine(message,a,b) prenant en entrée le message et la clé (a,b) 
# et renvoyant le cryptogramme
	


# Fonction dechiffreaffine(cryptogramme,a,b) prenant en entrée le cryptogramme 
# et la clé (a,b) et renvoyant le message.
	
#########################
#  Cryptanalyse affine  #
#########################

crypto2 ='lqdmadtfkahuhqutadnkxxutesdstqutrqmadtfkalsrpqumqdtmqpsstnawulsfswrpulsxkatmlshsfmstladsqtwkmrnsfsmaudtqdtsdkdrpamyaadtfkamsedamqxpkddsavmqdmfusdrkafmqmmskufdumafyakuwqdgsfestqutadtfkalsnkxxutesyauuwrpuyaspsekdzkftbfftkpiusdxupxkpsnkxxut'

###############################
#   Chiffrement de Vigénère   #
###############################

# Fonction chiffrevigenere(message,cle) prenant en entrée le message et la clé 
# et renvoyant le cryptogramme. 



# Fonction dechiffrevigenere(cryptogramme,cle) prenant en entrée le cryptogramme 
# et la clé, renvoyant le message


############################################
#  Cryptanalyse - Longueur de clé connue   #
############################################

# La clé utilisée pour obtenir le cryptogramme suivant est de lonqueur 3
crypto3 = 'snzsmmifkcgusivsniwnasotshnohbzizgkcsfmgulifbsmizfiwyvhybjyvocmbnxfcaruvgxmguntuqfyaeoqgyupfiwyvhcudizhuvhyasnkchawxmfujzyadoqgkcsfmgazohlsmxslachvsmijuqshbzuqfnzsmwqwcdymgybduzqyyiivbykcgxfyvocbfcmbutsozgamgnmgfwfmyiivguxslkccbihjsucxicfkcsfmilacwkijihcwbmachbdcmhlmgfmilusnqslnwamsnyictghwbnxzoarytwyvopmqfijcmdicfkcccvsjigwwbnqbomfnmzovshnohbojwfnmffiryagoazyusgmfyoolleomgozqyyicmgnmhlibamfliwhmfgifcifctyytsnbfyaoovxycbyxcybs'

# Fonction scindermod(texte,longueur) prenant en entrée "texte" une chaine de caractère 
# et un entier "longueur", et renvoyant une liste de chaînes extraites de texte  
# correspondant à la suite des caractères de texte d’indices congrus à 0,1…,l-1 modulo longueur. 

# A tester avec la chaîne "texte" suivante
texte= ‘lavielemalheurlisolementlabandonlapauvretesontdeschampsdebataillequiontleursherosvictorhugo'



# Analyse fréquentielle des sous-chaînes obtenues à partir du cryptogramme



##############################################
#  Cryptanalyse - Longueur de clé inconnue   #
##############################################

crypto4='chdvzopmpwiytdasmqqksmnnswfqrxsmlralicgxccanavuanxrxmfschlrysnlryviuzkglmaichbekgivykgjwyohivykgnzntgzwessctsginlvdohacuiliiuwlcakwxmrhwyvnycclbthivcawmarvoltrxbubhxsftrsshbpkgncavsolricoznmsuvgsocayncgureuuoakihmpkfnivtszizozcieohyiikqfmokoodvyoamqaaivqkxoadasfivrzydbeocbsgqyisgqyqyricnnahutbxgzivxsovcggxmpuhyxbaflmtgfxmeychxeutcthtviuzkxycakfyonxrytrschlrlowmnlowmvrbuxnysotrzsgxfjsjwyoffqqksxmzufnwhjshmnthxwazdicezohbvrogipnsfpbxfycegzvmezquuhybikry'
	
# Créer une fonction coincidence(texte) prenant en entrée texte, une chaine de caractère, 
# et renvoyant un nombre réel correspondant à son indice de coïncidence.



# Fonction coincidencemoy(texte,longcle) prenant en entrée, texte, une chaine de caractère
# et une longueur (de clé) longcle et renvoyant un nombre réel correspondant à 
# la moyenne des coïncidences 



# Calcul de la coïncidence moyenne pour différentes longueurs de clés 



# Déchiffrement de crypto4
