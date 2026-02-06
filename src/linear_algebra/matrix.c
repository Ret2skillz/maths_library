#include <stdio.h>
#include "../../include/linear_algebra/matrix.h"

matrix_t *matrix_create(int rows, int cols){
    matrix_t *m = malloc(sizeof(matrix_t));

    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(double*));

    for (int i=0; i<rows; i++) {
        m->data[i] = malloc(cols * sizeof(double));
    }

    return m;

}

void matrix_free(matrix_t *m){
    for (int i=0; i<m->rows; i++) {
        free(m->data[i]);
        m->data[i] = 0;
    }
    free(m->data);
    free(m);

    m->data = 0;
    m = 0;
}

void matrix_print(matrix_t *m){
    printf("test");
}