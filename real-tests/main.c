#include "cases.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	puts("\n\x1b[36m\x1b[1m*********************************");
	puts("*****    42 - Unit Tests    *****");
	puts("*********************************\x1b[0m\n\x1b[39m");
	ret = 0;
	ret += atoi_launcher();
	ret += strlen_launcher();
	ret += tolower_launcher();
	ret += toupper_launcher();
	return (ret);
}

