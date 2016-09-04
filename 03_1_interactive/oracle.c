#include <stdio.h>

int main() {
    printf("I will tell you your destination.\n");
    printf("Are you a woman (y/n)?\n");

    char woman_answer;
    scanf("%c", &woman_answer);

    if (woman_answer == 'y') {
        printf("Hey! You should not be a programmer.\n");
    } else {
        if (woman_answer == 'n') {
            printf("Yeah... You will be a cool programmer!\n");
        } else {
            printf("You are not a human, go away.\n");
        }
    }
    return 0;
}
