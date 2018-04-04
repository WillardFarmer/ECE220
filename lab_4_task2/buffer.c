#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "buffer.h"
#include "memory.h"

int *inputBuffer = NULL;
int *outputBuffer = NULL;


void printBuffer(const char* name, const int* Buffer){

    printf("[BUFFER] %-12s = [%d", name, Buffer[0]);
    for(int i = 1; i < Buffer[1] + 2; i++){
        printf(", %d", Buffer[i]);
    }
    printf("]\n");

}

int reading() {

    int *smallBuffer = (int *)my_malloc(2*sizeof(int)); // mode, data #, NULL
    smallBuffer[0] = get_value();
    if (smallBuffer[0] == -1) {
        my_free(smallBuffer);
        return -1;
    }
    smallBuffer[1] = get_value();

    inputBuffer = (int *)my_malloc((smallBuffer[1] + 2)*sizeof(int));

    inputBuffer[0] = smallBuffer[0];
    inputBuffer[1] = smallBuffer[1];
    for(int i = 0; i < smallBuffer[1] ; i++ ){
        inputBuffer[i+2] = get_value();
    }

    printBuffer("inputBuffer", inputBuffer);

    my_free((void *)smallBuffer);
}

int *transferringTOlocal(int *localBuffer) {

    localBuffer = (int *)my_malloc((inputBuffer[1] + 2)*sizeof(int));

    for(int i = 0; i < inputBuffer[1] + 2 ; i++) { //Move input buffer to local buffer
        localBuffer[i] = inputBuffer[i];
    }

    my_free((void *)inputBuffer);
    printBuffer("localBuffer", localBuffer);

    return localBuffer;

}

void transferringFROMlocal(int localBuffer[]) {

    outputBuffer = (int *)my_malloc((localBuffer[1] + 2)*sizeof(int));

    for(int i = 0; i < localBuffer[1] + 2 ; i++) { //Move input buffer to local buffer
        outputBuffer[i] = localBuffer[i];
    }

    printBuffer("outputBuffer", localBuffer);

}
void submitting() {

    printf("\n===================");
    submit_results(outputBuffer);
    my_free(outputBuffer);
    printf("===================\n\n");

}