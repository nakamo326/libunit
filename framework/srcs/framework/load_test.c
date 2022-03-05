#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

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
