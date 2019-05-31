/******************************************************************************
* Filename: test_ws_6.c
*
* Description: tests for ExercisesWorksheet 6 - Bitwise operations
* Version:  1.0
* Created:  23/10/2018 15:45: PM
* Revision:  none
* Compiler:  c-89
*
*Created BY Bareket Sar Shalom                                                 
* Organization: rd58
*******************************************************************************/
#include <stdio.h> /*printf,fopen,freopen,fclose,fgets*/
#include <string.h> /*strncmp*/
#include "ws_6.c"






void Pow2_Test(void)
{

	int counter = 0;

	if(Pow2(1,-2) != 0.25)
	{
		++counter;
	}
	if(Pow2(1,0) != 1)
	{
		++counter;
	}
	if(Pow2(2,3) != 16)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n1.Pow2_Test ok\n");
	}
	else
	{
		printf("\n1.ERROR: Pow2_Test\n");
	}
}



void LoopPow2_Test(void)
{

	int counter = 0;
	
	if(LoopPow2(64) != 1)
	{
		++counter;
	}
	if(LoopPow2(1) != 1)
	{
		++counter;
	}
	if(LoopPow2(0) != 0)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n2.LoopPow2_Test ok\n");
	}
	else
	{
		printf("\n2.ERROR: LoopPow2_Test\n");
	}
	
	return;
}



void NoLoopPow2_Test(void)
{
	int counter = 0;
	
	if(NoLoopPow2(64) != 1)
	{
		++counter;
	}
	if(NoLoopPow2(1) != 1)
	{
		++counter;
	}
	if(NoLoopPow2(0) != 0)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n3.NoLoopPow2_Test ok\n");
	}
	else
	{
		printf("\n3.ERROR: NoLoopPow2_Test\n");
	}
	
	return;
}


void Add1_Test(void)
{
	int i;
	int counter = 0;
	
	for (i=0 ; i<100 ; ++i)
	{
		if(Add1(i) != (i+1))
		{
			++counter;
		}
	}
	
	if(counter == 0)
	{
		printf("\n4.Add1_Test ok\n");
	}
	else
	{
		printf("\n4.ERROR: Add1_Test\n");
	}
	return;
}

void Arry3BitOn_Test (void)
{

	unsigned int array[10] = {1,2,3,4,5,6,7,8,9,10};
	
	printf("\n4.This is 3 bit TEST:\n");
	printf("For array 1-10: ");
	Arry3BitOn(array, 10);
	
	printf("\nEnd of 3 bit TEST:\n");
}

void ByteMirrorLoop_Test(void) /*print hexa? %x*/
{
	int counter = 0;
	
	if(ByteMirrorLoop(1000) != 398458880)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n6.ByteMirrorLoop_Test ok\n");
	}
	else
	{
		printf("\n6.ERROR: ByteMirrorLoop_Test\n");
	}
	
	return;

}

void ByteMirror_Test(void)
{
int counter = 0;
	
	if(ByteMirror(1000) != 398458880)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n7.ByteMirror_Test ok\n");
	}
	else
	{
		printf("\n7.ERROR: ByteMirror_Test\n");
	}
	
	return;
}


void F1_Test(void)
{
	int counter = 0;
	
	if(F1(30) != 0)
	{
		++counter;
	}
	if(F1(34) != 1)
	{
		++counter;
	}
	if(F1(63) != 1)
	{
		++counter;
	}
	if(F1(79) != 0)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n8.F1_Test ok\n");
	}
	else
	{
		printf("\n8.ERROR: F1_Test\n");
	}
	
	return;

	
}

void F2_Test(void)
{
	int counter = 0;
	
	if(F2(30) != 1)
	{
		++counter;
	}
	if(F2(34) != 1)
	{
		++counter;
	}
	if(F2(63) != 1)
	{
		++counter;
	}
	if(F2(76) != 0)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n9.F2_Test ok\n");
	}
	else
	{
		printf("\n9.ERROR: F2_Test\n");
	}
	
	return;
}

