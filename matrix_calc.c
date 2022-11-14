// Homework 4: Structures
// Sarah Kogan
// Due Monday 9/26
// Implement structures in C to read 1D matrices from files, store the data in a 1D array struct and perform matrix math. 

// matrix_calc.c 
// holds the main() function 

#include "matrix_math.h"
#include "matrix_math.c"

int ct = 0; 
int sizes[2];
int main(int argc, char*argv[]) {

    struct matrix matrixA, matrixB; 

    matrixA = readMatrix(argv[1]);  // input 1
    matrixB = readMatrix(argv[2]);  // input 2

    char op;
     strcpy(&op, argv[3]); // input 3: operation (a, s, or n)

    if (sizes[0] == sizes[1]) {
        switch (op) {
            case 'a':
                printf("add");
                add(&matrixA, &matrixB);
                break;
            case 's':
                printf("subtract");
                sub(&matrixA, &matrixB);
                break;
            case 'n':
                printf("average");
                avg(&matrixA, &matrixB);
                break;
        }
    } else {
        printf("\nThis math cannot be performed.");
    };

}

// read matrix
// takes in file name 
// returns matrix with data from the file 

struct matrix readMatrix(char* fileName) {

    FILE *in_file = fopen(fileName, "r");
    int size; 
    fscanf(in_file, "%d", &size); // scan through the file 
    if (ct < 2) {
        ct ++; 
        sizes[ct] = size; // set sizes of matrices
    } // end if 

    // make and fill aray
    float *arr = malloc(size * sizeof(float)); // allocate mem for array
    
    for (int i=0; i<size;i++) { 
        fscanf(in_file, "%f", &arr[i]);
    } // add values into the array

    fclose(in_file);

    struct matrix output = {size, arr};

    return (struct matrix) output; 

}

// delete matrix 
// takes in a matrix pointer to delete
// returns void and deletes the matrix

void deleteMatrix(struct matrix *mat) {
    free (mat);
}
