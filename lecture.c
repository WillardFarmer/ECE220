#include <stdio.h>

int main(void){

    char ch;
    ch = getch();

    while((ch = getch()) != '#'){
	putchar(ch);
    }
return 0;
}


