#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char* argv[1])
{
	int fd;
	char* filename;
	char* text = "hello world!";
	char* addr;
	struct stat st;
	int ret;

	if (argc < 2) {
		printf("Use default filename (text.txt)\n");
		filename = "text.txt";
	} else
		filename = argv[1];

	fd = open(filename, O_RDWR | O_CREAT, 0664);
	if (fd < 0) {
		perror("open");

		return -1;
	}

	ret = fstat(fd, &st);
	if (ret < 0) {
		perror("fstst");

		return -1;
	}

	addr = (char*)mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	if (NULL == addr) {
		perror("mmap");
		close(fd);
		
		return -1;
	}
	
	while (*text) {
		*addr = *text;
		sync();
		addr++;
		text++;
	}
	
	munmap(addr, st.st_size);
	close(fd);

	return 0;
}
