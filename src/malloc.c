#include "../include/include.h"

struct block *head = NULL;

void *_my_malloc(size_t size){

    if(size <= 0)
        return NULL;

    void *mem;
    block_t *temp, *new;
    size_t alloc_size = align(size) + sizeof(block_t);

    temp = head;

    while(temp){
        if(temp->size >= size){
           mem = mem_block(temp);
           remove_free_list(temp);
           if(temp->size == size){
               return mem;
           }

           new = split_mem(temp, size);
           add_to_free_list(new);
           return mem;
        }else{
            temp = temp->next;
        }
    }

    // We couldn't find free blocks
    if(!(temp = allocate_mem(temp,alloc_size,size)))
        return NULL;

    return mem_block(temp);
}

