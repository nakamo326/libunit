#include "../cases.h"

int	strlen_launcher(void)
{
	t_clist	*lst;

	load_test(&lst, "basic_test", basic_test);
	load_test(&lst, "basic_test2", basic_test2);
	load_test(&lst, "basic_test3", basic_test3);
	load_test(&lst, "basic_test4", basic_test4);
	load_test(&lst, "basic_test5", basic_test5);
	load_test(&lst, "basic_test6", basic_test6);
	load_test(&lst, "basic_test7", basic_test7);
	load_test(&lst, "basic_test8", basic_test8);
	load_test(&lst, "include_space_test", include_space_test);
	load_test(&lst, "empty_str_test", empty_str_test);
	load_test(&lst, "include_nullchar_test", include_nullchar_test);
	load_test(&lst, "include_allascci_test", include_allascii_test);
	load_test(&lst, "bigger_str_test", bigger_str_test);
	load_test(&lst, "NULL_test", null_test);
	load_test(&lst, "bus_error", bus_error);
	load_test(&lst, "ko_case", ko_case);
	load_test(&lst, "zero_divide", zero_divide);
	load_test(&lst, "not_endwith_nullchar", double_free);
	load_test(&lst, "sig_ill", sig_ill);
	return (launch_tests(&lst, "STRLEN"));
}
