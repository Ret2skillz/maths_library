#include <stdio.h>
#include <stdlib.h>
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

void matrix_delete(matrix_t *m){
    if (!m) return;

    for (int i=0; i<m->rows; i++) {
        free(m->data[i]);
        m->data[i] = 0;
    }
    free(m->data);
    

    m->data = 0;
    free(m);
}

void matrix_print(matrix_t *m){
    if (!m) return;

    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            printf("%8.3f", m->data[i][j]);
        }
        putchar('\n');
    }
}

void matrix_fill(matrix_t *m, double value){
    if (!m) return;

    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            m->data[i][j] = value;
        }
    }
}

void matrix_fill_array(matrix_t *m, double *arr) {
    if (!m) return;

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = arr[i * m->cols + j];
        }
    }
}

void matrix_ones(matrix_t *m){
    if (!m) return;

    matrix_fill(m, 1.0);
}

void matrix_identity(matrix_t *m) {
    if (!m) return;

    // First fill with zeros
    matrix_fill(m, 0.0);
    
    // Then set diagonal to 1
    int size = (m->rows < m->cols) ? m->rows : m->cols;  // min(rows, cols)
    for (int i = 0; i < size; i++) {
        m->data[i][i] = 1.0;
    }
}


//matrix operations
matrix_t* matrix_add(const matrix_t *a, const matrix_t *b){
    if (!a || !b) return NULL;

    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    matrix_t *c = matrix_create(a->rows, a->cols);

    for (int i=0; i<c->rows; i++){
        for (int j=0; j<c->cols; j++){
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

matrix_t *matrix_sub(const matrix_t *a, const matrix_t *b)
{
    if (!a || !b) return NULL;

    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    matrix_t *c = matrix_create(a->rows, a->cols);

    for (int i=0; i<c->rows; i++){
        for (int j=0; j<c->cols; j++){
            c->data[i][j] = a->data[i][j] - b->data[i][j];
        }

    }

    return c;
}

matrix_t* matrix_mul(const matrix_t *a, const matrix_t *b)
{
    if (!a || !b) return NULL;

    if ((a->cols != b->rows)){
        return NULL;
    }
    matrix_t *c = matrix_create(a->rows, b->cols);
    
    for (int i=0; i<c->rows; i++){
        for (int j=0; j<c->cols; j++){
            for (int k=0; k<a->cols; k++){
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }

    }

    return c;
}

matrix_t *matrix_scalar_mul(const matrix_t *m, double s)
{
    if (!m) return NULL;

    matrix_t *c = matrix_create(m->rows, m->cols);

    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            c->data[i][j] = m->data[i][j] * s;
        }
    }

    return c;
}

matrix_t *matrix_transpose(const matrix_t *m)
{
    if (!m) return NULL;

    matrix_t *c = matrix_create(m->cols, m->rows);

    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            c->data[j][i] = m->data[i][j];
        }
    }

    return c;
}

matrix_t *matrix_hadamard(const matrix_t *a, const matrix_t *b)
{
    if (!a || !b) return NULL;

    if ((a->rows == b->rows) && (a->cols == b->cols)){
        return NULL;
    }

    matrix_t *c = matrix_create(a->rows, a->cols);

    for (int i=0; i<a->rows-1; i++){
        for (int j=0; j<a->cols-1; j++){
            c->data[i][j] = a->data[i][j] * b->data[i][j];
        }
    }

    return c;
}
