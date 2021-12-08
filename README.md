## my_malloc
malloc, free, calloc, realloc - allocate and free dynamic memory

The malloc() function allocates size bytes and returns a pointer
to the allocated memory.  The memory is not initialized.  If size
is 0, then malloc() returns either NULL, or a unique pointer
value that can later be successfully passed to free().

The free() function frees the memory space pointed to by ptr,
which must have been returned by a previous call to malloc(),
calloc(), or realloc().  Otherwise, or if free(ptr) has already
been called before, undefined behavior occurs.  If ptr is NULL,
no operation is performed.

## What are the differents types of memory?

![screenshot](https://storage.googleapis.com/qwasar-public/s02_SE/memory_stack.png)

## How to run

1. tests already are in `src/main.c`
2. `make` to Makefile.
3. You can run the command
    * > ./my_malloc
4. After you are done you can clean the Makefile
    * `make clean` to clean the objects
    * `make fclean` to clean the objects and the run file `./my_malloc`
    * `make re` to `make clean` and `make fclean`
