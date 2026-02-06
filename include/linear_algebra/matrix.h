#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double **data;
    int rows;
    int cols;
} matrix_t;

//creation
matrix_t* matrix_create(int rows, int cols);
void matrix_delete(matrix_t *m);
void matrix_print(matrix_t *m);

//Operations
matrix_t* matrix_add(matrix_t *a, matrix_t *b);

#endif // MATRIX_H