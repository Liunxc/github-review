#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_LEN 512

int main(int argc, char* argv[])
{
	int fd;
	int ret;
	char buff[BUFF_LEN] = "hello world";
	if (argc < 1) {
		return -1;
	}

	fd = open(argv[1], O_CREAT | O_RDWR);
	if (fd < 0 ) {
		perror("open!");
		return -1;
	}
	
	ret = write(fd, buff, 512);
	if (ret < 0) {
		close(fd);
		return -1;
	}

	printf("%s", buff);
	
	close(fd);

	return 0;
}
