#include <stdio.h>
#include <unistd.h>
//#include <string.h>
#include "display.h"



int main(int argc, char **argv)
{
	struct six_draw *draw;
	make_canvas(&draw);

	draw->print_display_info();


	close_canvas();

}
	





