#include "lal.h"

Matrix* create_matrix(Arena* arena, u32 rows, u32 cols) {
    u64 size = (u64)rows * (u64)cols * sizeof(f64);
    f64* data = (f64*)safe_allocation(arena, size, true);
    Matrix* matrix = (Matrix*)safe_allocation(arena, sizeof(Matrix), true);
    
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->size = size;
    matrix->data = data;

    return matrix;
}

void print_matrix(Matrix* matrix) {
    for (u32 i = 0; i < matrix->rows; ++i) {
        for (u32 j = 0; j < matrix->cols; ++j) {
            printf("%lf ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void fill_matrix(Matrix* matrix, f64* data, u64 data_size) {
    if (data_size != matrix->size) {
        fprintf(stderr, "Error: Data size does not match matrix size.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(matrix->data, data, data_size);
}


