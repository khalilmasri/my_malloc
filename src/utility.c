#include "../include/include.h"

size_t align(size_t size){
    return (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1));
}

void *mem_block(block_t *ptr){
    return ((void *)((unsigned long)ptr + sizeof(block_t)));
}

void remove_free_list(block_t *ptr){

    if(!ptr->prev){
        if(ptr->next){
            head = ptr->next;
        }else{
            head = NULL;
        }
    }else{
        ptr->prev->next = ptr->next;
    }

    if(ptr->next)
        ptr->next->prev = ptr->prev;
}

void add_to_free_list(block_t *ptr){

    ptr->next = NULL;
    ptr->prev = NULL;

    if(!head || (unsigned long)head > (unsigned long)ptr){
        if(head)
            head->prev = ptr;

        ptr->next = head;
        head = ptr;
    }else{
        block_t *temp = head;
        while(temp->next && (unsigned long)temp->next < (unsigned long)ptr){
            temp = temp->next;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void *split_mem(block_t *ptr, size_t size){

    void *mem = mem_block(ptr);
    block_t *new = (block_t*)((unsigned long)mem + size);

    new->size = ptr->size - (size+sizeof(block_t));
    ptr->size = size;
    return new;
}

void *allocate_mem(block_t *ptr, size_t alloc_size, size_t passed_size){

    ptr = mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if(!ptr){
        printf("Coudln't allocate in memory %ld.\n", passed_size);
        return NULL;
    }
    
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->size = passed_size;
    if(alloc_size > passed_size + sizeof(block_t)){
        block_t *new = split_mem(ptr, passed_size);
        add_to_free_list(new);
    }

    return ptr;
}
