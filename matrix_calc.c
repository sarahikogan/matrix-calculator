// Homework 3: Matrix Calculator
// Sarah Kogan
// Due Friday 9/16

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// FUNCTION DECLARATIONS
void printMatrix(int rmat, int cmat, float M[][cmat]);
void add(int rA, int cA, int rB, int cB, float mA[][cA], float mB[][cB]);
void subtract(int rA, int cA, int rB, int cB, float mA[][cA], float mB[][cB]);
void multiply(int rA, int cA, int rB, int cB, float A[][cA], float B[][cB]);

// PRINTMATRIX
void printMatrix(int rmat, int cmat, float M[][cmat]) {

    int i, j;

    for (i=0; i<rmat; i++) {
        for (j=0; j<cmat; j++) {
            printf("%8.2f", M[i][j]);
            if (j==cmat-1) {
                printf("\n");
            }  // end newline if
        } // end col for
    } // end row for

} // end printMatrix

// ADD
void add(int rA, int cA, int rB, int cB, float mA[][cA], float mB[][cB]) {

    printf("A + B = \n");

    float matc[rA][cA]; // initialize matrix with same dimensions as original 
    int i, j; 

    for (i=0; i<rA; i++) {
        for (j=0; j<cA; j++) {
            matc[i][j] = mA[i][j] + mB[i][j];
        } // end col for
    } // end row for

    printMatrix(rA, cA, matc);
} // end add

// SUBTRACT
void subtract(int rA, int cA, int rB, int cB, float mA[][cA], float mB[][cB]) {

    printf("A - B = \n");

    float matc[rA][cA]; // initialize matrix with same dimensions as original 
    int i, j; 

    for (i=0; i<rA; i++) {
        for (j=0; j<cA; j++) {
            matc[i][j] = mA[i][j] - mB[i][j];
        } // end col for
    } // end row for

    printMatrix(rA, cA, matc);
} // end subtract

// MULTIPLY
void multiply(int rA, int cA, int rB, int cB, float A[][cA], float B[][cB]) {

    printf("A * B = \n");

    int i, j, k;
    float matc[rA][cB];

    for (i=0; i<rA; i++) { 
        for (j=0; j<cB; j++) {
            matc[i][j] = 0; // initialize

            for (k=0; k<rB; k++) {
                matc[i][j] += (A[i][k] * B[k][j]); // matrix multiplication rule
            } // end rB for
        } // end cB for
    } // end rA for

    printMatrix(rA, cB, matc);
} // end multiply


// MAIN
int main() {

    int i, j;
    int max, may, mbx, mby;

    // TAKE USER INPUTS

    // MAT A INPUT
    printf("What is the size of matrix A: \n"); // size
    scanf("%i %i", &max, &may);

    float mata[max][may]; // create matrix

    printf("Enter the value for A: \n"); // values
    for (i=0; i<max; i++) { // scan in numbers
        for (j=0; j<may; j++) {
            scanf("%f", &mata[i][j]);
        } // end for
    } // end for

    // MAT B INPUT
    printf("What is the size of matrix B: \n"); // matrix b
    scanf("%i %i", &mbx, &mby);

    float matb[mbx][mby]; // create matrix

    int k, l;

    printf("Enter the value for B: \n"); // enter values
    for (k=0; k<mbx; k++) {
        for (l=0; l<mby; l++) {
            scanf("%f", &matb[k][l]);
        } // end for
    } // end for

    printf("Would you like to add, subtract or multiply? Please enter a, s or m: \n");
    char op;
    scanf(" %c", &op);

    if (op == 'a' || op == 's') { // adding or subtracting
        if (max == mbx && may == mby) { // matrices are the same size
            if (op == 'a') {
                add(max, may, mbx, mby, mata, matb); // add
            }
            if (op == 's') {
                subtract(max, may, mbx, mby, mata, matb); // subtract
            }
        } else {
            printf("This math cannot be performed.\n");
            return 0;
        }
    } else if (op == 'm') {
        if (may == mbx) { // rows of a == columns of b
            multiply(max, may, mbx, mby, mata, matb); // multiply
        } else {
            printf("This math cannot be performed.\n");
            return 0;
        }
    }

    return 1;
}