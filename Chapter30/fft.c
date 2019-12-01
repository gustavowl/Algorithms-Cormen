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

	double complex omega_n = cexp(2*pi*I/n);
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

void ifft(double complex* a, double complex* y, size_t n) {
	//a: input vector
	//y: output vector
	//n: size of a, and y vectors. n must be a power of 2
	
	if (n == 1) {
		y[0] = a[0];
		return;
	}

	double complex omega_n = cexp(-2*pi*I/n);
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
		y[k] = y0[k] + omega * y1[k] / n;
		y[k + n/2] = y0[k] - omega * y1[k] / n;
		omega = omega * omega_n;
	}
}

void free_pol(polynomial* p) {
	free(p->pol);
	free(p);
}

polynomial* extend_pol(polynomial p, size_t new_size) {
	//creates polynomial
	polynomial* p_ext = (polynomial*) malloc(sizeof(polynomial));
	p_ext->size = new_size;
	double complex* pol;
	pol = (double complex*) malloc(p_ext->size * sizeof(double complex));
	p_ext->pol = pol;

	//initializes
	for (size_t i = 0; i < p.size; i++) //copies original values
		pol[i] = p.pol[i];
	for (size_t i = p.size; i < p_ext->size; i++) //0 remaining values
		pol[i] = 0;

	return p_ext;
}

polynomial* multiply_pols(polynomial pol_a, polynomial pol_b) {

	//extends input polynomials
	size_t pol_c_size = pol_a.size > pol_b.size ? pol_a.size : pol_b.size;
	pol_c_size *= 2;

	polynomial* a_ext = extend_pol(pol_a, pol_c_size);
	polynomial* b_ext = extend_pol(pol_b, pol_c_size);

	//applies fft to extended polynomials
	double complex* ya = (double complex*) malloc(a_ext->size * sizeof(double complex));
	double complex* yb = (double complex*) malloc(b_ext->size * sizeof(double complex));
	fft(a_ext->pol, ya, a_ext->size);
	fft(b_ext->pol, yb, b_ext->size);

	//assigns point-value representation to extended polynomials
	free(a_ext->pol);
	free(b_ext->pol);
	a_ext->pol = ya;
	b_ext->pol = yb;

	//multiples a_ext and b_ext
	polynomial* pol_c;
	pol_c = extend_pol(pol_a, pol_c_size);
	
	for (size_t i = 0; i < pol_c->size; i++)
		pol_c->pol[i] = a_ext->pol[i] * b_ext->pol[i];

	//TODO: implement ifft

	free_pol(a_ext);
	free_pol(b_ext);

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

	print_polynomial(*pol_c);
	printf("\n");

	free_pol(pol_c);

	return 0;
}
