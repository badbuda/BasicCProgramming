/******************************************************************************
* Filename: ws_9.h
*
* Description: Header for Worksheet 9 - Structs
* Version:  1.0
* Created:  29/10/2018 15:45: PM
* Last Update: 1/11/2018 10:20: AM
* Revision:  none
* Compiler:  c-89
*
*Created BY Bareket Sar Shalom                                                 *
* Organization: rd58
*******************************************************************************/
#include <stdint.h> /*uint16_t*/


#ifndef __WS9_H__
#define __WS9_H__


#define _IsLittleEndian (*(uint16_t *)"a" < 256)
/*******************************************************************************
* checks whether the system is Little endian				       *
*******************************************************************************/

void *Memset(void *s, int c, size_t n);
/*******************************************************************************
* copies the character c (an unsigned char) to the first n characters of the   *
* string pointed to, by the argument s .    				       *
*******************************************************************************/

void *Memcpy(void *dest, const void *src, size_t n);
/******************************************************************************* 
copies n characters from memory area src to memory area dest                   *
*******************************************************************************/

void *Memmove(void *dest, const void *src, size_t n);
/*******************************************************************************
* copies n characters from src to dest, but for overlapping memory blocks,     *
* memmove() is a safer approach than memcpy().                                 *
*******************************************************************************/

char *Itoa10(int value, char *str);
/*******************************************************************************
converts base 10 int data type to string data type                             *
*******************************************************************************/

int Atoi10(const char *str);
/*******************************************************************************
converts base 10 string argument str to an integer (type int).  	       *
*******************************************************************************/

char *Itoa36(int value, char *str,int base);
/*******************************************************************************
converts up to base 36 int data type to string data type                       *
*******************************************************************************/


int Atoi36(const char *str,int base);
/*******************************************************************************
converts up base 36string argument str to an integer (type int).               *
*******************************************************************************/

void OnlyTwice(char *a, int a_size, char *b, int b_size, char *c, int c_size);
/*******************************************************************************
* print the letters that appear in both  first 2 arrays, but does not appear   * 
* in the third						         	       *
*******************************************************************************/

int IsLittleEndian();
/*******************************************************************************
* checks whether the system is Little endian				       *
*******************************************************************************/

#endif
