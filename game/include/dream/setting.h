#ifndef SETTING_H
#define SETTING_H

#define WIDTH 200
#define HEIGHT 600
/*
*	显示在屏幕上，可以看到的颜色基因。
*/
struct skin_color{
	unsigned char transparent;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

struct DNA {
	struct skin_color skin;
};


#endif
