/*
 ============================================================================
 Name        : lecture-06.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>

int main(void)
{
	long num;

	printf("enter a number: ");
	scanf("%ld", &num);

	if (num < 1)
		printf("inside if ..., num is: %ld\n", num);
	else if (num < 4)
		printf("inside else if ..., num is: %ld\n", num);
	else
		printf("inside else ..., num is: %ld\n", num);

	printf("end\n");

	return 0;
}
