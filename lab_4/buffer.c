#include <stdio.h>
#include "io.h"
#include "buffer.h"

int inputBuffer[BUFFER_SIZE] = {0};
int outputBuffer[BUFFER_SIZE]= {0};



void printBuffer(const char* name, const int* Buffer){

    printf("%-12s = [%d", name, Buffer[0]);
    for(int i = 1; i < Buffer[1] + 2; i++){
        printf(", %d", Buffer[i]);
    }
    printf("]\n");

}

int reading() {

    inputBuffer[0] = get_value();
    if(inputBuffer[0] == -1){return -1;}

    inputBuffer[1] = get_value();
    for(int i = 0; i < inputBuffer[1] ; i++ ){
        inputBuffer[i+2] = get_value();
    }

    printBuffer("inputBuffer", inputBuffer);

    return inputBuffer[0];
}
void transferringTOlocal(int localBuffer[]) {

    for(int i = 0; i < inputBuffer[1] + 2 ; i++) { //Move input buffer to local buffer
        localBuffer[i] = inputBuffer[i];
    }

    printBuffer("localBuffer", localBuffer);

}
void transferringFROMlocal(int localBuffer[]) {

    for(int i = 0; i < localBuffer[1] + 2 ; i++) { //Move input buffer to local buffer
        outputBuffer[i] = localBuffer[i];
    }

    printBuffer("outputBuffer", localBuffer);

}
void submitting() {
    submit_results(outputBuffer);
    printf("\n");
}
