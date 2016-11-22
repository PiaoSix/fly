#include <stdio.h>
//#include <unistd.h>
//#include <string.h>

int main(int argc, char **argv)
{
	struct date{
		char bit_0;
		char bit_8;
		char bit_16;
		char bit_24;
	};

	struct date * color = NULL;
	int a = 0x12345678;

	color = &a;

	printf("bit_0 = %x, bit_8 = %x, bit_16 = %x, bit_24 = %x \n", color->bit_0, color->bit_8, color->bit_16, color->bit_24);
	printf("%d \n", a);
	printf("&bit_0  = %p \n", &color->bit_0);	
	printf("&bit_8  = %p \n", &color->bit_8);	
	printf("&bit_16 = %p \n", &color->bit_16);	
	printf("&bit_24 = %p \n", &color->bit_24);	
	
	return 0;
}







