/* Question 1*/

CREATE OR REPLACE TYPE Localisation_t AS OBJECT(
    Rue VARCHAR2(50),
   Residence VARCHAR2(50),
   Batiment VARCHAR2(1));

CREATE OR REPLACE TYPE Capteurs_t AS OBJECT(
    Nom VARCHAR2(50),
    Qtt Number
);



CREATE OR REPLACE TYPE Dispositifs_t AS OBJECT(
    Nom VARCHAR2(50),
    Statut Number,
    Capteurs Capteurs_t
);

CREATE OR REPLACE DispositifS TABLE OF Dispositifs_t

CREATE TABLE APPARTEMENT(
    NumApt Number NOT NULL PRIMARY KEY,
    Localisation Localisation_t,
    Dispositif DispositifS
)NESTED TABLE Dispositif STORE AS Dispositif_tab;

/* Question 2*/

INSERT INTO APPARTEMENT VALUES (1, Localisation_t('24 Rue des Cerisiers', 'Les Jardins de lEspoir', 'E'), 
                                DispositifS(Dispositifs_t('Thermostat intelligent', 1, Capteurs_t(('Température', 2), Capteurs_t('Humidité', 2), Capteurs_t('Qualité de l air', 5))),
                                            Dispositifs_t('Machine à café', 1, Capteurs_t(NULL,NULL))
                                            ));



/* Question 3*/

Select DISTINCT(D.Capteurs)
FROM APPARTEMENT A, TABLE (A.Dispositif) D

/* Question 4*/

SELECT D.Nom
FROM APPARTEMENT.Dispositif D
WHERE D.Statut = 1;

/* Question 5*/

SELECT A.NumApt, MAX(COUNT(D.Capteurs.qtt))
FROM APPARTEMENT A, TABLE (A.Dispositif) D  

/* Question 6*/

UPDATE TABLE APPARTEMENT A, TABLE(A.Dispositif) D 
SET D.Statut = 0
WHERE D.Nom = 'Caméra de sécurité' AND A.NumApt = 3;

/* Question 7*/

SELECT COUNT(D.Capteurs.qtt)
FROM APPARTEMENT, TABLE (A.Dispositif) D
WHERE A.Localisation.Residence LIKE "Villa des%";

/* Question 8*/

SELECT A.NumApt
FROM APPARTEMENT A, TABLE(A.Dispositif) D
WHERE COUNT(D.NOM) > 2; 