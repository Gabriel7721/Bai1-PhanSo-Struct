#ifndef FRACTION_H
#define FRACTION_H

#include <stdio.h>
#include "utils.h"

typedef struct
{
    i64 num;
    i64 den;
} Fraction;

typedef struct
{
    Fraction a;
    Fraction b;
} FractionPair;

Fraction fraction_input(void);
void fraction_print(Fraction x);

Fraction fraction_normalize(Fraction x);
Fraction fraction_reduce(Fraction x);

Fraction fraction_add(Fraction a, Fraction b);
Fraction fraction_sub(Fraction a, Fraction b);
Fraction fraction_mul(Fraction a, Fraction b);
Fraction fraction_div(Fraction a, Fraction b);

int fraction_is_reduced(Fraction x);
int fraction_sign(Fraction x);
FractionPair fraction_common_den(Fraction a, Fraction b);

int fraction_cmp(Fraction a, Fraction b);

#endif
