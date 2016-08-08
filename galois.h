typedef unsigned char gal8;

typedef uint8_t gal8; /* Galois field of order 2^8 */

const gal8 min_poly  = 0b11101,     /* Minimal polynomial x^8 + x^4 + x^3 + x^2 + 1 */
           generator = 0b10;        /* Generator of Galois field */
