/* Memoized discrete exponentiation and logarithm */

#include "galois.h"

gal8 gal_mul_fast(gal8 a, gal8 b); /* Fast multiplication */
gal8 gal_div_fast(gal8 a, gal8 b); /* Fast division */

gal8 gal_pow(gal8 b, int e); /* b ^ e */
gal8 gal_exp(int n);         /* generator ^ n */
int gal_log(gal8 a);         /* Return 0 ≤ n ≤ 254 such that generator ^ n = a */

/* Exponent and logarithm tables linked to each other by way of indices */
static gal8 exps[255];
static int  logs[255];

static int calculated = 0;

static void setup_tables();
