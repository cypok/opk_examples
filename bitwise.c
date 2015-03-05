#include <stdio.h>
#include <stdbool.h>

void print_bits(int x) {
    for (int i = 31; i >= 0; i--) {
        int mask = 1 << i;
        if ((x & mask) != 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

#define FOO (1 << 0)
#define BAR (1 << 1)
#define QUX (1 << 2)


int main() {

    int flags = FOO | QUX;
    print_bits(flags);

    flags |= BAR;
    print_bits(flags);


    flags &= ~FOO;
    print_bits(flags);

    //int x = 37;
    //
    //printf("37:\n");
    //print_bits(x);

    ////printf("37 << 2:\n");
    ////print_bits(x << 2);

    ////printf("37 << 16:\n");
    ////print_bits(x << 16);

    ////printf("37 << 31:\n");
    ////print_bits(x << 31);

    ////printf("37 >> 2:\n");
    ////print_bits(x >> 2);

    //int y = -37;

    //printf("-37:\n");
    //print_bits(y);

    //printf("-37 << 2:\n");
    //print_bits(y << 2);

    //printf("-37 >> 2:\n");
    //print_bits(y >> 2);

    //unsigned int z = 3000000000;

    //printf("z:\n");
    //print_bits(z);

    //printf("z >> 2:\n");
    //print_bits(z >> 2);

    return 0;
}
