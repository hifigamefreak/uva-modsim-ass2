#include <stdio.h>
#include <math.h>

/* Limit for the bisection to stop. */
#define EPS 0.0001
int num_steps = 0;

/* Determine whether the given result 'value' of the function 'fun'
 * lies between the given upper_value and lower_value parameters. */
int function_has_value(double value, double lower_limit, double upper_limit, double (*fun)(double)) {
   double lower_value = fun(lower_limit);
   double upper_value = fun(upper_limit);

   return (lower_value > value && upper_value < value) ||
      (lower_value < value && upper_value > value);
}

/*
 * Bisection method to accurately find the find of a given function between
 * given boundaries. If the value is found, it will be printed.
 */
void bisect(double value, double lower_limit, double upper_limit, double (*fun)(double)) {
   int has_value = function_has_value(value, lower_limit, upper_limit, fun);
   num_steps++;   
   
   /* This section contains a zero, and we're not at our stop treshhold yet:
    * Perform another bisection (ie: split the boundaries in 2,
    * and check again for each half)*/
   if(has_value && (fabs(lower_limit - upper_limit) > EPS)) {
      bisect(value, (lower_limit + upper_limit) / 2.0, upper_limit, fun);
      bisect(value, lower_limit, (lower_limit + upper_limit) / 2.0, fun);
   } 
   /* This section contains a zero, and we're below our threshold.
    * This means we've accurately found a zero! */
   else if(has_value) {
      printf("using Bisection:\n\t%f found, between %f and %f. \n\tUsed %d steps with an epsilon of %f.\n",
         value, lower_limit, upper_limit, num_steps, EPS);
   }
}

