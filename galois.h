typedef unsigned char gal8;

typedef uint8_t gal8; /* Galois field of order 2^8 */

const gal8 min_poly  = 0b11101,     /* Minimal polynomial x^8 + x^4 + x^3 + x^2 + 1 */
           generator = 0b10;        /* Generator of Galois field */

gal8 gal_add(gal8 a, gal8 b);       /* Add two elements of GF(2^8) */
gal8 gal_mul(gal8 a, gal8 b);       /* Multiply two elements of GF(2^8) */
void gal_print(gal8 a);             /* Print an element of GF(2^8) in binary form */
int hamming_norm(int a);            /* Number of nonzero bits in a */
int hamming_distance(int a, int b); /* Number of different bits between a and b */
