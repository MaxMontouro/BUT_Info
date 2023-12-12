# -*- coding: utf-8 -*-
"""
Created on Thu Dec  7 11:15:57 2023

@author: maxmontouro
"""

#importation des bilbioteques
import random as rd
import sympy as sp

#renvoie vrai si un nombre est premier faux sinon
def est_premier(nombre):
    return sp.isprime(nombre)

#renvoie le pgcd de deux nombres
def pgcd(a, b):
    while b:
        a, b = b, a % b
    return a

# renvoie une cle avec i un nombre premier et l = un nombre premier

def choixCle(i : int, l : ):
    p = sp.randprime(i, i + l)
    q = sp.randprime(p + 1, p + l + 1)
    n = p * q
    f = (p - 1) * (q - 1) #phi(pq)
    e = rd.randrange(2, f)
    while pgcd(e, f) != 1:
            e = rd.randrange(2, f)
    return p, q, e

def clePublique(p : int ,q : int ,e : int) -> int :
    i  = rd.randint(0, 10)
    l = rd.randint(0, 10)
    p,q,e = choixCle(i,l)
    
    
    
def pow(nombre, exposant) -> int:
    return nombre ** exposant

def exposant_modulaire(nombre, modulo) -> int:
    return nombre%modulo

def decrypte_message(chaine, clePrivee, n) -> int:
    return exposant_modulaire(pow(chaine, clePrivee), n)

def crypteMessage(message, clePublique, n) -> int:
    return exposant_modulaire(pow(message, clePublique), n)