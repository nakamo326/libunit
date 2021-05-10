#include "libunit.h"

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
	return (-!!res);
}

int	launch_tests(t_clist **lst)
{
	int	res;

	if (!lst)
		err_exit(NULL, NULL);
	if (!g_start || !*lst)
		return (-!!puts("\x1b[31m[KO]      : no test detected\x1b[39m"));
	res = run_test(*lst);
	lst_clear(*lst);
	g_start = 0;
	return (res);
}
