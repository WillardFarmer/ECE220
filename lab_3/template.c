#include <stdio.h>
#include "io.h"

//#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 64

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5

// prototypes of your functions you need to write

// this function fills input buffer using values
// obtained with the function get_value()
void reading(int[]);

// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int[]);

// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
// and to transfer data from local buffer to output buffer
void transferring(int[], int[]);

// this function submit the results stored
// in output buffer for validation
void submitting(int[]);


// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)


int main(void) {
    
    int inputBuffer[BUFFER_SIZE] = {0};
    int localBuffer[BUFFER_SIZE] = {0};
    int outputBuffer[BUFFER_SIZE]= {0};

    reading(inputBuffer);

    while (inputBuffer[0]!=-1) {

        transferring(inputBuffer,localBuffer);
        processing(localBuffer);
        transferring(localBuffer,outputBuffer);
        submitting(outputBuffer);

        reading(inputBuffer);
    }
    return 0;
}

void reading(int inputBuffer[]) {

    inputBuffer[0] = get_value();
    inputBuffer[1] = get_value();
    for(int i = 0; i < inputBuffer[1] ; i++ ){
        inputBuffer[i+2] = get_value();
    }
}

void processing(int localBuffer[]) {

    int a, b;  // temporary values to perform the processes
    switch(localBuffer[0]){

        case MIN:

            a = localBuffer[2]; // a is the minimum value

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
               if( localBuffer[i] < a )
                   a = localBuffer[i];
            }

            localBuffer[1] = -1; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            localBuffer[3] = 0;
            break;

        case MAX:

            a = localBuffer[2]; // a is the maximum value

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] > a )
                    a = localBuffer[i];
            }

            localBuffer[1] = -1; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            localBuffer[3] = 0;
            break;

        case ODD:

            a = 0; // a is an odd number counter

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] % 2 == 1 )
                    a++;
            }

            localBuffer[1] = -1; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            localBuffer[3] = 0;
            break;

        case EVEN:

            a = 0; // a is an even number counter

            for( int i = 2; i < (localBuffer[1] + 2); i++ ){
                if( localBuffer[i] % 2 == 0 && localBuffer[i] != 0)
                    a++;
            }

            localBuffer[1] = -1; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            localBuffer[3] = 0;
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

            localBuffer[1] = -2; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            localBuffer[3] = b;
            break;

        case ODDEVEN:

            a = 0; // a is an odd number counter

            for( int i = 2; i < localBuffer[1] + 2; i++ ){
                if( localBuffer[i] % 2 == 1 )
                    a++;
            }

            localBuffer[3] = localBuffer[1] - a;
            localBuffer[1] = -2; //negative value is used as a flag for transferring()
            localBuffer[2] = a;
            break;

        default:break;
    }

}

void transferring(int sourceBuffer[], int destinationBuffer[]) {


    if( sourceBuffer[1] > 0 ){

        for(int i = 0; i < sourceBuffer[1] + 2 ; i++) {
            destinationBuffer[i] = sourceBuffer[i];
        }

    }else{

        sourceBuffer[1] *= -1; //Reset from flag for output

        for(int i = 0; i < 4 ; i++)
            destinationBuffer[i] = sourceBuffer[i];

        printf("ID:                %d\n", sourceBuffer[0]);
        printf("Number of points:  %d\n", sourceBuffer[1]);
        printf("Results            %d", sourceBuffer[2]);
        if( sourceBuffer[1] == 2 ){
            printf(", %d", sourceBuffer[3]);
        }
    }
}

void submitting(int outputBuffer[]) {

submit_results(outputBuffer);
printf("\n");

}

