switch(st.st_mode & S_IFMT) {
	case S_IFREG:
		printf("-");
		break;
	case S_IFSOCK:
		printf("s");
		break;
	case S_IFLINK:
		printf("l");
		break;
	case S_IFBLK:
		printf("b");
		break;
	case S_IFCHR:
		printf("c");
		break;
	case S_IFIFO:
		printf("p");
		break;
	case S_IFDIR:
		printf("d");
		break;
	defualt:
		break;
}
