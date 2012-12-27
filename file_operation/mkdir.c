#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int fd;
	
	if (argc < 2) {
		printf("Usage %s <dirpath>\n", argv[0]);

		return -1;
	}
	fd = mkdir(argv[1], O_CREAT | O_RDWR);
	if (fd < 0) {
		perror("mkdir");
		
		return -1;
	}

	return 0;
}
