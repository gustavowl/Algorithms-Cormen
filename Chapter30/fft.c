#include <complex.h>
#include <stdio.h>

double complex A[4] = {1, 2, 3, 4};
double complex B[4] = {1, 2, 3, 4};

int main(void)
{
    double complex z = 1 + 2*I;
    z = 1/z;
    printf("1/(1.0+2.0i) = %.1f%+.1fi\n", creal(z), cimag(z));
}
