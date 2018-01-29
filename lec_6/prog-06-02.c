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
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar();
	while (ch != '\n') {

		if (ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);

		ch = getchar();
	}

	putchar(ch);

	return 0;
}
