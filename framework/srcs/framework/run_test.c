#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

void	run_test(t_clist *lst)
{
	t_case	*testcase;

	testcase = lst->data;
	testcase->pid = fork();
	if (testcase->pid < 0)
		err_exit(lst, NULL);
	else if (testcase->pid == 0)
		exit(testcase->f_case());
}

void	run_suite(t_clist *suite, char *title)
{
	ft_putstrs_fd((char *[]){BOLD, title, " \n\n" B_RESET, NULL}, STDOUT_FILENO);
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		run_test(suite);
		suite = suite->next;
	}
}
