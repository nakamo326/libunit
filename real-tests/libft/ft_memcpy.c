#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;
	size_t		i;

	dest_cpy = (char *) dest;
	src_cpy = (const char *) src;
	i = 0;
	if (n == 0 || dest_cpy == src_cpy)
		return (dest);
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
