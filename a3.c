/* Practicum Modelleren Simuleren 
 * Joost Hekman (5887232)
 *
 * Assignment 2, part 3:
 * Numerical integration of two given functions.
 */

#include <stdio.h>
#include "newtonraphson.h"

/* Function 1 */
double f1(double x) {
   return x * x * x - 3 * x - 2;
}

/* Function 2 */
double f2(double x) {
   return x * x - x + 2;

}

/* Main function */
int main(int argc, char* argv[]) {
   /* Calculate the zero using Newton-Raphson of function 1 */
   printf("\nFinding zero for x^3 - 3x - 2:");
   newtonraphson(4, &f1, 0);

   /* Now do the same for function 2 */
   printf("\n\nFinding zero for x^2 - x + 2:");
   newtonraphson(0.5, &f2, 0);
   return 1;
}
