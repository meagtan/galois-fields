/* Memoized discrete exponentiation and logarithm */

#include "galois.h"

gal8 gal_exp(int n);
int gal_log(gal8 a);

static gal8 exps[255], logs[255]; /* Exponent and logarithm tables linked to each other by way of indices and pointers */
static int calculated = 0;

static void setup_tables();

void setup_tables()
{
    gal8 a = 1;
    int i;
    for (i = 0; i < 255; ++i) {
        a = gal_mul(a, generator);
        exps[i] = logs + a - 1;
        logs[a - 1] = exps + i;
    }
}

gal8 gal_exp(int n)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return exps[n % 255] - logs + 1;
}

int gal_log(gal8 a)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return logs[a - 1] - exps;
}
