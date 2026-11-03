#ifndef LAL_H
#define LAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "arena.h"


// Ints
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
// Unsigned Ints
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef i8 b8;
typedef i32 b32;
// Floats
typedef float f32;
typedef double f64;
// Boolean
typedef i32 b32;

typedef struct Arena Arena;

// Matrix
typedef struct {
    u32 rows;
    u32 cols;
    u64 size;
    f64* data;
} Matrix;

// Utils
void* safe_allocation(Arena* arena, u64 size, b32 non_zero);

// Basic
Matrix* create_matrix(Arena* arena, u32 rows, u32 cols);
void print_matrix(Matrix* matrix);
void fill_matrix(Matrix* matrix, f64* data, u64 data_size);

// Operations
void transpose_matrix(Matrix* matrix);
Matrix* multiply_matrices(Arena* arena, Matrix* A, Matrix* B);
Matrix* add_matrices(Arena* arena, Matrix* A, Matrix* B);


#endif // LAL_H
