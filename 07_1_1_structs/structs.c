#include <stdio.h>

typedef struct _Point {
    double x;
    double y;
    double z;
} Point;

typedef struct _Planet {
    char *name;
    Point position;
} Planet;

void print_point(Point *p) {
    printf("(%g, %g, %g)", p->x, p->y, p->z);
}

void scan_point(Point *p) {
    double x, y, z;
    int res = scanf("%lf %lf %lf", &x, &y, &z);
    if (res == 3) {
        p->x = x;
        p->y = y;
        p->z = z;
    }
}

Point scan_point_bad() {
    double x, y, z;
    int res = scanf("%lf %lf %lf", &x, &y, &z);
    if (res == 3) {
        // it will copy your struct while return
        Point p = { x, y, z };
        return p;
    } else {
        // TODO: error handling?
        Point p = { 0, 0, 0 };
        return p;
    }
}

int main() {

    Point p1;
    p1.x = 1;
    p1.y = 0;
    p1.z = 2;

    Point p2 = {3.5, 4, 5};

    printf("p1: ");
    print_point(&p1);
    printf("\n");

    printf("p2: ");
    print_point(&p2);
    printf("\n");

    Point p3;
    scan_point(&p3);
    printf("p3: ");
    print_point(&p3);
    printf("\n");

    Planet earth = { "Earth", { 100, 500, 0.5 } };
    printf("%s: ", earth.name);
    print_point(&earth.position);
    printf("\n");

    Planet mars = { "Mars", { 500, 700, 0.8 } };

    Planet solar_system[] = { earth, mars };

    return 0;
}

