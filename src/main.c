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

    /* char *src = "Hello"; */
    /* char *dest = _my_malloc(100); */
    /* strcpy(dest, src); */

    /* printf("dest: %s size: %ld address: %p \n", dest, strlen(dest), dest); */


    /* /1* _my_free(dest); *1/ */

    char *src = _my_malloc(100);
    char *dest = _my_malloc(100);
    char *t = _my_malloc(100);
    char *r = _my_malloc(100);

    strcpy(src, "heloo");
    strcpy(dest, "helo");
    strcpy(t, "hlo");
    strcpy(r, "o");
    printf("src: %s src: %ld address: %p \n", src, strlen(src), src);
    printf("r: %s r: %ld address: %p \n", r, strlen(r), r);
    printf("t: %s t: %ld address: %p \n", t, strlen(t), t);
    printf("dest: %s dest: %ld address: %p \n", dest, strlen(dest), dest);


    _my_free(dest);
    printf("dest: %s dest: %ld address: %p \n", dest, strlen(dest), dest);
    char *s = _my_malloc(20);
    strcpy(s, "mama");
    printf("s: %s s: %ld address: %p \n", s, strlen(s), s);
    printf("src: %s src: %ld address: %p \n", src, strlen(src), src);
    printf("dest: %s dest: %ld address: %p \n", dest, strlen(dest), dest);
    printf("t: %s t: %ld address: %p \n", t, strlen(t), t);
    char *k = _my_malloc(30);
    strcpy(k, "ho");
    printf("s: %s s: %ld address: %p \n", k, strlen(k), k);
    /* printf("dest: %s dest: %ld address: %p \n", dest, strlen(dest), dest); */

    return 0;
    /* _my_free(dest); */
}

