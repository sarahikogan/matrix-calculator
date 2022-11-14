// matrix_math.c
// holds the source code for the matrix math

#include "matrix_math.h"

// --- OPERATIONS ---

// ADD
// takes in two matrices 
// prints their sum
void add(struct matrix *mata, struct matrix *matb) {

    printf("\nA + B =\n\t");

    double output[mata->size];
    for (int i=0;i<mata->size;i++) {
        output[i] = mata->data[i] + matb->data[i];
    }

    for (int i=0;i<mata->size;i++) {
        printf("%.2f  ", output[i]);
    }
}

// SUB
// takes in two matrices 
// prints their difference

void sub(struct matrix *mata, struct matrix *matb) {

    printf("\nA - B =\n\t");

    double output[mata->size];
    for (int i=0;i<mata->size;i++) {
        output[i] = mata->data[i] - matb->data[i];
    }

    for (int i=0;i<mata->size;i++) {
        printf("%.2f  ", output[i]);
    }
} 

// AVG
// accepts two matrices 
// prints their average
void avg(struct matrix *mata, struct matrix *matb) {

    printf("\n(A + B)/2 =\n\t");

    double output[mata->size];
    for (int i=0;i<mata->size;i++) {
        output[i] = (mata->data[i] + matb->data[i])/2;
    }

    for (int i=0;i<mata->size;i++) {
        printf("%.2f  ", output[i]);
    }
}

