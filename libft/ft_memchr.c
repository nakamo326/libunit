#include "libft.h"

void	*ft_memchr(const void *src, int ch, size_t len)
{
	const unsigned char	*src_cpy;
	int					count;

	src_cpy = (const unsigned char *)src;
	count = 0;
	while (len--)
	{
		if (src_cpy[count] == (unsigned char)ch)
			return ((void *)&src_cpy[count]);
		count++;
	}
	return (NULL);
}
