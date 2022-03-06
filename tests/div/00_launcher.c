#include "../cases.h"

int	div_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", div_basic_test);
	load_test(&lst, "zero_test", div_zero_test);
	return (launch_tests(&lst, "DIV"));
}
