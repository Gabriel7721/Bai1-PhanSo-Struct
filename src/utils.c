#include "utils.h"

i64 i64_abs(i64 x)
{
    return x < 0 ? -(x) : x;
}

i64 i64_gcd(i64 a, i64 b)
{
    a = i64_abs(a);
    b = i64_abs(b);

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (b != 0)
    {
        i64 r = a % b;
        a = b;
        b = r;
    }

    return a;
}

i64 i64_lcm(i64 a, i64 b)
{
    a = i64_abs(a);
    b = i64_abs(b);

    if (a == 0 || b == 0)
        return 0;

    return (a / i64_gcd(a, b) * b);
}
