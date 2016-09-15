/*
*life game
*/
#include <time.h>
#include "life_game.h"

int save[HEIGHT][WIDTH] = {0};
//int show_save[WIDTH][HEIGHT] = {0};
int tmp[HEIGHT][WIDTH] = {0};

struct six_draw *draw;


void test_init()
{
	save[2][2] = 1;
	save[2][3] = 1;
	save[2][4] = 1;
}
void init()
{
	srand((unsigned)time(0));
	for(int i = 0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			save[i][j] = rand() % 2;
		}
	}
}

void show()
{
	for(int i = 0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			if(save[i][j] == 1){
				draw->pixel(i, j, RGB888(255,0,0));
			}else{
				draw->pixel(i, j, RGB888(0,0,0));
			
			}
		}
	}
}

void clean()
{
	for(int i = 0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			save[i][j] = 0;
		}
	}
}

void copy()
{
	for(int i = 0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			save[i][j] = tmp[i][j];
		}
	}
}

void next_step()
{
	for(int i = 0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			tmp[i][j] = rule_entry(i, j, save);
		}
	}
}

int life_game()
{
	int ret = 0;
	ret = make_canvas(&draw);
	
	draw->print_display_info();

	init();
	show();
	sleep(1);

	while(1000){
		usleep(100);
		next_step();
		copy();
		show();
	}

	close_canvas();

	return 0;
}
	





