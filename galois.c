#include <stdio.h>

typedef uint8_t gal8; /* Galois field of order 2^8 */

const gal8 min_poly  = 0b11101,     /* Minimal polynomial x^8 + x^4 + x^3 + x^2 + 1 */
           generator = 0b10;        /* Generator of Galois field */

gal8 gal_add(gal8 a, gal8 b);       /* Add two elements of GF(2^8) */
gal8 gal_mul(gal8 a, gal8 b);       /* Multiply two elements of GF(2^8) */
void gal_print(gal8 a);             /* Print an element of GF(2^8) in binary form */
int hamming_norm(int a);            /* Number of nonzero bits in a */
int hamming_distance(int a, int b); /* Number of different bits between a and b */

gal8 gal_add(gal8 a, gal8 b)
{
    return a ^ b;
}

gal8 gal_mul(gal8 a, gal8 b)
{
    gal8 res = 0;
    for (; b; b >>= 1) {
        if (b & 1)
            res ^= a;
        if (a & 0x80)
            a = (a << 1) ^ min_poly;
        else
            a <<= 1;
    }
    return res;
}

void gal_print(gal8 a)
{
    int i = 8;
    while (i--)
        putchar((a >> i & 1) + '0');
}

int hamming_norm(int a)
{
    int res = 0;
    while (a) {
        if (a & 1) ++res;
        a >>= 1;
    }
    return res;
}

int hamming_distance(int a, int b)
{
    return hamming_norm(a ^ b);
}

int main()
{
    int i = 0, c = 0;
    gal8 a = 1;
    while (i++ < 256) {
        /*
        gal_print(a);
        if (i != 1 && a == 1) break;
        a = gal_mul(a, generator);
        */
        printf("%d", hamming_distance(a, gal_mul(a, generator)));
        a = gal_mul(a, generator);
        if (c++ < 7) {
            putchar('\t');
        } else {
            putchar('\n');
            c = 0;
        }
    }
    if (c)
        putchar('\n');
}