#include  <sys/types.h>
#include  <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

#define FILENAME_LEN 512
#define STR_LEN 10
void mode_to_letters( mode_t mode,char str[])
{
strcpy(str,"----------");
if(S_ISDIR(mode))   str[0]='d';
if(S_ISCHR(mode))   str[0]='c';
if(S_ISBLK(mode))   str[0]='b';

if(mode & S_IRUSR)  str[1]='r';
if(mode & S_IWUSR)  str[2]='w';
if(mode & S_IXUSR)  str[3]='x';

if(mode & S_IRGRP)  str[4]='r';
if(mode & S_IWGRP)  str[5]='w';
if(mode & S_IXGRP)  str[6]='x';

if(mode & S_IROTH)  str[7]='r';
if(mode & S_IWOTH)  str[8]='w';
if(mode & S_IXOTH)  str[9]='x';
}

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	struct stat st;
	struct passwd *pw_str;
	struct group *grp_ptr;
	int ret;
	int fd;
	char filepath[FILENAME_LEN];
	char* namepath;
	char path[FILENAME_LEN] = {'\0'};
	int i;	
	char str[STR_LEN];
	char* time;

	if (argc < 2) {
			printf("Usage %s <path(/maxwit/)>\n", argv[0]);
			
			return -1;
		} else {
			strcpy(path,argv[1]);
	}
	
	printf("%s\n", path);
	if (NULL == (dp = opendir(path))) {
		printf("can’t open %s", path);
		
		return -1;
	}

	while (dirp = readdir(dp)) {
		namepath = strcpy(filepath, argv[1]);
		if (NULL == namepath) {
			perror("strcpy");
			closedir(dp);

			return -1;
			}

		namepath = strcat(filepath, dirp->d_name);
		if (NULL == namepath) {
			perror("strcat");
			closedir(dp);

			return -1;			
			}

		ret = lstat(namepath, &st);
		if (ret < 0) {
			perror("lstat");
			closedir(dp);

			return -1;
		}
		
		pw_str = getpwuid(st.st_uid);
		if (NULL == pw_str) {
			perror("getpwuid");
			closedir(dp);

			return -1;
		}

		grp_ptr = getgrgid(st.st_gid);
		if (NULL == grp_ptr) {
			perror("getgrgid");
			closedir(dp);

			return -1;
		}

		time = ctime(&st.st_mtime);
		if (NULL == time) {
			perror("ctime");
			closedir(dp);

			return -1;
		}

		mode_to_letters(st.st_mode, str);
		printf("%8s %4d", str, st.st_nlink);
		printf("%8s", pw_str->pw_name);
		printf("%8s", grp_ptr->gr_name);
		printf("%8d",(int) st.st_size);
		printf(" ");
		i = 0;
		while (*time) {
			i++;
			time++;
			if (i >= 4 && i <= 15) {
				printf("%c", *time);
			}
		}

		printf("%16s", dirp->d_name);
		printf("\n");
	}

	closedir(dp);
	printf("\n");

	return 0;
}
