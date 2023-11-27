CREATE TABLE DEPT (
  NUMDEP INT NOT NULL,
  NOMDEP VARCHAR2(50) NOT NULL,
  NOMLOC VARCHAR2(50) NOT NULL,
  PRIMARY KEY(NUMDEP)
)

CREATE TABLE EMP (
  NUMEMP INT NOT NULL,
  NOM_COMPLET VARCHAR2(50) NOT NULL,
  PROFESSION VARCHAR2(50) NOT NULL,
  CHEF INT,
  SALAIRE INT NOT NULL,
  NUMDEP INT NOT NULL,
  PRIMARY KEY(NUMEMP),
  FOREIGN KEY(NUMDEP) REFERENCES DEPT(NUMDEP))
  


/*INSERTION DANS DEPT*/

INSERT INTO DEPT VALUES (1,'RECHERCHE', 'DIJON');
INSERT INTO DEPT VALUES (2,'DEVELOPPEMENT', 'NEW-YORK');
INSERT INTO DEPT VALUES (3,'FACTURATION', 'PARIS');
INSERT INTO DEPT VALUES (4,'DIRECTION', 'LONDRES');

/*INSERTION DANS EMP*/

INSERT INTO EMP VALUES (1,'BARTH Florent', 'CHEF DE PROJET', 3, 13000, 2);
INSERT INTO EMP VALUES (2,'XAVIER Richard', 'CHERCHEUR', 3, 21000, 1);
INSERT INTO EMP VALUES (3,'NICOLLE Chris', 'CHERCHEUR',NULL, 25000, 1);
INSERT INTO EMP VALUES (4,'BLAKE John', 'DEVELOPPEUR', 6, 8000, 2);
INSERT INTO EMP VALUES (5,'DUPONT Jean', 'DEVELOPPEUR', 3, 9000, 2);
INSERT INTO EMP VALUES (6,'MARTIN Alexandre', 'COMPTABLE', 3, 10000, 3);
INSERT INTO EMP VALUES (7,'RAY Benjamin', 'COMPTABLE', 3, 10000, 3);
INSERT INTO EMP VALUES (8,'MILLER Pascal', 'DEVELOPPEUR', 3, 9000, 2);
INSERT INTO EMP VALUES (9,'FORD John', 'DIRECTEUR', 3, 30000, 4);


/*TEST DU CODE QUI NE MARCHE PAS EN PL/SQL*/

DECLARE
  --
  n NUMBER(2);
  --
  CURSOR employes IS SELECT numemp, nomemp, salaire FROM EMP;/*utiliser nos attribut*/
  --
  newsal emp.salaire%TYPE;
  --
  empv EXCEPTION;
BEGIN
  --
  SELECT COUNT(*)FROM EMP;/*aucune affectation dans n*/
  --
  IF n=0 ALORS/* commande ALORS ???*/
    --
    RAISE empv;
  END IF;
  --
  FOR employe IN employes LOOP
    --
     newsal=employe.salaire+50;
    --
    UPDATE EMP SET SALAIRE=newsal where NUMEMP = employe.numemp;
  END LOOP;
  Commit;
  --
  EXCEPTION
  --
  WHEN empv THEN dbms_output.put_line('Message d''erreur !');
  
END;

/*MODIFICATION DU CODE*/
set serveroutput on
DECLARE
  -- déclaration de la varible n
  n NUMBER(2);
  --pointeur vers la requete
  CURSOR employes IS SELECT NUMEMP, NOM_COMPLET, SALAIRE FROM EMP;/*utiliser nos attribut*/
  -- declare newsal du meme type que salaire donc int
  newsal EMP.SALAIRE%TYPE;
  -- declare une variable exception
  empv EXCEPTION;
BEGIN
  --
  SELECT COUNT(*)INTO n FROM EMP;/*aucune affectation dans n*/
  --test
  IF n=0 THEN
    -- Si il y a eu une erreur va directement dans bloque d exception
    RAISE empv;
  END IF;
  --sinon boucle
  FOR employe IN employes LOOP
    -- mets a jour le salaire et affiche si salaire bien mis a jour 
     newsal:=employe.SALAIRE+50;
     dbms_output.put_line('Mise à jour réussie');
    -- modification et sauvegarde dans la table
    UPDATE EMP SET SALAIRE=newsal where NUMEMP = employe.numemp;
  END LOOP;
  Commit;
  --bloque exception
  EXCEPTION
  -- si n=0
  WHEN empv THEN dbms_output.put_line('Ceci est un message derreur !');
  
