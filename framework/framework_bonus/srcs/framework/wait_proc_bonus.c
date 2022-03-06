#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (-!!WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else
		return (UNKNOWN);
}

t_proc	wait_case(void)
{
	int		status;
	t_proc	proc;

	proc.pid = wait(&status);
	if (proc.pid != -1)
		proc.res = get_exit_status(status);
	return (proc);
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
