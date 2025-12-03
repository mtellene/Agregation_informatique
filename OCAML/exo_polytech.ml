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


(*Exercice 4*)
let min3entiers a b c = min2entiers (min2entiers a b) c
let a = 3 and b = 3 and c = 10
let () = print_endline (string_of_int (min3entiers a b c))












































