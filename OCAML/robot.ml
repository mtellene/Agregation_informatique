type direction_absolue = Nord | Sud | Est | Ouest
type direction_relative = Gauche | Droite
type coordonnees = int * int

type legume = Haricot | Carotte | Courge
type fleur = Rose | Pissenlit | Tournesol
type fruit = Poirier | Bananier | Figuier
type couleur = Rose | Rouge | Bleu
type plante = Legume of legume | Fleur_Couleur of (fleur * couleur) | Arbre_Fruitier of fruit

type taille = Petit | Moyen | Grand
type contenu_arrosoir = Vide | Rempli of int
type outil = Beche of taille | Pioche | Arrosoir of contenu_arrosoir

type objet = Plante of plante | Outil of outil | Panier_Vide | Panier_Un of legume | Panier_Deux of (legume*legume)
type contenu_case = Robinet | Objet of objet

let changer_direction da dr =
	match (da, dr) with
	| (Nord, Gauche) -> Ouest
	| (Nord, Droite) -> Est
	| (Sud, Gauche) -> Est
	| (Sud, Droite) -> Ouest
	| (Est, Gauche) -> Sud
	| (Est, Droite) -> Nord
	| (Ouest, Gauche) -> Nord
	| (Ouest, Droite) -> Sud
	
let string_of_direction d =
	match d with
	| Nord -> "Nord"
	| Sud -> "Sud"
	| Est -> "Est"
	| Ouest	-> "Ouest"
	
let mouvoir da n (x,y) =
	match da with
	| Nord -> (x+n,y)
	| Sud -> (x-n,y)
	| Est -> (x,y-n)
	| Ouest -> (x,y+n)
	
let da : direction_absolue = Est
let dr : direction_relative = Gauche
let () = Printf.printf "Nouvelle direction %s\n" (string_of_direction (changer_direction da dr))

let coord : coordonnees = mouvoir da 5 (0,0)
let () = Printf.printf "Déplacement : (0,0) à (%d,%d)\n" (fst coord) (snd coord)


let case = Fleur_Couleur (Rose, Bleu)
let o = Arrosoir (Rempli 1)
let obj = Panier_Vide
