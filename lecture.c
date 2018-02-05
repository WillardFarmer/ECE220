#include <stdio.h>


int main(void){
    int test;
    float num;

    test = scanf("%f", &num);

    if(test == 0 || num < 0){
    printf("\n%f , %d\n",num,test);
    }else{
	printf("f u feg");
    }

return 0;
}


