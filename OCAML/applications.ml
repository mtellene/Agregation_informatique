let print_list l =
	let aux = Buffer.create (List.length l) in List.iter (fun c -> Buffer.add_char aux c) l;
	Buffer.contents aux


(*Exercice 41*)
let rec ajout c n l = if n==0 then l else ajout c (n-1) (l@[c])

let rec decomp_rec l l_bis =
	match l with
	| [] -> l_bis
	| (x,y)::_ -> ajout y x l_bis

let decompression l = decomp_rec l []
	

let l = [(3,'a') ; (1,'b') ; (1,'a') ; (2,'b')]
let l_decomp = decompression l
let () = print_list (l_decomp)

