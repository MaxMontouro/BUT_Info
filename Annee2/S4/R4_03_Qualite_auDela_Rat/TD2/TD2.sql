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