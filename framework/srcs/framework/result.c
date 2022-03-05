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

size_t	get_max_len_of_case_name(t_clist *suite)
{
	size_t	latest_len;
	size_t	max_len;
	t_data	*testcase;

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

int	run_test(t_clist *suite, char *title)
{
	size_t	max_len;
	int		res;
	long	total_cases;
	long	success_cases;
	long	ko;
	t_data	*testcase;

	ft_putstrs_fd((char *[]){BOLD, title," \n\n" B_RESET, NULL}, STDOUT_FILENO);
	max_len = get_max_len_of_case_name(suite);
	ko = 0;
	total_cases = 0;
	success_cases = 0;
	suite = ft_clstfirst(suite);
	while (!ft_clst_isend(suite))
	{
		total_cases++;
		res = case_result(suite);
		if(res == 0)
			success_cases++;
		testcase = suite->data;
		ko += print_result(title, testcase->case_name, res, max_len);
		suite = suite->next;
	}
	print_suite_result(success_cases, total_cases);

	return (-!!ko);
}
