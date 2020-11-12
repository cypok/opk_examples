#include <stdio.h>
#include "rational.h"
#include "rational.h" // check double include

int main() {
    Rat x = {1, 2};
    Rat y = {1, 4};
    Rat z = rat_add(rat_add(x, y), RAT_ONE);
    printf("%d/%d\n",
            z.numer, z.denom);
    return 0;
}
