/*
* display.h
*/


#include <stdio.h>
#include <unistd.h>
//#include <string.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
//#include "display.h"

#define DEVNAME "/dev/fb0"
#define RGB888(r,g,b) (((r) & 0xff) << 16 | ((g) & 0xff) << 8 | (b) & 0xff )



typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8; 

struct display_info{
	int fd;
	struct fb_fix_screeninfo fix;
	struct fb_var_screeninfo var;
	u32 x_real_size, y_real_size, pixel_size;
	void *addr;
	void (* draw_pixel)(int x, int y, unsigned int color);
};

struct six_draw{
	void (*print_display_info)();
	void (*pixel)(int x, int y, unsigned int color);
	void (*point)(int x, int y, unsigned int size, unsigned int color);
	void (*line)(int x1, int y1, int x2, int y2, unsigned int color);
	void (*square)(int x, int y, int xlength, int ylength, unsigned int color);
};


int make_canvas(struct six_draw **user_draw);
int close_canvas();

	
	
	
	
	
	

	
