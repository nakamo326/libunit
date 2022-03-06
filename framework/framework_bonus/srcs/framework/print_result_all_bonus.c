#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static void	print_cases_result(t_clist *suite, char *title, size_t max_len)
{
	t_case	*testcase;
	t_proc	*proc;

	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		testcase = suite->data;
		proc = &testcase->proc;
		print_result_one(title, testcase->case_name, proc->res, max_len);
		if (proc->res == 0)
			inc_success_count();
		suite = suite->next;
	}
}

static void	print_suite_result(void)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putsize_fd(get_success_count(), STDOUT_FILENO);
	ft_putstr_fd("/", STDOUT_FILENO);
	ft_putsize_fd(get_testcount(), STDOUT_FILENO);
	ft_putendl_fd(" tests passed\n", STDOUT_FILENO);
	ft_putendl_fd(CYAN BOLD BORDER "\n" B_RESET RESET, STDOUT_FILENO);
}

void	print_result_all(t_clist *suite, char *title)
{
	size_t	max_len;

	max_len = get_max_len_of_case_name(suite);
	catch_test_result(suite);
	print_cases_result(suite, title, max_len);
	print_suite_result();
	create_log_file(suite, title, max_len);
}
