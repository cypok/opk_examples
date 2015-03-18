#define _CRT_SECURE_NO_WARNINGS
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

void printPoint(Point *p) {
    printf("(%g, %g, %g)", p->x, p->y, p->z);
}

void scanPoint(Point *p) {
    double x, y, z;
    int res = scanf("%lf %lf %lf", &x, &y, &z);
    if (res == 3) {
        p->x = x;
        p->y = y;
        p->z = z;
    }
}

Point scanPointMega() {
    double x, y, z;
    int res = scanf("%lf %lf %lf", &x, &y, &z);
    if (res == 3) {
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
    printPoint(&p1);
    printf("\n");

    printf("p2: ");
    printPoint(&p2);
    printf("\n");

    //Point p3;
    //scanPoint(&p3);
    //printf("p3: ");
    //printPoint(p3);
    //printf("\n");

    Planet earth = { "Earth", { 100, 500, 0.5 } };
    printf("%s: ", earth.name);
    printPoint(&earth.position);
    printf("\n");

    Planet mars = { "Mars", { 500, 700, 0.8 } };

    Planet solarSystem[] = { earth, mars };

    return 0;
}
