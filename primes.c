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
*	This is a C program that calculates and prints all prime numbers
* between a range specified by the user.
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void getRangePrintPrimes();
void printPrime(unsigned int num);

int main()
{
	getRangePrintPrimes();
	return 0;
}


void getRangePrintPrimes()
{
	unsigned int low, high;
	printf("Type the lower bound [positive integer]: ");
	scanf("%u", &low);
	printf("Type the upper bound [positive integer]: ");
	scanf("%u", &high);

	printf("The prime numbers between %u and %u are:\n", low, high);

	while(low <= high)
	{
		printPrime(low);
		low++;
	}
}


void printPrime(unsigned int num)
{
	unsigned int i, flag = 0;

	for(i=2; i<num; i++)
	{
		if(num % i == 0)
		{
			flag = 1;
			break;
		}
	}

	if(flag == 0 && num != 1 && num != 0)
		printf("%u\n", num);
}
