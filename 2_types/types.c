#include <stdio.h>
#include <stdbool.h>

int main() {
    short short_num = 3; // 16 bytes: -32000 ... +32000
    int num = 3; // 32 bytes: -2*10^9 ... +2*10^9
    long long int big_num = 5000000000L; // 64 bytes: -much ... +mach
    float value = 7.0f;
    double value2 = 9.0;
    char symbol = 'a';
    char *string = "some string";
    bool some_flag = true; // C99
    bool inverted_flag = !some_flag;
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("short num: %d\n", num);
    printf("num: %d\n", num);
    printf("big num: %lld\n", big_num);
    printf("floating point num: %.2f\n", value);
    printf("floating point num with double precision: %.1lf\n", value2);
    printf("character: %c\n", symbol);
    printf("string: %s\n", string);
    printf("boolean flag: %s\n", some_flag ? "true" : "false");
    printf("boolean inverted flag: %s\n", inverted_flag ? "true" : "false");
    printf("array: there is no way to output array via printf\n");
    return 0;
}
