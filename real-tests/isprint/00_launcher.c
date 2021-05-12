#include "../cases.h"

int	isprint_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test('A'-'Z')", isprint_basic_test);
	load_test(&lst, "basic_test2('a'-'z')", isprint_basic_test2);
	load_test(&lst, "space", isprint_space);
	load_test(&lst, "standard_space", isprint_stdspace);
	load_test(&lst, "null_char", isprint_null_char);
	load_test(&lst, "not_ascii", isprint_not_ascii);
	return (launch_tests(&lst, "ISPRINT"));
}
