#include <stdio.h>

typedef uint8_t gal8;

const gal8 min_poly  = 0b11101,
           generator = 0b10;

gal8 gal_add(gal8 a, gal8 b);
gal8 gal_mul(gal8 a, gal8 b);
void gal_print(gal8 a);

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

int main()
{
    int i = 0, c = 0;
    gal8 a = 1;
    while (i++ < 256) {
        gal_print(a);
        if (i != 1 && a == 1) break;
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