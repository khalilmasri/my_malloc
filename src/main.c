/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: My_malloc 
 *
 *        Version:  1.0
 *        Created:  11/30/2021 01:53:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chris Dallat, Khalil Masree  
 *   Organization:  ELU 
 *
 * =====================================================================================
 */
#include "../include/include.h" 


int main(){

    char *src = "Hello";
    char *dest = _my_malloc(100);
    strcpy(dest, src);

    printf("dest: %s size: %ld address: %p \n", dest, strlen(dest), dest);

    _my_free(dest);
    printf("dest: %s size: %ld address: %p \n", dest, strlen(dest), dest);
}

