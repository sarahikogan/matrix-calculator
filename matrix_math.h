#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrix {
    int size; 
    float *data; 
};

void deleteMatrix(struct matrix *mata);
struct matrix readMatrix(char* filename); 
void add(struct matrix *mata, struct matrix *matb);
void sub(struct matrix *mata, struct matrix *matb);
void avg(struct matrix *mata, struct matrix *matb);

#endif