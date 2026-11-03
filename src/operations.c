#include "lal.h"

void transpose_matrix(Matrix* matrix) {
    u32 rows = matrix->rows;
    u32 cols = matrix->cols;
    u64 size = (u64)rows * (u64)cols * sizeof(f64);
    f64* transposed_data = (f64*)safe_allocation(NULL, size, true);

    for (u32 i = 0; i < rows; ++i) {
        for (u32 j = 0; j < cols; ++j) {
            transposed_data[j * rows + i] = matrix->data[i * cols + j];
        }
    }

    // Swap rows and cols
    matrix->rows = cols;
    matrix->cols = rows;

    // Free the old data and assign the new transposed data
    free(matrix->data);
    matrix->data = transposed_data;
}