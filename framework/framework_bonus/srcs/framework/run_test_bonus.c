#include "libunit_bonus.h"
#include "ft_list_bonus.h"
#include "libft.h"

static void	run_test(t_case *testcase)
{
	int		stderr_copy_fd;
	int		exit_status;

	testcase->proc.pid = fork();
	if (testcase->proc.pid < 0)
		err_exit(NULL, NULL);
	else if (testcase->proc.pid == 0)
	{
		alarm(3);
		stderr_copy_fd = dup(STDERR_FILENO);
		close(STDERR_FILENO);
		exit_status = testcase->f_case();
		dup2(stderr_copy_fd, STDERR_FILENO);
		exit(exit_status);
	}
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
