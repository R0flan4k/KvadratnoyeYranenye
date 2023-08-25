# Quadratic Equation Solver
![Quadratic equation format](images/equation_format.png)

## Program Purpose

This program is designed to solve a quadratic equation, but it can do more than that. 

## Program Features

- Solve 0th, 1st and 2nd degree equations.
- Communicating with the user in different languages (the list of languages will be expanded).
- Testing computational functions

## Installation:
Bend the repository and compile the files

First step:
~~~
git clone https://github.com/R0flan4k/Quadratic.git
~~~

Second step:
~~~
cd Quadratic\QuadraticEquationSolver
~~~

Third step:
~~~
make
~~~

## Usage

~~~
qSolver.exe --*flags* *arguments*
~~~

## Flags
This program supports the following flags (the list will be extended in the future)

- Start tests according to the test_arguments.txt file. The list of files with tested input data can be expanded.

--test

~~~
qSolver.exe --test test_arguments.txt
~~~

- Get the coefficients of an equation from the command line.

--coeffs

~~~
qSolver.exe --coeffs 1 -1.618 3.14
~~~
