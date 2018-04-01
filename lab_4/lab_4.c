#include <stdio.h>
#include "io.h"
#include "buffer.h"

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5
// prototypes of your function you need to write here

void processing(int[]);

int main(void) {

    int isData;
    int localBuffer[BUFFER_SIZE] = {0};

    printf("test\n\n");
    isData = reading();

    while (isData != - 1) {
        transferringTOlocal(isData, localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);
        submitting();
        isData = reading();
    }
    return 0;

}

void processing(int localBuffer[]) {
}