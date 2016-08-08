/* Memoized discrete exponentiation and logarithm */

typedef unsigned char galint;

extern galint generator;
static galint exps[255], logs[255]; /* Exponent and logarithm tables linked to each other by way of indices and pointers */
static int calculated = 0;

static void setup_tables();
galint gal_exp(int n);
int gal_log(galint a);

void setup_tables()
{
    galint a = 1;
    int i;
    for (i = 0; i < 255; ++i) {
        a = gal_mul(a, generator);
        exps[i] = logs + a - 1;
        logs[a - 1] = exps + i;
    }
}

galint gal_exp(int n)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return exps[n % 255] - logs + 1;
}

int gal_log(galint a)
{
    if (!calculated) {
        setup_tables();
        calculated = 1;
    }
    return logs[a - 1] - exps;
}
