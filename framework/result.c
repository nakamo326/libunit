#include "libunit.h"

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