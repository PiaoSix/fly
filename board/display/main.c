#include <stdio.h>
#include <unistd.h>
//#include <string.h>
#include "display.h"


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
//  draw_line(&d_info, 10, 10, 100, 100, RGB888(255, 0, 0));

	munmap(d_info.addr, d_info.fix.smem_len);
	close(d_info.fd);

	return 0;
err_open:
	return -1;
}
	





