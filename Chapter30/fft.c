#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

polynomial* multiply_pols(polynomial pol_a, polynomial pol_b) {
	//pol_a and pol_b: polynomials to be multiplied
	//
	//output: polynomyal C
	
	//fft(A, B, 2);
	//print_complex(B[0]);
	//printf("\n");
	//print_complex(B[1]);
	//printf("\n");
	
	polynomial* pol_c = (polynomial*) malloc(sizeof(polynomial));
	pol_c->size = (pol_a.size > pol_b.size ? pol_a.size : pol_b.size) * 2;
	double complex* c;
	c = (double complex*) malloc(pol_c->size * sizeof(double complex));
	pol_c->pol = c;

	return pol_c;
}

void print_complex(double complex z) {
    printf("%.1f%+.1fi", creal(z), cimag(z));
}

void print_polynomial(polynomial p) {
	for (size_t i = p.size; i > 0; i--) {
		printf("(");
		print_complex(p.pol[i - 1]);
		printf(")x^%lu ", i - 1);
	}
}

int main(void)
{
	double complex A[] = {1, 2, 3, 4};
	double complex B[] = {1, 2, 3, 4};

	polynomial pol_a, pol_b;
	pol_a.size = 4;
	pol_a.pol = A;
	pol_b.size = 4;
	pol_b.pol = B;

	polynomial* pol_c = multiply_pols(pol_a, pol_b);
	

	print_polynomial(pol_a);
	printf("\n");
	//TODO: free pol_c
	free(pol_c->pol);
	free(pol_c);
	return 0;
}
