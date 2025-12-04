let () = print_endline "Début exécution"


(*Exercice 2 : Aires*)
let aire_carre a = a*a
let a = 4
let () = print_endline (string_of_int (aire_carre a))

let aire_rect a b = (a+b)*2
let a = 4 and b = 8
let () = print_endline (string_of_int (aire_rect a b))

let aire_cercle r = Float.pi *. r *. r 
let r = 4.0
let () = print_endline (string_of_float (aire_cercle r))


(*Exercice 3 : Prédicats*)
let positif x = if x>0 then true else false
let x = -5
let () = print_endline (string_of_bool (positif x))

let pair x = if (x mod 2) == 0 then true else false
let x = 5
let () = print_endline (string_of_bool (pair x))


(*Exercice 4*)
let min2entiers a b = if a<b then a else b
let a = 3 and b = 3
let () = print_endline (string_of_int (min2entiers a b))


(*Exercice 5*)
let max2entiers a b = if a<b then b else a
let a = 3 and b = 10
let () = print_endline (string_of_int (max2entiers a b))


(*Exercice 6*)
let min3entiers a b c = min2entiers (min2entiers a b) c
let a = 3 and b = 3 and c = 10
let () = print_endline (string_of_int (min3entiers a b c))


(*Exercice 7*)
let rec facto n = if n==0 then 1 else n * (facto (n-1)) 
let n = 8
let () = print_endline (string_of_int (facto n))


(*Exercice 8 -> calcul x^y*)
let rec puissance_rec x y = if y==0 then 1 else x * (puissance_rec x (y-1))
let x = 8 and y = 5
let () = print_endline (string_of_int (puissance_rec x y))


(*Exercice 9*)
let rec pgcd x y = if y==0 then x else (pgcd y (x mod y))
let x = 8 and y = 8
let () = print_endline (string_of_int (pgcd x y))


(*Exercice 10*)
let rec somme_n n = if n==1 then 1 else n + (somme_n (n-1))
let n = 150
let () = print_endline (string_of_int (somme_n n))

(*Exercice 11*)
let rec somme_n_impair n = if n==1 then 1 else 
	if (n mod 2) == 1 then n + (somme_n_impair (n-1)) else somme_n_impair (n-1)
let n = 150
let () = print_endline (string_of_int (somme_n_impair n))


(*Exercice 12*)
let rec eucli x y acc = if (x<y) then (acc,x) else (eucli (x-y) y (acc+1))
let division_eucli x y = if y!=0 then (eucli x y 0) else failwith "division by 0"
let x = 803 and y = 123
let (a,b) = division_eucli x y
let () = Printf.printf "quotient = %d, reste = %d\n" a b


(*Exercice 14*)
let rec fibo n = if n==0 then 0 else
	if n==1 then 1 else (fibo (n-2)) + (fibo (n-1))
let n = 1
let () = Printf.printf "fibo de %d = %d\n" n (fibo n)


let rec check_fibo x n = if x>fibo(n) then (check_fibo x (n+1)) else
	if x==fibo(n) then true else false
let est_dans_fibo x = check_fibo x 0
let x = 0
let () = Printf.printf "%d dans fibonacci : %b\n" x (est_dans_fibo x)


(*Exercice 15*)
type semaine = Lundi | Mardi | Mercredi | Jeudi | Vendredi | Samedi | Dimanche

let est_weekend d = 
	match d with
	| Samedi | Dimanche -> true
	| _ -> false
	
let jour : semaine = Samedi
let () = print_endline (string_of_bool (est_weekend jour))


(*Exercice 17*)
type pays = Allemagne | Belgique | Espagne | Italie | Luxembourg | Suisse

let capitale p = 
	match p with
	| Allemagne -> "Berlin" 
	| Belgique -> "Bruxelles" 
	| Espagne -> "Madrid" 
	| Italie -> "Rome"
	| Luxembourg -> "Luxembourg" 
	| Suisse -> "Bern"
	
let p : pays = Italie
let () = Printf.printf "La capitale est %s\n" (capitale p) 


(*Exercice 23*)
let rec appartient_l x l =
	match l with
	| [] -> false
	| y::z -> if x==y then true else appartient_l x z
	
let l = [1;2;3] and x = 4
let () = Printf.printf "%d dans la liste : %b\n" x (appartient_l x l)


(*Exercice 24*)
let rec min_liste_rec l min =
	match l with
	| [] -> min
	| x::y -> if x<min then min_liste_rec y x else min_liste_rec y min
	
let min_liste l = 
	match l with
	| [] -> failwith "Liste vide"
	| x::_ -> min_liste_rec l x
	
let l = [2;1;3]
let () = Printf.printf "Minimum de la liste : %d\n" (min_liste l)


(*Exercice 25*)
let rec max_liste_rec l max =
	match l with
	| [] -> max
	| x::y -> if x>max then max_liste_rec y x else max_liste_rec y max
	
let max_liste l = 
	match l with
	| [] -> failwith "Liste vide"
	| x::_ -> max_liste_rec l x
	
let () = Printf.printf "Maximum de la liste : %d\n" (max_liste l)






















































