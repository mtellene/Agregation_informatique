(*Exercice 41*)
let rec string_list_of_tuple l =
	match l with
	| [] -> Printf.printf "Liste vide"
	| (x,y)::[] -> Printf.printf "(%d,%c)\n" x y
	| (x,y)::z -> Printf.printf "(%d,%c); " x y ; string_list_of_tuple z

let rec string_list_of_char l =
	match l with
	| [] -> Printf.printf "Liste vide"
	| x::[] -> Printf.printf "%c\n" x
	| x::y -> Printf.printf "%c ; " x ; string_list_of_char y 

let rec ajout c n l = if n==0 then l else ajout c (n-1) (l@[c])

let rec decomp_rec l l_bis =
	match l with
	| [] -> l_bis
	| (x,y)::z -> decomp_rec z (ajout y x l_bis)

let decompression l = decomp_rec l []

let rec get_last_tuple l =
	match l with
	| [] -> failwith "Liste vide"
	| (x,y)::[] -> (x,y)
	| (x,y)::z -> get_last_tuple z
	
(*
let rec ajout_bis x l_bis = 

let rec comp_rec l l_bis =
	match l with
	| [] -> l_bis
	| x::y -> comp_rec y (ajout_bis x l_bis)

let compression l = comp_rec l []
*)	

let l = [(3,'a') ; (1,'b') ; (1,'a') ; (2,'b')]
let () = Printf.printf "Liste initiale : " ; string_list_of_tuple (l)

let l_decomp = decompression l
let () = Printf.printf "Liste après décompression : " ; string_list_of_char (l_decomp)

(*let l_recomp = compression l_decomp
let () = Printf.printf "Liste après compression : " ; string_list_of_tuple (l_recomp)
*)
let () = let (x,y) = get_last_tuple l in Printf.printf "(%d,%c)\n" x y

















