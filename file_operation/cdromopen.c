#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/cdrom.h>
int main(int argc, char *argv[])
{
	int fd;
	fd = open("/dev/sr0", O_RDWR | O_NONBLOCK);

    ioctl(fd,CDROMEJECT);

	close(fd);

	return 0;
}
