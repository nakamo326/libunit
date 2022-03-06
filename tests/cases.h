#ifndef CASES_H
# define CASES_H
# include <string.h>
# include "../real-tests/libft/libft.h"
# include "tester.h"
# include <limits.h>

int	atoi_launcher(void);
int	atoi_basic_test(void);
int	error_a(void);
int	ascii_0(void);
int	space(void);
int	space2(void);
int	space3(void);
int	space4(void);
int	space5(void);
int	hyphen(void);
int	plus(void);
int	intmin(void);
int	over_intmin(void);
int	over_intmax(void);
int	over_intmax2(void);
int	over_long(void);
int	over_long2(void);
int	over_long3(void);
int	over_long4(void);
int	over_long5(void);
int	over_long6(void);
int	over_long7(void);
int	over_long8(void);
int	over_long9(void);
int	over_long10(void);
int	over_long11(void);
int	over_long12(void);
int	over_long13(void);
int	null_p(void);
int	strlen_launcher(void);
int	basic_test(void);
int	basic_test2(void);
int	basic_test3(void);
int	basic_test4(void);
int	basic_test5(void);
int	basic_test6(void);
int	basic_test7(void);
int	basic_test8(void);
int	include_allascii_test(void);
int	include_nullchar_test(void);
int	include_space_test(void);
int	empty_str_test(void);
int	bigger_str_test(void);
int	null_test(void);
int	exception_launcher(void);
int	ko_case(void);
int	bus_error(void);
int	time_out(void);
int	sig_abrt(void);
int	sig_fpe(void);
int	sig_pipe(void);
int	sig_ill(void);
int	stdout_launcher(void);
int	stdout_test(void);

#endif
