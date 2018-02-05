#include <stdio.h>

int main(void)
{
    char name[100];
    float pizza = -1;
    float other = -1;
    float edu   = -1;
    int exit = 0;
    int sub_exit = 0;
    int option;
    int sub_option;

    printf("What is your name? ");
    scanf("%s", name);
    if(name[0] >= 97 && name[0] <= 122){name[0] = name[0] - 32;} 



    while(!exit){

    printf("\nMAIN MENU:\n1. FOOD\n2. EDUCATION\n3. EXIT\n>");
    scanf("%d",&option);

    switch(option){
	case 1:
	    do{
		sub_exit = 0;
		printf("\nFOOD:\n1. CHEESE/PIZZA\n2. OTHERS\n3. EXIT\n>");
		scanf("%d",&sub_option);
		switch (sub_option){
		    case 1:
			printf("How much did you spend on cheese pizza? $");
			scanf("%f", &pizza);
			while(pizza < 0 ){
			    printf("You must enter a positive number. $");
			    scanf("%f", &pizza);
			}    
			break;
		    case 2:
			printf("How much did you spend on other items? ");
			scanf("%f", &other);
			while(other < 0){
			    printf("You must enter a positive value. $");
			    scanf("%f", &other);
			}    
			break;
		    case 3:
			if(pizza < 0 || other < 0){ 
			printf("You must print values for both sub-categories");
			}else{
			sub_exit = 1;
			}
			break;
		    default:
			printf("You did not select a valid option");
		}
	    }while(!sub_exit);
	    break;
	case 2:
	    do{
		sub_exit = 0;
		printf("\nEDUCATION:\n1. Books\n2. Back to main menu\n>");
		scanf("%d",&sub_option);
		switch (sub_option){
		    case 1:
			printf("How much did you spend on your education? $");
			scanf("%f", &edu);
			while(edu < 0){
			    printf("You must enter a positive number. $");
			    scanf("%f", &edu);
			}    
			break;
		    case 2:
			if(edu < 0){ 
			printf("You must input a value for EDUCATION\n");
			}else{
			sub_exit = 1;
			}
			break;
		    default:
			printf("You did not select a valid option");
		}
	    }while(!sub_exit);
	    break;
	case 3:
	    if(pizza < 0 || other < 0 || edu < 0){
		printf("You must input a value for all categories and all sub-categories\n");
	    }else{
	    exit = 1;
	    }
	    break;
	default:
	    printf("Invalid menu option\n"); 
    }
    }

    printf("\n\n%s, you spent:\n", name);
    printf("CHEESE/PIZZA: $%f\n",pizza);
    printf("OTHER:        $%f\n",other);
    printf("EDUCATION:    $%f\n",edu);
    printf("-----------------------------\n");
    printf("Total:        $%f\n",pizza + other + edu);

    return 0;
}




