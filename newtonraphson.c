#include <stdio.h>
#include <math.h>
#include "derive.h"

#define R_EPS 0.0001
#define MAX_STEPS 200

/*
 * Newton-Raphson method to accurately find the value of a given function
 * around a given estimated value using central dervation method. 
 * Stops when either a maximum number of steps has been reached
 * or when the difference between two subsequent guesses is smaller then
 * a predefined epsilon.
 */
//void bisect(double value, double lower_limit, double upper_limit, double (*fun)(double))
void newtonraphson(double guess, double (*fun)(double), int n_steps) {
   
   /*
    * Maximum number of steps reached and no solution found, so stop.
    */
   if(n_steps > MAX_STEPS) {
      printf("No solution found. Maximum amount of steps (%d) exceeded.\n\n", MAX_STEPS);
      return;
   }

   /*
    * Next best guess based on previous guess and central derivation.
    */
   double new_guess = guess - fun(guess) / derive_central(guess, 0.0001, fun);

   /*
    * Difference smaller then epsilon found, so stop and print solution.
    */
   if(fabs(guess - new_guess) < R_EPS) {
      printf("\n\nUsing Newton-Raphson with an epsilon of %f:\n\t solution found: %f in %d steps.\n",
         R_EPS, new_guess, n_steps);
   }
   else {
      /*
       * Recursively continue with one step taken.
       */
      newtonraphson(new_guess, fun, n_steps + 1);
   }
}
