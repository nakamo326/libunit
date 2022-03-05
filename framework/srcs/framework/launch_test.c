#include "libunit.h"
#include "ft_list.h"

#define NO_TEST "[KO]      : no test detected"

int	launch_tests(t_clist **lst, char *title)
{
	int	res;
	const int fd = STDOUT_FILENO;

	if (!lst)
		err_exit(NULL, NULL);
	if (!get_testcount() || !*lst)// || ft_clst_isend(*lst)) //dame
	{
		ft_putstrs_fd((char *[]){RED "[", title, NO_TEST RESET, NULL}, fd);
		return (-1);
	}
	res = run_test(*lst, title);
	ft_clst_clear(lst, free);
	reset_testcount();
	return (res);
}
