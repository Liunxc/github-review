#include <stdio.h>

#define SWAP(a,b) do {\
	tyoeof(a) tmp;		\
	tmp = (a);			\
	(a) = (b);			\
	(b) = tmp;			\
} while (0)

#define SWAP(a, b) do {\
	(a) = (a) + (b);			\
	(b) = (a) - (b);			\
	(a) = (a) - (b);			\
} while (0)

#define SWAP(a, b) do {\
	(a) = (a) ^ (b);		\
	(b) = (a) ^ (b);		\
	(a) = (a) ^ (b);		\
} while (0)


