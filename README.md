# GestionElection
En vue de l'automatisation des opérations électorales prochaines, le Conseil Electoral Provisoire (CEP) vous demande de concevoir et de réaliser une solution logicielle en langage C qui devra lui permettre de gérer ces opérations.
 
 
En vue de l'automatisation des opérations électorales prochaines, le Conseil Electoral Provisoire (CEP) vous demande de concevoir et de réaliser une solution logicielle en langage C qui devra lui permettre de gérer ces opérations.  La solution proposée doit comprendre au moins les modules suivants sachant que seul les sénatoriales doivent être considérées et que 3 sénateurs doivent être élus par département. a) Partis Politiques b) Bureaux de Votes c) Electeurs d) Candidats e) Votes f) Rapports et Résultats 
 
1- Module Partis Politiques Ce module devra permettre de gérer les données relatives aux partis politiques inscrits.  Ces données seront stockées dans un fichier de données appelé part_pol.dat et comprendra au moins les champs suivants: - Id_PP    : pour identifier un parti politique (la valeur de ce champ doit être unique; c'est à dire que deux partis politiques ne peuvent pas avoir le même Id_PP) - Nom       : le nom du parti politique - Date_créat       : la date de création du parti politique - Date_ins       : la date d'inscription du parti politique - Adress   : l'adresse du parti politique qui sera subdivisée en plusieurs sous champs (No Rue, Rue, Département,) - Responsable: le nom du responsable du parti politique - Téléphone : le numéro de téléphone du parti politique - email  : adresse email du parti politique. 
 
Les fonctions à implémenter sont : o ins_PP : pour enregistrer un parti politique dans le fichier spart_pol.dat o modif_PP : pour modifier une donnée d'un parti politique (Id_Succ ne peut être modifié en aucun cas) 
 
2- Module Bureaux de Votes Ce module doit gérer les données relatives aux bureaux de votes.  Ces données seront stockées dans le fichier Bvotes.dat qui doit contenir les champs : - Id_BV          (l'identifiant du bureau de vote) -Adresse_BV  (l'adresse du bureau de vote) - Id_President  (l'identifiant du président du BV) - Id_VPresident (l'identifiant du vice président du BV) - Id_Secret  (l'identifiant du secrétaire du BV) 
 
Les membres d'un BV doivent être des potentiels électeurs. 
 
Les fonctions à implémenter sont : o ajout_BV : pour ajouter un Bureau de Vote 
Ce travail doit être réalisé par groupe de 4 étudiants. 
 
Date : 12 mars 2019   Date de remise : 30 mai 2019 

 
 
o modif_BV :  pour modifier une donnée d'un Bureau de Vote. 
 
3- Module Electeurs Ce module permettra de gérer les données relatives aux potentiels électeurs.  Ces données sont stockées dans le fichier elect.dat dont les champs sont : - CIN         (le CIN  est le numéro de la carte d'identification nationale de l'électeur. Il identifie l'électeur) - nom  (le nom de l'électeur) - prénom (le prénom de l'électeur) - Adresse  (l'adresse de l'électeur) - BV  (l'identifiant du Bureau de vote assigné à l'électeur)   Les fonctions à implémenter sont : a) ins_elect : pour enregistrer un électeur b) modif_elect : pour modifier une donnée d’un électeur 
 
4- Module Candidats Ce module permettra de gérer les données relatives aux candidats inscrits.  Ces données seront stockées dans le fichier candid.dat   qui contiendra au moins les champs suivants : - Id_candid     (un code qui identifie le candidat; ce code est unique) - Nom  (le nom du candidat)    - Prénom (le prénom du candidat)  - Dat_Nais (Date de naissance du candidat) - Adresse (adresse du candidat) - Email (adresse email du candidat) - tél  (le numéro de téléphone du candidat) - type  (Type de candidat: indépendant ou sous bannière d'un parti politique) - Date_ins       (la date d'inscription du candidat) 
 
Le champ type, relatif au type de candidat, prendra comme valeur 0 s'il s'agit d'un candidat indépendant ou la valeur de l'Id_PP de son parti politique dans le cas contraire. 
 
 
Les fonctions à implémenter sont : o ins_cand  : pour inscrire un candidat  o modif_cand : pour modifier une donnée relative à un candidat donné 
 
5- Module Votes Ce module permettra de gérer les votes des électeurs.  Les données relatives aux votes seront stockées dans le fichier votes.dat   qui contiendra au moins les champs suivants : 
 
- Id_vote  (l'identifiant du vote) - Date_vote       (la date du vote.  Cette valeur doit être saisie automatiquement à partir de la date du système) - BV   (l'identifiant du Bureau de vote assigné à l'électeur) - CIN          (le CIN  de l'électeur. Il identifie l'électeur) - id_candid_1  (l'identifiant du candidat 1 choisi) - id_candid_2  (l'identifiant du candidat 2 choisi) - id_candid_3  (l'identifiant du candidat 3 choisi) 
Lors du vote,  chaque électeur a la possibilité de choisir au maximum 3 candidats.  Lors du choix d'un candidat, son identifiant est inséré dans le champ concerné.  Si l'électeur a été voté et n'a choisi aucun candidat, alors le vote est considéré comme un vote blanc.   Le vote blanc est normalement comptabilité et est pris en compte dans les calculs des résultats.  Exemple, pour un département donné, le pourcentage de votes obtenu par un candidat au sénat est donné par la formule:    _                                     Nombre total de votes obtenu par le candidat                                 _          Nombre total de votes non blancs pour ce Dpt + Nombre total de votes blancs pour ce Dpt 
 
 
6- Module Rapports et Résultats Ce module permettra de générer les rapports et les résultats du scrutin.  Il comprendra les fonctions suivantes : a) List_Electeurs :  qui donne la liste des électeurs par département et par Bureau de Vote (Département, Id_BV, CIN, Nom, Prénom, Adresse Electeur) b) List_Candid : qui donne la liste des candidats au Sénat par département (Département, Nom, Prénom, CIN, Type). c) List_BV  : qui donne la liste des Bureaux de vote (Id_BV, Adresse, Nom et prénom des membre du BV); d) Résultats: qui donne la liste des résultats par département et par candidat (Département, Nom et Prénom candidat, total votes obtenu, pourcentage votes obtenu).  Il faudra également prendre le soin d'afficher, pour chaque département, le nombre total de votes non blancs et le nombre total de votes blancs. Les résultats seront affichés sous forme de tableaux et en ordre décroissant du pourcentage de votes obtenu.  
 
 
Note 1: - Les champs Adresse doivent comprendre plusieurs sous champs (No Rue, Rue, Département,) - Les numéros de téléphone doivent respecter un format spécifique. 
 
