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
#include <ctype.h>

int main(void)
{
	char ch;
	printf("Give me a letter of the alphabet, and I will give ");
	printf("an animal name\nbeginning with that letter.\n");
	printf("Please type in a letter; type # to end my act.\n");

	while ((ch = getchar()) != '#') {
		if('\n' == ch)
			continue;
		if (islower(ch))
			switch (ch) {
			case 'a' :
				printf("argali, a wild sheep of Asia\n"); break;
			case 'b' :
				printf("babirusa, a wild pig of Malay\n"); break;
			default :
				printf("That's a stumper!\n");
			}
		else
			printf("I recognize only lowercase letters\n");

		printf("Please type another letter or # to stop ");

	}
	printf("end\n");

	return 0;
}
