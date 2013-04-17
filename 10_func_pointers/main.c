#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE(a) (sizeof(a)/sizeof((a)[0]))

typedef struct _Student {
    char *name;
    int group;
} Student;

Student *new_student(char *name, int group) {
    Student *s = (Student*)malloc(sizeof(Student));
    s->name = name;
    s->group = group;
    return s;
}

typedef struct _List {
    void *head;
    struct _List *tail;
} List;

List *add(void *head, List *tail) {
    List *list = (List*)malloc(sizeof(List));
    list->head = head;
    list->tail = tail;
    return list;
}

void student_print1(Student *s) {
    printf("%s: %d\n", s->name, s->group);
}

void student_print2(Student *s) {
    printf("%s is bad. ;)\n", s->name);
}

typedef void (*StudentPrinter)(Student *);

void array_print(Student arr[], int size, StudentPrinter f) {
    int i;
    for (i = 0; i < size; ++i) {
        f(&arr[i]);
    }
}

void list_print(List *list, StudentPrinter f) {
    List *i;
    for (i = list; i != NULL; i = i->tail) {
        f((Student*)(i->head));    
    }
}

int main() {
    Student students_array[] = {
        {"Gorn", 12351},
        {"Minakov", 12361},
        {"Ponomarenko", 12361},
        {"Burdastykh", 12351}
    };

    List *students_list = NULL;

    students_list = add(new_student("Gorn", 12351), students_list);
    students_list = add(new_student("Minakov", 12361), students_list);
    students_list = add(new_student("Ponomarenko", 12361), students_list);
    students_list = add(new_student("Burdastykh", 12351), students_list);
    
    array_print(students_array, ARR_SIZE(students_array), student_print1);
    array_print(students_array, ARR_SIZE(students_array), student_print2);
    
    list_print(students_list, student_print1);
    list_print(students_list, student_print2);


    return 0;
}
