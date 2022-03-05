#include "libunit.h"
#include "ft_list.h"
#include "libft.h"

static void	init_test(t_clist **lst)
{
	*lst = or_exit(ft_clstnew(NULL));
}

void	load_test(t_clist **lst, char *case_name, int (*f_case)())
{
	t_case	*testcase;

	if (!lst || !case_name || !f_case)
		return ;
	if (!get_testcount())
		init_test(lst);
	testcase = or_exit(malloc(sizeof(t_case)));
	*testcase = (t_case){.case_name = case_name, .f_case = f_case};
	or_exit(ft_clstnew_add_back(*lst, testcase));
	inc_testcount();
}
