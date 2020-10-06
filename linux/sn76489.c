#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define base 0x2C0

int main(void){
ioperm(base,1,1);
outb(0x9F,base);
outb(0xBF,base);
outb(0xDF,base);
outb(0xFF,base);
return 0;
}
