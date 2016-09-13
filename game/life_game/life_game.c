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
#include <time.h>
#define WIDTH 100
#define HEIGHT 50

int save[HEIGHT][WIDTH] = {0};
//int show_save[WIDTH][HEIGHT] = {0};
int tmp[HEIGHT][WIDTH] = {0};

struct six_draw *draw;

int die_or_alive(int i, int j);

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
			tmp[i][j] = die_or_alive(i, j);
		}
	}
}


int die_or_alive(int i, int j)
{
	int w, h;
	int x, y;
	int count_lifes = 0;

	for(h = i - 1; h < i + 2; ++h){
		if(h < 0){
			y = HEIGHT - 1;
		}else if(h >= HEIGHT){
			y = 0;
		}else{
			y = h;
		}
		
		for(w = j - 1; w < j + 2; ++w){
			if(w < 0){
				x = WIDTH - 1;
			}else if(w >= WIDTH){
				x = 0;
			}else{
				x = w;
			}

			if(y == i && x == j){
				continue;
			}

			if(save[y][x] == 1){
				++count_lifes;
			}
		}
	}

	if(count_lifes == 2){
		return save[i][j];
	}else if(count_lifes == 3){
		return 1;
	}else{
		return 0;
	}
}//end die_or_alive()


int life_game()
{
	int ret = 0;
	ret = make_canvas(&draw);
	
	draw->print_display_info();

	init();
	show();
	sleep(1);

	while(1000){
		sleep(1);
		next_step();
		copy();
		show();
	}




/*
	for(int i = 0; i < 100 ; i++){
		for(int j = 0; j < 200; j++){
			draw->pixel(i, j, RGB888(255,0,0));
		}
	}
*/

	close_canvas();

	return 0;
}
	





