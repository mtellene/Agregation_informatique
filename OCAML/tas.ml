let max x y = if (x>y) then x else y

(*
implémentation d'un tas_min sous forme d'arbre
N(l,x,r) où x >= l et x >=r ; l et r sont des tas
*)

type 'a tas =
	| E
	| N of 'a tas * 'a * 'a tas

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
	| N(l,x,r) -> Printf.printf "%d " x ; prefixe l ; prefixe r
	
let rec infixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,x,r) -> infixe l ; Printf.printf "%d " x ; infixe r
	
let rec postfixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,x,r) -> postfixe l ; postfixe r ; Printf.printf "%d " x
	
let get_min tas =
	match tas with 
	| E -> failwith "Arbre vide"
	| N(_,x,_) -> x
	
let rec merge t1 t2 =
	match t1, t2 with
	| E, t | t, E -> t
	| N(l1, x1, r1), N(l2, x2, r2) ->
		if (x1<x2) then N(merge l1 r1 ,x1, t2)
		else N(t1, x2, merge l2 r2)
		
let delete_min tas =
	match tas with
	| E -> failwith "Arbre vide"
	| N(l, x, r) -> merge l r
	
let ajout tas x =
	match tas with
	| E -> N(E,x,E)
	| N(l,x1,r) -> merge (N(E,x,E)) tas
	
	

let tas = N(
		N(N(N(E,5,E),2,N(E,8,E)),2,N(N(E,3,E),3,N(E,4,E))),
		1,
		N(N(E,11,E),10,N(E,15,E))
	) 
	
let () = Printf.printf "La taille de l'arbre est de %d\n" (size tas)
let () = Printf.printf "La hauteur de l'arbre est de %d\n" (height tas)
let () = Printf.printf "Parcours prefixe : " ; (prefixe tas) ; Printf.printf "\n"
let () = Printf.printf "Minimum de l'arbre est %d\n" (get_min tas)

let tas = delete_min tas
let () = Printf.printf "La taille de l'arbre est de %d\n" (size tas)
let () = Printf.printf "Parcours prefixe : " ; (prefixe tas) ; Printf.printf "\n"
let () = Printf.printf "Minimum de l'arbre est %d\n" (get_min tas)

let tas = ajout tas 1
let () = Printf.printf "La taille de l'arbre est de %d\n" (size tas)
let () = Printf.printf "Parcours prefixe : " ; (prefixe tas) ; Printf.printf "\n"
let () = Printf.printf "Minimum de l'arbre est %d\n" (get_min tas)







