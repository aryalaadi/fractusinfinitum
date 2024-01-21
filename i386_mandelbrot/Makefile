all:
	cc -c -m32 boot.s -ffreestanding
	cc -c -m32 mandelbrot_i386.c -I. -ffreestanding 
	cc -c -m32 dev/vga.c -I. -ffreestanding
	ld -melf_i386 -T linker.ld boot.o mandelbrot_i386.o vga.o -o mandelbrot_i386.elf -z noexecstack
	@rm *.o

qemu:
	qemu-system-i386 -kernel mandelbrot_i386.elf
