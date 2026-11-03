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

Matrix* multiply_matrices(Arena* arena, Matrix* A, Matrix* B) {
    if (A->cols != B->rows) {
        fprintf(stderr, "Error: Incompatible matrix dimensions for multiplication.\n");
        exit(EXIT_FAILURE);
    }

    Matrix* result = create_matrix(arena, A->rows, B->cols);
    for (u32 i = 0; i < A->rows; ++i) {
        for (u32 j = 0; j < B->cols; ++j) {
            f64 sum = 0.0;
            for (u32 k = 0; k < A->cols; ++k) {
                sum += A->data[i * A->cols + k] * B->data[k * B->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
    return result;
}

Matrix* add_matrices(Arena* arena, Matrix* A, Matrix* B) {
    if (A->size != B->size) {
        fprintf(stderr, "Error: Incompatible matrix dimensions for addition.\n");
        exit(EXIT_FAILURE);
    }

    // finish matrixe´s sum
}