#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	char		*src_cpy;
	char		*last_dest;
	char		*last_src;

	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (n == 0 || dest_cpy == src_cpy)
		return (dest);
	if (dest_cpy < src_cpy)
		while (n--)
			*dest_cpy++ = *src_cpy++;
	else
	{
		last_src = src_cpy + (n - 1);
		last_dest = dest_cpy + (n - 1);
		while (n--)
			*last_dest-- = *last_src--;
	}
	return (dest);
}
