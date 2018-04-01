#include <stdio.h>
#include "io.h"
#include "buffer.h"

int inputBuffer[BUFFER_SIZE] = {0};
int outputBuffer[BUFFER_SIZE]= {0};



void printBuffer(char* name, int Buffer[]){

    printf("test");
    fflush(stdout);
    printf("%s = ", name);

}


int reading() {

    printf("reading");
    fflush(stdout);
    inputBuffer[0] = get_value();
    if(inputBuffer[0] == -1){return -1;}

    inputBuffer[1] = get_value();
    for(int i = 0; i < inputBuffer[1] ; i++ ){
        inputBuffer[i+2] = get_value();
    }

    //Print
    char * Buffername = "localBuffer";
    printBuffer(Buffername, inputBuffer);

    return inputBuffer[0];
}

void transferringTOlocal(int isData, int localBuffer[]) {

    localBuffer[0] = isData;
    localBuffer[1] = get_value(); //number of values
    for(int i = 0; i < localBuffer[1] ; i++ ){
        localBuffer[i+2] = get_value();
    }

    //Print
    char * Buffername = "localBuffer";
    printBuffer(Buffername, localBuffer);

}
void transferringFROMlocal(int localBuffer[]) {
}
void submitting() {
}
