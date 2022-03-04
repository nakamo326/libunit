#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

int	case_result(t_clist *lst)
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
		return (-!!WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

void	print_suite_result(int success_num, int total_num)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putnbr_fd(success_num, STDOUT_FILENO);
	ft_putstr_fd("/", STDOUT_FILENO);
	ft_putnbr_fd(total_num, STDOUT_FILENO);
	ft_putendl_fd(" tests passed\n", STDOUT_FILENO);
	ft_putendl_fd(CYAN BOLD BORDER "\n" B_RESET RESET, STDOUT_FILENO);
}

int	run_test(t_clist *suite, char *title)
{
	int		res;
	long	total_cases;
	long	success_cases;
	long	ko;
	t_data	*testcase;

	ft_putstrs_fd((char *[]){BOLD, title," \n\n" B_RESET, NULL}, STDOUT_FILENO);
	ko = 0;
	total_cases = 0;
	success_cases = 0;
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		total_cases++;
		suite = suite->next;
		res = case_result(suite);
		if(res == 0)
			success_cases++;
		testcase = suite->data;
		ko += print_result(title, testcase->case_name, res);
	}
	print_suite_result(total_cases + ko, total_cases);

	return (-!!ko);
}
