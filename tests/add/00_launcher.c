#include "../cases.h"

int	add_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", add_basic_test);
	return (launch_tests(&lst, "ADD"));
}
