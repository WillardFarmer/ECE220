#include <stdlib.h>
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

        localBuffer = transferringTOlocal(localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);
        my_free(localBuffer);
        submitting();
        dataSize = reading();

    }
    return 0;
}

void processing(int localBuffer[]) {

    int a = 0, b = 0;  // temporary values to perform the processes
    switch(localBuffer[0]){

        case MIN:

            a = localBuffer[2]; // a is the minimum value

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] < a )
                    a = localBuffer[i];
            }
            localBuffer[1] = 1;
            break;

        case MAX:

            a = localBuffer[2]; // a is the maximum value

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] > a )
                    a = localBuffer[i];
            }
            localBuffer[1] = 1;
            break;

        case ODD:

            a = 0; // a is an odd number counter

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] % 2 == 1 )
                    a++;
            }
            localBuffer[1] = 1;
            break;

        case EVEN:

            a = 0; // a is an even number counter

            for( int i = 2; i < (localBuffer[1] + 2); i++ ){
                if( localBuffer[i] % 2 == 0 && localBuffer[i] != 0)
                    a++;
            }
            localBuffer[1] = 1;
            break;

        case MINMAX:

            a = localBuffer[2]; // a is the minimum value
            b = localBuffer[2]; // b is the maximum value

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] < a )
                    a = localBuffer[i];
                if( localBuffer[i] > b )
                    b = localBuffer[i];
            }
            localBuffer[1] = 2;
            break;

        case ODDEVEN:

            a = 0; // a is an odd number counter

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] % 2 == 1 )
                    a++;
            }

            b = localBuffer[1] - a;
            localBuffer[1] = 2;
            break;

        default:break;
    }

    localBuffer[2] = a;
    localBuffer[3] = b;

    printBuffer("localBuffer", localBuffer);

}

