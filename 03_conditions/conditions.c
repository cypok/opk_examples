#include <stdio.h>

void printBoolean(int value) {
    if (value) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main(void) {

    printBoolean( 1 ); // => true
    printBoolean( 0 ); // => false

    printBoolean( !(1) ); // => false
    printBoolean( !(0) ); // => true

    printBoolean( 1 && 1 ); // => true
    printBoolean( 1 && 0 ); // => false
    printBoolean( 0 && 0 ); // => false

    printBoolean( 1 || 1 ); // => true
    printBoolean( 1 || 0 ); // => true
    printBoolean( 0 || 0 ); // => false

    return 0;
}

