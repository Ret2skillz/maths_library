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

    matrix_fill(m, 0.0);

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

void matrix_fill(matrix_t *m, double value){
    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            m->data[i][j] = value;
        }
    }
}

void matrix_fill_array(matrix_t *m, double *arr) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = arr[i * m->cols + j];
        }
    }
}

void matrix_ones(matrix_t *m){
    matrix_fill(m, 1.0);
}

void matrix_identity(matrix_t *m) {
    // First fill with zeros
    matrix_fill(m, 0.0);
    
    // Then set diagonal to 1
    int size = (m->rows < m->cols) ? m->rows : m->cols;  // min(rows, cols)
    for (int i = 0; i < size; i++) {
        m->data[i][i] = 1.0;
    }
}