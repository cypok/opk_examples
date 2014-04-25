#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: copy <from> <to>\n");
        return 1;

    } else {
        int ch;
        char *from_file_name = argv[1];
        char *to_file_name = argv[2];

        FILE *from_file, *to_file;

        from_file = fopen(from_file_name, "rb");
        if (from_file == NULL) {
            printf("Could not read file \"%s\"!\n", from_file_name);
            return 1;
        }

        to_file = fopen(to_file_name, "wb");
        if (to_file == NULL) {
            printf("Could not write to file \"%s\"!\n", to_file_name);
            fclose(from_file);
            return 1;
        }

        // hardcore copy action
        while ((ch = getc(from_file)) != EOF) {
            putc(ch, to_file);
        }

        printf("Copied \"%s\" to \"%s\"\n", from_file_name, to_file_name);

        fclose(from_file);
        fclose(to_file);

        return 0;
    }
}

