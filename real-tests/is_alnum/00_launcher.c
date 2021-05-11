#include "../cases.h"

int	isalnum_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "alnum_basic_test", alnum_basic_test);
	load_test(&lst, "alnum_basic_test2", alnum_basic_test2);
	load_test(&lst, "alnum_basic_test3", alnum_basic_test3);
	load_test(&lst, "alnum_basic_test4", alnum_basic_test4);
	load_test(&lst, "alnum_basic_test5", alnum_basic_test5);
	return (launch_tests(&lst, "ALNUM"));
}
