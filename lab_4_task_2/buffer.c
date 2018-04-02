#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "buffer.h"
#include "memory.h"

int *inputBuffer = NULL;
int *outputBuffer = NULL;


void printBuffer(const char* name, const int* Buffer){

    printf("%-12s = [%d", name, Buffer[0]);
    for(int i = 1; i < Buffer[1] + 2; i++){
        printf(", %d", Buffer[i]);
    }
    printf("]\n");

}

int reading() {

    int *smallBuffer = (int *)my_malloc(3*sizeof(int)); // mode, data #, NULL
    smallBuffer[0] = get_value();
    if(smallBuffer[0] == -1){return -1;}
    smallBuffer[1] = get_value();

    printBuffer("smallBuffer", smallBuffer);




}
int transferringTOlocal(int localBuffer[]) {
}
void transferringFROMlocal(int localBuffer[]) {
}
void submitting() {
}