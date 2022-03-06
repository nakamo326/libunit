#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static void	run_test(t_case *testcase)
{
	testcase->pid = fork();
	if (testcase->pid < 0)
		err_exit(NULL, NULL);
	else if (testcase->pid == 0)
		exit(testcase->f_case());
}

static void	put_title(char *title)
{
	ft_putstrs_fd((char *[]){BOLD, title, " \n\n" B_RESET, NULL}, STDOUT_FILENO);
}

void	run_suite(t_clist *suite, char *title)
{
	put_title(title);
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		run_test(suite->data);
		suite = suite->next;
	}
}
