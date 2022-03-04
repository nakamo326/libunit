#include "libunit.h"
#include "ft_list.h"

int	print_result(char *case_name, int res)
{
	if (!res)
		printf(GREEN "[OK]"RESET"      : %s\n", case_name);
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

int	launch_tests(t_clist **lst, char *title)
{
	int	res;

	if (!lst)
		err_exit(NULL, NULL);
	if (!norm_hacker(GET, 0) || !*lst)
		return (-!!puts("\x1b[31m[KO]      : no test detected\x1b[39m"));
	res = run_test(*lst, title);
	ft_clst_clear(lst, free);
	norm_hacker(SET, 0);
	return (res);
}
