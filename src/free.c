#include "../include/include.h" 

void merge_free(){

    block_t *temp = head;

    unsigned long curr, next;
    
    while(temp->next){
        curr = (unsigned long)temp + temp->size + sizeof(block_t);
        next = (unsigned long)temp->next;
            printf("cur %ld next %ld\n", curr, next);

        if(next == curr){
            temp->size += temp->next->size + sizeof(block_t);
            temp->next = temp->next->next;
            if(temp->next){
                temp->next->prev = temp;
            }else{
                break;
            }
        }
        temp = temp->next;
    }
}

void free_(void **ptr){

    *ptr = ((void*)(unsigned long)ptr - sizeof(block_t));
    add_to_free_list(*ptr);
    merge_free();
}

void _my_free(void *ptr){
    free_(ptr);
}
