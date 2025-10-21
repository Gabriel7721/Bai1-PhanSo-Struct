#include <stdio.h>
#include "fraction.h"

Fraction fraction_normalize(Fraction x)
{
    if (x.den < 0)
    {
        x.den = -x.den;
        x.num = -x.num;
    }
    return x;
}

Fraction fraction_reduce(Fraction x)
{
    x = fraction_normalize(x);

    if (x.num == 0)
    {
        x.den = 1;
        return x;
    }
    i64 g = i64_gcd(x.num, x.den);
    x.num /= g;
    x.den /= g;
    return x;
}

Fraction fraction_input(void)
{
    Fraction x;

    while (1)
    {
        printf("Enter a fraction (num + den)");

        if (scanf("%ld %ld", &x.num, &x.den) != 2)
        {
            int c;

            while ((c = getchar()) != '\n' && c != EOF)
            {
                printf("invalid input. please try again. \n");

                continue;
            }
        }
        if (x.den == 0)
        {
            printf("den must be not equal to 0. Please try again. \n");
            continue;
        }
        break;
    }
    return fraction_reduce(x);
}

void fraction_print(Fraction x)
{
    x = fraction_reduce(x);
    if (x.den == 1)
    {
        printf("%ld", x.num);
    }
    else
    {
        printf("%ld %ld", x.num, x.den);
    }
}

Fraction fraction_add(Fraction a, Fraction b)
{
    Fraction c;

    c.num = a.num * b.den + b.num * a.den;
    c.den = a.den * b.den;

    return fraction_reduce(c);
}
Fraction fraction_sub(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.den - b.num * a.den;
    c.den = a.den * b.den;

    return fraction_reduce(c);
}
Fraction fraction_mul(Fraction a, Fraction b)
{
    Fraction c;

    c.num = a.num * b.num;
    c.den = a.den * b.den;

    return fraction_reduce(c);
}
Fraction fraction_div(Fraction a, Fraction b)
{
    Fraction c;

    if (b.num == 0)
    {
        printf("[WARNING] Fraction is divined by 0, return 0.\n");
        c.num = 0;
        c.den = 1;
        return c;
    }

    c.num = a.num * b.den;
    c.den = a.den * b.num;

    return fraction_reduce(c);
}

int fraction_is_reduced(Fraction x)
{
    x = fraction_normalize(x);
    if (x.num == 0)
        return 1;
    return i64_gcd(x.num, x.den) == 1;
}

int fraction_sign(Fraction x)
{
    x = fraction_normalize(x);
    if (x.num == 0)
        return 0;
    return (x.num > 0) ? 1 : -1;
}

FractionPair fraction_common_den(Fraction a, Fraction b)
{
    a = fraction_reduce(a);
    b = fraction_reduce(b);
    FractionPair out;
    i64 L = i64_lcm(a.den, b.den);
    i64 fa = L / a.den;
    i64 fb = L / b.den;
    out.a.num = a.num * fa;
    out.a.den = L;
    out.b.num = b.num * fb;
    out.b.den = L;
    return out;
}

int fraction_cmp(Fraction a, Fraction b)
{
    a = fraction_reduce(a);
    b = fraction_reduce(b);

#if defined(__GNUC__) || defined(__clang__)
    __int8 left = (__int8)a.num * b.den;
    __int8 right = (__int8)b.num * a.den;
    if (left < right)
        return -1;
    if (left > right)
        return +1;
    return 0;
#else
    // Portable fallback using long double
    long double va = (long double)a.num / (long double)a.den;
    long double vb = (long double)b.num / (long double)b.den;
    if (va < vb)
        return -1;
    if (va > vb)
        return +1;
    return 0;
#endif
}
