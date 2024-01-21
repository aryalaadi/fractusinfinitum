/*
	Modified from atrios/sys/i386/boot.s
*/

# Multiboot
.set FLAGS,    1<<2		    
.set MAGIC,    0x1BADB002           # Magic number
.set CHECKSUM, -(MAGIC + FLAGS)     # set the checksum
.section .multiboot                 # set multiboot enabled
.long MAGIC
.long FLAGS
.long CHECKSUM


stackb:
.skip 4096                          
stackt:
.section .text
.global _start
.type _start, @function

# program entry point
_start:
    	mov $stackt, %esp
	pushl %ebx
    	call mandelbrot_i386
   	cli

hangloop:
    	hlt
    	jmp hangloop
