#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

#define NO_TEST "[KO]      : no test detected"

int	norm_hacker(int flag, int assign)
{
	static int	g;

	if (flag == INC)
		return (g++);
	else if (flag == GET)
		return (g);
	else if (flag == SET)
	{
		g = assign;
		return (g);
	}
	return (g);
}

void	err_exit(t_clist *lst, t_data *data)
{
	free(data);
	ft_clst_clear(&lst, free);
	ft_putendl_fd("error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	load_test(t_clist **lst, char *case_name, int (*f_case)())
{
	t_data	*data;

	if (!lst || !case_name || !f_case)
		return ;
	if (!get_testcount())
	{
		*lst = ft_clstnew(NULL);
		if (!*lst)
			err_exit(*lst, NULL);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		err_exit(*lst, NULL);
	*data = (t_data){.case_name = case_name, .f_case = f_case};
	if (!ft_clstnew_add_back(*lst, data))
		err_exit(*lst, data);
	inc_testcount();
}

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
