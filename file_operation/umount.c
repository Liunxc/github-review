#include <stdio.h>
#include <sys/mount.h>

int main(int argc, char* argv[])
{
	int ret;
	if (argc < 0) {
		printf("Usage %s need targetpath\n", argv[1]);

		return -1;
	}	

	ret = umount(argv[1]);
	if (ret < 0) {
		perror("mount");

		return -1;
	}

	return 0;
}
