/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 3:
 * Find the square root of 2 using the bisection method, the Newton-Raphson
 * method and the Regula-Falsi method.
 */
#include <stdio.h>
#include <math.h>
#include "bisection.h"
#include "newtonraphson.h"
#include "falseposition.h"

/*
 * Function that approaches the exact value of the square root of 2 in 
 * x = 0.
 */
double power(double x) {
   return x * x - 2;
}

int main(void) {
   printf("Trying to find the square root of 2:\n\n");
   bisect(0, 0, 2, &power);
   newtonraphson(4.5, &power, 0);
   falseposition(0, 2, &power);
   return 1;

}


