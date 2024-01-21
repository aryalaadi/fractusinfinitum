/*
	file:		sys/dev/vga.c
	license:	GPL3
*/

#include <dev/vga.h>

#define TXT 0x07 // white on black

char *vgamagic = (char *) 0xb8000;

unsigned int line = 0;
unsigned int pos = 0;

void setcursor(int l, int p) {
	line = l;
	pos = p;
}

void incpos(void) {
	if (pos == 80*2) {
		pos = 0;
		line++;
	}
	else {
		pos+=2;
	}
}

void vgaclear(void){
    unsigned int i = 0;
    while (i < (80*25*2)){
        vgamagic[i] = ' ';
        i++;
        vgamagic[i] = TXT;
        i++;
    }
}

void vgaputc(const char c) {
	if (c == '\n') {
		line++;
		pos=0;
	}
	else {
		vgamagic[(line*80*2)+pos] = c;
		vgamagic[(line*80*2)+pos+1] = TXT;
		incpos();
	}
}

unsigned int vgaprint(char *string){
    unsigned int i = 0;

    i = (line*80*2);

    while(*string != 0){
        if (*string == '\n'){
            line++;
	    pos=0;
            i = (line*80*2);
            *string++;
        } else {
            vgamagic[i] = *string;
            *string++;
            i++;
            vgamagic[i] = TXT;
            i++;
	    incpos();
        }
    }
    line++;
    pos=0;
    return(1);
}
