/* https://adventofcode.com/2017/day/1 */
[@bs.val] external parseInt : string => int = "parseInt";

let parse = (input) => input |> Js.String.split("") |> Array.to_list |> List.map(parseInt);

let compute_point = (a, b) => a == b ? a : 0;

let run = (input) => {
  let input = parse(input);
  let length = List.length(input);
  input
  |> List.mapi((i, n) => (i + 1) mod length |> List.nth(input) |> compute_point(n))
  |> List.fold_left((a, b) => a + b, 0)
};

let run_2 = (input) => {
  let input = parse(input);
  let length = List.length(input);
  let offset = length / 2;
  input
  |> List.mapi((i, n) => (i + offset) mod length |> List.nth(input) |> compute_point(n))
  |> List.fold_left((a, b) => a + b, 0)
};
