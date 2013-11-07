#include <math.h>
#include "integrations.h"

/*
 * Trapezoidal method of finding the integral of a given function in a
 * domain from lower bound to upper bound.
 */
double trapezoid(int n, double lower_limit, double upper_limit, integral fun) {

    double sum = 0.0;
    double c = (upper_limit - lower_limit) / n;
    double d = (fun(lower_limit) + fun(upper_limit)) / 2.0;

    int k;
    for(k = 1; k < n; k++) {
        sum += fun(lower_limit + k * ((upper_limit - lower_limit) / n));
    }
    return c * (d + sum);
}

/*
 * Rectangle method of calculating the integral of any function given
 * the interval lower bound to upper bound.
 */
double rect(int n, double lower_limit, double upper_limit, integral fun) {

    double sum = 0.0;
    double delta = (upper_limit - lower_limit) / n;

    int i;
    for(i = 1; i <= n; i++) {
        sum += fun(lower_limit + (i - 0.5) * delta);
    }
    sum *= delta;
    return sum;
}

/*
 * Simpson method of calculating the integral of a given function in a
 * given interval.
 */
double simpson(int n, double lower_limit, double upper_limit, integral fun) {

    double sum1 = 0.0,
           sum2 = 0.0;
    double h = (upper_limit - lower_limit) / n;

    int j;
    for(j = 1; j < n / 2.0; j++) {
        sum1 += fun(lower_limit + 2.0 * j * h);
    }
    for(j = 1; j <= n / 2.0; j++) {
        sum2 += fun(lower_limit + (2.0 * j - 1.0) * h);
    }
    return (h / 3.0) * (fun(lower_limit) + 2.0 * sum1 + 4.0 * sum2 + fun(upper_limit));
}
/*
 * Get the i-th Gauss-Legendre polynomial root for a n-point Gaussian
 * quadrature and its weight.
 */
void gauss_coeff(int n, int i, double *dist, double *weight) {
    double z = 0.0,
           z1 = 0.0,
           pp = 0.0,
           p1 = 0.0,
           p2 = 0.0,
           p3 = 0.0;

    double eps = 0.00001;
    double x1 = -1.0;
    double x2 = 1.0;

    /*
     * Calculate roots
     */
    double xm = 0.5 * (x2 + x1);
    double xl = 0.5 * (x2 - x1);


    /*
     * Crude calculation of the root.
     */
    z = cos(PI * (i - 0.25) / (n + 0.5));

    /*
     * More precise calculation using Newtons method.
     */
    do {
        p1 = 1.0;
        p2 = 0.0;

        /*
         * The Legendre polynomial.
         */
        int j;
        for(j = 1; j <= n; j++) {
            p3 = p2;
            p2 = p1;
            p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3) / j;
        }
        pp = n * (z * p1 - p2) / (z * z - 1.0);
        z1 = z;
        z = z1 - p1 / pp;

    } while(fabs(z - z1) > eps);

    *dist = xm - xl * z;
    *weight = 2.0 * xl / ((1.0 - z * z) * pp * pp);
}

/*
 * N Point Gaussian Quadrature method of calculating the integral of a
 * given function from lower bound to upper bound.
 */
double gauss(int n, double lower_limit, double upper_limit, integral fun) {
     /*
      * Variables c and d are just shortcuts.
      */
     double c = (upper_limit - lower_limit) / 2.0;
     double d = (upper_limit + lower_limit) / 2.0;
     double dist = 0.0,
            weight = 0.0,
            sum = 0.0;

     int i;
     for(i = 1; i <= n; i++) {
         gauss_coeff(n, i, &dist, &weight);
         sum += weight * fun(c * dist + d);
     }
     sum *= c;
     return sum;

}

