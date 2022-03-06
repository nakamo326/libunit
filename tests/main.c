#include "cases.h"
#include <stdio.h>
#include <sys/wait.h>
int	main(void)
{
	int	ret;

	print_header();
	ret = 0;
	// ret |= atoi_launcher();
	// ret |= strlen_launcher();
	// ret |= exception_launcher();
	ret |= stdout_launcher();
	// if (!fork()) {
	// 	return 1;
	// }
	// while(1) {
	// 	sleep(1);
	// }
	return (ret);
}
