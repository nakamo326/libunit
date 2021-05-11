#include "strlen/strlen_tests.h"
#include "atoi/atoi_tests.h"
#include "tolower/tolower_tests.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	puts("\n\x1b[36m\x1b[1m*********************************");
	puts("*****    42 - Unit Tests    *****");
	puts("*********************************\x1b[0m\n\x1b[39m");
	ret = 0;
	ret += strlen_launcher();
	ret += atoi_launcher();
	ret += tolower_launcher();
	return (ret);
}
