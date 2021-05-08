#include "libft.h"
#include "limits.h"

static int	ft_is_overflow(long num, char next_num)
{
	if (num > (LONG_MAX - (next_num - '0')) / 10)
		return (1);
	return (0);
}

static int	ft_is_underflow(long num, char next_num)
{
	num *= -1;
	if (num < (LONG_MIN + (next_num - '0')) / 10)
		return (1);
	return (0);
}

static int	ft_skip_space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		negaposi_flg;
	long	num;

	negaposi_flg = 1;
	num = 0;
	i = ft_skip_space(nptr);
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negaposi_flg = negaposi_flg * -1;
		i++;
		break ;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (negaposi_flg == 1 && ft_is_overflow(num, nptr[i]))
			return ((int)LONG_MAX);
		if (negaposi_flg != 1 && ft_is_underflow(num, nptr[i]))
			return ((int)LONG_MIN);
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(num * negaposi_flg));
}
