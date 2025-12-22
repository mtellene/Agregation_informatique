let max x y = if (x>y) then x else y

type 'a bintree =
	| E
	| N of 'a bintree * 'a * 'a bintree

let rec print_bintree to_string indent t =
	match t with
  	| E -> ()
  	| N (l, x, r) ->
      		print_bintree to_string (indent ^ "   ") r;
      		Printf.printf "%s%s\n" indent (to_string x);
      		print_bintree to_string (indent ^ "   ") l

let rec size t = 
	match t with
	| E -> 0
	| N(l,_,r) -> 1 + size l + size r
	
let rec height t =
	match t with
	| E -> 0
	| N(l,_,r) -> 1 + max (height l) (height r)
	
let rec prefixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,x,r) -> Printf.printf "%d" x ; prefixe l ; prefixe r
	
let rec infixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,x,r) -> infixe l ; Printf.printf "%d" x ; infixe r
	
let rec postfixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,x,r) -> postfixe l ; postfixe r ; Printf.printf "%d" x

let ab_vide = E
let ab = N (
		N(E,3,E),
		5,
		N(E,4,E)
	)
	
let () = print_bintree string_of_int "" ab
let () = Printf.printf "La taille de l'arbre est de %d\n" (size ab)
let () = Printf.printf "La hauteur de l'arbre est de %d\n" (height ab)
let () = Printf.printf "Parcours prefixe : " ; (prefixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours infixe : " ; (infixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours postfixe : " ; (postfixe ab) ; Printf.printf "\n"

