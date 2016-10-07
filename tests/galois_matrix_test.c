#include <stdio.h>
#include <unistd.h> /* for sleep */
#include "galois_matrix.h"

int main()
{
    int i, j;
    gal8 a[8] = {0}, *aux;
    
    /* copy unity onto a */
    for (i = 0; i < 8; ++i)
        a[i] = unity[i];
    
    /* print each power of gentr */
    for (j = 0; j < 256; ++j) {
        mat_print(a);
        aux = mat_mul(a, gentr);
        for (i = 0; i < 8; ++i)
            a[i] = aux[i];
        sleep(1);
        putchar('\n');
    }
}
