#include "../include/include.h"

void *_my_realloc(void *ptr, size_t size){

    if(size <= 0 || size > available_size)
        return NULL;

    void *new = _my_malloc(size);

    new = ptr;
     
    _my_free(ptr);

    return new;
}
