#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "arena.h"
#include "lal.h"

Arena* arena_create(u64 capacity) {
    if (capacity < sizeof(Arena)) return NULL;

    Arena* arena = (Arena*)malloc(capacity);
    if (!arena) return NULL;

    arena->capacity = capacity;
    arena->pos = ARENA_BASE_POS;

    return arena;
}

void arena_free(Arena* arena) {
    free(arena);
}

void arena_clear(Arena* arena){
    arena_pop(arena, ARENA_BASE_POS);
}

void* arena_push(Arena* arena, u64 size, b32 non_zero) {
    if (!arena) return NULL;

    u64 pos_align = ALIGN_UP_POW2(arena->pos, ARENA_ALIGN);

    if (pos_align > arena->capacity || size > arena->capacity - pos_align) return NULL;
    
    arena->pos = pos_align + size;

    u8* out = (u8*)arena + pos_align;

    if (!non_zero) memset(out, 0, size);

    return out;
}

void arena_pop(Arena* arena, u64 size) {
    size = MIN(size, arena->pos - ARENA_BASE_POS);
    arena->pos -= size;
}

void arena_pop_to(Arena* arena, u64 pos) {
    u64 size = pos < arena->pos ? arena->pos - pos : 0;
    arena_pop(arena, size);
}