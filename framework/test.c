#include <string.h>
#include "libunit.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	basic_test(void)
{
	return (-(ft_strlen("Hello") != strlen("Hello")));
}

int	a(void)
{
	return (-(ft_strlen("") != strlen("")));
}

int	b(void)
{
	return (-(ft_strlen("1") != strlen("1w")));
}

int	c(void)
{
	char *s = NULL;
	return (-(ft_strlen(s) != strlen(s)));
}

int	d(void)
{
	return (-(ft_strlen("123456789") != strlen("123456789")));
}

int	e(void)
{
	char *s = malloc(1);
	free(s);
	free(s);
	return (-(ft_strlen("") != strlen("")));
}

int	g(void)
{
	char *s = "aiue";
	s[0] = 1;
	return (-(ft_strlen("") != strlen("")));
}

int main()
{
	t_clist *lst;

	puts("\x1b[1mSTRLEN\x1b[0m\n");
	load_test(&lst, "basic_test", basic_test);
	load_test(&lst, "a", a);
	load_test(&lst, "b", b);
	load_test(&lst, "c", c);
	load_test(&lst, "d", d);
	load_test(&lst, "e", e);
	load_test(&lst, "g", g);
	return (launch_tests(&lst));
}