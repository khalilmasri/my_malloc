#include "../include/include.h" 

void **free_ = NULL;

void unmap(void **ptr){
}

void _my_free(void *ptr){

    for(size_t i = 0; i < heap.block_size; i++){
        if(heap.blocks[i].address == ptr){
            heap.blocks[i].allocated = 0;
            printf("Ptr %p\n", ptr);
            break;
        }
    }
}
