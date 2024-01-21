#include <dev/vga.h>

// https://rosettacode.org/wiki/Mandelbrot_set#ASCII
int mandelbrot_i386(int k){
	float i,j,r,x,y=-16;
	while(vgaputc('\0'),y++<15)
		for(x=0;x++<80;vgaputc(" .:-;!/>)|&IH%*#"[k&15]))
			for(i=k=r=0;j=r*r-i*i-2+x/25,i=2*r*i+y/10,j*j+i*i<11&&k++<111;r=j);
	vgaprint("                                                                          ");
	setcursor(2, 0);
	vgaprint("                       Mandelbrot Set on i386 VGA                         ");
}
