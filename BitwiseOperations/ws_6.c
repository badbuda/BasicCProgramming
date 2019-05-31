/******************************************************************************
* Filename: ws_6.c
*
* Description: Exercises for Worksheet 6 - Bitwise operations
* Version:  1.0
* Created:  23/10/2018 15:45: PM
* Revision:  none
* Compiler:  c-89
*
*Created BY Bareket Sar Shalom                                                 
* Organization: rd58
*******************************************************************************/

#include <stdio.h> /*printf*/


double Pow2 (unsigned int x, int y);
/*a function which returns x*2^y */

int LoopPow2(unsigned int n);
/*******************************************************************************
* a function that receives unsigned int n and returns 1 if it a power of 2,    *
* and 0 otherwise.                                                             *
*******************************************************************************/

int NoLoopPow2(unsigned int n);
/*Like LoopPow2, but without a loop*/

int Add1(unsigned int n);
/*function that add 1 to an unsigned integer without aritmetic operators*/

void Arry3BitOn (unsigned int *arr, int size_arr);
/*******************************************************************************
* function that receives an array of unsigned integers and prints only the ints* 
* that have exactly 3 bits on												   *
*******************************************************************************/

int ByteMirrorLoop(unsigned int n);
/*function that mirrors n, with loop, include all the zeroes*/

int ByteMirrorLoop2(unsigned int n);
/*function that mirrors n, with a loop, exclude all the zeroes*/

int ByteMirror(unsigned int n);
/*function that mirrors n, without a loop, include all the zeroes*/

int F1(unsigned int n);
/*check the bits 2, 6, if they are both on it returns "true"*/

int F2(unsigned int n);
/*check the bits 2, 6, if at least one of them is on it returns "true"*/

int F3(unsigned int n);
/*swaps between bit 3 and bit 5 and returns the new number*/

unsigned int ClosestNum(int n);
/*******************************************************************************
* function that receives an unsigned int and returns the closest(smaller)      *
* number that is divided by 16 without reminder								   *
*******************************************************************************/

void Swap(unsigned int *x,unsigned int *y);
/*function that swaps 2 variables without using a third variable*/
void Swap2(unsigned int *x,unsigned int *y);
/*same as swap*/

int BitsOnLoop(unsigned int n);
/*function that count the number of set bits in an integer with a loop*/

int BitsOn(unsigned int n);
/*function that count the number of set bits in an integer without a loop*/

void FloatBits (float num);
/*program the receives a float from the user and prints its bits*/




/****************************Functions*****************************************/


double Pow2(unsigned int x, int y)
{
	double shift;
		
	if(y<0)
	{
		shift = 1.0 / (1<<(-y));
	}
	else shift = (1<<y);

	return (x * shift);
}



int LoopPow2(unsigned int n)
{
	int i;
	unsigned int tmp = 0;
	
	for(i=0 ; tmp <= n ; ++i)
	{
		tmp = (1<<i);
		if(tmp == n)
		{
			return(1);
		}
	}
	
	return(0);
}


int NoLoopPow2(unsigned int n)
{
	unsigned int tmp = (n - 1);
	if(0 == n)
	{
		return (0);
	}
	if (0 == (tmp & n))
	{
		return (1);
	}
	else return (0);
}

/******************************************************************************/

int Add1(unsigned int n)
{
	unsigned int i = 1;

	while(i)
	{
		if (i == n)
		{
			n = (n << 1);
			break;
		}
		else if (0 == (n & i))
		{
			n = (n | i);
			break;
		}
		else 
		{
			(n = (n ^ i));
			i = (i << 1);
		}
	}
	
	return (n);
}

/******************************************************************************/

