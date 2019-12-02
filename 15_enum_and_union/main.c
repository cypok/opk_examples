#include <stdio.h>
#include <assert.h>

typedef enum _ValueKind {
    INT,
    DOUBLE,
    STRING,
} ValueKind;

typedef struct _Value {
    ValueKind kind;
    union {
        int intValue;
        double doubleValue;
        char* stringValue;
    } value;
} Value;

typedef struct _Entry {
    char* key;
    Value value;
} Entry;

void printValue(FILE* f, Value* v) {
    switch (v->kind) {
        case INT:
            fprintf(f, "%d", v->value.intValue);
            break;
        case DOUBLE:
            fprintf(f, "%g", v->value.doubleValue);
            break;
        case STRING:
            fprintf(f, "%s", v->value.stringValue);
            break;
        default:
            assert(0);
            break;
    }
}

int main() {
    Entry database[] = {
            { .key = "Main skill",          .value = { .kind = STRING, .value.stringValue = "Computer science" } },
            { .key = "Age",                 .value = { .kind = INT,    .value.intValue    = 19 } },
            { .key = "Grade point average", .value = { .kind = DOUBLE, .value.doubleValue = 4.67 } },
    };

    for (size_t i = 0; i < sizeof(database)/sizeof(database[0]); i++) {
        Entry *e = &database[i];
        printf("%s: ", e->key);
        printValue(stdout, &e->value);
        printf("\n");
    }

    return 0;
}
