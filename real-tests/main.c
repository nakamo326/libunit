#include "cases.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	print_header();
	ret = 0;
	ret |= atoi_launcher();
	ret |= isprint_launcher();
	ret |= isalnum_launcher();
	ret |= strlen_launcher();
	ret |= strlcat_launcher();
	ret |= tolower_launcher();
	ret |= toupper_launcher();
	return (ret);
}
