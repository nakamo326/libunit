#include <stddef.h>

static size_t	g_testcount;

size_t	set_testcount(size_t value)
{
	g_testcount = value;
}

size_t	get_testcount()
{
	return (g_testcount);
}

void	reset_testcount()
{
	set_testcount(0);
}

void	inc_testcount()
{
	size_t	value;

	value = get_testcount();
	set_testcount(++value);
}
