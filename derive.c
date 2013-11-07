/* Use "Right-hand derivation" to find the derivative of a certain function fun
 * with parameter x */
double derive_righthand(double x, double h, double (*fun)(double)) {
   return (fun(x) - fun(x - h)) / h;
}

/* Use "Central derivation" to find the derivative of a certain function fun
 * with parameter x */
double derive_central(double x, double h, double(*fun)(double)) {
   return (fun(x + h) - fun(x - h)) / (2 * h);
}
