#include "libunit.h"
#include "ft_list.h"
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

static void	print_cases_result(t_clist *suite, char *title, size_t max_len)
{
	t_proc	result;
	t_proc	*proc;
	t_case	*testcase;
	t_clist	*found;
	t_clist	*finished;

	finished = or_exit(ft_clstnew(NULL));
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		testcase = suite->data;
		found = find_pid_from_finished(testcase->pid, finished);
		if (exists_pid(found))
		{
			proc = found->data;
			print_result_one(title, testcase->case_name, proc->res, max_len);
			if (proc->res == 0)
				inc_success_count();
			ft_clst_popdel(found, free);
			suite = suite->next;
		}
		result = wait_case();
		append_new_result(finished, &result);
	}
	ft_clst_clear(&finished, free);
}

static void	print_suite_result(void)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putnbr_fd(get_success_count(), STDOUT_FILENO);
	ft_putstr_fd("/", STDOUT_FILENO);
	ft_putnbr_fd(get_testcount(), STDOUT_FILENO);
	ft_putendl_fd(" tests passed\n", STDOUT_FILENO);
	ft_putendl_fd(CYAN BOLD BORDER "\n" B_RESET RESET, STDOUT_FILENO);
}

void	print_result_all(t_clist *suite, char *title)
{
	size_t	max_len;

	max_len = get_max_len_of_case_name(suite);
	print_cases_result(suite, title, max_len);
	print_suite_result();
}
