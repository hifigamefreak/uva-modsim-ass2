/* Practicum Modelleren Simuleren 
 * Jan Laan (5756529) & Joost Hekman (5887232)
 *
 * Assignment 2, part 1:
 * Numerical differentiation using both Right-hand as central differentiation
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "derive.h"

#define PI 3.14159265358979323846264338327

/* Main function */
int main(int argc, char* argv[]) {
   double dx = 0.0;
   int i, j = 0;

   /* These are the values we want to derive for the sinus function,
    * so: derive sin(PI/3.0) etc.*/
   double x_values[] = { PI / 3.0,
                         100 * PI + PI / 3.0,
                         pow(10,12) * PI + PI / 3.0 };

   /* Experiment with different values of h */
   double h_values[] = {0.1, 0.01, 0.001, 0.0001};

   /* Loop through the different values of x and h, 
    * and find the derivative of sin(x) using that.
    * Do this for both right-hand and central differentiation. */

   printf("---Right-hand differentiation---\n");
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 4; j++) {
         /* Calculate the derivative of sinus, using the given x_value
          * with a step size h */
         dx = derive_righthand(x_values[i], h_values[j], &sin);
         printf("dx of sin(%.3f) with h=%f: %f\n",
            x_values[i], h_values[j], dx);
      }
   }
   
   printf("---Central differentiation---\n");
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 4; j++) {
         /* Calculate the derivative of sinus, using the given x_value
          * with a step size h */
         dx = derive_central(x_values[i], h_values[j], &sin);
         printf("dx of sin(%.3f) with h=%f: %f\n",
            x_values[i], h_values[j], dx);
      }
   }

   return 1;
}
