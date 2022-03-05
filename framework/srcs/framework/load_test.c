#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

void	init_test(t_clist **lst)
{
	*lst = ft_clstnew(NULL);
	if (!*lst)
		err_exit(*lst, NULL);
}

void	load_test(t_clist **lst, char *case_name, int (*f_case)())
{
	t_case	*testcase;

	if (!lst || !case_name || !f_case)
		return ;
	if (!get_testcount())
		init_test(lst);
	testcase = malloc(sizeof(t_case));
	if (!testcase)
		err_exit(*lst, NULL);
	*testcase = (t_case){.case_name = case_name, .f_case = f_case};
	if (!ft_clstnew_add_back(*lst, testcase))
		err_exit(*lst, testcase);
	inc_testcount();
}