void F3_Test(void)
{
	int counter = 0;
	
	if(F3(0) != 0)
	{
		++counter;
	}
	if(F3(1) != 1)
	{
		++counter;
	}
	if(F3(5) != 17)
	{
		++counter;
	}
	if(F3(19) != 7)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n10.F3_Test ok\n");
	}
	else
	{
		printf("\n10.ERROR: F3_Test\n");
	}
	
	return;
}

void ClosestNum_Test(void)
{
	int counter = 0;
	
	if(ClosestNum(0) != 0)
	{
		++counter;
	}
	if(ClosestNum(15) != 0)
	{
		++counter;
	}
	if(ClosestNum(16) != 16)
	{
		++counter;
	}
	if(ClosestNum(17) != 16)
	{
		++counter;
	}
	if(ClosestNum(63) != 48)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n11.ClosestNum_Test ok\n");
	}
	else
	{
		printf("\n11.ERROR: ClosestNum_Test\n");
	}
	
	return;
}

void Swap_Test(void)
{
	unsigned int i,j;
	unsigned int n1, n2;
	int counter = 0;
		
	for(i=0,j=100; i<100; ++i, --j)
	{
		n1 = i;
		n2 = j;
		Swap(&n1, &n2);
		
		if((n1 != j) || (n2 != i))
		{
			++counter;
		}
	}
		if(counter == 0)
	{
		printf("\n12.Swap_Test ok\n");
	}
	else
	{
		printf("\n12.ERROR: Swap_Test\n");
	}
	
	return;
}

void BitsOnLoop_Tests(void)
{
	int counter = 0;
	
	if(BitsOnLoop(1) != 1)
	{
		++counter;
	}
	if(BitsOnLoop(3) != 2)
	{
		++counter;
	}
	if(BitsOnLoop(7) != 3)
	{
		++counter;
	}
	if(BitsOnLoop(9) != 2)
	{
		++counter;
	}
	if(BitsOnLoop(13) != 3)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n13.BitsOnLoop_Tests ok\n");
	}
	else
	{
		printf("\n13.ERROR: BitsOnLoop_Tests\n");
	}
	
	return;
}

void BitsOn_Tests(void)
{
	int counter = 0;
	
	if(BitsOn(1) != 1)
	{
		++counter;
	}
	if(BitsOn(3) != 2)
	{
		++counter;
	}
	if(BitsOn(7) != 3)
	{
		++counter;
	}
	if(BitsOn(9) != 2)
	{
		++counter;
	}
	if(BitsOn(13) != 3)
	{
		++counter;
	}
	
	if(counter == 0)
	{
		printf("\n13.BitsOn_Tests ok\n");
	}
	else
	{
		printf("\n13.ERROR: BitsOn_Tests\n");
	}
	
	return;
}

void FloatBits_Test (void)
{

	char line[33];
	int counter = 0;
	FILE *ptr_file = freopen("tmp.txt","a+",stdout);
	
	FloatBits(96.0); /*    01000010110000000000000000000000*/
	FloatBits(-96.0); /*(-)11000010110000000000000000000000*/
	freopen("/dev/tty","a",stdout);
	
	ptr_file = fopen("tmp.txt","r");
	fgets(line, 33, ptr_file);
	if(strncmp(line,"01000010110000000000000000000000",32))
	{
		++counter;
	}
		fgets(line, 33, ptr_file);
		fgets(line, 33, ptr_file);

	if(strncmp(line,"-1100001011000000000000000000000",32))
	{
		++counter;
	}
	fclose(ptr_file);
	remove("tmp.txt");
	
	if(counter == 0)
	{
		printf("\n15.FloatBits_Test ok\n");
	}
	else
	{
		printf("\n15.ERROR: FloatBits_Test\n");
	}
	
	return;
}

/******************************************************************************/
int main()
{
	printf("\n***************\nStart of Tests!\n");
	
	Pow2_Test();
	LoopPow2_Test();
	NoLoopPow2_Test();
	Add1_Test();
	Arry3BitOn_Test();
	ByteMirrorLoop_Test();
	ByteMirror_Test();
	F1_Test();
	F2_Test();
	F3_Test();
	ClosestNum_Test();
	Swap_Test();
	BitsOnLoop_Tests();
	BitsOn_Tests();
	FloatBits_Test();

	printf("\nEnd of Tests!\n***************\n");
	return (0);
}
/******************************************************************************/
