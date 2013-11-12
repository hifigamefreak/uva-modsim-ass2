/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 5:
 * Numerical intergration introduction.
 */
#include <stdio.h>
#include <math.h>
#include "integrations.h"

#define E 2.7182818284590452353602874713526624977572470936999595749669

double f1(double x) {
   return pow(E, -x);
}

double f2(double x) {
    return x * pow(E, -x);
}

double f3(double x) {
    return sin(x);
}

double f4(double x) {
    return pow(x, -0.5);
}

int main(void) {
    double j = 0.0;
    integral fun = &f1;

    printf("Integrals of e^-x:\n\n");
    j = trapezoid(10, 0, 1, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(10, 0, 1, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 1, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 1, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f2;

    printf("\n\nIntegrals of xe^-x on [0,2]:\n\n");
    j = trapezoid(10, 0, 2, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(10, 0, 2, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 2, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 2, fun);
    printf("Gauss \t\t= %G\n", j);

    printf("\n\nIntegrals of xe^-x on [0,20]:\n\n");
    j = trapezoid(10, 0, 20, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(10, 0, 20, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 20, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 20, fun);
    printf("Gauss \t\t= %G\n", j);

    printf("\n\nIntegrals of xe^-x on [0,200]:\n\n");
    j = trapezoid(100, 0, 200, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(100, 0, 200, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(100, 0, 200, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(100, 0, 200, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f3;

    printf("\n\nIntegrals of sin(x) on [0,8PI]:\n\n");
    j = trapezoid(10, 0, 8 * PI, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(10, 0, 8 * PI, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 8 * PI, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 8 * PI, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f4;

    printf("\n\nIntegrals of x^-0.5 on [0,2]:\n\n");
    j = trapezoid(10, 0, 2, fun);
    printf("Trapezodial \t= %G\n", j);
    j = rect(10, 0, 2, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 2, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 2, fun);
    printf("Gauss \t\t= %G\n", j);
}
