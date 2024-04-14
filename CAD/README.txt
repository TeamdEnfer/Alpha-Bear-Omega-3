Voici une description de la nomenclature pour les fichier de CAD pour le projet de session S4 en génie robotique
Les nom des fichiers sont en minuscule avec des _ pour séparer les mots.

x_y_concept_composante_extra_extra_z
_______________________________________________________________________________________
x:   		Choix de Conception Générale
		 	-0:Système avec poulie dentelée et courroie
_______________________________________________________________________________________
y:   		Version du concept Général
			-1: Système de poulie pour le Tibia et pour le Fémur
		 	-2: Système de poulie pour le Tibia et Barre pour le Fémur
_______________________________________________________________________________________
concept:	pour l'instant, représente le choix de conception comme x mais 
		sera décrit en mot. **sujet à changement vue la répétition
		 	-belt
			-directDrive 	
_______________________________________________________________________________________
composante:   	Nom de la pièce en question
			-body
		 	-femur
		 	-shaft
		 	-bar_trouee
_______________________________________________________________________________________
extra_extra:	Utilisée pour donner des informations suplémentaires sur la pièce.
		 	-60mm_en_L
		 	-simple_right
			-court
_______________________________________________________________________________________
z:   		Version de la pièce particulière auquel le nom est attaché.
_______________________________________________________________________________________

QUELQUES EXEMPLES:
	0_2_1_belt_epaule_1:	première version de l'épaule pour le système de drive belt pour
				le tibia et la barre pour le fémur
	0_0_2_belt_femur_une_piece1_0

*À noter qu'il est possible qu'une même pièce soit utilisé dans deux concept différent.
 Dans ce cas, le numéro de la version origionale est concervé.