*This project has been created as part of the 42 curriculum by smakkass.*

## Description
Push_swap is a sorting challenge built around two stacks (A and B) and a minimal instruction set (push, swap, rotate, reverse-rotate). The goal is to output the shortest possible sequence of operations that sorts the initial stack of integers. This repository provides the main solver (`push_swap`) and an optional checker (`checker`) that executes and validates a given set of instructions.

## Instructions
- **Build push_swap:** `make` (produces `push_swap`).
- **Build checker (bonus):** `make bonus` (produces `checker`).
- **Clean objects:** `make clean`; **full clean:** `make fclean`; **rebuild:** `make re`.
- **Run push_swap:** `./push_swap 2 1 3` or `./push_swap "2 1 3"` Prints the operation list to stdout.
- **Run checker:** `./push_swap 2 1 3 | ./checker 2 1 3` to verify the produced operations. The checker reads instructions from stdin and prints either 'OK' or 'KO' to stdout.

## Error Handling
In case of error, the program prints "Error" to stderr.
- Errors include, for example: some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.

## Resources
- **Sorting algorithms:**		https://www.geeksforgeeks.org/dsa/sorting-algorithms/
- **Greedy Algorithms:**		https://www.geeksforgeeks.org/dsa/greedy-algorithms/
- **The Turk Algorithm:**		https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- **Push_swap Visulizer:**		https://github.com/o-reo/push_swap_visualizer
- **Push_swap Tester:**			https://github.com/gemartin99/Push-Swap-Tester
- **AI usage:** 				AI was uset for brainstorming algorithm ideas and pre evaluating the pros and cons of each algorithm.

## Visual Example
<h3 align="center">5 Elements</h3>
<p align="center">
  <img
    src="https://github.com/saidmakkass/push_swap/blob/gif/gif/push_swap_visual_example_5_elements.gif?raw=true"
    width="600"
  />
</p>

<h3 align="center">100 Elements</h3>
<p align="center">
  <img
    src="https://github.com/saidmakkass/push_swap/blob/gif/gif/push_swap_visual_example_100_elements.gif?raw=true"
    width="600"
  />
</p>

<h3 align="center">500 Elements</h3>
<p align="center">
  <img
    src="https://github.com/saidmakkass/push_swap/blob/gif/gif/push_swap_visual_example_500_elements.gif?raw=true"
    width="600"
  />
</p>