#include "../cases.h"

int	stdout_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "stdout_test", stdout_test);
	return (launch_tests(&lst, "STDOUT"));
}
