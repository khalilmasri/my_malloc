#include "../include/include.h"

heap_t heap;
void *mem = NULL;
size_t available_size = 0;

void print_heap(int index, size_t size){

    printf("Address: %p heap size: %ld heap allocated %d trying size : %ld\n", heap.blocks[index].address, heap.blocks[index].size, heap.blocks[index].allocated, size);
}

void split_heap(int index, size_t size){

    heap.block_size += 1;

    int i;

    for(i = heap.block_size -1; i > index + 1; i--){
        heap.blocks[i] = heap.blocks[i-1];
    }

    heap.blocks[i].address = heap.blocks[index].address + (heap.blocks[index].size - size);
    heap.blocks[i].size = (heap.blocks[index].size - size);
    heap.blocks[i].allocated = 0;

    i -= 1;
    heap.blocks[i].address = heap.blocks[i-1].address - heap.blocks[i-1].size;
    heap.blocks[i].size = size;
    heap.blocks[i].allocated = 1;
}

void *search_available_blocks(size_t size){

    for(int i = 0; i < heap.block_size-1; i++){
        if(heap.blocks[i].allocated == 0){
            if(heap.blocks[i].size == size){
                heap.blocks[i].allocated = 1;
                return heap.blocks[i].address;
                break;
            }else if(heap.blocks[i].size > size){
                printf("Here\n");
                split_heap(i, size);
                return heap.blocks[i].address;
                break;
            }
        }
    }

    return NULL;
}

void *_my_malloc(size_t size){

    if(size <= 0)
        return NULL;

    size_t allocate_size = size;

    void *new;

    if(available_size < allocate_size)
        memory_map(allocate_size);

    if(!( new = search_available_blocks(allocate_size))){
        heap = add_blocks(allocate_size);
        return heap.blocks[heap.block_size-1].address;
    }

    return new;
}
