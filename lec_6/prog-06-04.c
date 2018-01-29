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
    const int ZERO = 0;
    float number;
    int counter_numbers = 0;

    printf("LOOP 1: Enter the list of numbers.\n");
    printf("'q' or a negative number finishes entering.\n");
    while (scanf("%f", &number) == 1)
    {
    	if (number < ZERO)
            break;
    	counter_numbers++;
    }
   	printf("LOOP1: You entered %d numbers.\n", counter_numbers);

   	counter_numbers = 0;
    printf("LOOP 2: Enter the list of numbers.\n");
    printf("'q' finishes entering.\n");
    while (scanf("%f", &number) == 1)
    {
    	if (number < ZERO)
            continue;
        counter_numbers++;

    }
   	printf("LOOP2: You entered %d numbers.\n", counter_numbers);

	printf("end\n");

    return 0;
}
