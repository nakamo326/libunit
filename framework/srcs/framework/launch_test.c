#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

#define NO_TEST " no test detected\n"

static int	get_result(void)
{
	if (get_testcount() == get_success_count())
		return (0);
	else
		return (-1);
}

static void	put_no_test(char *title)
{
	const int	fd = STDOUT_FILENO;

	ft_putstrs_fd((char *[]){RED, title, NO_TEST RESET "\n", NULL}, fd);
	ft_putendl_fd(CYAN BOLD BORDER "\n" B_RESET RESET, fd);
}

int	launch_tests(t_clist **lst, char *title)
{
	int			res;

	if (!lst)
		err_exit(NULL, NULL);
	if (!*lst || !get_testcount())
	{
		put_no_test(title);
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
