/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 6:
 * Numerical intergration continued.
 */
#include <math.h>
#include <stdio.h>
#include "integrations.h"

#define EPS 0.0001

/*
 * Formula which is complicated to integrate.
 */
double mystical(double x) {
    return (pow(x, (5 / 6.0)) * pow((4 - x), (1 / 6.0))) /
        ((5.0 - x) * (6.0 - x) * (7.0 - x));
}

/*
 * Evaluates the outcome of the integration of the function and compares
 * so that maximum precision is used, up to epsilon.
 */
void evaluate(double lower_limit, double upper_limit, integral fun, double(*integrate) (int, double, double, integral), double *value, int *steps) {
    double old_value = 0.0,
           new_value = 0.0;
    int i = 1;

    /*
     * Calculate two subsequent values of the integral of the function and
     * see if there is any significant difference between the two; continue
     * if there is, otherwise return answers and stop.
     */
    do {
        old_value = integrate(i, 0, 4, fun);
        new_value = integrate(i+1, 0, 4, fun);
        i += 1;
    } while(fabs(new_value - old_value > EPS));

    *steps = i;
    *value = new_value;
}

int main(void) {

    double value = 0.0;
    int steps = 0;

    evaluate(0, 2, &mystical, trapezoid, &value, &steps);
    printf("Trapezodial\t= %G with a maximal accuracy of %f with " 
        "%d sample points\n", value, EPS, steps);

    evaluate(0, 2, &mystical, rect, &value, &steps);
    printf("Rectangle\t= %G with a maximal accuracy of %f with " 
        "%d sample points\n", value, EPS, steps);

    evaluate(0, 2, &mystical, simpson, &value, &steps);
    printf("Simpson\t\t= %G with a maximal accuracy of %f with " 
        "%d sample points\n", value, EPS, steps);

    evaluate(0, 2, &mystical, gauss, &value, &steps);
    printf("Gauss\t\t= %G with a maximal accuracy of %f with " 
        "%d sample points\n", value, EPS, steps);
}
