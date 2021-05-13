#include "cases.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	printf("\n"CYAN"\x1b[1m*********************************\n");
	printf("*****    42 - Unit Tests    *****\n");
	printf("*********************************\x1b[0m\n\n"RESET);
	ret = 0;
	ret |= atoi_launcher();
	ret |= strlen_launcher();
	return (ret);
}
