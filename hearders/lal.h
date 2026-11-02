#ifndef LAL_H
#define LAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Matrix
typedef struct {
    u32 rows;
    u32 cols;
    u64 size;
    f64* data;
} Matrix;


#endif // LAL_H
