#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_cpy;

	s_cpy = (char *) s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s_cpy[i] == c)
			return (&s_cpy[i]);
		i++;
	}
	if (c == '\0')
		return (&s_cpy[i]);
	return (NULL);
}
