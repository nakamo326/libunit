#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

#define OK "[OK]"

// [test_function]:[test_name]:[status]

void output_case(char *title, char *case_name)
{
	const int fd = STDOUT_FILENO;

	ft_putstrs_fd((char *[]){title, " : ", case_name, " : ", NULL}, fd);
}

int	print_result(char *title, char *case_name, int res)
{
	output_case(title, case_name);
	if (!res)
		ft_putendl_fd(GREEN OK RESET, STDOUT_FILENO);
	else if (res == -1)
		printf(RED "[KO]" RESET "      : %s\n", case_name);
	else if (res == SIGSEGV)
		printf(YELLOW"[SEGV]"RESET"    : %s\n", case_name);
	else if (res == SIGABRT)
		printf(YELLOW"[ABORT]"RESET"   : %s\n", case_name);
	else if (res == SIGBUS)
		printf(YELLOW"[BUSE]"RESET"    : %s\n", case_name);
	else if (res == SIGFPE)
		printf(YELLOW"[FPE]"RESET"     : %s\n", case_name);
	else if (res == SIGALRM)
		printf(YELLOW"[TIMEOUT]"RESET" : %s\n", case_name);
	else
		printf(YELLOW"[UNKNOWN]"RESET" : %s\n", case_name);
	return (-!!res); // signal == -1 , exit = 0 , ko = -1
}

void	ft_putstrs_fd(char **strs, int fd)
{
	while (*strs)
	{
		ft_putstr_fd(*strs, fd);
		strs++;
	}
}

