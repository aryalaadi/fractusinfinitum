all:
	cc -c -m32 boot.s mandelbrot_i386.c dev/vga.c dev/vga.c -I. -ffreestanding
	ld -melf_i386 -T linker.ld boot.o mandelbrot_i386.o vga.o -o mandelbrot_i386.elf -z noexecstack
	@rm *.o

qemu:
	qemu-system-i386 -kernel mandelbrot_i386.elf
