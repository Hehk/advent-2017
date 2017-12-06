/* http://adventofcode.com/2017/day/2 */
[@bs.val] external parseInt : string => int =
  "parseInt";

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
         ((min, max), n) => (
           n < min ? n : min,
           n > max ? n : max
         ),
         (1000, 0)
       );
  max - min
};

let run = (input) =>
  input
  |> Js.String.split("\n")
  |> Array.map(run_line)
  |> Array.fold_left((a, b) => a + b, 0);
