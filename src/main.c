#include <stdio.h>
#include "fraction.h"

static void print_line(void) { puts("----------------------------------------"); }

int main(void) {
    Fraction p = fraction_input();
    Fraction q = fraction_input();

    print_line();
    printf("p = "); fraction_print(p); printf("\n");
    printf("q = "); fraction_print(q); printf("\n");

    print_line();
    printf("Reduced? p: %s, q: %s\n",
           fraction_is_reduced(p) ? "yes" : "no",
           fraction_is_reduced(q) ? "yes" : "no");

    print_line();
    FractionPair cd = fraction_common_den(p, q);
    printf("Common denominator form:\n");
    printf("p' = "); fraction_print(cd.a); printf("\n");
    printf("q' = "); fraction_print(cd.b); printf("\n");

    print_line();
    printf("p + q = "); fraction_print(fraction_add(p, q)); printf("\n");
    printf("p - q = "); fraction_print(fraction_sub(p, q)); printf("\n");
    printf("p * q = "); fraction_print(fraction_mul(p, q)); printf("\n");
    printf("p / q = "); fraction_print(fraction_div(p, q)); printf("\n");

    print_line();
    int sp = fraction_sign(p), sq = fraction_sign(q);
    printf("sign(p) = %d  ( -1: negative, 0: zero, +1: positive )\n", sp);
    printf("sign(q) = %d\n", sq);

    print_line();
    int cmp = fraction_cmp(p, q);
    if (cmp < 0) { fraction_print(p); printf(" < "); fraction_print(q); puts(""); }
    else if (cmp > 0) { fraction_print(p); printf(" > "); fraction_print(q); puts(""); }
    else { fraction_print(p); printf(" = "); fraction_print(q); puts(""); }

    return 0;
}
