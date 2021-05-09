#include "libunit.h"

int	print_result(char *case_name, int res)
{
	if (!res)
		printf("\x1b[32m[OK]\x1b[39m      : %s\n", case_name);
	else if (res == -1)
		printf("\x1b[31m[KO]\x1b[39m      : %s\n", case_name);
	else if (res == SIGSEGV)
		printf("\x1b[33m[SEGV]\x1b[39m    : %s\n", case_name);
	else if (res == SIGABRT)
		printf("\x1b[33m[ABORT]\x1b[39m   : %s\n", case_name);
	else if (res == SIGBUS)
		printf("\x1b[33m[BUSE]\x1b[39m    : %s\n", case_name);
	else if (res == SIGFPE)
		printf("\x1b[33m[FPE]\x1b[39m     : %s\n", case_name);
	else if (res == SIGALRM)
		printf("\x1b[33m[TIMEOUT]\x1b[39m : %s\n", case_name);
	else
		printf("\x1b[33m[UNKNOWN]\x1b[39m : %s\n", case_name);
	return (-!!res);
}

int	case_result(t_clist *lst)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		err_exit(lst, NULL);
	else if (pid == 0)
		exit(((t_data *)lst->data)->f_case());
	wait(&status);
	if (WIFEXITED(status))
		return (-!!(char)WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

int	run_test(t_clist *lst)
{
	int		res;
	long	cases;
	long	ko;
	t_clist	*start;

	if (!lst)
		return (-1);
	ko = 0;
	cases = 0;
	start = lst;
	while (1)
	{
		cases++;
		lst = lst->prev;
		res = case_result(lst);
		ko += print_result(((t_data *)lst->data)->case_name, res);
		if (lst == start)
			break ;
	}
	printf("\n%ld/%ld tests passed\n\n", cases + ko, cases);
	return (-!!ko);
}

int	launch_tests(t_clist **lst)
{
	int res;

	if (!lst)
		err_exit(NULL, NULL);
	if (!g_start)
		return (-1);
	res = run_test(*lst);
	lst_clear(*lst);
	g_start = 0;
	#ifndef ABC
	#endif
	return (res);
}