#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	size_t			i;

	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		if (s1_cpy[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
