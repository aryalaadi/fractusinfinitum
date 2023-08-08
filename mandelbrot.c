// public domain
// mandelbrot fractral in C for unix terminals
// by Aaditya Aryal

#include <stdio.h>
#include <complex.h>
#include <sys/ioctl.h>

int mandelbrot(double complex z);

int main() {
	
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
			if (mandelbrot(z) == 1) {
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

int mandelbrot(double complex z) {
	double complex c = z;
	for (int it=0; it<16; it++) {
		z = (z*z)+c;
		// 15 iterations of the function
		if (cabs(z)<=4 && it==15) {
			return 1;
		}
	}
	return 0;
}
