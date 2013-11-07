#include <stdio.h>
#include <math.h>

#define FP_EPS 0.0001
int steps = 0;

/*
 * Regula Falsi method to accurately find the range of a zeropoint of a
 * given function. 
 */
void falseposition(double lower_limit, double upper_limit, double (*fun) (double)) {
   
   steps++;

   double a_k = fun(lower_limit);
   double b_k = fun(upper_limit);
   
   /*
    * Difference smaller then epsilon found, so return range and stop.
    */
   if(fabs(a_k - b_k) < FP_EPS) {
      printf("\n\nUsing Regula Falsi:\n\tsolution found: between %f and %f\n\tUsed %d steps with an epsilon of %f.\n",
         lower_limit, upper_limit, steps, FP_EPS);
      return;
   }

   /*
    * Calculate the root of the secant line between lower and upper
    * limit.
    */
   double c_k = (b_k * lower_limit - a_k * upper_limit) / (b_k - a_k);

   /*
    * We want to continue finding our zero. As new bounds we use the
    * part between our secant line and one of our upper/lower bounds
    * that crosses 0 (= the function of those 2 have a different sign)
    */
   if((a_k > 0 && fun(c_k) > 0) || (a_k < 0 && fun(c_k) < 0)) {
      falseposition(c_k, upper_limit, fun);
   }
   else {
      falseposition(lower_limit, c_k, fun);
   }
}
