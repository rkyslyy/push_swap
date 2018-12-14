# push_swap

## Description

Goal of the project was to write two programs in C called `checker` and `push_swap`:

`checker` takes integer arguments and reads instructions on the standard output.
Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

`push_swap` calculates and displays on the standard output using Push_swap instruction language
the quickest way to sort integer arguments received.

## Game rules

• The game is composed of 2 stacks named a and b.<br />
• To start with:<br />
◦ a contains a random number of either positive or negative numbers without any duplicates.<br />
◦ b is empty<br />
• The goal is to sort in ascending order numbers into stack a.<br />
• Following commands are available to reach goal:<br />
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).<br />
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).<br />
ss : sa and sb at the same time.<br />
pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.<br />
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.<br />
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.<br />
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.<br />
rr : ra and rb at the same time.<br />
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.<br />
rrb : reverse rotate b - shift down all elements of stack b by 1. The last elementbecomes the first one.<br />
rrr : rra and rrb at the same time.

### Example
```diff
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
8
5
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
8
5
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```

### The `checker` program
• `checker` takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of
the stack (be careful about the order). If no argument is given checker stops and displays nothing.<br />
• `checker` will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, `checker` will
execute them on the stack received as an argument.<br />
• If after executing those instructions, stack a is actually sorted and b is empty, then
`checker` displays "OK" followed by a ’\n’ on the standard output. In every
other case, `checker` displays "KO" followed by a ’\n’ on the standard output.<br />
• In case of error, `checker` displays "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.<br />

### Example
```diff
./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
```

### The `push_swap` program
• `push_swap` receives as an argument the stack a formatted as a list of integers. The first argument should be at the top
of the stack.<br />
• The program displays the smallest list of instructions possible to sort the stack a, the smallest number being at the top.<br />
• Instructions are separaed by a ’\n’.<br />
• The goal is to sort the stack with the minimum possible number of operations.<br />
• In case of error, `push_swap` displays "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.<br />

### Example
```diff
./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
./push_swap 0 one 2 3
Error
```

## Flags
`checker` programm can be run with various flags:<br />
<br />-v to visualize changes in stacks:
```diff
ARG="6 5 4" ; ./push_swap $ARG | ./checker $ARG -v
[Beginning]
 ↓↓↓↓↓↓↓↓↓
a: 6 ⁀ 5 ⁀ 4|
b: |

[sa]
 ↓↓
a: 5 ⁀ 6 ⁀ 4|
b: |

[rra]
 ↓↓↓
a: 4 ⁀ 5 ⁀ 6|
b: |

OK
```
-h in combination with -v highlights moved numbers or whole stacks by wrapping them in brackets;<br />
-t displays total amount of operation in the end:
```diff
ARG="6 5 4" ; ./push_swap $ARG | ./checker $ARG -v -h -t
[Beginning]
 ↓↓↓↓↓↓↓↓↓
a: 6 ⁀ 5 ⁀ 4|
b: |

[sa]
 ↓↓
a: [5] ⇔ [6] ⁀ 4|
b: |

[rra]
 ↓↓↓
[⇾ a ⇾]: 4 ⁀ 5 ⁀ 6|
b: |

Total amount of operations: 2
___________________________________
OK
```

-i allows to run commands entered to standard output after each operation and sort stack manually 'in real time' while ignoring data from `push_swap`:
```diff
ARG="6 5 4" ; ./push_swap $ARG | ./checker $ARG -v -h -t -i
[Beginning]
 ↓↓↓↓↓↓↓↓↓
a: 6 ⁀ 5 ⁀ 4|
b: |

> Instruction: sa
[sa]
 ↓↓
a: [5] ⇔ [6] ⁀ 4|
b: |

> Instruction: rra
[rra]
 ↓↓↓
[⇾ a ⇾]: 4 ⁀ 5 ⁀ 6|
b: |

> Instruction: ^D
Total amount of operations: 2
___________________________________
OK
```

-r allows to read commands from file:
```diff
cat file.txt
sa
rra
ARG="6 5 4" ; ./checker $ARG -t -r
> Please enter instructions file name: file.txt
Total amount of operations: 2
___________________________________
OK
```

-o writes program output to file called 'log.txt'
```diff
ARG="6 5 4" ; ./push_swap $ARG | ./checker $ARG -t -o
Total amount of operations: 2
___________________________________
OK

cat log.txt
________________________________________________
Instructions memo:                              |
sa - swap first two values in stack 'A'         |
sb - swap first two values in stack 'B'         |
ss - swap first two values in both stacks       |
ra - rotate stack 'A'                           |
rb - rotate stack 'B'                           |
rr - rotate both stacks                         |
rra - reverse rotate stack 'A'                  |
rrb - reverse rotate stack 'B'                  |
rrr - reverse ratate both stacks                |
pa - push top value from stack 'B' to stack 'A' |
pb - push top value form stack 'A' to stack 'B' |
________________________________________________|

_________________
Given values are:
6 5 4

Suggested sorting instructions are:
____
sa
rra
____
Total amount of operations: 2
____________________________________
Values are sorted
```

### Sorting speed
Stacks with size up to 100 values are sorted in less than 700 operations.<br />
Stacks with size up to 500 values are sorted in less than 5500 operations.<br />
Different sorting algorithms are used within `push_swap` program: bubble sort, insertion sort, quicksort etc.

