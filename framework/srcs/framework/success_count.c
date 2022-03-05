#include <stddef.h>

static size_t	g_success_count;

void	set_success_count(size_t value)
{
	g_success_count = value;
}

size_t	get_success_count(void)
{
	return (g_success_count);
}

void	reset_success_count(void)
{
	set_success_count(0);
}

void	inc_success_count(void)
{
	size_t	value;

	value = get_success_count();
	set_success_count(++value);
}
