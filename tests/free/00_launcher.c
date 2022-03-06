#include "../cases.h"

int	free_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", free_basic_test);
	load_test(&lst, "literal_test", free_literal_test);
	return (launch_tests(&lst, "FREE"));
}
