#include "strlen/strlen_tests.h"
#include "atoi/atoi_tests.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	setvbuf(stdout, NULL, _IONBF, 0);
	write(1, "\n", 1);
	puts("\n\x1b[36m\x1b[1m*********************************");
	puts("*****    42 - Unit Tests    *****");
	puts("*********************************\x1b[0m\n\x1b[39m");
	ret = 0;
	ret += strlen_launcher();
	ret += atoi_launcher();
	return (ret);
}
