#include "../include/include.h" 

void **free_ = NULL;

void unmap(void **ptr){
    *ptr = NULL;
}

void _my_free(void *ptr){

    for(size_t i = 0; i < heap.block_size; i++){
        if(heap.blocks[i].address == ptr){
            heap.blocks[i].allocated = 0;
            heap.blocks[i].address = NULL;
            unmap(ptr);
            printf("Ptr %p\n", ptr);
            break;
        }
    }
}
