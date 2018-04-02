#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "buffer.h"
#include "memory.h"

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5


void processing(int[]);
int main(void) {

    int dataSize;
    int *localBuffer = NULL;
    dataSize = reading();

    while (dataSize !=-1) {

        localBuffer = (int *)transferringTOlocal(localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);
        my_free(localBuffer);
        submitting();
        dataSize = reading();

    }
    return 0;
}

void processing(int localBuffer[]);