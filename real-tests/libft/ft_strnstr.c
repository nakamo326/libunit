#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*uc_big;
	unsigned char	*uc_little;

	if (little[0] == '\0')
		return ((char *)big);
	uc_big = (unsigned char *)big;
	uc_little = (unsigned char *)little;
	i = 0;
	while (uc_big[i] && i < len)
	{
		j = 0;
		while (i + j < len && uc_big[i + j] == uc_little[j])
		{
			if (uc_little[j + 1] == '\0')
				return ((char *)&uc_big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
