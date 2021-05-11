#ifndef TOLOWER_TESTS_H
# define TOLOWER_TESTS_H

# include <string.h>
# include <ctype.h>
# include "../../real-tests/libft/libft.h"

int	tolower_launcher(void);
int	tolower_basic_test(void);
int	tolower_basic_test2(void);
int	tolower_not_alpha(void);
int	tolower_null_char(void);
int	tolower_not_ascii(void);

#endif