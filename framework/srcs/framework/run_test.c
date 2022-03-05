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

void	wait_case(t_clist *pidlst)
{
	pid_t	pid;
	int		status;
	t_proc	*proc;

	pid = wait(&status);
	if (pid == -1)
		return ;
	proc = malloc(sizeof(t_proc));
	proc->pid = pid;
	if (WIFEXITED(status))
		proc->res = -!!WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		proc->res = WTERMSIG(status);
	else
		proc->res = UNKNOWN;
	ft_clstnew_add_back(pidlst, proc);
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

bool	exists_pid(t_clist *found)
{
	return (found != NULL);
}

void	print_cases_result(t_clist *suite, char *title)
{
	size_t	max_len;
	t_proc	*proc;
	t_case	*testcase;
	t_clist	*found;
	t_clist	*finished;

	max_len = get_max_len_of_case_name(suite);
	finished = ft_clstnew(NULL);
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

void	print_result_all(t_clist *suite, char *title)
{
	print_cases_result(suite, title);
	print_suite_result();
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
