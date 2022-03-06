#include "../cases.h"

int	null_launcher(void)
{
	t_clist	*lst;

	load_test(NULL, "null", atoi_basic_test);
	load_test(&lst, NULL, atoi_basic_test);
	load_test(&lst, "null", NULL);
	return (launch_tests(&lst, NULL));
}
