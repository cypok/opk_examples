#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assoc_list.h"
#include "reader.h"

void free_key_and_value(void *key, void *value) {
	free(key);
	free(value);
}

void print_phonebook_entry(void *key, void *value) {
	char *name = (char*)key;
	char *number = (char*)value;
	printf("%s: %s\n", name, number);
}

int main() {
	AssocList *alist = alist_create((CmpFunc)strcmp);

	alist_put(alist, strdup("John"), strdup("+1-234-567-89-10"));
	alist_put(alist, strdup("Alex"), strdup("911"));
	alist_put(alist, strdup("Mike"), strdup("112"));

	for (;;) {
		char *name = read_string("Enter name, 'q' to exit");
		if (strcmp(name, "q") == 0) {
			break;
		} else {
			char *number = alist_get(alist, name);
            char *update_answer;
			if (number == NULL) {
				printf("%s not found.\n", name);
				update_answer = read_string("Add? [y/n]");
			} else {
				printf("%s: %s\n", name, number);
				update_answer = read_string("Update? [y/n]");
			}
            if (update_answer[0] == 'y' || update_answer[0] == 'Y') {
                number = read_string("Enter phone number");
                alist_put(alist, strdup(name), number);
                printf("%s: %s\n", name, number);
            }
            free(update_answer);
			free(name);
		}
	}

	printf("\nYour phonebook:\n");
	alist_foreach(alist, print_phonebook_entry);

	alist_foreach(alist, free_key_and_value);

	alist_destroy(alist);

	return 0;
}
