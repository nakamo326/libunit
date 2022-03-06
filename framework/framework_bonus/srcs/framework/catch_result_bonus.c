#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static bool	exists_pid(t_clist *found)
{
	return (found != NULL);
}

static void	append_new_result(t_clist *finished, t_proc *result)
{
	t_proc	*proc;

	if (result->pid == -1)
		return ;
	proc = or_exit(malloc(sizeof(t_proc)));
	*proc = *result;
	or_exit(ft_clstnew_add_back(finished, proc));
}

static void	store_test_result(t_case *testcase, t_clist *found)
{
	t_proc	*result;

	result = found->data;
	testcase->proc.res = result->res;
}

void	catch_test_result(t_clist *suite)
{
	t_proc	result;
	t_case	*testcase;
	t_clist	*found;
	t_clist	*finished;

	finished = or_exit(ft_clstnew(NULL));
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		testcase = suite->data;
		found = find_pid_from_finished(testcase->proc.pid, finished);
		if (exists_pid(found))
		{
			store_test_result(testcase, found);
			ft_clst_popdel(found, free);
			suite = suite->next;
		}
		result = wait_case();
		append_new_result(finished, &result);
	}
	ft_clst_clear(&finished, free);
}
