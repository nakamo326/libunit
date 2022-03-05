#include "libunit.h"
#include "ft_list.h"

#define NO_TEST "[KO]      : no test detected"

int	get_result()
{
	if (get_testcount() == get_success_count())
		return (0);
	else
		return (-1);
}

int	launch_tests(t_clist **lst, char *title)
{
	int			res;
	const int	fd = STDOUT_FILENO;

	if (!lst)
		err_exit(NULL, NULL);
	if (!*lst || !get_testcount())
	{
		ft_putstrs_fd((char *[]){RED "[", title, "]" NO_TEST RESET, NULL}, fd);
		return (0);
	}
	run_suite(*lst, title);
	print_result_all(*lst, title);
	res = get_result();
	reset_testcount();
	reset_success_count();
	ft_clst_clear(lst, free);
	return (res);
}
