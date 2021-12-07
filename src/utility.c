#include "../include/include.h"

size_t align(size_t size){
    return (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1));
}

size_t chunk_align(size_t size){
    return (((size)+(CHUNK_SIZE-1)) & ~(CHUNK_SIZE-1));
}

void memory_map(size_t size){
    mem = mmap(0, chunk_align(size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1 , 0);
    available_size = chunk_align(size);
    heap.block_size = 1;
    heap.blocks[0].address = mem;
    heap.blocks[0].allocated = 0;
    heap.blocks[0].size = available_size;
}

heap_t add_blocks(size_t size){

    heap.blocks[heap.block_size-1].address = mem;
    heap.blocks[heap.block_size-1].size = size;
    heap.blocks[heap.block_size-1].allocated = 1;

    mem += size;
    available_size -= size;

    heap.blocks[heap.block_size].address = mem;
    heap.blocks[heap.block_size].size = available_size;
    heap.block_size += 1;

    return heap;
}
