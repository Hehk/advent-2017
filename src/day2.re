/* http://adventofcode.com/2017/day/2 */
[@bs.val] external parseInt : string => int = "parseInt";

[@bs.val] external isNaN : int => bool = "isNaN";

let parse_line = (input) =>
  input
  |> Js.String.split(" ")
  |> Array.to_list
  |> List.map(parseInt)
  |> List.filter((n) => ! isNaN(n));

let run_line = (input) => {
  let (min, max) =
    input
    |> parse_line
    |> List.fold_left(
         ((min, max), n) => (n < min ? n : min, n > max ? n : max),
         (1000, 0)
       );
  max - min
};

let test_elem = (n, list) =>
  list |> List.fold_left((acc, n_2) => n != n_2 && n_2 mod n == 0 ? n_2 : acc, (-1));

let run_line_2 = (input) => {
  let (a, b) =
    input
    |> parse_line
    |> ((list) => List.fold_left((acc, n) => {
      switch (test_elem(n, list)) {
      | -1 => acc
      | x  => (n, x)
      }
    }, (0,0), list));

  b / a;
};

let create_run = (map, input) =>
  input
  |> Js.String.split("\n")
  |> Array.map(map)
  |> Array.fold_left((a, b) => a + b, 0);

let run = create_run(run_line);

let run_2 = create_run(run_line_2);
