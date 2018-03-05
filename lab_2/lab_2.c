#include <stdio.h>

int main(void)
{
    char name[100];
    double buff;	//Buffer for fscanf
    int exit = 0;	//for main while loop cutoff
    int sub_exit = 0;   //for sub-while loops cutoff
    int option;		//option
    int min = 0;

    const char *items[] = {"Cheese Pizza", "Other", "Books"}; //Abstraction
    double budget[3] = {-1,-1,-1};
    double balance[3] = {0, 0, 0};
    double expenses[3] = {0, 0, 0};
    double percentage = 0;
    

    //Read File
    FILE *fp;
    int weeks = 0;
    fp = fopen("expenses.txt","r");
    if (fp == NULL) {
	printf("The file cannot be found\n");
	return -1;
    }

    //Print expenses
    fscanf(fp,"%d", &weeks); 
    for(int i = 0;i < weeks; i++) {
	for(int j = 0;j < 3; j++){
	    fscanf(fp, "%lf", &buff);
	    expenses[j] = expenses[j] + buff;
	    /*printf("[DEBUG] expenses[%i] = %d, buff = %lf\n", j, expenses[j], buff);*/
	}
    }
    fclose(fp);

    /*Average calculation*/
    printf("Average expenses:\n");
    for(int k = 0;k < weeks; k++) {
	expenses[k] = expenses[k] / weeks;
	printf("%14s = %-6.2lf\n", items[k], expenses[k]);
    }

    //Name Input
    printf("\nWhat is your name? ");
    scanf("%s", name);
    if(name[0] >= 97 && name[0] <= 122){name[0] = name[0] - 32;} 

    //Budget input menu
    while(!exit){
	option = 0;
	printf("\nBUDGET:\n1. FOOD\n2. EDUCATION\n3. EXIT\n>");
	scanf("%d",&option);
	switch(option){
	    case 1: //FOOD
		do{
		    sub_exit = 0;
		    printf("\nFOOD:\n1. CHEESE/PIZZA\n2. OTHERS\n3. EXIT\n>");
		    scanf("%d",&option);
		    switch (option){
			case 1:
			    printf("What is your budget for Cheese Pizza? $");
			    scanf("%lf", &budget[0]);
			    while(budget[0] < 0 ){
				printf("You must enter a positive number. $");
				scanf("%lf", &budget[0]);
			    }    
			    break;
			case 2:
			    printf("What is your budget for Other itens? ");
			    scanf("%lf", &budget[1]);
			    while(budget[1] < 0){
				printf("You must enter a positive value. $");
				scanf("%lf", &budget[1]);
			    }    
			    break;
			case 3:
			    if(budget[0] < 0 || budget[1] < 0){ 
			    printf("You must input values for both sub-categories");
			    }else{sub_exit = 1;}
			    break;
			default:
			    printf("You did not select a valid option");
		    }
		}while(!sub_exit);
		break;
	    case 2: //EDUCATION
		do{
		    sub_exit = 0;
		    option = 0;
		    printf("\nEDUCATION:\n1. Books\n2. Back to main menu\n>");
		    scanf("%d",&option);
		    switch (option){
			case 1:
			    printf("What is your budget for Books? $");
			    scanf("%lf", &budget[2]);
			    while(budget[2] < 0){
				printf("You must enter a positive number. $");
				scanf("%lf", &budget[2]);
			    }    
			    break;
			case 2:
			    if(budget[2] < 0){ 
			    printf("You must input a value for Books\n");
			    }else{sub_exit = 1;}
			    break;
			default:
			    printf("You did not select a valid option");
		    } 
		}while(!sub_exit); 
		break;
	    case 3: //EXIT
		if(budget[0] < 0 || budget[1] < 0 || budget[2] < 0){
		    printf("You must input a value for all categories and all sub-categories\n");
		}else{exit = 1;}
		break;
	    default:
		printf("Invalid menu option\n"); 
	}
    }
    

    //Balance Output
    printf("\nBalance:\n");
    for(int l = 0; l < weeks; l++){
	balance[l] = budget[l] - expenses[l];
	printf("%14s: %-6.2lf = %-6.2lf - %6.2lf\n", items[l],balance[l],budget[l], expenses[l]);
	if(balance[l] < 0 && balance[l] <= balance[min]){
	    min = l;
	    percentage = -(balance[l] / budget[l]);
	}
    }

    //Budget increse (
    if(percentage != 0) {
	printf("\nIncrease budget by %4.2f%%\n\n", percentage * 100);
	for(int l = 0; l < weeks; l++){
	    budget[l] = budget[l] * percentage + budget[l];
	    balance[l] = budget[l] - expenses[l];
	    printf("%14s: %-6.2lf = %-6.2lf - %6.2lf\n", items[l],balance[l],budget[l], expenses[l]);
	}
    }	
    

    //Write to budget.txt
    fp = fopen("budgets.txt","w");
    if (fp == NULL) {
	printf("The file, 'expenses.txt' cannot be found or made.\n");
	return -1;
    }
    fprintf(fp,"Number of weeks: %i\n", weeks);
    for(int k = 0;k < weeks; k++) {
	fprintf(fp,"%12s = %-6.2lf\n", items[k], balance[k]);
    }
    fclose(fp);


    return 0;
}
