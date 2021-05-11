#ifndef TOUPPER_TESTS_H
# define TOUPPER_TESTS_H

# include <string.h>
# include <ctype.h>
# include "../../real-tests/libft/libft.h"

int	toupper_launcher(void);
int	toupper_basic_test(void);
int	toupper_basic_test2(void);
int	toupper_not_alpha(void);
int	toupper_null_char(void);
int	toupper_not_ascii(void);

#endif