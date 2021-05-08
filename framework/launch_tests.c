#include "libunit.h"

int	print_result(char *case_name, int res)
{
	if (!res)
		printf("%15s : \x1b[32m[OK]\x1b[39m\n", case_name);
	else if (res == -1)
		printf("%15s : \x1b[31m[KO]\x1b[39m\n", case_name);
	else if (res == SIGSEGV)
		printf("%15s : \x1b[33m[SEGV]\x1b[39m\n", case_name);
	else if (res == SIGABRT)
		printf("%15s : \x1b[33m[ABORT]\x1b[39m\n", case_name);
	else if (res == SIGBUS)
		printf("%15s : \x1b[33m[BUSE]\x1b[39m\n", case_name);
	else
		printf("%15s : \x1b[33m[UNKNOWN ERROR]\x1b[39m\n", case_name);
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
		return ((char)WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	err_exit(lst, NULL); //wacaran
	return (0);
}

int	run_test(t_clist *lst)
{
	int64_t	case_count;
	int64_t	pass_count;
	t_clist	*start;

	if (!lst) //未初期化ケース確認
		return (0);
	start = lst;
	pass_count = 0;
	while (1)
	{
		case_count++;
		lst = lst->prev;
		pass_count += case_result(lst);
		print_result(((t_data *)lst->data)->case_name, res);
		if (lst == start)
			break ;
	}
	printf("%ld/%ld tests passed", case_count + pass_count, case_count);
	return (-(case_count != -pass_count));
}

int	launch_tests(t_clist **lst)
{
	int res;

	if (!lst)
		err_exit(NULL, NULL);
	res = run_test(*lst);
	lst_clear(*lst);
	g_start = 0;
	return (res);
}