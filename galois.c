#include <stdio.h>

typedef uint8_t gal8; /* Galois field of order 2^8 */

const gal8 min_poly  = 0b11101, /* Minimal polynomial x^8 + x^4 + x^3 + x^2 + 1 */
           generator = 0b10;    /* Generator of Galois field */

gal8 gal_add(gal8 a, gal8 b);   /* Add two elements of GF(2^8) */
gal8 gal_mul(gal8 a, gal8 b);   /* Multiply two elements of GF(2^8) */
void gal_print(gal8 a);         /* Print an element of GF(2^8) in binary form */

gal8 gal_add(gal8 a, gal8 b)
{
    return a ^ b;
}

gal8 gal_mul(gal8 a, gal8 b)
{
    gal8 res = 0;
    for (; b; b >>= 1) {
        if (b & 1) /* add a to res if b's 0th bit is 1 */
            res ^= a;
        a = (a << 1) ^ (a & 0x80 & min_poly); /* shift a left, add min_poly if a's 8th bit is 1 */
    }
    return res;
}

void gal_print(gal8 a)
{
    int i = 8;
    while (i--)
        putchar((a >> i & 1) + '0');
}

/* print all powers of generator from 0 to 255 in an 8 column grid */
int main()
{
    int i = 0, c = 0;
    gal8 a = 1;
    while (i++ < 256) {
        gal_print(a);
        /* if (i != 1 && a == 1) break; */
        a = gal_mul(a, generator);
        if (++c < 8) {
            putchar(' ');
        } else {
            putchar('\n');
            c = 0;
        }
    }
    if (c)
        putchar('\n');
}