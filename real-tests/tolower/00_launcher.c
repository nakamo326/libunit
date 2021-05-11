#include "../cases.h"

int	tolower_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test('A'-'Z')", tolower_basic_test);
	load_test(&lst, "basic_test2('a'-'z')", tolower_basic_test2);
	load_test(&lst, "not_alpha", tolower_not_alpha);
	load_test(&lst, "null_char", tolower_null_char);
	load_test(&lst, "not_ascii", tolower_not_ascii);
	return (launch_tests(&lst, "TOLOWER"));
}
