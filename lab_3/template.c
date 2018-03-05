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

}

void processing(int localBuffer[]) {

}

void transferring(int sourceBuffer[], int destinationBuffer[]) {

}

void submitting(int outputBuffer[]) {

}

