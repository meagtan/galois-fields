#include <stdio.h>
#include "galois.h"

int main()
{
    int i = 0, c = 0;
    gal8 a = 1;
    while (i++ < 256) {
        gal_print(a);
        /* printf("%d", hamming_distance(a, gal_mul(a, generator))); */
        a = gal_mul(a, generator);
        if (c++ < 7) {
            putchar(' ');
        } else {
            putchar('\n');
            c = 0;
        }
    }
    if (c)
        putchar('\n');
}
