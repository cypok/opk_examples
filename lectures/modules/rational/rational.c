#include "rational.h"

const Rat RAT_ZERO = {0, 1};
const Rat RAT_ONE = {1, 1};

static Rat simplify(Rat x) {
    // For demo it's enough to divide by 2. ;)
    while (x.numer % 2 == 0 && x.denom % 2 == 0) {
        x.numer /= 2;
        x.denom /= 2;
    }
    return x;
}

Rat rat_add(Rat x, Rat y) {
    Rat res = {
        x.numer * y.denom + y.numer * x.denom,
        x.denom * y.denom};
    return simplify(res);
}

// ...