END;

/*procedure hello world*/
CREATE OR REPLACE PROCEDURE HelloWorld AS
BEGIN
      dbms_output.PUT_LINE('Hello World');
END;
  
DECLARE
BEGIN
    HelloWorld;
END;

/* FUNCTION AFFICHER SALAIRE 8.1*/
CREATE OR REPLACE FUNCTION afficherSalaire(nomEmploye VARCHAR2)
RETURN Number IS
salaireEMP EMP.Salaire%TYPE;
BEGIN 
  SELECT SALAIRE
  INTO  salaireEMP
  FROM EMP 
  WHERE NOM_COMPLET = nomEmploye;
RETURN salaireEMP;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
  DBMS_OUTPUT.PUT_LINE('Y a rien ');
  RETURN NULL;
END;

DECLARE 
BEGIN 
    dbms_output.PUT_LINE('le salaire est de ' || afficherSalaire('XAVIER Richard'));
END;


/* FUNCTION AFFICHER SALAIRE 8.2*/
CREATE OR REPLACE FUNCTION infoEmp(nomEmploye VARCHAR2)
RETURN VARCHAR2 IS
numero EMP.NOM_COMPLET%TYPE;
poste EMP.PROFESSION%TYPE;
salaireEMP EMP.Salaire%TYPE;
BEGIN 
  SELECT NUMEMP, PROFESSION, SALAIRE
  INTO  numero, poste, salaireEMP
  FROM EMP 
  WHERE NOM_COMPLET = nomEmploye;
RETURN 'Numero = '||numero||' Poste = '||poste|| ' Salaire = '||salaireEMP;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
  DBMS_OUTPUT.PUT_LINE('Y a rien ');
  RETURN NULL;
END;

DECLARE 
BEGIN 
    dbms_output.PUT_LINE(infoEMP('XAVIER Richard'));
END;


/* FUNCTION AFFICHER affecter_emp_dept*/
CREATE OR REPLACE PROCEDURE affecter_emp_dept(nomEMP VARCHAR2, nomDept Number) AS 
BEGIN 
  UPDATE EMP SET NUMDEP = nomDept
  WHERE NOM_COMPLET = nomEMP;
  DBMS_OUTPUT.PUT_LINE('Ca a marché');
  COMMIT;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
  DBMS_OUTPUT.PUT_LINE('Erreur');
END;

 
BEGIN 
    affecter_emp_dept('XAVIER Richard', 2);
END;


/* FUNCTION AFFICHER SALAIRE 10*/
CREATE OR REPLACE FUNCTION existe_EMP(nomEmploye VARCHAR2)
RETURN BOOLEAN IS
v_count NUMBER;
BEGIN 
  SELECT COUNT(*)
  INTO  v_count
  FROM EMP 
  WHERE NOM_COMPLET = nomEmploye;
RETURN v_count > 0;
END;


BEGIN 
  IF EXISTE_EMP('XAVIER bhyg') = TRUE THEN 
    dbms_output.PUT_LINE('Trouvé');
  ELSE
    dbms_output.PUT_LINE('Pas Trouvé');
  END IF;
END;

/* FUNCTION AFFICHER app_emp_dept 11*/
CREATE OR REPLACE FUNCTION app_emp_dept(nomEmploye VARCHAR2, numDept Number)
RETURN VARCHAR2 IS
nom EMP.NOM_COMPLET%TYPE;
numero EMP.NUMDEP%TYPE;
BEGIN 
  SELECT NOM_COMPLET, NUMDEP
  INTO  nom, numero
  FROM EMP
  WHERE NOM_COMPLET = nomEmploye;
  
  IF (nom = nomEmploye AND numero = numDept) THEN 
    RETURN 'Cet employé appartient au département ' || numDept;
  ELSE
    RETURN 'Cet employé n appartient au département ' || numDept;
  END IF;
END;


BEGIN 
  dbms_output.PUT_LINE(app_emp_dept('XAVIER Richard', 3));
END;
