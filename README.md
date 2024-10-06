# push_swap

## Project Overview
The push_swap project involves creating an algorithm to sort a stack of numbers as efficiently as possible using a predefined set of instructions with two stacks. The program outputs a sequence of push_swap instructions that sorts the input integers.

## Instruction Set
For the following instructions, if the instruction is not possible, the part of it that can’t be executed won’t.

| code       | short Description                                           |
|------------|-------------------------------------------------------------|
| `sa`       | Swaps the 2 top elements of stack a                          |
| `sb`       | Swaps the 2 top elements of stack b                          |
| `ss`       | Runs both sa and sb                                          |
| `pa`       | Moves the top element of stack b at the top of stack a       |
| `pb`       | Moves the top element of stack a at the top of stack b       |
| `ra`       | Shifts all elements of stack a from bottom to top            |
| `rb`       | Shifts all elements of stack b from bottom to top            |
| `rr`       | Runs both ra and rb                                          |
| `rra`      | Shifts all elements of stack a from top to bottom            |
| `rrb`      | Shifts all elements of stack b from top to bottom            |
| `rrr`      | Runs both 	both rra and rrb                                  |

## Algorithm
The push_swap algorithm is designed to sort a stack of integers using the least number of operations. Here’s a detailed breakdown of the algorithm:

### 1. Initial Setup:
The algorithm starts by pushing all but three elements from stack_a to stack_b. This is because sorting three elements is straightforward and can be done with a few operations.

### 2. Sorting Three Elements:
The three remaining elements in stack_a are sorted using a minimal number of operations. This ensures that when elements are pushed back from stack_b, they can be easily inserted into their correct positions.

### 3. Finding the Cheapest Move:
For each element in stack_b, the algorithm calculates the “cost” of moving it to its correct position in stack_a. The cost is determined by the number of operations required to move the element to the top of stack_b and then to its correct position in stack_a.

### 4. Executing the Move:
The algorithm selects the element with the lowest cost and performs the necessary operations to move it from stack_b to stack_a. This involves rotating or reversing stack_a and stack_b to position the element correctly.

### 5. Refreshing Nodes:
After moving an element from stack_b to stack_a, the algorithm updates the positions of the remaining elements in stack_b and recalculates the costs for the next move.

### 6 . Final Sorting:
Once all elements have been moved from stack_b to stack_a, the algorithm performs a final sort on stack_a to ensure all elements are in the correct order. This may involve a few additional rotations or swaps.

## Bonus
The bonus part involves writing a program named checker, which takes stack_a formatted as a list of integers as an argument. checker will then wait and read instructions from the standard input. Once all instructions have been read, checker will execute them on the stack received as an argument (after giving the instructions, press Ctrl + D).

after executing those instructions, stack_a is sorted and stack_b is empty, checker will display “OK”; otherwise, it will display “KO”. If checker arguments are invalid, it displays “Error”.

The checker code can be found in the checker_files directory file in this repository.

## Getting Started

### Compiling
Run the following commands:

#### To compile
```
make
```
#### To remove objects
```
make clean
```
#### To remove objects and the binary file (program)
```
make fclean
```
#### To re-compile
```
make re
```
#### Usage
after comiling it run it with the list of integers to be sorted as arguments. i.e. This will output if the program doesn't run into any problems:
```
./push_swap 3 1 2
```
