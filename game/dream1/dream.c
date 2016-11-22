/*
*life game
*/
#include <time.h>
#include "dream.h"

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
	for(int y = 0; y < HEIGHT; ++y){
		for(int x = 0; x < WIDTH; ++x){
			usleep(100);
			if(save[y][x] == 1){
				draw->pixel(x, y, RGB888(255,0,0));
			}else{
				draw->pixel(x, y, RGB888(0,0,0));
			
			}
		}
	}
}

void clean()
{
	for(int y = 0; y < HEIGHT; ++y){
		for(int x = 0; x < WIDTH; ++x){
			save[x][y] = 0;
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

int dream()
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
	





