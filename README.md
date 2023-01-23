# playing-with-numbers-in-C

Each `.c` file in this repository is a different program, and should be compiled separately.

### average.c
This C program calculates the average of any amount of numbers supplied by the user, using dynamic memory allocation. Compilation example: `gcc average.c -o average`.

### fibonacci.c
This C program calculates and stores (in memory) the Fibonacci sequence (only as needed, according to user input - it uses dynamic memory management). Compilation example: `gcc fibonacci.c -o fibonacci`.

### primes.c
This is a C program that calculates and prints all prime numbers between a range specified by the user. Compilation example: `gcc primes.c -o primes`.

### Compilation
I have added a makefile, so if you have `make` and `gcc`, all you need to do is clone the repository, enter it, and then type `make`.
