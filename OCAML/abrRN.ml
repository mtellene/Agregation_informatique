let max x y = if (x>y) then x else y

type color = R | B(*pour les arbres rouge noir*)

(*type abrRB -> abr rouge-noir, information sur la couleur du noeud*)
type ('k, 'v) abrRN =
	| E
	| N of color * ('k, 'v) abrRN * 'k * 'v * ('k, 'v) abrRN

let rec size t = 
	match t with
	| E -> 0
	| N(_,l,_,_,r) -> 1 + size l + size r
	
let rec height t =
	match t with
	| E -> 0
	| N(_,l,_,_,r) -> 1 + max (height l) (height r)

let rec prefixe t =
	match t with
	| E -> ()
	| N(c,l,k,v,r) -> 
		if (c=R) then 
			Printf.printf "(rouge %s,%d)," k v
		else 
			Printf.printf "(noir %s,%d)," k v; 
		prefixe l;
		prefixe r
	
let rec infixe t =
	match t with
	| E -> ()
	| N(c,l,k,v,r) ->
		infixe l;
		if (c=R) then
			Printf.printf "(rouge %s,%d)," k v
		else 
			Printf.printf "(noir %s,%d)," k v;
		infixe r
	
let rec postfixe t =
	match t with
	| E -> ()
	| N(c,l,k,v,r) -> 
		postfixe l;
		postfixe r;
		if (c=R) then
			Printf.printf "(rouge %s,%d)," k v
		else 
			Printf.printf "(noir %s,%d)," k v


let rec find t k =
	match t with
	| E -> failwith "Clé non trouvée"
	| N(_,l,k2,v,r) ->
		if (k>k2) then find r k
		else if (k<k2) then find l k
		else v

let lbalance t =
	match t with
	| N(B, N(R, N(R, t1, k1, v1, t2), k2, v2, t3), k3, v3, t4) ->
		N(R, N(B, t1, k1, v1, t2), k2, v2, N(B, t3, k3, v3, t4))
	| t -> t
	
let rbalance t =
	match t with
	| N(B, t1, k1, v1, N(R, t2, k2, v2, N(R, t3, k3, v3, t4))) ->
		N(R, N(B, t1, k1, v1, t2), k2, v2, N(B, t3, k3, v3, t4))
	| t -> t
		
let rec add t k v =
	match t with
	| E -> N(R,E,k,v,E)
	| N(c,l,k2,v2,r) ->
		if (k>k2) then rbalance (N(c, l, k2, v2, add r k v))
		else if (k<k2) then lbalance (N(c, add l k v, k2, v2, r))
		else N(c,l,k,v,r)
		
let rotation_droite t =
	match t with
	| N(c, N(c1, t1, ku, vu, t2), kv, vv, t3) -> N(c1 ,t1 ,ku, vu, N(c, t2, kv, vv, t3))
	| t -> t
	
let rotation_gauche t =
	match t with
	| N(c, t1, ku, vu, N(c1, t2, kv, vv, t3)) -> N(c, N(c1, t1 ,ku, vu, t2), kv, vv, t3)
	| t -> t
	
let insert t k v =
 	match add t k v with
  	| E -> E
  	| N(_, l, k, v, r) -> N(B, l, k, v, r)

	

let ab = N (B, E,"foo", 1,E)

let ab = insert ab "bar" 4
let ab = insert ab "baz" 2
let ab = insert ab "gee" 1

let () = Printf.printf "Parcours prefixe : " ; (prefixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours infixe : " ; (infixe ab) ; Printf.printf "\n"
let () = Printf.printf "Parcours postfixe : " ; (postfixe ab) ; Printf.printf "\n"




