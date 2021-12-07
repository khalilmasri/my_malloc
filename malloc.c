#include "../include/include.h"

struct heap_s *heap;

void *_my_malloc(size_t size){

    if(size <= 0)
        return NULL;

    if(!heap){
        heap = mmap(0, sizeof(heap_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        heap->block_size = 1;
        heap->block->address = heap;
        heap->block->freed = 0;
        heap->block->size = sizeof(heap_t);
        }

    size_t b_size = heap->block_size;
    if(b_size < MAX_CAP){
        if(b_size == 1){
            heap->block[b_size].address = (char*)heap + size;
        }else{
            heap->block[b_size].address = (char*)heap->block[b_size-1].address + size;
        }
            heap->block[b_size].freed = 0;
            heap->block[b_size].size = size;
            heap->block_size += 1;
    }

    return heap->block[b_size].address;
}

