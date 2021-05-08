#include "libunit.h"

void	print_result(int res, char *case_name)
{

}

int	new_process(t_clist *lst)
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
}

int	run_test(t_clist *lst)
{
	int		res;
	t_clist	*start;

	if (!lst) //未初期化ケース確認
		return (0);
	start = lst;
	while (1)
	{
		lst = lst->prev;
		res = new_process(lst);
		if (lst == start)
			break ;
	}
	return (res);
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