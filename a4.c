#include <stdio.h>
#include "newtonraphson.h"

double f1(double x) {
   return x * x - x + 2;
}

double f2(double x) {
   return x * x * x - 3 * x - 2;
}

double f3(double x) {
   return (x * x + 1) * (x - 4);
}

double f4(double x) {
   return x * x - x + 2;

}
int main (void) {
   printf("\nFinding zero for x^2 -1:");
   newtonraphson(4, &f1, 0);   

   printf("\nFinding zero for x^3 - 3x - 2:");
   newtonraphson(4, &f2, 0);

   printf("\nFinding zero for (x^2 + 1) (x - 4):");
   newtonraphson(2, &f3, 0);

   printf("\n\nFinding zero for x^2 - x + 2:");
   newtonraphson(0.5, &f4, 0);
   return 1;
}
