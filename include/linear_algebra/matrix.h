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

//filling with values
void matrix_fill(matrix_t *m, double value);
void matrix_fill_array(matrix_t *m, double *arr);
void matrix_ones(matrix_t *m);
void matrix_identity(matrix_t *m);

//Operations
matrix_t* matrix_add(matrix_t *a, matrix_t *b);
matrix_t* matrix_sub(matrix_t *a, matrix_t *b);
matrix_t* matrix_mul(matrix_t *a, matrix_t *b); //O(n**3)



#endif // MATRIX_H