#include <linear_algebra/matrix.h>
#include <stdio.h>

int main(void) {
    matrix_t *a = matrix_create(3, 3);
    matrix_t *b = matrix_create(3, 3);

    double array1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double array2[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    matrix_fill_array(a, array1);
    matrix_fill_array(b, array2);
    
    matrix_t *c = matrix_add(a, b);

    matrix_print(c);
}