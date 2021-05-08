#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_cpy;
	char	*result;

	result = NULL;
	s_cpy = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s_cpy[i] == c)
			result = &s_cpy[i];
		i++;
	}
	if (c == '\0')
		result = &s_cpy[i];
	return (result);
}
