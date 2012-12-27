#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "bmp.h"

#define SRC_BMP "/home/yy/project/client/review/bmp/splash"

int main(int argc, char *argv[])
{
	struct bmp_head bmp;
	int fd_bmp;
   fd_bmp= open(SRC_BMP, O_RDONLY);
   if (fd_bmp == 0)
	   perror("open");

   read(fd_bmp, &bmp, sizeof(bmp));
   printf("filesize = %d\n"
		   "width = %d\n"
		   "height = %d\n"
		   "bpp = %d\n",
		   bmp.filesize,
		   bmp.width,
		   bmp.height,
		   bmp.bpp);

	return 0;
}
