#include <stdio.h>
#include <unistd.h>
#include <string.h>
//#include "2.h"


void change(int *x, int *y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;

}


int main(int argc, char **argv)
{
	printf("%s \n", __func__);

	int a, b;
	a = 1; 
	b = 2;
	

	change(&a, &b);

	printf("a = %d, b = %d \n", a, b);

	return 0;
}







