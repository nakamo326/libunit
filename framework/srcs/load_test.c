#include "libunit.h"
#include "ft_list.h"

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

size_t	my_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	err_exit(t_clist *lst, t_data *data)
{
	char	*s;

	free(data);
	ft_clst_clear(&lst, free);
	s = "error\n";
	write(STDERR_FILENO, s, my_strlen(s));
	exit(1);
}

void	load_test(t_clist **lst, char *case_name, int (*f_case)())
{
	t_data	*data;
	t_clist	*new;

	if (!lst || !case_name || !f_case)
		return ;
	if (!ft_setptr(&data, malloc(sizeof(t_data))))
		err_exit(*lst, NULL);
	data->case_name = case_name;
	data->f_case = f_case;
	if (!ft_setptr(&new, ft_clstnew(data)))
		err_exit(*lst, data);
	ft_clstadd_front(*lst, new);
	norm_hacker(SET, 1);
}
