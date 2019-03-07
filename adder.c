// adder.c
// Takes two integers arguments at commandline
// and outputs their sum
// by gunnarpope
// ~/repos/embedded_C $ gcc -o adder adder.c && ./adder 1 2
// 1 + 2 = 3


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char **argv)
{
int a,b;

sscanf(argv[1], "%d", &a);
sscanf(argv[2], "%d", &b);
printf("%d + %d = %d\r\n",a,b,a+b );
return 0;
}
