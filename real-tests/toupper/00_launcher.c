#include "../../framework/libunit.h"
#include "toupper_tests.h"

int	toupper_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test('a'-'z')", toupper_basic_test);
	load_test(&lst, "basic_test2('A'-'Z')", toupper_basic_test2);
	load_test(&lst, "not_alpha", toupper_not_alpha);
	load_test(&lst, "null_char", toupper_null_char);
	load_test(&lst, "not_ascii", toupper_not_ascii);
	return (launch_tests(&lst, "TOUPPER"));
}
