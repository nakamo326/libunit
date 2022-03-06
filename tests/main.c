#include "cases.h"
#include <stdio.h>
#include <sys/wait.h>
int	main(void)
{
	int	ret;

	print_header();
	ret = 0;
	ret |= stdout_launcher();
	ret |= atoi_launcher();
	ret |= strlen_launcher();
	ret |= add_launcher();
	ret |= strlcpy_launcher();
	ret |= is_prime_launcher();
	ret |= free_launcher();
	ret |= div_launcher();
	ret |= get_written_fd_launcher();
	ret |= asm_jmp_launcher();
	return (ret);
}
