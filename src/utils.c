#include "lal.h"

void* safe_allocation(Arena* arena, u64 size, b32 non_zero) {
    void* ptr = arena_push(arena, size, non_zero);
    if (!ptr) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}