void Arry3BitOn (unsigned int *arr, int size_arr)
{
	int i, j;
	unsigned int tmp;
	int count;

	for (i = 0 ; i < size_arr ; ++i )
	{
		count = 0;
	
			for (j = 0 , tmp =0 ; tmp < arr[i] ; ++j )
			{
				tmp = (1 << j);
				if(tmp == (arr[i] & tmp))
				{
					++count;
				}
			}
			
			if (3 == count)
			{
				printf("%d\n", arr[i]);
			}
	}
	
	return;

}

/******************************************************************************/
int ByteMirrorLoop(unsigned int n)
{
	int i;
	unsigned int tmp, result;
	int number_of_bits = (8 * (int)sizeof(unsigned int) - 1);

	result = 0;

	for (i=0 ; i <= number_of_bits ; ++i)
	{
		tmp = (1 << i);	
		if (tmp == (n & tmp))
		{
		tmp = (tmp >> i);
		result = (result | (tmp << (number_of_bits-i)));
		}
	}
	return (result);
}


int ByteMirrorLoop2(unsigned int n)
{
	int i;
	unsigned int tmp, result;
	int number_of_bits = (8 * (int)sizeof(unsigned int));
	int used_bits = 0;
	
	result = 0;

	for(i=0 , tmp = 0;  i < number_of_bits ; ++i )
	{
		tmp = (1 << i);
		if (tmp == (n & tmp))
		{
			used_bits = i ;
		}
	}
	
	
	for (i=0 ; i <= used_bits ; ++i)
	{
		tmp = (1 << i);	
		if (tmp == (n & tmp))
		{
		tmp = (tmp >> i);
		result = (result | (tmp << (used_bits-i)));
		}
	}
	return (result);
	
}

int ByteMirror(unsigned int x)
{
	int bits  = (8 * (int)sizeof(unsigned int));

    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1); /* Swap _<>_ */
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2); /* Swap __<>__*/
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4); /* Swap ____<>____*/
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8); /* Swap ...*/
    x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16); /* Swap ...*/
    
    return x >> (32 - bits);
}

/******************************************************************************/
int F1(unsigned int n)
{
	int result = 0;
	
	result = (((n & (1<<1)) >> 1) & ((n & (1<<5)) >> 5));

	return(result);
}

int F2(unsigned int n)
{
	int result = 0;
	
	result = (((n & (1<<1)) >> 1) | ((n & (1<<5)) >> 5));

	return(result);
}

int F3(unsigned int n)
{
	unsigned int bit3;
	unsigned int bit5;
	
	bit3 = (n & (1<<2));
	bit5 = (n & (1<<4));
	
	n = ((n ^ (1<<2)) & (n ^ (1<<4)));
 	n = ((n ^ (bit3<<2)) | ((n ^ (bit5>>2))));
 	
	return (n);
}

/******************************************************************************/

unsigned int ClosestNum(int n)
{
	return(n & ~15);
}

/******************************************************************************/

void Swap(unsigned int *x,unsigned int *y)
{
			*x = (*x ^ *y);
			*y = (*x ^ *y);
			*x = (*x ^ *y);
	
	return;
}

void Swap2(unsigned int *x,unsigned int *y)
{
	unsigned int i = 1;

	while (i)
	{

		if ((*x & i) != (*y & i))
		{
			*x = (*x ^ i);
			*y = (*y ^ i);
		}
		
		i = (i<<1);		
	}
	
	return;
}



/******************************************************************************/
int BitsOnLoop(unsigned int n)
{
	unsigned int i = 1;
	int counter = 0;
	
	while (i)
	{
		if ((n & i) == i)
		{
			++counter;		
		}
		
		i = (i<<1);		
	}
	return (counter);
}


int BitsOn(unsigned int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return ((((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
}

/******************************************************************************/

void FloatBits (float n)
{
  int i= (1 << 31);
  int buff;
  int *fl = (int *)&n;
  
  for(i=31 ; i>=0; --i)
  {
  	buff = (((1<<i) & *fl) >> i);
  	printf ("%d",buff);
  }
  
  printf("\n");
  return;
}
/******************************************************************************/


