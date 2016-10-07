/* Memoized discrete exponentiation and logarithm */

#include "logarithm.h"

void setup_tables()
{
    gal8 a = 1;
    int i;
    for (i = 0; i < 255; ++i) {
        exps[i] = a - 1;
        logs[a - 1] = i;
        a = gal_mul(a, generator);
    }
}

gal8 gal_mul_fast(gal8 a, gal8 b)
{
    return gal_exp(gal_log(a) + gal_log(b));
}

gal8 gal_div_fast(gal8 a, gal8 b)
{
    return gal_exp(gal_log(a) - gal_log(b));
}

gal8 gal_pow(gal8 b, int e)
{
    return gal_exp(gal_log(b) * e);
}

gal8 gal_exp(int n)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return exps[n % 255] + 1;
}

int gal_log(gal8 a)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return logs[a - 1];
}
