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
matrix_t* matrix_add(const matrix_t *a, const matrix_t *b);
matrix_t* matrix_sub(const matrix_t *a, const matrix_t *b);
matrix_t* matrix_mul(const matrix_t *a, const matrix_t *b); //O(n**3)
matrix_t* matrix_scalar_mul(const matrix_t *m, double s);
matrix_t* matrix_transpose(const matrix_t *m);
matrix_t *matrix_hadamard(const matrix_t *a, const matrix_t *b);



#endif // MATRIX_H
