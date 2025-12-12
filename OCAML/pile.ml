let convert_char_to_int x = Char.code x - Char.code '0'

let create () = ref []

let est_vide s =
	match !s with
	| [] -> true
	| _ -> false

let empiler s x = (*Printf.printf "Ajout de %d\n" x ;*) s := x::!s

let avoir_tete s =
	match !s with
	| [] -> failwith "Pile vide, tete indisponible"
	| x::_ -> x
	
let depiler s =
	match !s with
	| [] -> failwith "Pile vide, dépiler impossible"
	| x::y -> s := y ; x


(*
let s = create ()
let () = Printf.printf "Pile vide ? %b\n" (est_vide s) ;
	empiler s 5 ;
	Printf.printf "Pile vide ? %b\n" (est_vide s) ;
	Printf.printf "Tete de la pile : %d\n" (avoir_tete s) ;
	empiler s 8 ;
	Printf.printf "Tete de la pile : %d\n" (avoir_tete s)

let x = depiler s

let () = Printf.printf "Valeur dépilée : %d\n" x ;
	Printf.printf "Tete de la pile : %d\n" (avoir_tete s)


let check_parenthese s c =
	if est_vide s || depiler s != '(' then false else true

let rec verif_parenthese_rec s expr i = 
	if i = String.length expr then est_vide s else	
		let c = expr.[i] in
		match c with
		| '(' -> empiler s '(' ; verif_parenthese_rec s expr (i+1)
		| ')' -> if (check_parenthese s c) then verif_parenthese_rec s expr (i+1) else false
		| _ -> false

let verif_parenthese expr = verif_parenthese_rec (create ()) expr 0	

let e = "((()())())()(((())))()()()()"
let () = Printf.printf "L'expression %s est bien parenthésée : %b\n" e (verif_parenthese e)
*)


let rec eval_npi_rec s expr i =
	if i = String.length expr then avoir_tete s else
		let c = expr.[i] in
		match c with
		| '+' -> empiler s ((depiler s) + (depiler s)) ; eval_npi_rec s expr (i+1)
		| '-' -> empiler s ((depiler s) - (depiler s)) ; eval_npi_rec s expr (i+1)
		| '*' -> empiler s ((depiler s) * (depiler s)) ; eval_npi_rec s expr (i+1)
		| '/' -> empiler s ((depiler s) / (depiler s)) ; eval_npi_rec s expr (i+1)
		| _ -> empiler s (convert_char_to_int (c)) ; eval_npi_rec s expr (i+1)

let eval_npi expr = eval_npi_rec (create ()) expr 0

let e = "34+5-5*2/"
let () = Printf.printf "Résultat de %s : %d\n" e (eval_npi e)







