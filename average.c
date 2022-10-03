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
*	This is a C program that calculates the average of any amount of numbers
* supplied by the user, using dynamic memory allocation.
*/


#include <stdio.h>
#include <stdlib.h>


unsigned long getAmount()
{
	unsigned long nElements;
	printf("\nType how many numbers do you want to provide to calculate the average [0 to exit]: ");
	scanf("%lu", &nElements);
	return nElements;
}


double* allocateMemory(unsigned long nElements)
{
	double* array = NULL;
	array = malloc(sizeof(double) * nElements);

	if(array == NULL)
	{
		printf("\nError: not enough memory! Exiting...\n");
		free(array);
		exit(1);
	}

	return array;
}


int getElements(unsigned long nElements, double* array)
{
	unsigned long count;

	for(count = 0; count < nElements; count++)
	{
		printf("Type the element [%lu]: ", count+1);
		scanf("%lf", &array[count]);
	}

	return 0;
}


int showElements(unsigned long nElements, double* array)
{
	unsigned long count;

	printf("\nCalculating the average of the following numbers:\n");

	for(count = 0; count < nElements; count++)
		printf("%.2lf\t", array[count]);

	return 0;
}


double calculateAverage(unsigned long nElements, double* array)
{
	unsigned long count;
	double result = 0.0;

	for(count = 0; count < nElements; count++)
		result += array[count];

	result /= nElements;

	printf("\n\n\tThe average is: %.2lf\n", result);

	return result;
}


int main(void)
{
	unsigned long nElements;
	double* array = NULL;

	nElements = getAmount();

	while(nElements)
	{
		array = allocateMemory(nElements);
		getElements(nElements, array);
		showElements(nElements, array);
		calculateAverage(nElements, array);

		free(array);
		array = NULL;

		nElements = getAmount();
	}

	return 0;
}
