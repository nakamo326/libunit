#include <stddef.h>

static size_t	g_testcount;

void	set_testcount(size_t value)
{
	g_testcount = value;
}

size_t	get_testcount(void)
{
	return (g_testcount);
}

void	reset_testcount(void)
{
	set_testcount(0);
}

void	inc_testcount(void)
{
	size_t	value;

	value = get_testcount();
	set_testcount(++value);
}
