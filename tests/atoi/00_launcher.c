#include "../../framework/libunit.h"
#include "atoi_tests.h"

int	atoi_launcher(void)
{
	t_clist *lst;

	puts("\x1b[1mATOI\x1b[0m\n");
	load_test(&lst, "basic_tset", atoi_basic_test);
	load_test(&lst, "error_a", error_a);
	load_test(&lst, "null_p", null_p);
	load_test(&lst, "over_long13", over_long13);
	load_test(&lst, "over_long12", over_long12);
	load_test(&lst, "over_long11", over_long11);
	load_test(&lst, "over_long10", over_long10);
	load_test(&lst, "over_long9", over_long9);
	load_test(&lst, "over_long8", over_long8);
	load_test(&lst, "over_long7", over_long7);
	load_test(&lst, "over_long6", over_long6);
	load_test(&lst, "over_lon5", over_lon5);
	load_test(&lst, "over_long4", over_long4);
	load_test(&lst, "over_long3", over_long3);
	load_test(&lst, "over_long2", over_long2);
	load_test(&lst, "over_long", over_long);
	load_test(&lst, "over_intmax", over_intmax);
	load_test(&lst, "over_intmin", over_intmin);
	load_test(&lst, "intmin", intmin);
	load_test(&lst, "plus", plus);
	load_test(&lst, "space5", space5);
	load_test(&lst, "space4", space4);
	load_test(&lst, "hyphen", hyphen);
	load_test(&lst, "space3", space3);
	load_test(&lst, "space2", space2);
	load_test(&lst, "space", space);
	load_test(&lst, "ascii_0", ascii_0);
	return (launch_tests(&lst));
}
