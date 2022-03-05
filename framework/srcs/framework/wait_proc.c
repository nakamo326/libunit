#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

void	wait_case(t_clist *pidlst)
{
	pid_t	pid;
	int		status;
	t_proc	*proc;

	pid = wait(&status);
	if (pid == -1)
		return ;
	proc = malloc(sizeof(t_proc));
	proc->pid = pid;
	if (WIFEXITED(status))
		proc->res = -!!WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		proc->res = WTERMSIG(status);
	else
		proc->res = UNKNOWN;
	ft_clstnew_add_back(pidlst, proc);
}

t_clist	*find_pid_from_finished(pid_t target, t_clist *waited)
{
	t_proc	*proc;

	waited = ft_clstfirst(waited);
	while (!ft_clst_isend(waited))
	{
		proc = waited->data;
		if (proc->pid == target)
			return (waited);
		waited = waited->next;
	}
	return (NULL);
}

bool	exists_pid(t_clist *found)
{
	return (found != NULL);
}

size_t	get_max_len_of_case_name(t_clist *suite)
{
	size_t	latest_len;
	size_t	max_len;
	t_case	*testcase;

	max_len = 0;
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		testcase = suite->data;
		latest_len = ft_strlen(testcase->case_name);
		if (max_len < latest_len)
			max_len = latest_len;
		suite = suite->next;
	}
	return (max_len);
}
