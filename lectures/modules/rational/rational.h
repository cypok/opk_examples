#ifndef _RATIONAL_H_
#define _RATIONAL_H_

typedef struct Rat {
    int numer;
    unsigned denom;
} Rat;

extern const Rat RAT_ZERO;
extern const Rat RAT_ONE;

Rat rat_add(Rat x, Rat y);
Rat rat_sub(Rat x, Rat y);
Rat rat_mul(Rat x, Rat y);
// ...

#endif
