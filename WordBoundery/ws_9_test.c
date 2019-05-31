/******************************************************************************
* Filename: ws_9.c
*
* Description: Exercises for Worksheet 9 - Structs
* Version:  1.0
* Created:  29/10/2018 15:45: PM
* Revision:  none
* Compiler:  c-89
*
*Created BY Bareket Sar Shalom                                                 *
* Organization: rd58
*******************************************************************************/

#include <stdio.h> /*printf, size_t*/
#include <string.h> /*strncmp, strncmp, strcpy*/
#include <stdlib.h> /*malloc*/
#include "ws_9.h"
/*#include "ws_9.c"*/
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

/****************Functions definitions*****************************************/


void MemsetTest(void)
{
	char str1[50];
	char str2[50];
	strcpy(str1,"This is string.h library function");
	strcpy(str2,"This is string.h library function");
	memset(str1,'$',20);
	Memset(str2,'$',20);

	if (0 == strcmp(str1, str2))
	{
				printf(GRN "\n1.MemsetTest ok\n" RESET);
	}
	else
	{
		printf(RED "\n1.ERROR: MemsetTest\n" RESET);
	}
}

void MemcpyTest(void)
{
	char str_dest[50];
	char str_src[50];
	strcpy(str_dest,"123123123123123123123123123123123");
	strcpy(str_src,"This is string.h library function");

	Memcpy(str_dest, str_src,13);

	if (0 == memcmp(str_dest, str_src, 13))
	{
				printf(GRN "\n2.MemcpyTest ok\n" RESET);
	}
	else
	{
		printf(RED "\n2.ERROR: MemcpyTest\n" RESET);
	}
}
void MemmoveTest(void)
{
	char str[40];
	char *str_src;
	char *str_dest;
	

	

	strcpy(str, "123456789ABCDEFGHIJKLMNOPQRST");

	str_src = str;
	str_dest = str + 9;

	Memmove(str_dest, str_src,13);

	if (0 == strncmp(str_dest, "123456789ABCDNOPQRST", 20))
	{
				printf(GRN "\n3.MemmoveTest ok\n" RESET);
	}
	else
	{
		printf(RED "\n3.ERROR: MemmoveTest\n" RESET);
	}
}

/******************************************************************************/
void Itoa10Test(void)
{

	char *str;
	int value = 1000; 
	int n_new = value;
	int count = 0;

	while (n_new != 0)
	{
		++count;
		n_new /= 10;
	}
	
	if(NULL == (str = (char*)malloc(count*sizeof(char)+1)))
	{
		return;
	}
	
	Itoa10(value, str);
	
	if (0 == strcmp(str, "1000"))
	{
				printf(GRN "\n4.Itoa10Test ok\n" RESET);
	}
	else
	{
		printf(RED "\n4.ERROR: Itoa10Test\n" RESET);
	}
	free(str);
	
}
void Atoi10Test(void)
{
  int count = 0;
   char str[20];
   
	strcpy(str, "98993489");

   	if (atoi(str) != Atoi10(str))
	{
		++count;
	}

	strcpy(str, "tutorialspoint.com");
   
   	if (atoi(str) != Atoi10(str))
	{
		++count;
	}
	
	strcpy(str, "22to1asp1int.co1");
   
   	if (atoi(str) != Atoi10(str))
	{
		++count;
	}
   	strcpy(str, "-123");
   
   	if (atoi(str) != Atoi10(str))
	{
		++count;
	}
   

   	if (0 == count)
	{
	printf(GRN "\n5.Atoi10Test ok\n" RESET);
	}
	else
	{
		printf(RED "\n5.ERROR: Atoi10Test\n" RESET);
	}
}

void Itoa36Test(void)
{
    int count = 0;
	char buffer[20];
	
/*		printf("%s\n", Itoa36(196232,buffer,20));*/
/*		printf("%s\n", Itoa36(196232,buffer,12));*/
		
	if(strcmp("0", Itoa36(0,buffer,2)))
	{
		++count;
	}
  	
	if(strcmp("10000", Itoa36(16,buffer,2)))
	{
		++count;
	}
	
	if(strcmp("-16", Itoa36(-16,buffer,10)))
	{
		++count;
	}
	
	if(strcmp("31", Itoa36(16,buffer,5)))
	{
		++count;
	}
	
	if(strcmp("g", Itoa36(16,buffer,17)))
	{
		++count;
	}


  	if (0 == count)
	{
	printf(GRN "\n6.Itoa36Test ok\n" RESET);
	}
	else
	{
		printf(RED "\n6.ERROR: Itoa36Test\n" RESET);
	}
 

}


void Atoi36Test(void)
/*Convert from any base to decimal*/
{
 	int count = 0;
	char str[20];
 
 	strcpy(str, "0");

   	if (Atoi36(str, 16) != 0)
	{
		++count;
	}
	  
	strcpy(str, "11A");

   	if (Atoi36(str, 16) != 282)
	{
		++count;
	}

	strcpy(str, "11a");
   
   	if (Atoi36(str, 16) != 282)
	{
		++count;
	}
	
	strcpy(str, "31");
   
   	if (Atoi36(str, 5) != 16)
	{
		++count;
	}
	
   	strcpy(str, "530");
   
   	if (Atoi36(str, 4) != 92)
	{
		++count;
	}
	
   	if (0 == count)
	{
	printf(GRN "\n7.Atoi36Test ok\n" RESET);
	}
	else
	{
		printf(RED "\n7.ERROR: Atoi36Test\n" RESET);
	}
/*	printf("%d", Atoi36("14ABC",20));*/
}

/******************************************************************************/
void OnlyTwiceTest(void)
{
	char *a = "a9bcabc12g5333";
	char *b = "a999bdefgab3566585";
	char *c = "bcbc";
		
	printf("\n8.OnlyTwiceTest\n");
	printf("  Expected result: 359ag\n");
	printf("  function result: ");
	
	OnlyTwice(a, strlen(a), b, strlen(b), c, strlen(c));
	
}

/******************************************************************************/
void IsLittleEndianTest()
{
	int result = IsLittleEndian();
	
   	if (0 == result)
	{
	printf(GRN "\n9.System is Big-endian\n" RESET);
	}
	else
	{
	printf(GRN "\n9.System is Little-endian\n" RESET);
	}
	
}

void IsLittleEndianMacroTest()
{
	int result = _IsLittleEndian;

   	if (0 != result)
	{
	printf(GRN "\n10.System is Big-endian\n" RESET);
	}
	else
	{
	printf(GRN "\n10.System is Little-endian\n" RESET);
	}
}



/************************************Main**************************************/
int main()
{
	MemsetTest();
	MemcpyTest();
	MemmoveTest();
	Itoa10Test();
	Atoi10Test();
	Itoa36Test();
	Atoi36Test();
	OnlyTwiceTest();
	IsLittleEndianTest();
	IsLittleEndianMacroTest();

	
	return (0);
}

/******************************************************************************/

