/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 5:
 * Numerical intergration introduction of the six specified function 
 * and their range with all of the methods defined in the headerfile.
 */
#include <stdio.h>
#include <math.h>
#include "integrations.h"

#define E 2.7182818284590452353602874713526624977572470936999595749669

/* Function 1 */
double f1(double x) {
    return pow(x, 2);
}

/* Function 2 */
double f2(double x) {
    return pow(x, 3);
}

/* Function 3 */
double f3(double x) {
    return pow(x, 5);
}

/* Function 4 */
double f4(double x) {
    return pow(E, -x);
}

/* Function 5 */
double f5(double x){
    return x * pow(E, -x);
}

/* Function 6 */
double f6(double x){
    return pow(x, -0.5);
}

/* Main function */
int main(int argc, char* argv[]) {
    double j = 0.0;
    integral fun = &f1;

    /* Print the integrals of the first function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of x^2 on [0,1]:\n\n");
    j = trapezoid(10, 0, 1, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 1, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 1, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 1, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f2;

    /* Print the integrals of the second function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of x^3 on [0,1]:\n\n");
    j = trapezoid(10, 0, 1, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 1, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 1, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 1, fun);
    printf("Gauss \t\t= %G\n", j);
	
    fun = &f3;

    /* Print the integrals of the third function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of x^5 on [0,1]:\n\n");
    j = trapezoid(10, 0, 1, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 1, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 1, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 1, fun);
    printf("Gauss \t\t= %G\n", j);
 
    fun = &f4;

    /* Print the integrals of the fourth function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of e^-x on [0,1]:\n\n");
    j = trapezoid(10, 0, 1, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 1, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 1, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 1, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f5;

    /* Print the integrals of the fifth function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of xe^-x on [0,2]:\n\n");
    j = trapezoid(10, 0, 2, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 2, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 2, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 2, fun);
    printf("Gauss \t\t= %G\n", j);

    fun = &f6;

    /* Print the integrals of the sixth function using all of the available 
     * methods including trapezoidal, rectangle, Simpson and Gauss
     */
    printf("\nIntegrals of x^-0.5 on [0,2]:\n\n");
    j = trapezoid(10, 0, 2, fun);
    printf("Trapezoidal \t= %G\n", j);
    j = rect(10, 0, 2, fun);
    printf("Rectangle \t= %G\n", j);
    j = simpson(10, 0, 2, fun);
    printf("Simpson \t= %G\n", j);
    j = gauss(10, 0, 2, fun);
    printf("Gauss \t\t= %G\n", j);

    return 1;
}
