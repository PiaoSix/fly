#include "rules.h"


/*
*	这个函数是核心，判断每个点的生或死（亮灭）
*/
static int die_or_alive(int i, int j, const int save[HEIGHT][WIDTH])
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



int rule_entry(int i, int j, const int save[HEIGHT][WIDTH])
{
	return die_or_alive( i, j, save);
}


