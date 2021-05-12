#include "../cases.h"

int	strlcat_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", strncmp_basic_test);
	load_test(&lst, "basic_test2", strncmp_basic_test2);
	load_test(&lst, "basic_test3", strncmp_basic_test3);
	load_test(&lst, "str1_empty", strncmp_empty_string_test2);
	load_test(&lst, "str2_empty", strncmp_empty_string_test3);
	load_test(&lst, "both_empty", strncmp_empty_string_test);
	load_test(&lst, "zero_len", strncmp_zerolen_test);
	load_test(&lst, "include_nullchar", strncmp_include_nullchar_test);
	return (launch_tests(&lst, "STRNCMP"));
}
