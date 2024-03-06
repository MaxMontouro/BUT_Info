/**
TD2 Qualité au dela du rationnel
*/

/*Question 1*/

CREATE OR REPLACE TYPE B_Point AS OBJECT
(   x NUMBER NOT NULL, 
    y NUMBER NOT NULL);

/*Question 2*/

CREATE OR REPLACE TYPE Ligne_t AS OBJECT
(   p1 B_Point NOT NULL, 
    p2 B_Point NOT NULL);

/*Question 3*/

CREATE OR REPLACE TYPE Polygone_ AS TABLE OF B_Point;

/*Question 4*/

CREATE TABLE REGION (
    NOM_REGION VARCHAR2(50) NOT NULL,
    POLYGONE Polygone_t NOT NULL,
    ) NESTED TABLE POLYGONEb STORE AS Polygone_t ;

/*Question 5*/

INSERT INTO REGION VALUES ("Aquitaine", Polygone_t(Ligne_t(B_Point(0,0), B_Point(0,1)), Ligne_t(B_Point(0,1), B_Point(1,1)), Ligne_t(B_Point(1,1), B_Point(1,0)), Ligne_t(B_Point(1,0), B_Point(0,0)))) ;

/*Question 6*/

CREATE OR REPLACE TYPE Rect_t AS TYPE
(   p1 B_Point NOT NULL, 
    p2 B_Point NOT NULL);

/*Question 7*/

CREATE TABLE VILLE(
    NOM_VILLE VARCHAR2(50) NOT NULL,
    RECT Rect_t NOT NULL,
    PRIMARY KEY (NOM_VILLE)) ;

/*Question 8*/

INSERT INTO VILLE VALUES ("Anglet", Rect_t(B_Point(8950,4840), B_Point(9180,5050)));
INSERT INTO VILLE VALUES ("Lyon", Rect_t(B_Point(8820,7020), B_Point(9080,7230)));
INSERT INTO VILLE VALUES ("Paris", Rect_t(B_Point(6310,2940), B_Point(6560,3110)));

/*Question 9*/

SELECT v.NomVille, ((v.RectVille.pt_Min.X - v.RectVille.pt_Max.X) * (v.RectVille.pt_Min.Y - v.RectVille.pt_Max.Y)) AS Surface
FROM VILLE v;

/*Question 10*/

SELECT NomVille FROM VILLE v
WHERE (v.RectVille.pt_Min.X - v.RectVille.pt_Max.X) > 10
OR (v.RectVille.pt_Min.Y - v.RectVille.pt_Max.Y) > 10;

/** PARTIE 2 **/

/*Question 1*/

CREATE OR REPLACE TYPE Metadonnee_type AS OBJECT
(   Au VARCHAR2(50) NOT NULL,
    Geo VARCHAR2(50) NOT NULL,
    D VARCHAR2(50) NOT NULL);

CREATE OR REPLACE TYPE Lien_type AS OBJECT
( URL VARCHAR2(50),
    RELATION VARCHAR2(50));

CREATE OR REPLACE LienS_type AS TABLE OF Lien_type;

CREATE TABLE TWITTER (
    URL VARCHAR2(50) NOT NULL,
    Texte VARCHAR2(50) NOT NULL,
    objetMIME VARCHAR2(50) NOT NULL,
    D/H DATE NOT NULL,
    Metadonnee Metadonnee_type NOT NULL,
    LienS LienS_type NOT NULL,
    PRIMARY KEY (URL))
    NESTED TABLE LienS STORE AS LienS_type ;

/*Question 2*/

INSERT INTO TWITTER VALUES ("Ma-photo-1", "Photo prise lors d'une soirée avec des amis", "image/jpeg", "12/05/09", Metadonnee_type("X. Tintin", "43.8345-0.3516", "03/04/08"), LienS_type(Lien_type("Ma-photo-2", "theme")));

/*Question 3*/

SELECT t.URL, t.Texte, t.objetMIME
FROM TWITTER t
WHERE t.Metadonnee.Au = "%X. Tintin";

/*Question 4*/

UPDATE TWITTER t, TABLE(t.LienS) l l.RELATION = "similaire"
WHERE t.URL = "Ma-photo-1";

/*Question 5*/

UPDATE TWITTER t, TABLE(t.LienS) l SET L = Lien_type("Chanson12", "reponse")
TYPE
WHERE t.URL = "Photo-belle";


/*Question 6*/

SELECT l.URL, l.RELATION
FROM TWITTER t, TABLE(t.LienS) l
WHERE t.URL = "Ma-photo-1";

/*Question 7*/

SELECT * FROM TWITTER t
WHERE T.Texte LIKE "Master%";