#include <stdio.h>
//#include <unistd.h>
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
	u32 xsize, ysize, pixel_size;
	void *addr;
	void (* draw_pixel)(struct display_info *, u32 x, u32 y, u32 color);
};

struct draw{
	void (*pixel)(int x, int y, int size);
	void (*line)(int x1, int y1, int x2, int y2, u32 color);
	void (*draw_square)(int x, int y, int xlength, int ylength, u32 color);
};

void print_display_info(struct display_info *);
void draw_square(struct display_info *, u32 x, u32 y, u32 xlength, u32 ylength, u32 color);
void draw_line(struct display_info *, s32 x1, s32 y1, s32 x2, s32 y2, u32 color);

void draw_pixel_rgb888(struct display_info *,  u32 x, u32 y, u32 color);
void draw_pixel_rgb565(struct display_info *,  u32 x, u32 y, u32 color);

	
	
	
	
	
	

	
