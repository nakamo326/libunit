#include "../cases.h"

int	strlcpy_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", strlcpy_basic_test);
	load_test(&lst, "literal_test", strlcpy_literal_test);
	return (launch_tests(&lst, "STRLCPY"));
}
