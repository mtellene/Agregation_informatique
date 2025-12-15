let rec display_ht_rec ht i =
	let rec display_list l ht i =
		match l with
		| [] -> Printf.printf "[]\n" ; display_ht_rec ht (i+1)
		| x::y -> Printf.printf "%d -> " x ; display_list y ht i
	in 
	if i < (Array.length ht) then
		match ht.(i) with
		| [] -> Printf.printf "%d : []\n" i ; display_ht_rec ht (i+1)
		| l -> Printf.printf "%d : " i ; display_list l ht i

let display_ht ht = display_ht_rec ht 0

let rec print_list l =
	match l with
	| [] -> Printf.printf "[]\n"
	| x::y -> Printf.printf "%d -> " x ; print_list y


(*
les clés de la table de hachage sont des string
elles sont suivies d'un tableau de valeur
*)

type hashtable = string list array

(*m est le nombre d'entrées dans le tableau*)
let create m = if m <= 0 then failwith "Création impossible" else Array.make m []

(*attention cette fonction peut renvoyer un hash négatif => débordement arithmétique*)
let hash expr = 
	let n = String.length expr in
	let rec hash acc i =
		if i=n then acc else hash (31*acc + Char.code expr.[i]) (i+1) in
	hash 0 0
	
(*
détermine l'endroit où l'on doit ranger dans la hash table
=> attention au débordement arithmétique (land -> et logique pour effacer le bit de signe)
*)

let bucket expr hash_table =
	let h = (hash expr) land max_int in h mod (Array.length hash_table)
	

(*
range la valeur (v) à l'index calculé par la fonction bucket
*)
let put ht expr v =
	let idx = bucket expr ht in ht.(idx) <- v::ht.(idx)
	
(*
fonction qui renvoie la valeur associée à une clé si elle existe dans la table, lève une exception sinon
*)
let get ht expr =
	let idx = bucket expr ht in
	match ht.(idx) with
	| [] -> failwith "Pas de valeur associée"
	| _ -> ht.(idx)
	
	
(*programme*)
let ht = create 10

let expr = "hey"
let () = 
	put ht "salut" 5 ;
	put ht "bonjour" 8 ;
	put ht "adieu" 1 ;
	put ht "hey" 3 (*;
	display_ht ht*)

	
let tmp = get ht expr
let () = Printf.printf "Affiche des valeurs de la clé %s : " expr ; print_list tmp



(*
let () = Printf.printf "Présence de %s : %d\n" t (get ht t)

let ht = put ht t 5
let () = display_ht ht
*)







