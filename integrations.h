#define PI 3.1415926535897932384626433832795028841971693993751058209749

typedef double (*integral)(double);

double trapezoid(int n, double lower_limit, double upper_limit, integral);

double rect(int n, double lower_limit, double upper_limit, integral);

double simpson(int n, double lower_limit, double upper_limit, integral);

void gauss_coeff(int n, int i, double *dist, double *weight);

double gauss(int n, double lower_limit, double upper_limit, integral);

