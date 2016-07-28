/*
*
*life game
*/

/*
#include <stdio.h>
#include <unistd.h>
//#include <string.h>
#include "display.h"
*/
#include "life_game.h"


int life_game()
{
	struct six_draw *draw;
	int ret = 0;
	ret = make_canvas(&draw);
	
	draw->print_display_info();

	for(int i = 0; i < 100 ; i++){
		for(int j = 0; j < 200; j++){
			draw->pixel(i, j, RGB888(255,0,0));
		}
	}


	close_canvas();

	return 0;
}
	





