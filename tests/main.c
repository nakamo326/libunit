#include "cases.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	print_header();
	ret = 0;
	ret |= atoi_launcher();
	ret |= strlen_launcher();
	ret |= exception_launcher();
	return (ret);
}
