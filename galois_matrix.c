/* 
 * This alternate implementation realizes elements of the finite field GF(2^8) as 8x8 matrices of bits, or arrays of 8 bytes.
 * The generator of the finite field is simply the companion matrix of the minimal polynomial x^8 + x^4 + x^3 + x^2 + 1,
 * or its transpose. The arithmetic in this finite field is usual matrix arithmetic.
 */

#include "galois_matrix.h"

gal8 *mat_add(gal8 *a, gal8 *b)
{
    gal8 res[8];
    int i;
    
    for (i = 0; i < 8; ++i)
        res[i] = a[i] + b[i];
        
    return res;
}

gal8 *mat_mul(gal8 *a, gal8 *b)
{
    gal8 res[8] = {0};
    int i, j, k;
    
    /* For each ij, res_ij = sum of a_ik & b_kj for each k */
    for (i = 0; i < 8; ++i)
        for (j = 0; j < 8; ++j)
            for (k = 0; k < 8; ++k)
                res[i] ^= ((a[i] >> (7 - k)) & (b[k] >> (7 - j)) & 1) << (7 - j); 
    
    return res;
}

/* this concerns a as a scalar, not as a gal8 */
gal8 *mat_scalar_mul(uint8_t a, gal8 *b)
{
    gal8 res[8];
    int i;
    
    for (i = 0; i < 8; ++i)
        res[i] = a & b[i];
    
    return res;
}

/* a is taken to be a row vector, applied to b from the left */
gal8 mat_app(gal8 a, gal8 *b)
{
    gal8 res = 0;
    int i, j;
    
    /* multiply the ith row of b with the ith bit of a starting from the left */
    for (i = 0, j = 0x80; i < 8; ++i, j >>= 1)
        if (a & j)
            res ^= b[i];
    
    return res;
}

/* convert a to its matrix equivalent */
gal8 *to_matrix(gal8 a)
{
    gal8 res[8] = {0}, *aux;
    int i;
    
    for (; a; a >>= 1) {
        aux = mat_add(res, mat_scalar_mul(a & 1, gener));
        for (i = 0; i < 8; ++i)
            res[i] = aux[i];
    }

    return res;
}

void mat_print(gal8 *a)
{
    int i;
    for (i = 0; i < 8; ++i) {
        gal_print(a[i]);
        putchar('\n');
    }
}
