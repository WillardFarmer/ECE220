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
	printf("a country name\nbeginning with that letter.\n");
	printf("Please type in a letter; type # to end my act.\n");

	while ((ch = getchar()) != '#')
	{
	    if('\n' == ch)
	        continue;
	    if (islower(ch))
	    	switch (ch) {
	    		case 'a' :
	    			printf("Algeria, ...\n"); break;
	    		case 'b' :
	    			printf("Belgium, ...\n"); break;
	    		case 'c' :
	    			printf("Chile\n"); break;
	    		case 'd' :
	    			printf("Denmark\n");
	    		case 'e' :
	    			printf("Equador\n"); break;
	    		case 'f' :
	    			printf("France\n"); break;
	    		default :
	    			printf("That's a stumper!\n");
				/* end of switch */
	    	}
	    else
	    	printf("I recognize only lowercase letters.\n");
	    while (getchar() != '\n')
	    	continue; /* skip rest of input line */
	    printf("Please type another letter or #.\n");
	} /* while loop end */

	printf("end\n");

return 0; }
