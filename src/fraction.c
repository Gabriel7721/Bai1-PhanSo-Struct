#include <stdio.h>
#include "fraction.h"

Fraction fraction_normalize(Fraction x)
{

}

Fraction fraction_reduce(Fraction x)
{

}


Fraction fraction_input(void)
{
   
}

void fraction_print(Fraction x)
{
   
}


Fraction fraction_add(Fraction a, Fraction b)
{
   
}
Fraction fraction_sub(Fraction a, Fraction b)
{
   
}
Fraction fraction_mul(Fraction a, Fraction b)
{
  
}
Fraction fraction_div(Fraction a, Fraction b)
{
  
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
    __int128 left = (__int128)a.num * b.den;
    __int128 right = (__int128)b.num * a.den;
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
