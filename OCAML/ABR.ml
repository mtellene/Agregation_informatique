let max x y = if (x>y) then x else y
 
type ('k, 'v) abr =
	| E
	| N of ('k, 'v) abr * 'k * 'v * ('k, 'v) abr

let rec size t = 
	match t with
	| E -> 0
	| N(l,_,_,r) -> 1 + size l + size r
	
let rec height t =
	match t with
	| E -> 0
	| N(l,_,_,r) -> 1 + max (height l) (height r)

let rec prefixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,k,v,r) -> Printf.printf "(%s,%d)," k v ; prefixe l ; prefixe r
	
let rec infixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,k,v,r) -> infixe l ; Printf.printf "(%s,%d)," k v ; infixe r
	
let rec postfixe t =
	match t with
	| E -> Printf.printf ""
	| N(l,k,v,r) -> postfixe l ; postfixe r ; Printf.printf "(%s,%d)," k v


let rec find t k =
	match t with
	| E -> failwith "Clé non trouvée"
	| N(l,k2,v,r) ->
		if (k>k2) then find r k
		else if (k<k2) then find l k
		else v
		
let rec add t k v =
	match t with
	| E -> N(E,k,v,E)
	| N(l,k2,v2,r) ->
		if (k>k2) then N(l, k2, v2, add r k v)
		else if (k<k2) then N(add l k v, k2, v2, r)
		else N(l,k,v,r)
		
let rotation_droite t =
	match t with
	| N(N(t1, ku, vu, t2), kv, vv, t3) -> N(t1 ,ku, vu, N(t2, kv, vv, t3))
	| t -> t
	
let rotation_gauche t =
	match t with
	| N(t1, ku, vu, N(t2, kv, vv, t3)) -> N(N(t1 ,ku, vu, t2), kv, vv, t3)
	| t -> t

let ab_vide = E
let ab = N (
		N(E,"bar",4,N(E,"baz", 2,E)),
		"foo", 1,
		N(E,"gee",1,E)
	)
	
let () = Printf.printf "La taille de l'arbre est de %d\n" (size ab)
let () = Printf.printf "La hauteur de l'arbre est de %d\n" (height ab)
let () = Printf.printf "Parcours prefixe : " ; (prefixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours infixe : " ; (infixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours postfixe : " ; (postfixe ab) ; Printf.printf "\n"

let cle = "foo"
let () = Printf.printf "Valeur associée à la clé %s : %d\n" cle (find ab cle)

(*let ab = add ab "salut" 8
let ab = add ab "gato" 6
let () = Printf.printf "Parcours infixe : " ; (infixe ab) ; Printf.printf "\n"
*)
let ab = rotation_droite ab
let () = Printf.printf "Parcours prefixe : " ; (prefixe ab) ; Printf.printf "\n"

let ab = rotation_gauche ab
let () = Printf.printf "Parcours prefixe : " ; (prefixe ab) ; Printf.printf "\n"



