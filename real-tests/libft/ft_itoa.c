#include "libft.h"

static int	ft_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n >= 10)
	{
		digit++;
		n /= 10;
	}
	digit++;
	return (digit);
}

static void	ft_itoa_reverse(char *result, int n)
{
	int	negative_flg;
	int	idx;

	idx = 0;
	negative_flg = 0;
	if (n < 0)
	{
		negative_flg = 1;
		n *= -1;
	}
	while (n >= 10)
	{
		result[idx] = '0' + n % 10;
		idx++;
		n /= 10;
	}
	result[idx] = '0' + n % 10;
	idx++;
	if (negative_flg)
	{
		result[idx] = '-';
		idx++;
	}
	result[idx] = '\0';
}

static void	ft_revsort(char *str, int digit)
{
	char	revstr[12];
	int		i;

	i = 0;
	ft_strlcpy(revstr, str, digit + 1);
	while (i < digit)
	{
		str[i] = revstr[digit - 1 - i];
		i++;
	}
	str[digit] = '\0';
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*result;

	digit = ft_digit(n);
	result = malloc(digit + 1);
	if (!result)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(result, "-2147483648", digit + 1);
		return (result);
	}
	ft_itoa_reverse(result, n);
	ft_revsort(result, digit);
	return (result);
}
