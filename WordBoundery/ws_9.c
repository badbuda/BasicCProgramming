/******************************************************************************
* Filename: ws_9.c
*
* Description: Exercises for Worksheet 9 - Structs
* Version:  1.0
* Created:  29/10/2018 15:45: PM
* Last Update: 1/11/2018 10:20: AM
* Revision:  none
* Compiler:  c-89
*
*Created BY Bareket Sar Shalom                                                 *
* Organization: rd58
*******************************************************************************/

#include <stdio.h> /*printf, */
#include <string.h> /*strlen*/
#include <stdlib.h> /*__WORDSIZE*, malloc, calloc, free*/
/*#include <stdint.h>*/ /*uint16_t*/
#include "ws_9.h"



/****************Functions declarations****************************************/
void reverse(char *str, int length);
/* A utility function to reverse a string */

/****************Functions definitions*****************************************/
/*#define _IsLittleEndian (*(uint16_t *)"a" < 256)*/
/*
* uint16_t is unsigned 16-bit integer.
* unsigned short int is unsigned short integer, but the size is implementation 
* dependent. The  standard only says it's at least 16-bit (i.e, minimum value of 
* UINT_MAX is 65535). In practice, it usually is 16-bit, but you can't take that 
* as guaranteed.
* Note:
*    If you want a portable unsigned 16-bit integer, use uint16_t.
*    inttypes.h and stdint.h are both introduced in C99. If you are using C89, 
*    define your own type.
*    uint16_t may not be provided in certain implementation, 
*    but unsigned short int is always available.
*/

int IsLittleEndian()
{
	int test_num = 0x0A0B0C0D;
	char *ptr;
	ptr = (char *)&test_num;

	if (0x0D == *ptr)
	{
		return (1);
	}
	else return (0);
}

/******************************************************************************/
void *Memset(void *s, int c, size_t n)
{
	int i = 0;
	char ch = c;
	char *ptr_byte = (char *)s;

	int copied = n;
	int word_bytes = __WORDSIZE / 8;
	
	char *c_arr = malloc(word_bytes);

	for (i=0 ; i < word_bytes ; ++i)
	{
		c_arr[i] = ch;
	}
	
	while (copied > 0)
	{
		if (0 == (size_t)ptr_byte % word_bytes && copied >= word_bytes)
		{
			*(size_t *)&ptr_byte[0] = *(size_t *)&c_arr[0];

			ptr_byte += word_bytes;
			copied -= word_bytes;
		}
		else
		{
			*(char *)&ptr_byte[0] = ch;
			++ptr_byte;
			--copied;
		}
	}

	free(c_arr);
	return (s);
}


void *Memcpy(void *dest, const void *src, size_t n)
{
	char *ptr_dest = (char *)dest;
	char *ptr_src = (char *)src;
	int copied = n;
	int word_bytes = __WORDSIZE / 8;
	
	while (copied > 0)
	{
		if ((0 == (size_t)ptr_dest % word_bytes) && 
		    (0 == (size_t)ptr_dest % word_bytes) && (copied >= word_bytes))
		{
			*(size_t *)&ptr_dest[0] = *(size_t *)&ptr_src[0];

			ptr_dest += word_bytes;
			ptr_src += word_bytes;
			copied -= word_bytes;
		}
		else
		{
			*(char *)&ptr_dest[0] = *(char *)&ptr_src[0];	
			++ptr_dest;
			++ptr_src;
			--copied;
		}
	}
	
	return (dest);
}


void *Memmove(void *dest, const void *src, size_t n)
{
	int i = 0;
	char *ptr_dest = (char *)dest;
	char *ptr_src = (char *)src;

	if(ptr_dest > ptr_src && ptr_dest <= ptr_src + n)
	{
		
		ptr_dest += n - 1;
		ptr_src += n - 1;

		for (i = 0 ; (unsigned)i < n ; ++i)
		{
			*ptr_dest = *ptr_src;
			--ptr_dest;
			--ptr_src;
		}
	}	
	else
	{
		Memcpy(dest, src, n);
	}
	
	return (dest);
}
/******************************************************************************/

char *Itoa10(int value, char *str)
{
	sprintf(str, "%d", value);
	return(str);
}

int Atoi10(const char *str)
{
	int result = 0;
	int i = 0;
	int str_ln = strlen(str);
	int flag_minus = 0;
	
	if('-' == str[0])
	{
		flag_minus = 1;
		++i;
	}
	
	for( ; i < str_ln ; ++i)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			result = (result * 10) + (str[i] - '0');
		}
		else break;
	}	
	
	if(1 == flag_minus)
	{
		return(-result);
	}
	else return (result);
}


char *Itoa36(int num, char *str,int base)
{
	int i = 0; 
	int isNegative = 0; 
	int reminder = 0;
	
	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (0 == num) 
	{ 
		str[i] = '0'; 
		str[i + 1] = '\0'; 
		return str; 
	} 

	if (num < 0) 
	{ 
		isNegative = 1; 
		num = -num; 
	} 

	while (num != 0) 
	{ 
		reminder = num % base;
		if (reminder > 9)
		{
			str[i] = (reminder-10) + 'a';
		} 
		else
		{
			str[i] = reminder + '0'; 
		}
		
		num = num/base; 
		++i;
	} 


	if (isNegative)
	{
		str[i] = '-'; 
		++i;
	} 
		
	str[i] = '\0'; 
	reverse(str, i);

	return str; 
}


void reverse(char *str, int length) 
{ 
/* A utility function to reverse a string */
	int start = 0; 
	int end = length -1; 
	while (start < end) 
	{ 
		str[start] += str[end];
		str[end] = str[start] - str[end]; 
		str[start] -= str[end]; 
		
		++start; 
		--end; 
	} 
}  

int Atoi36(const char *str,int base)
{
	int result = 0;
	int i = 0;
	int str_ln = strlen(str) - 1;
	int current_num = 0;
	int power = 1;
	int flag_minus = 0;
	
	if('-' == str[0])
	{
		flag_minus = 1;
	}
	
	for(i = str_ln ; i >= flag_minus ; --i , power *= base)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			current_num = str[i] - '0';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			current_num = str[i] - 'A' + 10;
		}
		else
		{
			current_num = str[i] - 'a' + 10;
		}
		
		result += current_num * power;
	}
	
	if(1 == flag_minus)
	{
		return(-result);
	}
	else return (result);
}
/******************************************************************************/

void OnlyTwice(char *a, int a_size, char *b, int b_size, char *c, int c_size)
{
	int i = 0;
	char *letters = calloc((1 << 8) , sizeof(char));
	char *b_letters = calloc((1 << 8) , sizeof(char));
	
	for (i = 0 ; i < a_size ; ++i)
	{
		if(letters[(unsigned)a[i]] != a[i])
		{
			letters[(unsigned)a[i]] = a[i];
		}
	}
	
	for (i = 0 ; i < b_size ; ++i)
	{
		if(b_letters[(unsigned)b[i]] != b[i])
		{
			b_letters[(unsigned)b[i]] = b[i];
		}
	}

	for (i = 0 ; i < (1<<8) ; ++i)
	{
		if(letters[i] != b_letters[i])
		{
			letters[i] = 0;
		}
	}
	
	for (i = 0 ; i < c_size ; ++i)
	{
		if(letters[(unsigned)c[i]] == c[i])
		{
			letters[(unsigned)c[i]] = 0;
		}
	}
	
	for (i = 0 ; i < (1<<8) ; ++i)
	{
		printf("%c",letters[i]);
	}

	printf("\n");
	
	free(letters);
	free(b_letters);
	return;
}



/******************************************************************************/






