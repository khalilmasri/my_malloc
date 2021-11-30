
// LIBRARIES

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#define ALIGNMENT 8

typedef struct block{
    size_t size;
    struct block *next;
    struct block *prev;
}block_t;

extern struct block *head;

#ifndef MALLOC_H
#define MALLOC_H

void *_my_malloc(size_t);

#endif

// ---------------------------------------

#ifndef UTILITY_H
#define UTILITY_H

size_t align(size_t);
void *mem_block(block_t*);
void remove_free_list(block_t*);
void add_to_free_list(block_t*);
void *split_mem(block_t*, size_t);
void *allocate_mem(block_t*, size_t, size_t);

#endif

// ---------------------------------------

#ifndef FREE_H
#define FREE_H

void _my_free(void*);

#endif
