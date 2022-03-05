#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

void	print_cases_result(t_clist *suite, char *title)
{
	size_t	max_len;
	t_proc	*proc;
	t_case	*testcase;
	t_clist	*found;
	t_clist	*finished;

	max_len = get_max_len_of_case_name(suite);
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
		wait_case(finished);
	}
	ft_clst_clear(&finished, free);
}

void	print_suite_result(void)
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
	print_cases_result(suite, title);
	print_suite_result();
}
