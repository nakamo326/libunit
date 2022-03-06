#include "../cases.h"

int	is_prime_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", is_prime_basic_test);
	load_test(&lst, "intmax_test", is_prime_intmax_test);
	return (launch_tests(&lst, "IS_PRIME"));
}
