#include "display.h"

static struct display_info *info;

/*
*	填充颜色格式为 RGB565
*/
static void pixel_rgb565(int x, int y, unsigned int color)
{
	int red = ((color >> 16) & 0xff) >> (8 - info->var.red.length) << info->var.red.offset;
	int green = ((color >> 8) & 0xff) >> (8 - info->var.green.length) << info->var.green.offset;
	int blue = (color & 0xff) >> (8 - info->var.blue.length) << info->var.blue.offset;

	*((u16 *)info->addr + x + info->x_real_size * y) = (u16)(red | green | blue); 
}

/*
*	填充颜色格式为 RGB888
*/
static void pixel_rgb888(int x, int y, unsigned int color)
{
	*((int *)info->addr + x + info->x_real_size * y) = color; 
}

/*
*	画点
*/
static void point(int x, int y,  unsigned int size, unsigned int color)
{
	printf("这个函数还没有添加。");	
}


/*
*	画 直线
*/

static void line(s32 x1, s32 y1, s32 x2, s32 y2, unsigned int color)
{
	s32 dy = y2 - y1;
	s32 dx = x2 - x1;
	int i, eps;
/*
	for(i = x1; i <= x2; ++i){
		info->draw_pixel(info, i, x, color);	
	}
*/
}



/*
*	画 矩形
*/
static void square(int x, int y, int xlength, int ylength, unsigned int color)
{
	int i, j;
	for(i = y; i < y + ylength; ++i){
		for(j = x; j < x + xlength; ++j){
			info->draw_pixel(j, i, color );
		}
	}

}

/*
*	打印屏幕信息
*/
static void display_info()
{
	//获取var对象
	ioctl(info->fd, FBIOGET_VSCREENINFO, &info->var);
	//获取fix对象
	ioctl(info->fd, FBIOGET_FSCREENINFO, &info->fix);
	
//	info->draw_pixel = draw_pixel_rgb888;

	printf("resolution:x=%d,y=%d\n", info->var.xres, info->var.yres);
	printf("virtualRes:x=%d,y=%d\n", info->var.xres_virtual, info->var.yres_virtual);
	printf("xoffset=%d\nyoffset=%d\n", info->var.xoffset, info->var.yoffset);
	
	info->pixel_size =  info->var.bits_per_pixel / 8;
	printf("pixel_size=%d\n", info->pixel_size );

	info->x_real_size = info->fix.line_length / info->pixel_size;
	info->y_real_size = info->fix.smem_len / info->fix.line_length;

	printf("x_real_size=%d\ny_real_size=%d\npixel_size=%d\n", info->x_real_size, info->y_real_size, info->pixel_size);
	

}



static struct six_draw draw = {
	.print_display_info = display_info,
	.pixel = pixel_rgb888,
	.point = point,
	.line = line,
	.square = square,
};


static struct display_info canvas;

/*
*	创建画布
*/
int make_canvas(struct six_draw **user_draw)
{	
	info = &canvas;
	canvas.fd = open(DEVNAME, O_RDWR);

	if(canvas.fd < 0){ 
		perror("open fb0");
		goto err_open;
	}
	*user_draw = &draw;
	canvas.addr = mmap(NULL, canvas.fix.smem_len, PROT_WRITE, MAP_SHARED, canvas.fd, 0);

	return 0;
err_open:
	return -1; 

}

int close_canvas()
{
	munmap(canvas.addr, canvas.fix.smem_len);
	close(canvas.fd);
	
	return 0;
}





