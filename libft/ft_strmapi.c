#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	idx;

	if (!s)
		return (NULL);
	idx = 0;
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[idx] != '\0')
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
