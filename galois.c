/*
 * The following is an implementation of the finite field GF(2^8) as bit vectors of length 8, where the nth bit represents the
 * coefficient of the nth power of the generator in each element, and the generator satisfies the minimal polynomial
 * x^8 + x^4 + x ^3 + x^2 + 1 in the prime field Z_2, in which addition is equivalent to XOR and multiplication to AND.
 * The elements of GF(2^8) thus represent polynomials of degree < 8 in the generator x. Addition in this field is simply 
 * bitwise XOR, but multiplication requires the elimination of powers of x <= 8.
 */

#include "galois.h"

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
