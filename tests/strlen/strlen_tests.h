#ifndef STRLEN_TESTS_H
# define STRLEN_TESTS_H

# include <string.h>
# include "../../real-tests/libft/libft.h"

int	strlen_launcher(void);
int	basic_test(void);
int	basic_test2(void);
int	basic_test3(void);
int	basic_test4(void);
int	basic_test5(void);
int	basic_test6(void);
int	basic_test7(void);
int	basic_test8(void);
int include_allascii_test(void);
int	not_endwith_nullchar(void);
int	include_space_test(void);
int	empty_str_test(void);
int	include_nullchar_test(void);
int	bigger_str_test(void);
int	null_test(void);
int	bus_error(void);
int	ko_case(void);
int	zero_divide(void);

#endif