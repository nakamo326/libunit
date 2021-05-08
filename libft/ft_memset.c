#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uch_c;
	unsigned char	*s2;

	i = 0;
	uch_c = (unsigned char) c;
	s2 = (unsigned char *) s;
	while (i < n)
	{
		s2[i] = uch_c;
		i++;
	}
	return (s);
}
