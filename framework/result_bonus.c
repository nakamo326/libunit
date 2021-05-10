#include "libunit.h"

void	print_file(char *case_name, int res)
{
	if (!res)
		printf("[OK]      : %s\n", case_name);
	else if (res == -1)
		printf("[KO]      : %s\n", case_name);
	else if (res == SIGSEGV)
		printf("[SEGV]    : %s\n", case_name);
	else if (res == SIGABRT)
		printf("[ABORT]   : %s\n", case_name);
	else if (res == SIGBUS)
		printf("[BUSE]    : %s\n", case_name);
	else if (res == SIGFPE)
		printf("[FPE]     : %s\n", case_name);
	else if (res == SIGALRM)
		printf("[TIMEOUT] : %s\n", case_name);
	else
		printf("[UNKNOWN] : %s\n", case_name);
}

void	file_out(char *case_name, int res, int fd)
{
	int stdout_tmp;

	stdout_tmp = dup(1);
	dup2(fd, 1);
	print_file(case_name, res);
	dup2(stdout_tmp, 1);
}

int	case_result(t_clist *lst)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		err_exit(lst, NULL);
	else if (pid == 0)
	{
		alarm(7);
		exit(((t_data *)lst->data)->f_case());
	}
	wait(&status);
	if (WIFEXITED(status))
		return (-!!WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

int	run_tester(t_clist *lst, int fd)
{
	int		res;
	long	cases;
	long	ko;
	t_clist	*start;

	ko = 0;
	cases = 0;
	start = lst;
	while (1)
	{
		cases++;
		lst = lst->prev;
		res = case_result(lst);
		ko += print_result(((t_data *)lst->data)->case_name, res);
		if (res && fd > 0)
			file_out(((t_data *)lst->data)->case_name, res, fd);
		if (lst == start)
			break ;
	}
	printf("\n%ld/%ld tests passed\n\n", cases + ko, cases);
	return (-!!ko);
}

int	run_test(t_clist *lst)
{
	int	fd;
	int	ret;

	fd = open("../result.txt",
		O_WRONLY | O_CREAT | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO);
	ret = run_tester(lst, fd);
	write(fd, "\n", 1);
	close(fd);
	return (ret);
}