Note 2: Afin de faciliter les calculs, vous devez utiliser un fichier param.dat qui stockera les paramètres suivants pour chaque département: - Nombre Total de votes non blancs - Nombre Total de votes blancs  Ces paramètres auront pour valeur initiale 0 et donneront, à tout instant, respectivement, le nombre total de votes non blancs et le nombre total de votes blancs pour le département concerné. 
 
Note 3:  - toute fonction doit être documentée             - les fonctions, si nécessaire, doivent avoir des paramètres (pas de variables globales)   - utilisation intelligente et justifiée des pointeurs. 
 
Note 4 : Découpage des codes sources du projet.  Les fichiers sources suivants sont obligatoires : - un fichier election.h contenant les structures de données, les nouveaux types de données, les variables et les constantes globales . - un fichier ge_parti.c  contenant les fonctions de base de manipulation des données et fichier relatifs aux partis politiques. 

 
- un fichier ge_BV.c contenant les fonctions de base de manipulation des données et fichiers relatifs aux Bureaux de Votes. - un fichier ge_elect.c contenant les fonctions de base de manipulation des données et du fichier relatifs aux électeurs. - un fichier ge_candi.c contenant les fonctions de base de manipulation des données et fichiers relatifs aux candidats - un fichier ge_votes.c contenant les fonctions de base de manipulation des données et fichiers relatifs aux votes - un fichier rapp.c contenant les fonctions permettant la génération des rapports de gestion et des résultats du scrutin. - un fichier velectro.c contenant :    - le menu général et les sous menus,    - le main et l'appel du menu général. 
 
Note 5:  Avant la présentation, au plus tard la veille, les fichiers de données doivent être alimentés comme suit: - créer au moins 5 bureaux de vote par département - enregistrer au moins 50 électeurs par département - inscrire 10 partis politiques - inscrire 5 candidats par département dont 1 indépendant - Le jour du vote, faire voter les électeurs sachant que certains voteront blanc et d'autres ne participent pas au scrutin. 
 
