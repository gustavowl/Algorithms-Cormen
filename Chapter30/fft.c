#include <complex.h>
#include <math.h>
#include <stdio.h>

const double pi = acos(-1);

typedef struct polynomials {
	double complex* pol;
	size_t size;
} polynomial;


void fft(double complex* a, double complex* y, size_t n) {
	//a: input vector
	//y: output vector
	//n: size of a, and y vectors. n must be a power of 2
	
	if (n == 1) {
		y[0] = a[0];
		return;
	}

	double complex omega_n = cexp(pi * I); //\omega_n = e^{2 \pi i / n}
	double complex omega = 1;

	double complex a0[n/2], a1[n/2];
	double complex y0[n/2], y1[n/2];

	for (size_t i = 0; i < n/2; i++) {
		a0[i] = a[i*2]; //a_0, a_2, a_4, ... , a_{n - 2}
		a1[i] = a[i*2 + 1]; //a_1, a_3, a_5, ... , a_{n - 1}
	}
	
	fft(a0, y0, n/2);
	fft(a1, y1, n/2);

	for (size_t k = 0; k < n/2; k++) {
		y[k] = y0[k] + omega * y1[k];
		y[k + n/2] = y0[k] - omega * y1[k];
		omega = omega * omega_n;
	}
}

void print_complex(double complex z) {
    printf("%.1f%+.1fi", creal(z), cimag(z));
}

int main(void)
{
	//double complex A[] = {1, 2, 3, 4};
	//double complex B[SIZE] = {1, 2, 3, 4};
	//multiply_pols(A, B, *size);
}
