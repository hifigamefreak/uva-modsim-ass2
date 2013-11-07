/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 2:
 * Find the zero for a given function using the bisection method.
 */
#include <stdio.h>
#include <math.h>
#include "bisection.h"

/*
 * Implementation of the function we want to find the zero of.
 */
double f(double x) {
   return x * sin(x) - 1.0;
}


int main(void) {   
   
   bisect(0, 0.0, 2.0, &f);
   
   return 1;
}
