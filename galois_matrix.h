/* 
 * This alternate implementation realizes elements of the finite field GF(2^8) as 8x8 matrices of bits, or arrays of 8 bytes.
 * The generator of the finite field is simply the companion matrix of the minimal polynomial x^8 + x^4 + x^3 + x^2 + 1,
 * or its transpose. The arithmetic in this finite field is usual matrix arithmetic.
 */

#include "galois.h"
             
const gal8 gener[8] = {1, 0x80, 0x40 + 1, 0x20 + 1, 0x10 + 1, 8, 4, 2}, /* companion matrix of min_poly */
           gentr[8] = {0x40, 0x20, 0x10, 8, 4, 2, 1, 0b10111000}, /* transpose of gener */
           unity[8] = {0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1},
           zero[8]  = {0};

gal8 *mat_add(gal8 *a, gal8 *b);          /* add two matrices */
gal8 *mat_mul(gal8 *a, gal8 *b);          /* multiply two matrices */
gal8 *mat_scalar_mul(uint8_t a, gal8 *b); /* multiply matrix by scalar */
gal8 mat_app(gal8 a, gal8 *b);            /* apply matrix to row vector */
gal8 *to_matrix(gal8 a);                  /* convert byte into matrix */
void mat_print(gal8 *a);                  /* print matrix */
