// public domain
// julia fractal in C for unix terminals
// by Aaditya Aryal

#include <stdio.h>
#include <complex.h>
#include <sys/ioctl.h>
#include <math.h>

int julia(double complex z, double complex c);

int main(int argc, char *argv) {
	
	// multi-julia seed
	// using f(z) = z*z + 0.7885*(e^(i*π)) for the julia seed
	double cre = 0.7885*cos(M_PI); 
	double cim = 0.7885*sin(M_PI);	
	double complex c = CMPLX(cre, cim);

	/*
	Julia set is defined to be J(z)=z*z+c where C is a constant between (-1,1) and (-1i,1i)
	unlike mandelbrot set where the constant is defined to be the range of the given function. 
	The julia set is a set of many other julia sets, a constant given for the function is the seed
	one standard general seed is given by c = 0.7885*(e^i*a) where a is another constant between (0, 2π)
	
	other cool seeds:	
	c = 1 − φ
	c = (φ − 2) + (φ − 1)i
	c = −0.835 − 0.2321i
	c = −0.7269 + 0.1889i
	cre = cim = -0.5251993
	c = -0.512511498387847167, 0.521295573094847167i
	
	φ is the golden ratio, approx. 1.618
	*/

	struct winsize sz;
	ioctl(0, TIOCGWINSZ, &sz);
	int h = sz.ws_row;
	int w = sz.ws_col;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			double re = (2*(j - (double)w/2))/(double)h;
			double im = (2*(i - (double)h/2))/(double)w*5;
			/*
			scaling `im` by 5 to fit the unix terminal height width ratio
			also scaling x and y to be within abs<=4 due to the rules of the set
			*/
			double complex z = CMPLX(re, im);
			if (julia(z,c) == 1) {
				printf("x"); // within the set
			} 
			else {
				printf("."); // not part of the set
			}	
		}	
		printf("\n");
	}
	return 0;
}

int julia(double complex z, double complex c) {
	for (int it=0; it<16; it++) {
		z = (z*z)+c;
		// 15 iterations of the function
		if (cabs(z)<=4 && it==15) {
			return 1;
		}
	}
	return 0;
}
