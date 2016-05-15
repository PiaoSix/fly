#include "display.h"

/*
#include <stdio.h>
#include <unistd.h>
//#include <string.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include "display.h"

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

static struct display_info d_info;

static void print_display_info(struct display_info *);
static void draw_square(struct display_info *, u32 x, u32 y, u32 xlength, u32 ylength, u32 color);
static void draw_line(struct display_info *, s32 x1, s32 y1, s32 x2, s32 y2, u32 color);

static void draw_pixel_rgb888(struct display_info *,  u32 x, u32 y, u32 color);
static void draw_pixel_rgb565(struct display_info *,  u32 x, u32 y, u32 color);
*/
/*
static struct display_info d_info;
int main(int argc, char **argv)
{
	d_info.fd = open(DEVNAME, O_RDWR);	
	
	if(d_info.fd < 0){
		perror("open fb0");
		goto err_open;
	}

	print_display_info(&d_info);

	d_info.addr = mmap(NULL, d_info.fix.smem_len, PROT_WRITE, MAP_SHARED, d_info.fd, 0);

	draw_square(&d_info, 0, 0, 200, 100, RGB888(255, 255, 0));	
//	draw_line(&d_info, 10, 10, 100, 100, RGB888(255, 0, 0));
	
	munmap(d_info.addr, d_info.fix.smem_len);
	close(d_info.fd);
	return 0;
err_open:
	return -1;
}
*/
/*
*	填充颜色格式为 RGB565
*/
void draw_pixel_rgb565(struct display_info * info,  u32 x, u32 y, u32 color)
{
	u32 red = ((color >> 16) & 0xff) >> (8 - info->var.red.length) << info->var.red.offset;
	u32 green = ((color >> 8) & 0xff) >> (8 - info->var.green.length) << info->var.green.offset;
	u32 blue = (color & 0xff) >> (8 - info->var.blue.length) << info->var.blue.offset;

	*((u16 *)info->addr + x + info->xsize * y) = (u16)(red | green | blue); 
}

/*
*	填充颜色格式为 RGB888
*/
void draw_pixel_rgb888(struct display_info * info,  u32 x, u32 y, u32 color)
{
	*((u32 *)info->addr + x + info->xsize * y) = color; 
}

/*
*	画 直线
*/
/*
static void draw_line(struct display_info *info, s32 x1, s32 y1, s32 x2, s32 y2, u32 color)
{
	s32 dy = y2 - y1;
	s32 dx = x2 - x1;
	int i, eps;
	for(i = x1; i <= x2; ++i){
		info->draw_pixel(info, i, x, color);	
	}

}
*/


/*
*	画 矩形
*/
void draw_square(struct display_info * info, u32 x, u32 y, u32 xlength, u32 ylength, u32 color)
{
	int i, j;
	for(i = y; i < y + ylength; ++i){
		for(j = x; j < x + xlength; ++j){
			info->draw_pixel(info, j, i, color );
		}
	}

}

/*
*	打印屏幕信息
*/
void print_display_info(struct display_info *info)
{
	//获取var对象
	ioctl(info->fd, FBIOGET_VSCREENINFO, &info->var);
	//获取fix对象
	ioctl(info->fd, FBIOGET_FSCREENINFO, &info->fix);
	
	info->draw_pixel = draw_pixel_rgb888;

	printf("resolution:x=%d,y=%d\n", info->var.xres, info->var.yres);
	printf("virtualRes:x=%d,y=%d\n", info->var.xres_virtual, info->var.yres_virtual);
	printf("xoffset=%d\nyoffset=%d\n", info->var.xoffset, info->var.yoffset);
	
	info->pixel_size =  info->var.bits_per_pixel / 8;
	printf("pixel_size=%d\n", info->pixel_size );

	info->xsize = info->fix.line_length / info->pixel_size;
	info->ysize = info->fix.smem_len / info->fix.line_length;

	printf("xsize=%d\nysize=%d\npixel_size=%d\n", info->xsize, info->ysize, info->pixel_size);
	

}


/*
*	创建画布
*/



