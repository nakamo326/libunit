#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;
	size_t				i;

	dest_cpy = (unsigned char *) dest;
	src_cpy = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		if (dest_cpy[i] == (unsigned char) c)
		{
			dest += i + 1;
			return (dest);
		}
		i++;
	}
	return (NULL);
}
