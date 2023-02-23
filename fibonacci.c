/*
* BSD 3-Clause License
*
* Copyright (c) 2022, Wagner Bertholdo Burghausen
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its
*    contributors may be used to endorse or promote products derived from
*    this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


/*
*	This C program calculates and stores (in memory) the Fibonacci sequence
* (only as needed, according to user input - it uses dynamic memory management).
*/


#include <stdio.h>
#include <stdlib.h>


unsigned long getUserInput()
{
	unsigned long input;

	do
	{
		printf("\nType how many elements of the Fibonacci sequence you want to see: ");
		scanf("%lu", &input);

		// user input can't be zero
		if(input == 0)
			printf("\nError! Type a number greater that zero!\n");

	}
	while(input == 0);

	return input;
}


unsigned long* allocateMemory(unsigned long userInput, unsigned long* fib)
{
	fib = realloc(fib, sizeof(unsigned long) * userInput);

	if(fib == NULL)
	{
		printf("\nError: not enough memory! Exiting...\n");
		free(fib);
		exit(1);
	}

	return fib;
}


unsigned long* getFibo(unsigned long* fib, unsigned long* arrayLen)
{
	unsigned long userInput;

	userInput = getUserInput();

	// if necessary, alocate more memory and caculate more fibo numbers
	if(userInput > (* arrayLen))
	{
		fib = allocateMemory(userInput, fib);

		for(unsigned long count = (* arrayLen); count < userInput; count++)
			fib[count] = fib[count-2] + fib[count-1];

		(* arrayLen) = userInput;
	}

	// print the result
	printf("\nThe first %lu numbers of the Fibonacci sequence are:\n", userInput);
	for(unsigned long count = 0; count < userInput; count++)
		printf("%lu\n", fib[count]);

	return fib;
}


int menu(void)
{
	char option;

	printf("\nDo you want to exit the program? ");
	printf("Type y or n: ");
	scanf(" %c", &option);

	switch(option)
	{
		case 'Y':
		case 'y':
			return 0;
		case 'N':
		case 'n':
			return 1;
		default:
			printf("\nError! Please, type only y or n\n");
			printf("Exiting program...\n");
			return 0;
	}
}


int main(void)
{
	unsigned long* fib = NULL;
	unsigned long arrayLen = 2;

	// initialize the fibo sequence
	fib = allocateMemory(arrayLen, fib);
	fib[0] = 0, fib[1] = 1;

	// repeat the program how many times the user wants
	do
		fib = getFibo(fib, &arrayLen);
	while(menu());

	// free the memory before exiting
	free(fib);
	fib = NULL;

	return 0;
}
