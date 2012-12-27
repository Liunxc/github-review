#include <stdio.h>
#include <sys/mount.h>

int main(int argc, char* argv[])
{
	//const char* sourse = "/dev/sdb4";
	//const char* target = "/mnt";
	const char* filesystem = "msdos";
	if (argc < 3) {
		printf("Usage %s need <soursedevice>,<targetpath>\n", argv[0]);

		return -1;
	}
	int ret;

	ret = mount(argv[1], argv[2], filesystem,  MS_MGC_VAL, NULL);
	if (ret < 0) {
		perror("mount");

		return -1;
	}

	return 0;
}
